#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	if (!strcmp(argv[1],"to-ecef")) {
		printf("[coord] Converting geodetic to ECEF...\n");
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

float to_ecef(struct geocoord *input_geo) {

}
