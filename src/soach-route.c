#include "soach-conf.h"

void SOACH_route_free(struct SOACH_route *route)
{
	free(route->route);
	free(route->service);
}
