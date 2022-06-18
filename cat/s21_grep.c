#include <stdio.h>
#include <errno.h>
#include <string.h>

int parse_flags(char * s) {
    printf("%s\n", s);
    return 0;
}
int proccess_reg_exp(char * s) {
    char * regexp = NULL;
    while (* s) {
        regexp = (char *) realloc (regexp, sizeof(char));
        * regexp = * s;
    }
    printf("%s\n", s);
    return 0;
}
int proccess_file(char * s) {
    FILE * file = fopen(s, "r");
    if (file != NULL) {
        printf("%s\n", s);
    } else {
        printf("%s: %s\n", s, strerror(errno));
    }
    return 0;
}
int s21_grep(int argc, char * argv[]) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            printf("%s\n", argv[i]);
            if (argv[i][0] == '-') {
                parse_flags(argv[i]);
            } else if (argv[i][0] == 34) {
                proccess_reg_exp(argv[i]);
            } else {
                proccess_file(argv[i]);
            }
        }
    } else {
        printf("Too few args. Abort.");
    }
    return 0;
}

#ifdef mytest
int main(int argc, char * argv[]) {
    s21_grep(argc, argv);
    return 0;
}
#endif
