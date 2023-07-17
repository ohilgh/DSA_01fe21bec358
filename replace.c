#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

void searchAndReplaceWord(FILE* inputFile, FILE* tempFile, const char* searchWord, const char* replaceWord) {
    char line[MAX_LENGTH];
    size_t searchWordLen = strlen(searchWord);

    while (fgets(line, MAX_LENGTH, inputFile) != NULL) {
        char* word = line;

        while ((word = strstr(word, searchWord)) != NULL) {
            fwrite(line, 1, word - line, tempFile); // Write characters before the word
            fwrite(replaceWord, 1, strlen(replaceWord), tempFile); // Write the replacement word
            word += searchWordLen; // Move word pointer to the end of the search word
        }

        fputs(word, tempFile); // Write the remaining part of the line after the replaced word
    }
}

int main() {
    char fileName[100];
    char searchWord[100];
    char replaceWord[100];
    char tempFileName[100] = "tempfile.txt"; // Temporary file name

    printf("Enter the file name: ");
    scanf("%s", fileName);

    printf("Enter the word to search for: ");
    scanf("%s", searchWord);

    printf("Enter the word to replace with: ");
    scanf("%s", replaceWord);

    FILE* inputFile = fopen(fileName, "r");
    if (inputFile == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    FILE* tempFile = fopen(tempFileName, "w");
    if (tempFile == NULL) {
        printf("Failed to create temporary file.\n");
        fclose(inputFile);
        return 1;
    }

    searchAndReplaceWord(inputFile, tempFile, searchWord, replaceWord);

    fclose(inputFile);
    fclose(tempFile);

    // Replace the original file with the modified contents
    if (remove(fileName) != 0) {
        printf("Failed to remove the original file.\n");
        return 1;
    }

    if (rename(tempFileName, fileName) != 0) {
        printf("Failed to rename the temporary file.\n");
        return 1;
    }

    printf("Word replaced successfully in the file.\n");

    return 0;
}
