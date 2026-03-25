#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure for tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue structure
struct Queue {
    struct Node* node;
    int hd;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = newNode(arr[0]);

    struct Node* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct Node* temp = queue[front++];

        if (arr[i] != -1) {
            temp->left = newNode(arr[i]);
            queue[rear++] = temp->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            temp->right = newNode(arr[i]);
            queue[rear++] = temp->right;
        }
        i++;
    }

    return root;
}

void verticalTraversal(struct Node* root) {

    if (!root)
        return;

    struct Queue queue[MAX];
    int front = 0, rear = 0;

    int map[2 * MAX][MAX];
    int count[2 * MAX] = {0};

    int offset = MAX;

    queue[rear].node = root;
    queue[rear].hd = 0;
    rear++;

    int min = 0, max = 0;

    while (front < rear) {

        struct Node* temp = queue[front].node;
        int hd = queue[front].hd;
        front++;

        map[hd + offset][count[hd + offset]++] = temp->data;

        if (hd < min)
            min = hd;

        if (hd > max)
            max = hd;

        if (temp->left) {
            queue[rear].node = temp->left;
            queue[rear].hd = hd - 1;
            rear++;
        }

        if (temp->right) {
            queue[rear].node = temp->right;
            queue[rear].hd = hd + 1;
            rear++;
        }
    }

    for (int i = min; i <= max; i++) {
        for (int j = 0; j < count[i + offset]; j++) {
            printf("%d ", map[i + offset][j]);
        }
        printf("\n");
    }
}

int main() {

    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalTraversal(root);

    return 0;
}