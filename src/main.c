#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gnss.h"
#include "coord.h"
#include "dop.h"
#include "orbit.h"
#include "pseudorange.h"
#include "rinex.h"
#include "gnssutils.h"

void print_usage(const char *parm) {
	printf("Usage: %s <command> [options]\n", parm);
	printf("Commands:\n");
	printf("  coord        Coordinates conversions (ECF <-> Latitude/Longitude)\n");
	printf("  dop          Compute Dillution of Precision\n");
	printf("  orbit        Orbit propagation from Kleperian elements\n");
	printf("  pseudorange  Compute receiver position from pseudoranges\n");
	printf("  rinex        Parse RINEX observation/navigation files\n");
	printf("  help         Show this help message\n");
	printf("  version      Show gnss-tools version\n");
}

int main(int argc, char *argv[]) {
	// case 0: no module call triggers help
	if (argc < 2) {
		print_usage(argv[0]);
	}
	// case 1: coord module
	else if (!strcmp(argv[1],"coord")) {
		cmd_coord(argc - 1, &argv[1]);
	}
	// case 2: dop module
	else if (!strcmp(argv[1],"dop")) {
		cmd_dop(argc - 1, &argv[1]);
	}
	// case 3: orbit module
	else if (!strcmp(argv[1],"orbit")) {
		cmd_orbit(argc - 1, &argv[1]);
	}
	// case 4: pseudorange module
	else if (!strcmp(argv[1], "pseudorange")) {
		cmd_pseudorange(argc - 1, &argv[1]);
	}
	// case 5: rinex parser module
	else if (!strcmp(argv[1], "rinex")) {
		cmd_rinex(argc - 1, &argv[1]);
	}
	// case 6: help!
	else if (!strcmp(argv[1],"help")){
		print_usage(argv[0]);
	}
	// case 7: version
	else if (!strcmp(argv[1],"version")) {
		printf("gnss-tool: version %s\n", VERSION);
	}
	// failure case: bad input
	else {
		fprintf(stderr, "Unknown command: %s\n", argv[1]);
		print_usage(argv[0]);
		return EXIT_FAILURE;
	}
}

