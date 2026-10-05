import hashlib
import json
import subprocess
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SCENE = ROOT / "tests/scenes/minimal.scene.json"

def test_scene_contract():
    scene = json.loads(SCENE.read_text())
    assert scene["version"] == 1
    assert scene["render"] == {"width": 320, "height": 256, "frame": 0}
    assert len(scene["objects"]) == 1

def test_reference_render_is_deterministic():
    with tempfile.TemporaryDirectory() as d:
        a = Path(d) / "a.ppm"
        b = Path(d) / "b.ppm"
        cmd = ["python3", str(ROOT/"tools/m0_render.py"), str(SCENE)]
        subprocess.run(cmd+[str(a)], check=True)
        subprocess.run(cmd+[str(b)], check=True)
        assert hashlib.sha256(a.read_bytes()).digest() == hashlib.sha256(b.read_bytes())
