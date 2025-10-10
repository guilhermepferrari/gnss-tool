#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "orbit.h"
/*
 *
 * cmd_orbit - Command initiator for orbit subcommand
 * @argc: number of arguments;
 * @argv: arguments array;
 *
 * This command computes the Orbit propagation from Keplerian
 * elements (a,e,i, OMEGA, omega, MI).
 *
 * Example:
 *
 *     gnss-tool orbit 
 *
 */
int cmd_orbit(int argc, char *argv[]) {
	if (argc < 2) {
		//EXIT FAILURE: not enough arguments
		print_orbit_usage();
		return EXIT_FAILURE;
	}
	printf("[orbit]: Computing orbit propagation...\n");
	return EXIT_SUCCESS;
}

void print_orbit_usage() {
	printf("Usage: gnss-tool orbit <subcommands>\n");
	printf("Subcommands:\n");
	printf(" <a> <e> <i> <OMEGA> <omega> <MI>    computes the orbit propagation.\n");
	printf(" help                                displays this help.\n");
}

