#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 100

int main() {
    char old_word[MAX_WORD_LENGTH], new_word[MAX_WORD_LENGTH];
    char file_name[MAX_LINE_LENGTH], temp_file_name[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    FILE *fp_in, *fp_temp;

    printf("Enter the name of the file: ");
    scanf("%s", file_name);

    printf("Enter the word to be replaced: ");
    scanf("%s", old_word);

    printf("Enter the new word: ");
    scanf("%s", new_word);

    fp_in = fopen(file_name, "r");
    if (fp_in == NULL) {
        printf("Error: Could not open input file.\n");
        exit(EXIT_FAILURE);
    }

    sprintf(temp_file_name, "%s.temp", file_name);
    fp_temp = fopen(temp_file_name, "w");
    if (fp_temp == NULL) {
        printf("Error: Could not create temporary file.\n");
        fclose(fp_in);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp_in)) {
        char *ptr = strstr(line, old_word);
        while (ptr != NULL) {
            int len = strlen(old_word);
            strncpy(ptr, new_word, len);
            ptr += len;
            ptr = strstr(ptr, old_word);
        }
        fputs(line, fp_temp);
    }

    fclose(fp_in);
    fclose(fp_temp);

    if (remove(file_name) != 0) {
        printf("Error: Could not delete input file.\n");
        exit(EXIT_FAILURE);
    }

    if (rename(temp_file_name, file_name) != 0) {
        printf("Error: Could not rename temporary file.\n");
        exit(EXIT_FAILURE);
    }

    printf("The word '%s' has been replaced with '%s' in the file '%s'.\n", old_word, new_word, file_name);

    return 0;
}
