#include "main.h"

int main(int argc, char* argv[])
{
	char* fvalue = NULL;

	if (argc < 2) {
		presentation();
		return EXIT_SUCCESS;
	}

	if (!handle_options(&fvalue, argc, argv)) {
		return EXIT_FAILURE;
	}

	struct SOACH_route_vector* routes =
		malloc(sizeof(struct SOACH_route_vector));
	if (routes == NULL) {
		fprintf(stderr, "%s\n", strerror(errno));
		return EXIT_FAILURE;
	}

	SOACH_route_vector_init(routes, DEFAULT_ROUTES_CAPACITY);

	if (!SOACH_conf_read(fvalue, routes)) {
		return EXIT_FAILURE;
	}

	for (int i = 0; i < routes->size; i++) {
		struct SOACH_route route = *SOACH_route_vector_get(routes, i);
		fprintf(stdout, "Route: %s, Service: %s\n", route.route,
				route.service);
	}

	SOACH_route_vector_free(routes);

	return EXIT_SUCCESS;
}

bool handle_options(char** fvalue, int argc, char** argv)
{
	int f;

	while ((f = getopt(argc, argv, "f:")) != -1) {
		switch (f) {
		case 'f':
			*fvalue = optarg;
			break;
		}
	}

	return *fvalue != NULL;
}

void presentation()
{
	fprintf(stdout,
			"SOA in C over HTTP\n"
			"\t-f <filename>\tUses <filename> as routing file\n");
}
