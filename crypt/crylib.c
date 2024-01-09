// cry.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ckey[50];

int getKeyShift(int inx) {
    char skey[16];
    char ck1;
    int ck1n = 0;
    sprintf(skey, "%d", ckey[inx]);  // make string of the int key code
    ck1 = skey[1];  // take 2nd digit of the (numeric) string
    ck1n = ck1 - '0';  // convert and return as int
    if (ck1n == '0') ck1n = 3;  // many zeros with no shift value
    return ck1n; 
}

char *encrypt(char *etext, char *plain) {
    char ch;
    int kix = 0;
    int klen = strlen(ckey);
    int ix = 0;
    char cval;
    int plen = strlen(plain);
    for(ix=0; ix < plen; ix++) {
        ch = plain[ix];
        cval = ch + getKeyShift(kix);
        etext[ix] = cval;
        kix++;
        if (kix > klen) kix = 0;
    }
    etext[ix] = '\0';
    return etext;
}

char *decrypt(char *plain, char *etext) {
    char ch;
    int kix = 0;
    int klen = strlen(ckey);
    int ix = 0;
    char cval;
    int elen = strlen(etext);
    for(ix=0; ix < elen; ix++) {
        ch = etext[ix];
        cval = ch - getKeyShift(kix);
        plain[ix] = cval;
        kix++;
        if (kix > klen) kix = 0;
    }
    plain[ix] = '\0';
    return plain;
}


void main() {

    char px[500] = {"\0"};
    char ex[500] = {"\0"};

    strcpy(ckey, "secretKEY124578");
    strcpy(px, "50 My name is Francisco Max. | I am 100 years young!");
    puts(px);
    puts(encrypt(ex, px));
    // memset(px, '\0', 64);
    puts(decrypt(px, ex));
}
