#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <cctype>
using namespace std;
const int maxn = 1010;
int post[maxn], in[maxn];

struct ans {
    int layer, father, lc, rc;
    ans() {
        layer = 1;
        father = lc = rc = -1;
    }
}anss[maxn];

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
    int k;
    for (k = inL; k < inR; ++k) {
        if (in[k] == post[postR]) break;
    }
    int numLeft = k - inL;
    root->left = create(postL, postL+numLeft-1, inL, k-1);
    root->right = create(postL+numLeft, postR-1, k+1, inR);
    return root;
}

int maxLayer = 0; bool isFull = true;
void bfs(node* root) {
    queue<node*> Q;
    Q.push(root);
    while (!Q.empty()) {
        node* fro = Q.front();
        Q.pop();
        if (fro->left != NULL) {
            int idx = fro->data;
            anss[idx].lc = fro->left->data;
            anss[fro->left->data].father = idx;
            anss[fro->left->data].layer = anss[idx].layer + 1;
            if (anss[fro->left->data].layer > maxLayer) maxLayer = anss[fro->left->data].layer;
            Q.push(fro->left);
        }
        if (fro->right != NULL) {
            int idx = fro->data;
            anss[idx].rc = fro->right->data;
            anss[fro->right->data].father = idx;
            anss[fro->right->data].layer = anss[idx].layer + 1;
            if (anss[fro->right->data].layer > maxLayer) maxLayer = anss[fro->right->data].layer;
            Q.push(fro->right);
        }
        if ((fro->left != NULL && fro->right == NULL) || (fro->right != NULL && fro->left == NULL)) isFull = false;
    }
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &post[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &in[i]);
    node* root = create(0, n-1, 0, n-1);
    bfs(root);
    int m; scanf("%d", &m);
    getchar();
    for (int i = 0; i < m; ++i) {
        string word;
        int a = -1, b = -1, type = -1; bool flag = true;
        while (cin >> word) {
            if (word == "root") type = 1;
            else if (word == "siblings") type = 2;
            else if (word == "parent") type = 3;
            else if (word ==  "left") type = 4;
            else if (word == "right") type = 5;
            else if (word == "level") type = 6;
            else if (word == "full") type = 7;
            else { // whether num
                bool isNum = true;
                for (int i = 0; i < word.length(); ++i)
                    if (!isdigit(word[i])) isNum = false;
                if (isNum) a == -1 ? a = stoi(word) : b = stoi(word);
            }
            if (getchar() == '\n') break;
        }
        switch (type) {
            case 1: if (a != root->data) flag = false;
                break;
            case 2: if (anss[a].father != anss[b].father) flag = false;
                break;
            case 3: if (anss[b].father != a) flag = false;
                break;
            case 4: if (anss[b].lc != a) flag = false;
                break;
            case 5: if (anss[b].rc != a) flag = false;
                break;
            case 6: if (anss[a].layer != anss[b].layer) flag = false;
                break;
            case 7: flag = isFull;
                break;
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
