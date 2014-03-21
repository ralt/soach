#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

#include "soach-route.h"
#include "soach-route-vector.h"
#include "soach-conf.h"

#define DEFAULT_ROUTES_CAPACITY 50

bool handle_options(char**, int, char**);

void presentation();
