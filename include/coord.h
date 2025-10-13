#ifndef COORD_H
#define COORD_H

/* ---- Data Structures ---- */

struct cartesian {
	float x;
	float y;
	float z;
};

struct geodesic {
	float lat;
	float lon;
	float h;
};

/* ---- Function Prototypes ---- */

int cmd_coord(int argc, char *argv[]);
void print_coord_usage();
struct cartesian to_ecef (struct geodesic *geocoord);
struct geodesic to_geo (struct cartesian *cartcoord);

/* ---- Constants ---- */

#define WGS84_A 6378137.0 // Semi-major Axis "a" in meters
#define WGS84_F 1.0/298.257223563 // Flattening Factor

#endif
