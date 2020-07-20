#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[]) {

    FILE *fp;
    int filecounter = 1;
    char buffer[1000];

    if (argc == 1) {
        printf("No file specified.\n");
        exit(0);
    }
    if (argc > 1) {
        while (filecounter <= argc-1) { /*käydään kaikki annetut argumentit läpi*/
            fp = fopen(argv[filecounter],"r");
            if (fp == NULL) {
                perror("my-cat: cannot open file.\n");
                exit(1);
            }
            while(fgets(buffer,1000,fp) != NULL) {
                printf("%s",buffer);
            }
            
            
            filecounter++;
            printf("\n");
            fclose(fp);
        }
    }

    return 0;
}