#ifndef SOACH_ROUTE
#define SOACH_ROUTE

struct SOACH_route {
	char* route;
	char* service;
};

#endif

void SOACH_route_free(struct SOACH_route *route);
