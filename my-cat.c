#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[]) {

    FILE *fp;
    int filecounter = 1;
    char buffer[1000];

    if (argc == 1) { /*jos ei anneta tiedostoa, lopetetaan ajo*/
        printf("No file specified.\n");
        exit(0);
    }
    if (argc > 1) { /*jos annetaan yksi tai enemmän tiedostoja käydään ne kaikki läpi*/
        while (filecounter <= argc-1) { /* argc-1 koska argc ja argv indeksi lähtee eri numeroista*/
            fp = fopen(argv[filecounter],"r");
            if (fp == NULL) {
                perror("my-cat: cannot open file.\n");
                exit(1);
            }
            /*käydään rivi kerrallaan tiedostoa läpi ja tulostetaan se terminaaliin*/
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