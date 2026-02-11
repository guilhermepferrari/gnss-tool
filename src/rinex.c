#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rinex.h"

/* command line functions ................................................... */

int cmd_rinex(int argc, char *argv[]){
	if (argc < 2) {
		print_rinex_usage();
		return EXIT_FAILURE;
	}
	printf("[rinex]: Parsing observation/navigation files...\n");
	return EXIT_SUCCESS;
}


void print_rinex_usage(){
	printf("Usage: gnss-tool rinex <subcommands>");
}


/* rinex observation parser functions ....................................... */


int read_obs_header(FILE *fp, rinex_obs_header *hdr) {
	char line[128];					// fixed line width

	while (fgets(line, sizeof(line), fp)) {

		if (strstr(line, "RINEX VERSION")) {	// substring for version
			hdr->version = atof(line);	// convert to double
		}

		if (strstr(line, "# / TYPES OF OBSERV")) { // substr for obs_t
			sscanf(line,"%d", &hdr->n_obs); // scan and store
			for (int i = 0; i < hdr->n_obs; i++)
				strncpy(hdr->obs_types[i], line + 10 + i*6, 3);
		}

		if (strstr(line, "INTERVAL")) {		// substr for interval
			hdr->interval = atof(line);
		}

		if (strstr(line, "END OF HEADER")) {
			return 1;
		}
	}
	return 0;
}

// TODO: read_obs_epoch
















