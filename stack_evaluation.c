#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int books[MAX_SIZE];
    int top;
} Stack;

void init(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return (stack->top == -1);
}

int isFull(Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

void push(Stack *stack, int book) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }

    stack->books[++stack->top] = book;
    printf("Book %d added to the stack.\n", book);
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }

    int book = stack->books[stack->top--];
    printf("Book %d removed from the stack.\n", book);
    return book;
}

void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Books in the stack:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->books[i]);
    }
}

void retrieveBook(Stack *stack, int targetBook) {
    Stack tempStack;
    init(&tempStack);

    while (!isEmpty(stack)) {
        int book = pop(stack);

        if (book == targetBook) {
            printf("Required book %d retrieved!\n", book);
            break;
        } else {
            push(&tempStack, book);
        }
    }

    while (!isEmpty(&tempStack)) {
        int book = pop(&tempStack);
        push(stack, book);
    }
}

int main() {
    Stack bookStack;
    init(&bookStack);

    int choice, book;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Push a book\n");
        printf("2. Pop a book\n");
        printf("3. Retrieve a specific book\n");
        printf("4. Display the stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the book to push: ");
                scanf("%d", &book);
                push(&bookStack, book);
                break;
            case 2:
                pop(&bookStack);
                break;
            case 3:
                printf("Enter the book to retrieve: ");
                scanf("%d", &book);
                retrieveBook(&bookStack, book);
                break;
            case 4:
                display(&bookStack);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
