#include <stdio.h>
#include <stdlib.h>
#include "ami3d/renderer.h"

static Ami3DRenderResult write_reference_ppm(
    const Ami3DScene *scene,
    const Ami3DRenderSettings *settings,
    const char *output_path)
{
    FILE *f;
    uint32_t x, y;
    uint32_t cx, cy;

    if (!scene || !settings || !output_path || settings->width == 0 || settings->height == 0)
        return AMI3D_RENDER_ERROR;

    f = fopen(output_path, "wb");
    if (!f)
        return AMI3D_RENDER_ERROR;

    fprintf(f, "P6\n%u %u\n255\n", (unsigned)settings->width, (unsigned)settings->height);
    cx = settings->width / 2;
    cy = settings->height / 2;

    for (y = 0; y < settings->height; ++y) {
        for (x = 0; x < settings->width; ++x) {
            unsigned char pixel[3] = {0, 0, 0};
            if (x >= cx - 8 && x < cx + 8 && y >= cy - 8 && y < cy + 8)
                pixel[0] = pixel[1] = pixel[2] = 255;
            if (fwrite(pixel, 1, sizeof(pixel), f) != sizeof(pixel)) {
                fclose(f);
                return AMI3D_RENDER_ERROR;
            }
        }
    }

    if (fclose(f) != 0)
        return AMI3D_RENDER_ERROR;
    return AMI3D_RENDER_OK;
}

const Ami3DRenderer ami3d_reference_renderer = {
    "reference",
    write_reference_ppm
};
