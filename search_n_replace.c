#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[100], tempfilename[100], searchword[50], replaceword[50];
    FILE *fp, *temp;
    int wordcount = 0;
    char ch;

    printf("Enter the filename: ");
    scanf("%s", filename);

    printf("Enter the search word: ");
    scanf("%s", searchword);

    printf("Enter the replace word: ");
    scanf("%s", replaceword);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open file.");
        exit(1);
    }

    temp = fopen(tempfilename, "w");
    if (temp == NULL) {
        printf("Unable to create temporary file.");
        fclose(fp);
        exit(1);
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == ' ' || ch == '\t' || ch == '\n') {
            wordcount = 0;
        } else if (++wordcount == strlen(searchword) && strncmp(searchword, &ch - wordcount + 1, strlen(searchword)) == 0) {
            fputs(replaceword, temp);
        } else {
            fputc(ch, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove(filename);
    rename(tempfilename, filename);

    printf("\nSuccessfully replaced all occurrences of \"%s\" with \"%s\".", searchword, replaceword);

    return 0;
}
