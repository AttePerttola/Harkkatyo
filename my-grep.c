#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, const char* argv[]) {

    FILE *fp;
    
    char buffer[1000];
    char *line;
    size_t len = 0;
    ssize_t nread;

    if (argc == 1) {
        printf("my-grep: searchterm [file...]\n");
        exit(1);
    } else if (argc == 2) {
        /*jos haettu termi on tyhjä ei löydetä mitää :D*/
        if (!strcmp(argv[1],"\0")) {
            printf("No matches found.\n");
            exit(1);
        }
        printf("Write line for search: \n");
        fgets(buffer,1000,stdin);
        
        
        /*onko haluttu termi rivillä*/
        if (strstr(buffer,argv[1]) != NULL) {
            printf("%s",buffer);
        } else {
            printf("my-grep: No matches found.\n");
        }
        exit(0);

    } else if (argc == 3) {
        /*jos haettu termi on tyhjä ei löydetä mitää :D*/
        if (!strcmp(argv[1],"\0")) {
            printf("No matches found.\n");
            exit(1);
        }
        fp = fopen(argv[2],"r");
        if (fp == NULL) {
            perror("my-grep: cannot open file.\n");
            exit(1);
        }
        while((nread = getline(&line,&len,fp)) != -1) {
            if (strstr(line,argv[1]) != NULL) {
                printf("%s",line);
            }
        }
        free(line);
        fclose(fp);
    } else {
        printf("Too many arguments.\n");
        exit(1);
    }
    return 0;
}