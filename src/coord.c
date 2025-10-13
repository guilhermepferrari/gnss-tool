#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "coord.h"

/**
 * 
 * cmd_coord - Command initiator for coord subcommand.
 * @argc: number of arguments;
 * @argv: arguments array;
 *
 * This command provides coordinate conversions:
 *   - to-ecef <lat> <lon> <h>
 *   - to-geo <x> <y> <z>
 * 
 * Example:
 *   gnss-tool coord to-ecef 52.0 13.0 100
 */
int cmd_coord(int argc, char *argv[]) {
	if (argc < 2) {
		// EXIT FAILURE: not enough arguments
		print_coord_usage();
		return EXIT_FAILURE;
	}

	// from geodetic to cartesian
	if (!strcmp(argv[1],"to-ecef")) {
		printf("[coord] Converting geodetic to ECEF...\n");
		struct geocoord input_geo = {
			.lat = argv[2],
			.lon = argv[3],
			.h = argv[4]
		};
		struct cartesian result = to_ecef(&input_geo);
	
	// from cartesian to geodetic 
	} else if (!strcmp(argv[1], "to-geo")) {
		printf("[coord] Converting ECEF to geodetic...\n");
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

/**/
struct cartesian to_ecef(const struct geocoord *input_geo) {
	// STEP 1: Convert geocoord to rad
	double lat_rad = input_geo->lat * M_PI / 180.0;
	double lon_rad = input_geo->lon * M_PI / 180.0;
	double e_sq = (2 * WGS_F) - pow(WGS_F, 2);
	
	// STEP 2: Compute the radius of the curvature
	double N = WGS_A / sqrt(1.0 - (e_sq * pow(sin(lat_rad),2)));

	// STEP 3: Compute Cartesian coordinates
	double x = (N + input_geo->h) * cos(lat_rad) * cos(lon_rad);
	double y = (N + input_geo->h) * cos(lat_rad) * sin(lon_rad);
	double z = (((1 - e_sq) * N) + input_geo->h) * sin(lat_rad);

	struct cartesian result = {
		.x = x, 
		.y = y, 
		.z = z
	};

	return result;
}
