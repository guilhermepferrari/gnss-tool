#ifndef RINEX_H
#define RINEX_H


/* constants -----------------------------------------------------------------*/

// TODO: definitions

/* type definitions ----------------------------------------------------------*/

// TODO: new structs

/* function prototypes -------------------------------------------------------*/

/**
 * TODO: cmd_rinex documentation
 */
int cmd_rinex(int argc, char *argv[]);

/**
 * TODO: print_rinex_usage documentation
 */
void print_rinex_usage();

/**
 * @brief Reads and parses RINEX observation files.
 * 
 * @param[in] filepath Path to RINEX file.
 *  
 * @return Observation data structure containing both headers and observation
 */
int read_obs_header(char filepath);

#endif
