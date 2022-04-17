/*
zendlgs.c
https://help.gnome.org/users/zenity/stable/index.html.en#dialogs
----------------------------------------------------------------
zenmsg      message dialog 4 types: "question", "error", "warning", "info"
zenfile     filedialog 2 types: open (false) and save (true)
zenform     form dialog: entry, calendar, list, combo
zenlist     list dialog with columns
zentry      1 field entry dialog (prompt?)
zentext     simple multi-line text dialog
zenpass     password dialog: password (false) or passwd & username (true)
zenotify    display a system notification message
*/
#include "../myc.h"


                      ///////////////////////////////////
                     //            M A I N            //
                    ///////////////////////////////////

void main (int argc, char *argv[]) {
    char data[4096]; // buffer to hold responses from dialogs


    /////////////////////////////> zenmsg example:

    // types: "question", "error", "warning", "info"
    if (zenmsg("Title ..", "Body of 'question' message ...", "question")) {
        zenmsg("title", "you answered NO", "info");
    } else {
        zenmsg("TITLE ..", "you answered YES", "info");
    }


    /////////////////////////////> zenfile example:

    zenfile(data, "/usr/local/bin", false, true);  // open directory
    puts(data);  // fullpath to open file
    zenfile(data, "/usr/local/bin", true, false);  // save file
    puts(data); // fullpath to save file
    /*
    NOTE: You must check for overwrite existing
    zenfile does NOT do that for you.

    if(file_exists(f2)) {
        if(zenmsg("Exists", "Overwrite Destination file?", "question") == ZENMSG_YES)
            filemove(f1, f2);
        } else {
            filemove(f1, f2);
    }
    */


    /////////////////////////////> zenform example:

    char form_layout[] =
        "--title='New Friend' "
        "--text='Enter your information' "
        "--separator=',' "
        "--add-entry='Your full name' "
        "--add-password='Password' "
        "--add-entry='Your Email' "
        "--add-combo='Fav ice cream' "
        "--combo-values='strawberry|cherry|vanilla|chocolate' "
        "--add-calendar='Birthday' "
        "--add-list='Fav Color' "
        "--list-values='black|blue|red|orange|green|yellow' ";
    zenform(data, form_layout);
    puts(data); // Delimited items from the form response


    /////////////////////////////> zenlist example:

    char list_layout[] =
        "--title='New Friends' "
        "--text='Enter your information' "
        "--print-column='1' "  // defaule 1st column only
        "--multiple "
        "--separator=',' "  // delimited results for multiple row selection  
        "--column='Name' "
        "--column='Age' "
        "--column='Fav Color' "
        "Jack 70 orange "  // space delimited data strings ...
        "Joel 60 blue "
        "Jill 65 yellow "
        "Jane 66 purple "
        "James 50 'dark red' ";

    zenlist(data, list_layout);
    puts(data); // what was selected


    /////////////////////////////> zentry example:

    zentry(data, "zentry exam.", "Enter something witty!", "");
    puts(data); // what was entered


    /////////////////////////////> zentext example:

    zentext(data, "Notes (edit)", "testinfo.txt", true);
    // edited content is now in 'data'
    // write is back the the file
    FILE * f = open_for_write("testinfo.txt");
    fprintf(f, "%s", data);
    fclose(f);

    zentext(data, "Notes (read-only)", "testinfo.txt", false);

    /////////////////////////////> zenotify example:

    zenotify("No more examples!", true);
}
