#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "soach-route.h"

#ifndef SOACH_ROUTE_VECTOR
#define SOACH_ROUTE_VECTOR

struct SOACH_route_vector {
	size_t size;
	int capacity;
	struct SOACH_route **routes;
};

#endif

/**
 * Initializes the memory for a vector of routes with defined capacity.
 */
void SOACH_route_vector_init(struct SOACH_route_vector *route, int capacity);

/**
 * Appends a SOACH_route on the vector. If needed, it reallocates memory.
 */
void SOACH_route_vector_append(struct SOACH_route_vector *vector,
		struct SOACH_route *route);

/**
 * Returns the SOACH_route at index.
 */
struct SOACH_route *SOACH_route_vector_get(struct SOACH_route_vector *vector,
		int index);

/**
 * Defines the SOACH_route stored at index.
 */
void SOACH_route_vector_set(struct SOACH_route_vector *vector, int index,
		struct SOACH_route *route);

/**
 * Frees the memory for the vector.
 */
void SOACH_route_vector_free(struct SOACH_route_vector *vector);
