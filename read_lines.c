#include <stdio.h>

#define MAX_LINES 10
#define MAX_LENGTH 100

void read_lines(char lines[][MAX_LENGTH]);
int get_length(char line[]);

int main() {
    char lines[MAX_LINES][MAX_LENGTH];
    int max_length = 0;
    int max_index = 0;

    read_lines(lines);

    for (int i = 0; i < MAX_LINES; i++) {
        int length = get_length(lines[i]);
        if (length > max_length) {
            max_length = length;
            max_index = i;
        }
    }

    printf("Longest line: %s\n", lines[max_index]);

    return 0;
}

void read_lines(char lines[][MAX_LENGTH]) {
    printf("Enter up to %d lines of text:\n", MAX_LINES);
    for (int i = 0; i < MAX_LINES; i++) {
        fgets(lines[i], MAX_LENGTH, stdin);
        if (lines[i][0] == '\n') {
            break;
        }
    }
}

int get_length(char line[]) {
    int length = 0;
    while (line[length] != '\0' && line[length] != '\n') {
        length++;
    }
    return length;
}
