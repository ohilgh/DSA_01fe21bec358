#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void push(int stack[], int *top, int num, FILE *push_log) {
    if (*top == MAX_SIZE - 1) {
        fprintf(stderr, "Stack overflow!\n");
        fprintf(push_log, "Stack overflow!\n");
        return;
    }
    stack[++(*top)] = num;
    fprintf(push_log, "Pushed %d\n", num);
}

int pop(int stack[], int *top, FILE *pop_log) {
    if (*top == -1) {
        fprintf(stderr, "Stack underflow!\n");
        fprintf(pop_log, "Stack underflow!\n");
        return -1;
    }
    int num = stack[(*top)--];
    fprintf(pop_log, "Popped %d\n", num);
    return num;
}

void display(int stack[], int top) {
    printf("Stack contents: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int p, q, n, num, choice;
    int stack[MAX_SIZE], top = -1;

    FILE *input_file = fopen("input.txt", "w");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file!\n");
        return 1;
    }
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &n);

    printf("Enter the range of numbers (p and q): ");
    scanf("%d %d", &p, &q);

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        num = p + rand() % (q - p + 1);
        fprintf(input_file, "%d ", num);
    }
    fclose(input_file);

    FILE *push_log = fopen("push_log.txt", "w");
    if (push_log == NULL) {
        fprintf(stderr, "Error opening push log file!\n");
        return 1;
    }

    FILE *pop_log = fopen("pop_log.txt", "w");
    if (pop_log == NULL) {
        fprintf(stderr, "Error opening pop log file!\n");
        return 1;
    }

    FILE *operation_log = fopen("operation_log.txt", "w");
    if (operation_log == NULL) {
        fprintf(stderr, "Error opening operation log file!\n");
        return 1;
    }

    FILE *input_file_read = fopen("input.txt", "r");
    if (input_file_read == NULL) {
        fprintf(stderr, "Error opening input file for reading!\n");
        return 1;
    }

    while (fscanf(input_file_read, "%d", &num) != EOF) {
        printf("1.push\n2.pop\n3.display\n4.exit: ", num);
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(stack, &top, num, push_log);
                fprintf(operation_log, "Pushed %d\n", num);
                break;
            case 2:
                num = pop(stack, &top, pop_log);
                if (num != -1)
			            fprintf(operation_log, "Popped %d\n", num);
            break;
        case 3:
            display(stack, top);
            fprintf(operation_log, "Displayed stack contents\n");
            break;
        case 4:
            exit(1);
        default:
            printf("Invalid choice!\n");
            fprintf(operation_log, "Invalid choice!\n");
            break;
    }
}

fclose(push_log);
fclose(pop_log);
fclose(operation_log);
fclose(input_file_read);

return 0;
}
