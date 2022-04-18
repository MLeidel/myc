// zen.c
// #include <myc.h>
#include "../myc.h"


void main (int argc, char *argv[]) {
    char data[4096] = {'\0'}; // buffer to hold zen responses
    char src[1024] = {'\0'}; // holds zenity code

    /*
        The "zen" function is completely 'free form'.
        It just supplies the 'zenity ' command and you
        supply the rest in a string. It purpose is to
        allow for other zenity dialogs or variations
        not covered by the "myc.h zenity" functions.
        https://help.gnome.org/users/zenity/stable/index.html.en#dialogs
    */

    // color picker dialog
    zen(data, "--color-selection --show-palette");
    puts(data);

    // scale dialog
    zen(data, "--scale --text='How many jelly-beans are in the jar?' --value=100");
    puts(data);

    // password entry dialog
    zen(data, "--password --username");
    puts(data);

    // calendar dialog
    concat(src, "--calendar ",
                "--text='Click on a date to select it.' "
                "--date-format='%F' ", END);  // strftime formats
    zen(data, src);
    puts(data);

}
