#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#define B 1
#define N 2
#define E 4
#define V 8
#define T 16

int putv(int * c, int flags) {  
    if ((* c == 9) && !(flags & T)) {
    }  else if (*c >= 0 && *c < 32) {       
        putchar('^'); 
        *c+=64;
    } else if (*c == 127) {
        putchar('^');
        *c = '?';
    }
    return 0;
}
int printfile(char * s, int flags) {
    FILE * file;
    file = fopen(s, "r");
    if (file != NULL) {
        int c = 0;
        int line = 1;
        while((c = fgetc(file)) != EOF) {
            if (c != '\n') {
                if (flags & B || flags & N) printf("%6u\t", line++);
                if (flags & V) putv(&c, flags);
                printf("%c", c);
                while(((c = fgetc(file)) != '\n') && c != EOF) {                    
                    putchar(c);
                }
            } else if (flags & N && !(flags & B)) printf("%6u\t", line++);
            
            if(flags & E) putchar('$');
            putchar(c);
        }
    } else {
        printf("%s: %s\n", s, strerror(errno));
    }    
    return 0;
}

int parseflags(char * s [], int * flags) {
    int i = 0;
        if (s[1][i] == '-') {
            i++;
            while (s[1][i]) {
                switch (s[1][i])
                {
                    case 'n':
                    * flags |= N;
                    break;
                    case 't':
                    * flags |= T;
                    [[fallthrough]];
                    case 'v':
                    * flags |= V;
                    break;
                    case 'e':
                    * flags |= E;
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