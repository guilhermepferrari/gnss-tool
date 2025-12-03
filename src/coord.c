#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "coord.h"

/* ----------------------------------------------------
 *  Command Line Interface and Display Functions
 * --------------------------------------------------- */

int cmd_coord(int argc, char *argv[]) {
    if (argc < 2) {
        // EXIT FAILURE: not enough arguments
        print_coord_usage();
        return EXIT_FAILURE;
    }

    // from geodetic to cartesian
    if (!strcmp(argv[1],"to-ecef")) {
        printf("[coord] Converting geodetic to ECEF...\n");

        struct geodesic input_geo = {
            .lat = atof(argv[2]),
            .lon = atof(argv[3]),
            .h = atof(argv[4])
        };
        struct cartesian result = to_ecef(&input_geo);
        print_cartesian_coord(&result);

    // from cartesian to geodetic
    } else if (!strcmp(argv[1], "to-geo")) {
        printf("[coord] Converting ECEF to geodetic...\n");

        struct cartesian input_xyz = {
            .x = atof(argv[2]),
            .y = atof(argv[3]),
            .z = atof(argv[4])
        };
        struct geodesic result = to_geo(&input_xyz);
        print_geodesic_coord(&result);
    
    // unknown command
    } else {
        fprintf(stderr, "Unkown command: %s\n", argv[1]);
        print_coord_usage();
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}


void print_coord_usage() {
    printf("Usage: gnss-tool coord <subcommands>\n");
    printf("Subcommands:\n");
    printf("  to-ecef <lat> <lon> <height>  converts from GEO to ECEF\n");
    printf("  to-geo <x> <y> <z>            converts from ECEF to GEO\n");
    printf("  help                          displays this help.\n");
}


void print_geodesic_coord(const struct geodesic *geocoord) {
    printf("[to_geo@coord] output: \n");
    printf(" lat -> %f \n lon -> %f \n h -> %f \n",
        geocoord->lat, geocoord->lon, geocoord->h);
}


void print_cartesian_coord(const struct cartesian *carcoord) {
    printf("[to_ecef@coord] output:\n");
    printf(" x -> %f \n y -> %f \n z -> %f \n",
        carcoord->x, carcoord->y, carcoord->z);
};


/* ----------------------------------------------------
 * Geodesic Functions
 * --------------------------------------------------- */

struct cartesian to_ecef(const struct geodesic *geocoord) {
    // Convert geocoord angles to rad
    double lat_rad = geocoord->lat * M_PI / 180.0;
    double lon_rad = geocoord->lon * M_PI / 180.0;
    double e_sq = (2 * WGS84_F) - pow(WGS84_F, 2);

    // Compute the radius of the curvature
    double N = WGS84_A / sqrt(1.0 - (e_sq * pow(sin(lat_rad),2)));

    // Compute Cartesian coordinates
    double x = (N + geocoord->h) * cos(lat_rad) * cos(lon_rad);
    double y = (N + geocoord->h) * cos(lat_rad) * sin(lon_rad);
    double z = (((1 - e_sq) * N) + geocoord->h) * sin(lat_rad);

  // Struct result
    struct cartesian result = {
        .x = x,
        .y = y,
        .z = z
    };

    return result;
}


struct geodesic to_geo(const struct cartesian *cartcoord) {
    // longitude
    double lon = atan2(cartcoord->y,cartcoord->x);
    
    // initial latitude
    double p = sqrt(pow(cartcoord->x, 2.0) + pow(cartcoord->y, 2.0));
    double e_sq = (2.0 * WGS84_F) - pow(WGS84_F, 2.0);
    double lat = atan2(cartcoord->z, (1 - e_sq) * p);

    double prev_lat = lat;
    double N, h;
    int iter = 0;

    do {
        prev_lat = lat;
        N = WGS84_A / sqrt(1.0 - e_sq * pow(sin(prev_lat),2.0));
        h = (p / cos(prev_lat)) - N;
        lat = atan2(cartcoord->z,(1.0 - e_sq * (N / (N + h))) * p);
        iter++;
    } while (fabs(lat - prev_lat) > 1e-12 && iter < 1000);

    lon *= 180.0 / M_PI;
    lat *= 180.0 / M_PI;
    
    struct geodesic result = {
        .lat = lat,
        .lon = lon,
        .h = h
    };

    return result;
}
