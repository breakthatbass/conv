#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"
#include "conv.h"


// binary to decmimal converter
uint64_t btod(char *bin)
{
	uint64_t n = 0;	// decimal to return
	uint64_t base = 1;

	size_t len = strlen(bin)-1;

	int i;
	for (i = len; i >= 0; i--) {
		if (bin[i] == '1') n += base;
		base = base << 1;
	}
	return n;
}


// decimal to binary converter
char *dtob(uint64_t n)
{
	static char bin[MAXBIN];
	int i;

	for (i = 0; n > 0; i++) {
		// convert to string and plug into b array
		itoa((n % 2), &bin[i]);
		n = n >> 1;
	}
	reverse(bin);
	return bin;
}


// binary to hex converter
char *btoh(char *bin) {
	static const char *h = "123456789ABCDEF";

	int i, n;
	char *hex;	// string to return

	char *nbin = pad_bin(bin);
	int len = strlen(nbin);
	int hexlen = len/4; // need one hex for every 4 bins
	hexlen++;

	hex = malloc(sizeof(char)*hexlen);
	if (hex == NULL) {
		fprintf(stderr, "btoh: couldn't allocate memory\n");
		exit(EXIT_FAILURE);
	}

	char buf[5];
	for (i = 0; i < len; i+=4) {
		// copy over 4 bins from binary str
		memcpy(buf, nbin, 4);
		// make it a proper str
		buf[4] = '\0';
		// convert to decimal
		n = btod(buf) - 1;
		// add to hex str
		*hex++ = *(h+n);
		// move ahead four spots for the next conversion
		nbin += 4;
	}
	*hex = '\0';
	// move pointer back to start
	hex -= hexlen-1;
	return hex;
}

#include <ctype.h>

#define HEXLEN 6

struct x {
	char c;
	int val;
};

struct x hex_c[HEXLEN];  // key value pairs for each hex char


// get a decimal value from a single hex char
int get_value(char c)
{
	int i, n;
	char ch;
	int p;

	for (i = 0, ch = 'A', n = 10; i < HEXLEN; ch++, i++, n++) {
		hex_c[i].c = ch;
		hex_c[i].val = n;
	}

	if (isnumber(c)) {
		sscanf(&c, "%d", &p);
		return p;
	}
	else if (c >= 'A' || c <= 'F') {
		// get val from struct
		for (i = 0; i < HEXLEN; i++) {
			if (c == hex_c[i].c) {
				return hex_c[i].val;
			}
		}
	} 
	return -1;
}



// hex to dec
long htod(char *hex)
{	
	int i, n;
	long dec = 0;
	long base = 1;

	size_t len = strlen(hex)-1;

	hex += len;
	for (i = len; i>=0; --i, --hex) {
		n = get_value(*hex);
		if (n < 0) {
			fprintf(stderr, "not a valid HEX\n");
			exit(EXIT_FAILURE);
		}
		dec += base * n;
		base *= 16;
	}
	return dec;
}

