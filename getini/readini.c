/*
    Read ini file value

    use: readini ini_file_full_path value_to_return
    test file is "~/.config/curv.ini"

curv.ini:

voice =  alloy
format=mp3
speed=0.95
model=tts-1

*/

#include <myc.h>

// char *getini(char *value, char *inifile, char *ininame) {
//     /*
//         Returns a named value from an ini file
//     */
//     int lines[2];
//     int inx=0;
//     int p=0;

//     list flst = list_read(inifile, true);

//     for(inx=0; inx < flst.nbr_rows; inx++) {
//         if (startswith(flst.item[inx], ininame)) {
//             p = indexof(flst.item[inx], "=");
//             substr(value, flst.item[inx], p+1, 0);
//             strncpy(value, trim(value), strlen(value));
//             list_del(flst);
//             return value;
//         }
//     }
//     if (inx >= flst.nbr_rows) {
//         printf("\nDid not find ini file key name %s\n", ininame);
//         list_display(flst);
//         list_del(flst);
//         exit(1);
//     }
// }


void main(int argc, char *argv[]) {
    if (argc < 3) {
        puts("missing args: file, name");
        exit(1);
    }

    char ivalue[1024] = "{\0}"; // static string to hold ini named value

    puts(getini(ivalue, argv[1], argv[2]));
}
