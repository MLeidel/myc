// mycrypt.c (see crylib.c)
#include "../myc.h";
/**********************************************
    mycrypt.c uses a character value shift
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

void main() {

    string pstring = string_def(512, '\0');
    string xstring = string_def(512, '\0');

    string_cpy(pstring, "Hello What's happening?");
    puts(pstring.value);
    puts(encrypt(xstring.value, pstring.value, "secret%key"));
    puts(decrypt(pstring.value, xstring.value, "secret%key"));


    // Now try something longer
    puts("\nEncrypt and Decrypt 'sample.txt' \n");

    if (readfile(pstring.value, "sample.txt") == -1) {
        puts("readfile fail for sample.txt");
        exit(EXIT_FAILURE);
    } else {
        puts(encrypt(xstring.value, pstring.value, "secret%key"));
    }

    puts(decrypt(pstring.value, xstring.value, "secret%key"));

    string_del(pstring);
    string_del(xstring);
}


