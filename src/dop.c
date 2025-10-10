#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dop.h"
/**
 *
 * cmd_dop - Command initiator for dop subcommand.
 * @argc: number of arguments.
 * @argv: arguments array.
 *
 * This command provides DOP values from a sats file
 *   - sats <sats file path>
 *
 * Example:
 *   gnss-tool dop sats ../data/satdata.txt
 *
 */
int cmd_dop(int argc, char *argv[]) {
	if (argc < 2) {
		print_dop_usage();
		return EXIT_FAILURE;
	} else if (!strcmp(argv[1], "sats")) {
		printf("[dop] Computing DOP for %s sats file\n", argv[2]);
	} else if (!strcmp(argv[1], "help")) {
		print_dop_usage();
	} else {
		fprintf(stderr, "Unknown command: %s\n", argv[1]);
		print_dop_usage();
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void print_dop_usage() {
	printf("Usage: gnss-tool dop <subcommands>\n");
	printf("Subcommands:\n");
	printf("  sats <data_file_path>   computes DOP from a sats datafile\n");
	printf("  help                    displays this help\n");
}

