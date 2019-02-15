#include <cstdio>
const int maxn = 66000;
int in[maxn], post[maxn];

struct node {
    int data;
    node* left;
    node* right;
    node() {
        left = right = NULL;
    }
};

node* create(int postL, int postR, int inL, int inR) {
    if (postL > postR) return NULL;
    node* root = new node;
    root->data = post[postR];
    int rootPos = inL;
    while (in[rootPos] != root->data) ++rootPos;
    int numLeft = rootPos - inL;
    root->left = create(postL, postL+numLeft-1, inL, rootPos-1);
    root->right = create(postL+numLeft, postR-1, rootPos+1, inR);
    return root;
}

void preTraversal(node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preTraversal(root->left);
    preTraversal(root->right);
    delete root;
}

int main() {
    int cnt = 0;
    while (scanf("%d", &in[cnt++])) {
        if (getchar() == '\n') break;
    }
    for (int i = 0; i < cnt; ++i) scanf("%d", &post[i]);
    node* root = create(0, cnt-1, 0, cnt-1);
    preTraversal(root);
    return 0;
}
