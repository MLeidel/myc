// insert.c
#include "../myc.h"

/*
    returns a string with new text inserted into it

    insert( buffer to receive new string,
            string to receive the inserted text,
            text to insert,
            index where to insert the text)
*/


void main() {

    char text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit";
    char buf[120];

    puts(text);

    insert(buf, text, " amor", 26);
    puts(buf);  //Lorem ipsum dolor sit amet amor, consectetur adipiscing elit

    puts(insert(buf, text, "\n", 28));
        // Lorem ipsum dolor sit amet,
       //  consectetur adipiscing elit

    puts(insert(buf, text, "prepended ", 0));
        // prepended Lorem ipsum dolor sit amet, consectetur adipiscing elit

    puts(insert(buf, text, " appended.", strlen(text))); //
        // Lorem ipsum dolor sit amet, consectetur adipiscing elit appended.

    puts("\n");


    // replace 'buf' with a dynamic string
    cstr mein = cstr_def(1028, '\0');
    insert(mein.str, text, " AMOR", 26);
    puts(mein.str);
    cstr_del(mein);
}

 /*
    also see insert_new
 */
