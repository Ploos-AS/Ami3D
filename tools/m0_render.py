#!/usr/bin/env python3
import json
import struct
import sys

def load_scene(path):
    with open(path, "r", encoding="utf-8") as f:
        scene = json.load(f)
    assert scene["version"] == 1
    assert scene["render"]["width"] > 0
    assert scene["render"]["height"] > 0
    return scene

def write_ppm(scene, output):
    w = scene["render"]["width"]
    h = scene["render"]["height"]
    # Deterministic M0 reference image: black background, white center marker.
    pixels = bytearray(w * h * 3)
    cx, cy = w // 2, h // 2
    for y in range(max(0, cy-8), min(h, cy+8)):
        for x in range(max(0, cx-8), min(w, cx+8)):
            i = (y*w+x)*3
            pixels[i:i+3] = b"\xff\xff\xff"
    with open(output, "wb") as f:
        f.write(f"P6\n{w} {h}\n255\n".encode("ascii"))
        f.write(pixels)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        raise SystemExit("usage: m0_render.py SCENE OUTPUT.ppm")
    write_ppm(load_scene(sys.argv[1]), sys.argv[2])
