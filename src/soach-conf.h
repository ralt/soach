#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#include "soach-route.h"
#include "soach-route-vector.h"

#define SEPARATOR "\t"

bool SOACH_conf_read(char *fvalue, struct SOACH_route_vector *routes);

bool SOACH_conf_valid_line(char *line, size_t len);

struct SOACH_route *SOACH_conf_readline(char *line, size_t len);
