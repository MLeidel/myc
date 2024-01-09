/* cry.c
Author: Michael D Leidel 2018

Encrypt and Decrypt text file
Version of Vigenere cipher

usage:
cry e keytext [plainFILE cryptFILE]
cry d keytext [cryptFILE] 

DEFAULT plainFILE = plain.txt
DEFAULT cryptFILE = crypto.cry
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ch;
FILE *f_inp;
FILE *f_out;
char outfile[128] = "crypto.txt\0";
char cfilename[128] = "plain.txt\0";
char caction[2];
char ckey[50];
int kix = 0;
int klen = 0;

int getKeyShift(int inx) {
    char skey[32];
    char ck1;
    int ck1n = 0;
    sprintf(skey, "%d", ckey[inx]); // make string of the int key code
    ck1 = skey[1];      // take 2nd digit of the (numeric) string
    ck1n = ck1 - '0';   // convert and return as int
    if (ck1n == '0') ck1 = 3;   // many zeros with no shift value
    return ck1n; 
}

int main(int argc, char *argv[]) {
    char cval;

    if (argc < 5) {
        printf("Something is missing...\n");
        exit(1);
    }

    strcpy(caction, argv[1]);   // action "d" or "e"
    strcpy(ckey, argv[2]);      // cipher key string
    klen = strlen(ckey);

    strcpy(cfilename, argv[3]);
    strcpy(outfile, argv[4]);


/**********************************************
    cry uses a character value shift
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

    if (strcmp(caction, "e") == 0) {
        f_out = fopen(outfile, "wb");
        f_inp = fopen(cfilename, "rb");
        while ((ch = fgetc(f_inp)) != EOF) {
            cval = ch + getKeyShift(kix);
            putc(cval, f_out);
            kix++;
            if (kix > klen) kix = 0;
        }
        fflush(f_out);
        fclose(f_out);
        fclose(f_inp);
        return 0;
    }

    if (strcmp(caction, "d") == 0) {
        f_out = fopen(outfile, "wb");
        f_inp = fopen(cfilename, "rb");
        while ((ch = fgetc(f_inp)) != EOF) {
            cval = ch - getKeyShift(kix);
            //printf("%c", cval);
            fprintf(f_out, "%c", cval);
            kix++;
            if (kix > klen) kix = 0;            
        }
        fclose(f_out);
        fclose(f_inp);
        return 0;
    }
    return 1;
}
