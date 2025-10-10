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

#define WGS84_A 0.000 // Semi-major Axis "a"
#define WGS84_F 0.000 // Flattening Factor (1-b/a), where "b" is the minoraxis
#define WGS84_R 0.000 // Ellipsoid Radius



#endif
