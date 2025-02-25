
#pragma once

namespace drumstick {

    struct Coordinate {
        const f32 latitude;
        const f32 longitude;

        Coordinate(f32 latitude, f32 longitude);
    };

    /*
        Helper for relative projection.
    */
    class Projection {
        const f32 v0; // reference lon
        const f32 v1; // reference lat
        const f32 v2;
        const f32 v3;
        const f32 v4; // meter / pixel
        const f32 v5; // meter / pixel

    public:
        explicit Projection(f32 v0, f32 v1, f32 v2, f32 v3, f32 v4, f32 v5);

        Coordinate
        coordinate_from_grid_position(int ROW, int COL);
    };

}