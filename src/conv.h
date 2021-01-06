#ifndef __CONV_H__
#define __CONV_H__

#define MAXBIN 64

// binary to decimal converter
uint64_t btod(char *bin);

// decimal to binary converter
char *dtob(uint64_t n);

// binary to hex conveter
char *btoh(char *bin);

#endif
