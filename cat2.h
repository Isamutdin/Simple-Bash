#ifndef S21_CAT
#define S21_CAT

#include <stdio.h>
#include <string.h>
#include <getopt.h>
#define no_argument 0
#define required_argument 1
#define optional_argument 2

struct Flags {
	int n;
	int e;
	int v;
	int s;
	int b;
	int E;
	int T;
	int t;
};

/*
struct option {
	const char *name;
	int has_arg;
	int *flag;
	int val;
};

    struct option long_options[] = {{"number_nonblank", no_argument, NULL, 'b'},
                                    {"number", no_argument, NULL, 'n'},
                                    {"squeeze-blank", no_argument, NULL, 's'},
                                    {0, 0, 0, 0}};

struct option long_option[] {
			{"number-nonblank", no_argument, &b, 1},
			{"number", no_argument, &n, 1},
			{"squeeze-blank", no_argument, &s, 1},
			{NULL, 0, NULL, 0}
			};
*/

int my_strcmp(char *str1, char *str2);

#endif
