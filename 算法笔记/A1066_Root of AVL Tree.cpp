#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
    int data, height;
    node* left;
    node* right;
    node() {
        left = right = NULL;
        height = 0;
    }
};

node* newNode(int v) {
    node* Node = new node;
    Node->data = v;
    Node->height = 1;
    return Node;
}

int getHeight(node* root) {
    if (root==NULL) return 0; // 没写这一步导致没有AC NUll不等价于值为NULL的node
    return root->height;
}

void updateHeight(node* root) { // 节点父节点改变/插入新节点就要更新高度
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

int getBF(node* root) { // 计算平衡因子
    return getHeight(root->left) - getHeight(root->right);
}

void L(node*& root) { // 左旋
    node* tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void R(node*& root) {
    node* tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void insert(node*& root, int v) {
    if (root == NULL) {
        root = newNode(v); return;
    }
    if (v < root->data) {
        insert(root->left, v);
        updateHeight(root); // 因为是递归 所以插入后每个途经的节点高度都会被更新
        if (getBF(root) == 2) { // 左子树失衡
            if (getBF(root->left) == 1) { // 左左型失衡树
                R(root);
            }
            else if (getBF(root->left) == -1) { // 左右型失衡树
                L(root->left); R(root);
            }
        }
    }
    else if (v > root->data) {
        insert(root->right, v);
        updateHeight(root);
        if (getBF(root) == -2) {
            if (getBF(root->right) == -1) L(root); // 右右型失衡树
            else if (getBF(root->right) == 1) { // 右左型失衡树
                R(root->right); L(root);
            }
        }
    }
}

int main() {
    int n, v; scanf("%d", &n);
    node* root = NULL;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v); insert(root, v);
    }
    printf("%d", root->data);
}
