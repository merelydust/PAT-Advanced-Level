// sequence就是insertion sequence = =？
#include <cstdio>
#include <vector>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

void insert(node*& root, int data) {
    if (root == NULL) {
        root = new node; root->data = data;
        root->left = root->right = NULL;
        return;
    }
    if (data < root->data) insert(root->left, data);
    else insert(root->right, data);
}

void preOrder(node* root, vector<int>& vi) { // 先序遍历的结果存在vi
    if (root == NULL) return;
    vi.push_back(root->data);
    preOrder(root->left, vi);
    preOrder(root->right, vi);
}

void preOrderMirror(node* root, vector<int>& vi) {
    if (root == NULL) return;
    vi.push_back(root->data);
    preOrderMirror(root->right, vi);
    preOrderMirror(root->left, vi);
}

void postOrder(node* root, vector<int>& vi) {
    if (root == NULL) return;
    postOrder(root->left, vi);
    postOrder(root->right, vi);
    vi.push_back(root->data);
}

void postOrderMirror(node* root, vector<int>& vi) {
    if (root == NULL) return;
    postOrder(root->right, vi);
    postOrder(root->left, vi);
    vi.push_back(root->data);
}

vector<int> origin, pre, preM, post, postM;
int main() {
    int n, data; scanf("%d", &n);
    node* root = NULL;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &data);
        origin.push_back(data);
        insert(root, data);
    }
    preOrder(root, pre);
    preOrderMirror(root, preM);
    postOrder(root, post);
    postOrderMirror(root, postM);
    if (origin == pre) {
        printf("YES\n");
        for (int i = 0; i < post.size(); ++i) {
            if (i) printf(" ");
            printf("%d", post[i]);
        }
    }
    else if (origin == preM) {
        printf("YES\n");
        for (int i = 0; i < postM.size(); ++i) {
            if (i) printf(" ");
            printf("%d", postM[i]);
        }
    }
    else printf("NO\n");
    delete []root;
    return 0;
}
