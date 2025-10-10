#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pseudorange.h"
/*
 *
 * cmd_pseudorange - Command initiator for pseudorange subcommand.
 * @argc: number of arguments;
 * @argv: arguments array;
 *
 * This command provides pseudorange computation:
 *   - subcommand:
 *
 * Example:
 *   gnss-tool pseudorange 
 * */
int cmd_pseudorange(int argc, char *argv[]) {
	if (argc < 2) {
		// EXIT FAILURE: not enough arguments
		print_pseudorange_usage();
		return EXIT_FAILURE;
	}
	printf("[pseudorange]: Computing pseudorange from... \n");
	return EXIT_SUCCESS;
}


void print_pseudorange_usage() {
	printf("Usage: gnss-tool pseudorange <subcommands>\n");
}
