
#include <drumstick/Coordinate.hpp>

namespace drumstick {

    /*
    ## Coordinate: impl
    */

    Coordinate::Coordinate(f32 latitude, f32 longitude)
    : latitude(latitude), longitude(longitude) {}


    /*
    ## Projection: impl
    */

    Projection::Projection(f32 v0, f32 v1, f32 v2, f32 v3, f32 v4, f32 v5)
    : v0(v0), v1(v1), v2(v2), v3(v3), v4(v4), v5(v5) {}

    static inline f32
    acotan(f32 x) {
        return atan(1.0 / x);
    }

    Coordinate
    Projection::coordinate_from_grid_position(int ROW, int COL) {
        static constexpr f32 PI = 3.14159265358979323846;

        const f32 ph_rad = (1.570796326795-2*atan(0.404026225835*pow((1/sin(acotan(5899179.2/
            ((5676531.8*pow((tan((1.570796326795-(v1*0.017453292520))/2)/
            0.373884679485),0.737361597616)*sin(0.012869387656*(v0-13.333333333))-
            v3*v4)+COL*v4)-((6380000.0*(0.924636243305-0.889738536848*pow((tan((
            1.570796326795-(v1*0.017453292520))/2)/0.373884679485),0.737361597616)*
            cos(0.012869387656*(v0-13.333333333)))+v2*v5)-ROW*v5)/((5676531.8*
            pow((tan((1.570796326795-(v1*0.017453292520))/2)/0.373884679485),
            0.737361597616)*sin(0.012869387656*(v0-13.333333333))-v3*v4)+COL*v4))))*
            ((5676531.8*pow((tan((1.570796326795-(v1*0.017453292520))/2)/
            0.373884679485),0.737361597616)*sin(0.012869387656*(v0-13.333333333))-
            v3*v4)+COL*v4)/6380000.0*0.737361597616/sin(0.767944870878),1/
            0.737361597616)));

        const f32 la_rad = acotan(5899179.2/((5676531.8*pow((tan((1.570796326795-(v1*0.017453292520))
            /2)/0.373884679485),0.737361597616)*sin(0.012869387656*(v0-13.333333333))
            -v3*v4)+COL*v4)-((6380000.0*(0.924636243305-0.889738536848*pow((tan((
            1.570796326795-(v1*0.017453292520))/2)/0.373884679485),0.737361597616)*
            cos(0.012869387656*(v0-13.333333333)))+v2*v5)-ROW*v5)/((5676531.8*pow((
            tan((1.570796326795-(v1*0.017453292520))/2)/0.373884679485),
            0.737361597616)*sin(0.012869387656*(v0-13.333333333))-v3*v4)+COL*v4))/
            0.737361597616+0.232710566928;

        // Convert to degrees:
        return {
            (ph_rad * 180) / PI,
            (la_rad * 180) / PI
        };
    }

}
