#ifndef AMI3D_SCENE_H
#define AMI3D_SCENE_H

#include <stdint.h>

typedef struct {
    float x, y, z;
} Ami3DVec3;

typedef struct {
    Ami3DVec3 position;
    Ami3DVec3 rotation;
    Ami3DVec3 scale;
} Ami3DTransform;

typedef struct {
    uint32_t id;
    Ami3DTransform transform;
    uint32_t mesh_id;
    uint32_t material_id;
} Ami3DObject;

typedef struct {
    Ami3DTransform transform;
    float fov_degrees;
} Ami3DCamera;

typedef struct {
    uint32_t width;
    uint32_t height;
    uint32_t frame;
} Ami3DRenderSettings;

typedef struct {
    const Ami3DObject *objects;
    uint32_t object_count;
    Ami3DCamera camera;
} Ami3DScene;

#endif
