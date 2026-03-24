#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val  = val;
    node->left = node->right = NULL;
    return node;
}

TreeNode* buildTree(int* nodes, int n) {
    if (n == 0 || nodes[0] == -1) return NULL;

    TreeNode** queue = (TreeNode**)malloc(n * sizeof(TreeNode*));
    int front = 0, rear = 0;

    TreeNode* root = newNode(nodes[0]);
    queue[rear++] = root;

    int i = 1;
    while (front < rear && i < n) {
        TreeNode* curr = queue[front++];

        // Left child
        if (i < n) {
            if (nodes[i] != -1) {
                curr->left = newNode(nodes[i]);
                queue[rear++] = curr->left;
            }
            i++;
        }

        // Right child
        if (i < n) {
            if (nodes[i] != -1) {
                curr->right = newNode(nodes[i]);
                queue[rear++] = curr->right;
            }
            i++;
        }
    }

    free(queue);
    return root;
}

TreeNode* lca(TreeNode* root, int p, int q) {
    if (root == NULL)           return NULL;
    if (root->val == p ||
        root->val == q)         return root;

    TreeNode* left  = lca(root->left,  p, q);
    TreeNode* right = lca(root->right, p, q);

    if (left && right)          return root;   // p and q on opposite sides
    return left ? left : right;                // both on same side
}
void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n;
    scanf("%d", &n);

    int* nodes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &nodes[i]);

    int p, q;
    scanf("%d %d", &p, &q);

    TreeNode* root   = buildTree(nodes, n);
    TreeNode* result = lca(root, p, q);

    if (result)
        printf("%d\n", result->val);
    else
        printf("LCA not found\n");

    freeTree(root);
    free(nodes);
    return 0;
}
