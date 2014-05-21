#ifndef __PUKALL_H
#define __PUKALL_H

#include <stdio.h>

unsigned char *PC1(const unsigned char *key, unsigned int klen, const unsigned char *src,
                   unsigned char *dest, unsigned int len, int decryption);

#endif
