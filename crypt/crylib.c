// cry.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getKeyShift(int inx, char *ckey) {
    char skey[16];
    // char ckey[50];
    char ck1;
    int ck1n = 0;
    sprintf(skey, "%d", ckey[inx]);  // make string of the int key code
    ck1 = skey[1];  // take 2nd digit of the (numeric) string
    ck1n = ck1 - '0';  // convert and return as int
    if (ck1n == 0) ck1n = 3;  // many zeros with no shift value
    return ck1n;
}

char *encrypt(char *etext, char *plain, char *key) {
    char ch;
    uint kix = 0;
    uint klen = strlen(key) - 1;  // valid index bounds
    uint ix = 0;
    char cval = 'A';
    uint plen = strlen(plain);
    for(ix=0; ix < plen; ix++) {
        ch = plain[ix];
        cval = ch + getKeyShift(kix, key);
        while (cval == '\0') {
            printf("Found NULL at: %d kix=%d cval=%d klen=%d\n", ix, kix, cval, klen);
            kix++;
            if (kix > klen) kix = 0;
            cval = ch + getKeyShift(kix, key);
        }
        etext[ix] = cval;
        kix++;
        if (kix > klen) kix = 0;
    }
    etext[ix] = '\0';
    return etext;
}

char *decrypt(char *plain, char *etext, char *key) {
    char ch;
    uint kix = 0;
    uint klen = strlen(key) - 1;
    uint ix = 0;
    char cval;
    uint elen = strlen(etext);
    for(ix=0; ix < elen; ix++) {
        ch = etext[ix];
        cval = ch - getKeyShift(kix, key);
        while (cval == '\0') {
            printf("Found NULL at: %d kix=%d cval=%d klen=%d\n", ix, kix, cval, klen);
            kix++;
            if (kix > klen) kix = 0;
            cval = ch - getKeyShift(kix, key);
        }
        plain[ix] = cval;
        kix++;
        if (kix > klen) kix = 0;
    }
    plain[ix] = '\0';
    return plain;
}


void main() {

    char px[500000] = {"\0"};
    char ex[500000] = {"\0"};

    char str[1000] = \
    "50 My name is Francisco Max. | I am 100 years young!\n"
    "50 My name is Francisco Max. | I am 100 years young!\n"
    "500 My name is Francisco Max. | I am 100 years young!\n"
    "50 My name is Francisco Max. | I am 100 years young!\n"
    "500 My name is Francisco Max. | I am 100 years young!\n"
    "50 My name is Francisco Max. | I am 100 years young!\n"
    "500 My name is Francisco Max. | I am 100 years young!\n"
    "50 My name is Francisco Max. | I am 100 years young!\n"
    "500 My name is Francisco Max. | I am 100 years young!\n"
    "50 My name is Francisco Max. | I am 100 years young!\n"
    "500 My name is Francisco Max. | I am 100 years young!\n";

    strcpy(px, str);
    puts(px);
    puts(encrypt(ex, px, "SecretKey"));
    // memset(px, '\0', 64);
    puts(decrypt(px, ex, "SecretKey"));
}
