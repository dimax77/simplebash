#include <stdio.h>

int s21_cat(int argc, char * argv[]) {
    if(argc < 2) {
        printf("Too few args.. abort.\n");
        return 0;
    }
    FILE * fp;
    if(!((fp = fopen(argv[argc -1], "r")) == NULL)) {
        char ch;
        while ((ch = getc(fp)) != EOF) {
            putchar(ch);
        }
    }
    for (int i = 0; i < argc; i++) {
        printf("%d -> %s\n", i, argv[i]);
    }
    printf("Arguments quantity -> %d\n", argc);
    return 0;
}
#ifdef mytest
int main(int argc, char * argv[]) {
    s21_cat(argc, argv);
    return 0;
}
#endif