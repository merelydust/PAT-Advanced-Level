// 先根据后序和中序建树 再进行层序遍历
#include <cstdio>
#include <queue>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

const int maxn = 35;
int post[35], in[35];

node* createTree(int postL, int postR, int inL, int inR) {
    if (postL > postR) return NULL; // 如果序列为空
    node* root = new node;
    root->data = post[postR];
    int k; // root在中序序列中的位置
    for (k = inL; k <= inR; ++k) {
        if (in[k] == root->data) break;
    }
    int numLeft = k - inL; // 右子树的节点个数
    // 左子树的后序序列区间为[postL, postL+numLeft-1] 中序序列区间为[inL, k-1]
    root->left = createTree(postL, postL+numLeft-1, inL, k-1);
    // 右子树的后序序列区间为[postL+numLeft, postR-1] 中序序列区间为[k+1, inR];
    root->right = createTree(postL+numLeft, postR-1, k+1, inR);
    return root;
}

void layerOrder(node* root) { // 用queue遍历
    queue<node*> Q;
    Q.push(root);
    bool isFirst = true;
    while (!Q.empty()) {
        node* fro = Q.front();
        Q.pop();
        if (isFirst) {
            printf("%d", fro->data); isFirst = false;
        }
        else printf(" %d", fro->data);
        if (fro->left != NULL) Q.push(fro->left);
        if (fro->right != NULL) Q.push(fro->right);
    }
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &post[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &in[i]);
    node* root = createTree(0, n-1, 0, n-1);
    layerOrder(root); printf("\n");
    delete []root;
    return 0;
    
}
