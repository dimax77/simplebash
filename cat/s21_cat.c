#include <stdio.h>
#include <string.h>
#define B 1
#define N 2

int printfile(char * s, int flags) {
    FILE * file;
    file = fopen(s, "r");
    int c = 0;
    int line = 1;
        while((c = fgetc(file)) != EOF) {
            if (c != '\n') {
                if (flags & B || flags & N) printf("%6u\t", line++);
                printf("%c", c);
                while(((c = fgetc(file)) != '\n') && c != EOF) {
                    putchar(c);
                }
            } else if (flags & N && !(flags & B)) printf("%6u\t", line++);
            putchar(c);
        }
    return 0;
}

int parseflags(char * s [], int * flags) {
    int i = 0;
    printf("%c\n", s[1][i]);
        if (s[1][i] == '-') {
            i++;
            while (s[1][i]) {
                switch (s[1][i])
                {
                    case 'n':
                    * flags |= N;
                    break;
                    case 'b':
                    * flags |= B;
                    break;
                    default:
                    break;
                    }
                    i++;
                }
            
        }
    return * flags;
}

int s21_cat(int argc, char * argv[]) {
    int flags = 0;
    if(argc < 2) {
        printf("Too few args.. abort.\n");
        return 0;
    }
    int n = 0;
    int elements = 1;
    char * filename = NULL;
    for (;elements < argc; elements++){
        if(argv[elements][0] == '-') {
            flags = parseflags(argv, &flags);
        } else if (argv[elements][0] == '>') {
        } else if (argv[elements][0] == '<') {
        } else {
            filename = argv[elements];
            printfile(filename, flags);
            n++;
        }
    }
    return 0;
}
#ifdef mytest
int main(int argc, char * argv[]) {
    s21_cat(argc, argv);
    return 0;
}
#endif