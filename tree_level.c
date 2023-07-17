
#include <stdio.h>
#include <stdlib.h>

// Binary tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to display all elements at the same level as a particular number
void displaySameLevel(struct Node* root, int level, int target) {
    if (root == NULL)
        return;

    if (level == 0) {
        printf("%d ", root->data);
    } else if (level > 0) {
        displaySameLevel(root->left, level - 1, target);
        displaySameLevel(root->right, level - 1, target);
    }
}

// Function to calculate the height of the binary tree
int getHeight(struct Node* root) {
    if (root == NULL)
        return -1;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

// Function to display the elements at the same level as the target number
void displayElementsOnSameLevel(struct Node* root, int target) {
    int height = getHeight(root);

    for (int i = 0; i <= height; i++) {
        printf("Elements at level %d: ", i);
        displaySameLevel(root, i, target);
        printf("\n");
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int numNodes;
    int data;
    int target;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < numNodes; i++) {
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    printf("Enter the target number: ");
    scanf("%d", &target);

    displayElementsOnSameLevel(root, target);

    return 0;
}
