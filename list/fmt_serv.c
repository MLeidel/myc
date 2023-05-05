// fmt_serv.c
#include <myc.h>

void list_serv() {
    list line = list_def(20, 256);
    list flst = list_read("serv.txt", true);

    for(int x=0; x < flst.nbr_rows; x++) {
        int n = list_split(line, flst.item[x], ",");
        printf("[%12s]\n %s\n---------------\n", line.item[0], line.item[1]);
        //printf("%s\n", flst.item[x]);
    }
    list_del(flst);
    list_del(line);
}


void list_servc() {
    int cols = 3;
    int cntx = 0;
    char item[100] = {'\0'};
    list line = list_def(20, 256);
    list flst = list_read("serv.txt", true);

    for(int x=0; x < flst.nbr_rows; x++) {
        int n = list_split(line, flst.item[x], ",");
        strcpy(item, trim(line.item[0]));
        if (startswith(item, "-"))
                continue;
        printf("%14s  ", item);
        cntx++;
        if (cntx > cols-1) {
            printf("\n");
            cntx = 0;
        }
    }
    list_del(flst);
    list_del(line);
}


void main (int argc, char *argv[]) {

    list_servc();

}
