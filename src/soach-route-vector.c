#include "soach-route-vector.h"

void SOACH_route_vector_init(struct SOACH_route_vector *vector, int capacity)
{
	vector->size = 0;
	vector->capacity = capacity;
	vector->routes = malloc(sizeof(struct SOACH_route) * vector->capacity);
	if (vector->routes == NULL) {
		printf("%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	if (vector->routes == NULL) {
		exit(errno);
	}
}

void SOACH_route_vector_append(struct SOACH_route_vector *vector,
		struct SOACH_route *route)
{
	if (vector->size >= vector->capacity) {
		vector->capacity *= 2;
		vector->routes = realloc(vector->routes,
				sizeof(struct SOACH_route) *
				vector->capacity);
		if (vector->routes == NULL) {
			exit(errno);
		}
	}
	vector->routes[vector->size++] = route;
}

struct SOACH_route *SOACH_route_vector_get(struct SOACH_route_vector *vector,
		int index)
{
	if (index < 0 || index >= vector->size) {
		printf("Out of bounds\n");
		exit(1);
	}
	return vector->routes[index];
}

void SOACH_route_vector_set(struct SOACH_route_vector *vector, int index,
		struct SOACH_route *value)
{
	vector->routes[index] = value;
}

void SOACH_route_vector_free(struct SOACH_route_vector *vector)
{
	for (size_t i = 0; i < vector->size; i++) {
		SOACH_route_free(SOACH_route_vector_get(vector, i));
	}
	free(vector);
}
