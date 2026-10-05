# Ami3D

A modern 3D modelling, scene and rendering environment for classic Amiga systems.

## M0 goals

- Define a compact scene model suitable for AmigaOS/m68k.
- Keep rendering behind a backend API so local m68k rendering and AmiRender acceleration can coexist.
- Establish deterministic test scenes.
- Preserve future import paths for classic Amiga 3D formats.

## Architecture

```text
Ami3D UI / CLI
      |
  Scene Core
      |
 Render API
   |     |
 local  AmiRender
 m68k   appliance
```

## Initial scope

M0 intentionally does not attempt a complete modeller. It establishes the contracts that later milestones will build on.

Planned integration targets include LightWave, Imagine, Real3D, Cinema 4D, Aladdin 4D, Tornado3D, POV-Ray, AmiTerrain and Blender interchange through AmiRender.

## License

Software: MIT.
