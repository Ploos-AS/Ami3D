# M0 Status

Status: **FROZEN**

M0 establishes the portable Ami3D foundation.

## Accepted baseline

- compact public scene types
- renderer backend contract
- native C99 reference renderer
- deterministic scene fixture and reference output
- host-native build/test baseline
- CI gating

## M0 boundary

M0 deliberately excludes the GUI, modeller, production ray tracer, classic-format importers and Amiga-specific integration. Those belong to later milestones.

The Python renderer remains a deterministic test oracle. The product core is portable C.

Frozen after CI PASS.
