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

/**
 * @brief Converts geodesic coordinates (latitude, longitude, altitude) to
 * Earth-Centered, Earth-Fixed (ECEF) Cartesian coordinates (X, Y, Z).
 *
 * This function performs the necessary transformation using the established 
 * WGS-84 ellipsoid model parameters to convert from a geodetic reference 
 * system into a 3D Cartesian system centered at the Earth's center of mass.
 *
 * @param[in] geocoord A constant pointer to the input `struct geodesic`, 
 *                     assumed to contain latitude and longitude in decimal, 
 *                     degrees and altitude (height above ellipsoid) in meters.
 *
 * @return A populated `struct cartesian` containing the calculated X, Y, 
 *         and Z coordinates in the ECEF reference frame, in meters.
 * 
 * @note This implementation relies on the specific physical constants 
 *       defined within the library for the WGS-84 datum.
 *
 * @see to_geo()
 */
struct cartesian to_ecef (const struct geodesic *geocoord);

/**
 * @brief Converts ECEF cartesian coordinates (X, Y, Z) to geodesic coordinates
 * (latitude, longitude, altitude).
 * 
 * This function performs the necessary transformation using the established
 * WGS-84 ellipsoid model parameters to convert from a 3D cartesian reference
 * into a geodetic reference.
 * 
 * @param[in] cartesian A constante pointe to the input `struct cartesian`,
 *                      assumed to contain X, Y and Z coordinates in the
 *                      ECEF reference, in meters.
 * 
 * @return A populated `struct geodesic` containing the latitude, longitude 
 *         in decimal degrees and altitude (height above ellipsoid) in meters.
 * 
 * @note This implementation relies on the specific physical constants defined
 *       within the library for the WGS-84 datum.
 * 
 * @see to_ecef()
 */
struct geodesic to_geo (const struct cartesian *cartcoord);

void print_geodesic_coord(const struct geodesic *geocoord);

void print_cartesian_coord(const struct cartesian *carcoord);

/* ---- Constants ---- */

#define WGS84_A 6378137.0 // Semi-major Axis "a" in meters
#define WGS84_F 1.0/298.257223563 // Flattening Factor

#endif
