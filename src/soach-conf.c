#include "soach-conf.h"

bool SOACH_conf_read(char *fvalue, struct SOACH_route_vector *routes)
{
	FILE *fp = NULL;
	char *line = NULL;
	size_t len = 0;

	if ((fp = fopen(fvalue, "r")) == NULL) {
		fprintf(stderr, "%s\n", strerror(errno));
		return false;
	}

	while ((getline(&line, &len, fp)) != -1) {
		if (SOACH_conf_valid_line(line, len)) {
			SOACH_route_vector_append(routes,
					SOACH_conf_readline(line, len));
		}
	}

	free(line);

	if ((fclose(fp)) == EOF) {
		return false;
	}

	return true;
}

bool SOACH_conf_valid_line(char *line, size_t len)
{
	char *dupline = strdup(line);
	if (strsep(&dupline, SEPARATOR) == NULL) {
		free(dupline);
		return false;
	}

	free(dupline);
	return true;
}

struct SOACH_route *SOACH_conf_readline(char *line, size_t len)
{
	struct SOACH_route *route = malloc(sizeof(struct SOACH_route));
	if (route == NULL) {
		fprintf(stderr, "%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	char *dupline = strdup(line);
	if (dupline == NULL) {
		fprintf(stderr, "%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	route->route = strsep(&dupline, SEPARATOR);
	route->service = strsep(&dupline, SEPARATOR);

	return route;
}
