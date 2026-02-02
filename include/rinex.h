#ifndef RINEX_H
#define RINEX_H

/* constants -----------------------------------------------------------------*/

#define MAX_OBS_TYPES 16	/* max # of obs values per sat (C1, L1, etc) */
#define MAX_SATS      64	/* max # of satellites in a single obs epoch */
#define MAX_EPH       64        /* max # of ephemeris records stored */

/* type definitions ----------------------------------------------------------*/


typedef struct {	/* calendar timestamp */
	int year, month, day, hour, minute;
	double sec;
} gps_time_t; // GpsTime


typedef struct {	/* gnss satellite measurements for a single epoch */
	char id[4];     /* examples: "G01", "R12"*/
	double obs[MAX_OBS_TYPES]; /* observation rules */
} sat_obs_t; // SatObs


typedef struct {	/* all sat observations belonging to the same epoch */
	gps_time_t time;
	int n_sat;
	sat_obs_t sats[MAX_SATS]
} obs_epoch_t; // ObsEpoch


typedef struct {	/* obs header metadata */
	double version; // rinex version number
	int n_obs; // number of observation types
	char obs_types[MAX_OBS_TYPES][4]; // observation type indentifiers
	double interval; // time space between epochs, in seconds
} rinex_obs_header;


typedef struct {	/* nav ephemeris record */
	char sat_id[4]; // satellite identifier
	double af0, af1, af2; // satellite clock correction coefficients
	double toe; // reference time (time of ephemeris)
	double sqrt_a; // square root of semi-major axis
	double e; // orbital eccentricity
	double i0; // inclination angle at reference time
	double omega_0; // longitude of ascending mode 
	double omega; // argument of perigee
	double m0; // mean anomaly at reference time
	double omega_dot; // rate of right ascencion
	double idot; // rate of inclination
} ephemeris;

typedef struct {
	int n;
	ephemeris eph[MAX_EPH];
} nav_store;

/* function prototypes -------------------------------------------------------*/

int cmd_rinex(int argc, char *argv[]);
void print_rinex_usage();

FILE *read_rinex(char *path);

#endif
