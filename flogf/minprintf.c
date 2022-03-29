// minprintf.c
#include "../myc.h"


/*  minprintf: minimal printf with variable argument list
    from "The C Programming Language" by Brian Kernighan
*/
void minprintf(char *fmt, ...) {
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;

    va_start (ap, fmt); /* make ap point to 1st unnamed arg */

    for (p= fmt; *p; p++) {
        if (*p != '%') {
            putchar (*p);
            continue;
        }
        switch (*++p) {
            case 'd':
                ival= va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval= va_arg(ap, double);
                printf("%f", dval);
                break;
            case '$':
                dval= va_arg(ap, double);
                printf("%.02f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar (* sval);
                break;
            default:
                putchar (*p);
                break;
        }
    }
    va_end (ap);  /* clean up when done */
}

void main (int argc, char *argv[]) {
    int inum = 12322;
    char string[] = "Hello minprintf!";
    double dbl = 123212.21;

    minprintf("%d | %s | %s | %$\n", inum, string, "Literal String.", dbl);

}
