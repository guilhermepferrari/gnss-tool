#ifndef COORD_H
#define COORD_H

/* ---- Data Structures ---- */

struct cartesian {
	double x;
	double y;
	double z;
};

struct geodesic {
	double lat;
	double lon;
	double h;
};

/* ---- Function Prototypes ---- */

int cmd_coord(int argc, char *argv[]);
void print_coord_usage();
struct cartesian to_ecef (const struct geodesic *geocoord);
struct geodesic to_geo (const struct cartesian *cartcoord);
void print_geodesic_coord(const struct geodesic *geocoord);
void print_cartesian_coord(const struct cartesian *carcoord);

/* ---- Constants ---- */

#define WGS84_A 6378137.0 // Semi-major Axis "a" in meters
#define WGS84_F 1.0/298.257223563 // Flattening Factor

#endif
