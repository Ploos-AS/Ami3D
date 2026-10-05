#ifndef AMI3D_RENDERER_H
#define AMI3D_RENDERER_H

#include "scene.h"

typedef enum {
    AMI3D_RENDER_OK = 0,
    AMI3D_RENDER_UNSUPPORTED = 1,
    AMI3D_RENDER_ERROR = 2
} Ami3DRenderResult;

typedef struct {
    const char *name;
    Ami3DRenderResult (*render_frame)(
        const Ami3DScene *scene,
        const Ami3DRenderSettings *settings,
        const char *output_path
    );
} Ami3DRenderer;

#endif
