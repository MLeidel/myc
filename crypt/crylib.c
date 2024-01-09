// crylib.c
#include "../myc.h";
/**********************************************
    crylib.c uses a character value shift
    similar to a Ceasar Cipher.
    The difference is that here each
    character has a different shift
    value which is determined by a secret
    key consisting of a string of characters.
    The ascii value of each character
    in the key string is used to shift
    a character in the plain text string.
    Only the second digit of the ascii
    code is used for the shift value which
    is added to the plain text character value.
    Furthermore, if the digit is 0 it becomes
    3 since a shift of 0 does not really alter
    the plaintext character. After each character
    of the key has been applied it simply repeats
    until all of the plain text has been coded.
************************************************/

int getKeyShift(int inx) {
    char skey[32];
    char ckey[50];
    char ck1;
    int ck1n = 0;
    sprintf(skey, "%d", ckey[inx]);  // make string of the int key code
    ck1 = skey[1];  // take 2nd digit of the (numeric) string
    ck1n = ck1 - '0';  // convert and return as int
    if (ck1n == '0') ck1 = 3;  // many zeros with no shift value
    return ck1n; 
}

char *encrypt(char *etext, char *plain, char *key) {
    char ch;
    int kix = 0;
    int klen = 0;
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

char *decrypt(char *plain, char *etext, char *key) {
    char ch;
    int kix = 0;
    int klen = 0;
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

    char px[64] = {"\0"};
    char ex[64] = {"\0"};

    strcpy(px, "Hello What's happening?");
    puts(px);
    puts(encrypt(ex, px, "keytext"));
    // memset(px, '\0', 64);
    puts(decrypt(px, ex, "keytext"));
}
