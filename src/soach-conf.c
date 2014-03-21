#include "soach-conf.h"

bool SOACH_conf_read(char *fvalue, struct SOACH_route_vector *routes)
{
	SOACH_route_vector_init(routes, DEFAULT_ROUTES_CAPACITY);
	return true;
}
