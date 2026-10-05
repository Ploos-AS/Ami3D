#include <stdio.h>
#include "ami3d/reference_renderer.h"

int main(void)
{
    Ami3DScene scene = {0};
    Ami3DRenderSettings settings = {320, 256, 0};
    Ami3DRenderResult result;

    scene.camera.fov_degrees = 50.0f;
    result = ami3d_reference_renderer.render_frame(&scene, &settings, "m0-reference.ppm");
    if (result != AMI3D_RENDER_OK) {
        fprintf(stderr, "reference render failed\n");
        return 1;
    }
    return 0;
}
