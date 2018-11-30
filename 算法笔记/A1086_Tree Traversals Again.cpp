// push的顺序就是先序遍历的顺序 pop的顺序就是中序遍历的顺序
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int n;
vector<int> pre, in, post;

struct node {
    int data;
    node* left;
    node* right;
    node() {
        left = NULL; right = NULL;
    }
};

node* createTree(int preL, int preR, int inL, int inR) {
    if (preL > preR) return NULL;
    node* root = new node;
    root->data = pre[preL];
    int k = 0;
    for (; k < n; ++k) {
        if (in[k] == root->data) break;
    }
    int numLeft = k - inL;
    root->left = createTree(preL+1, preL+numLeft, inL, k-1);
    root->right = createTree(preL+numLeft+1, preR, k+1, inR);
    return root;
}

void postOrder(node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    post.push_back(root->data);
}

int main() {
    cin >> n;
    string action; int data;
    stack<int> tmp;
    while (cin >> action) {
        if (action == "Push") {
            cin >> data; tmp.push(data); pre.push_back(data);
        }
        else {
            in.push_back(tmp.top()); tmp.pop();
        }
    }
    node* root = createTree(0, n-1, 0, n-1);
    postOrder(root);
    for (int i = 0; i < post.size(); ++i) {
        if (i) printf(" ");
        printf("%d", post[i]);
    } printf("\n");
    delete []root;
    return 0;
}
