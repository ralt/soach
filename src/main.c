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

	fprintf(stdout, "%s\n", fvalue);

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
		case '?':
			if (optopt == 'c') {
				fprintf(stderr, "Option -%c requires an argument.\n", optopt);
			}
			else {
				fprintf(stderr, "Unknown option.\n");
			}
			return false;
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
