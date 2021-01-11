#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "conv.h"

static void usage()
{
	printf("usage: conv [-d] [-x] [-b] [-h] <number>\n\n");
	printf("Convert decimal, hexidecimal, and binary numbers\n\n");
	printf("  -d\tdecimal: convert dec to bin and hex\n");
	printf("  -x\thexidecimal: convert hex to dec and bin\n");
	printf("  -b\tbinary: convert bin to dec and hex\n");
	printf("  -h\tshow this help message and exit\n");
	exit(0);
}


int main(int argc, char **argv)
{
	int opt, n;
	uint64_t d;

	if (argc < 2 || argc > 3) {
		usage();
		exit(EXIT_FAILURE);
	}

	while ((opt = getopt(argc, argv, "d:x:b:h")) != -1) {
		switch(opt) {
		case 'd':
			n = atoi(optarg);
			// convert dec to bin
			char *bin = dtob(n);

			printf("  DEC:  %s\n", optarg);
			printf("  HEX:  %s\n", btoh(bin));
			printf("  BIN:  %s\n", bin);
			break;
		case 'x':
			// hex
			d = htod(optarg);
			printf("  HEX:  %s\n", optarg);
			// hex to dec
			printf("  DEC:  %llu\n", d);
			// hex to bin
			//printf("  BIN:  %s\n", dtob(p));
			break;
		case 'b':
			// binary
			printf("  BIN:  %s\n", optarg);
			// bin to dec
			printf("  DEC: %llu\n", btod(optarg));
			// bin to hex
			printf("  HEX: %s\n", btoh(optarg));
			break;
		case 'h':
			// help
			usage();
			break;
		default:
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}
