// between.c
#include "../myc.h"
#include "../mynet/mynet.h"

#define MAX_L 1024


/*
    Test uses html from 'hello.html'
*/

void console(int inx, char *str) {
    flogf(stdout, "next inx: %d\n[%s]\n\n", inx, trim(str));
}

void main () {

    char page[MAX_L] = {'\0'};
    char subs[MAX_L] = {'\0'};
    int p = 0;

    webpage(page, MAX_L, "https://michaelleidel.net/test/hello.html");

    p = between(subs, page, "<p>", "</p>", 0); // offset at beginning
    console(p, subs);

    p = between(subs, page, "<p>", "</p>", p); // offset at p
    console(p, subs);

    p = between(subs, page, "<p>", "</p>", p); // offset at p
    console(p, subs);

    p = between(subs, page, "<option>", "</option>", 0);
    console(p, subs);

    p = between(subs, page, "<option>", "</option>", p);
    console(p, subs);

    p = between(subs, page, "<option>", "</option>", p);
    console(p, subs);

    p = indexof(page, "<input");
    p = between(subs, page, "\"", "\"", p);
    console(p, subs);
    p = between(subs, page, "\"", "\"", p);
    console(p, subs);
    p = between(subs, page, "\"", "\"", p);
    console(p, subs);


/* OUTPUT
next inx: 235
[This is an example web page]

next inx: 272
[Below is a list - choose one:]

next inx: 484
[<input type="button" value="Activate" onclick="alert('You got it!')" />]

next inx: 318
[$1,000,000]

next inx: 350
[2 new Teslas]

next inx: 393
[Your own Pacific Island]

next inx: 428
[button]

next inx: 445
[Activate]

next inx: 476
[alert('You got it!')]
*/
}
