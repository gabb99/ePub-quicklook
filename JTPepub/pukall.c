#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "pukall.h"

//implementation of Pukall Cipher 1
unsigned char *PC1(const unsigned char *key, unsigned int klen, const unsigned char *src,
                   unsigned char *dest, unsigned int len, int decryption) {
    unsigned int sum1 = 0;
    unsigned int sum2 = 0;
    unsigned int keyXorVal = 0;
    unsigned short wkey[8];
    unsigned int i;
    if (klen != 16) {
        fprintf(stderr, "Bad key length!\n");
        return NULL;
    }
    for (i = 0; i < 8; i++) {
        wkey[i] = (key[i * 2] << 8) | key[i * 2 + 1];
    }
    for (i = 0; i < len; i++) {
        unsigned int temp1 = 0;
        unsigned int byteXorVal = 0;
        unsigned int j, curByte;
        for (j = 0; j < 8; j++) {
            temp1 ^= wkey[j];
            sum2 = (sum2 + j) * 20021 + sum1;
            sum1 = (temp1 * 346) & 0xFFFF;
            sum2 = (sum2 + sum1) & 0xFFFF;
            temp1 = (temp1 * 20021 + 1) & 0xFFFF;
            byteXorVal ^= temp1 ^ sum2;
        }
        curByte = src[i];
        if (!decryption) {
            keyXorVal = curByte * 257;
        }
        curByte = ((curByte ^ (byteXorVal >> 8)) ^ byteXorVal) & 0xFF;
        if (decryption) {
            keyXorVal = curByte * 257;
        }
        for (j = 0; j < 8; j++) {
            wkey[j] ^= keyXorVal;
        }
        dest[i] = curByte;
    }
    return dest;
}

