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


int read_obs_file(filepath) {
/* 1. read file ..............................................................*/
/* 2. iterate each line of the file ..........................................*/
/* 2.1 parse header ..........................................................*/
/**/

}














