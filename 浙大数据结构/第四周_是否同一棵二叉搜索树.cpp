#include <iostream>
#include <cstdio>
using namespace std;

struct node {
    int num;
    node *left;
    node* right;
    bool visited;
};

node* makeTree(int n);
node* insert(node* tr, int num);
node* newNode(int num);
bool check(node* tr, int num);
bool judge(node* tr, int num);
void resetTree(node* tr);
void freeTree(node* tr);

int main() {
    int n, l;
    node* tr;
    scanf("%d", &n);
    while (n) {
        scanf("%d", &l);
        tr = makeTree(n);
        for (int i = 0; i < l; ++i) {
            if (judge(tr, n)) cout << "Yes" << endl;
            else cout << "No" << endl;
            resetTree(tr);
        }
        freeTree(tr);
        scanf("%d", &n);
    }
    return 0;
}

node* newNode(int num) {
    node* tr = new node;
    tr->num = num;
    tr->left = tr->right = nullptr;
    tr->visited = false;
    return tr;
}

node* insert(node* tr, int num) {
    if (!tr) tr= newNode(num);
    else {
        if (num > tr->num) tr->right = insert(tr->right, num);
        else tr->left = insert(tr->left, num);
    }
    return tr;
}

node* makeTree(int n) {
    node* tr; int num;
    scanf("%d", &num);
    tr = newNode(num);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &num);
        tr = insert(tr, num);
    }
    return tr;
}

bool check(node* tr, int num) {
    if (tr->visited) {
        if (num < tr->num) return check(tr->left, num);
        else if (num > tr->num) return check(tr->right, num);
        else return false;
    }
    else {
        if (num == tr->num) {
            tr->visited = true;
            return true;
        }
        else return false;
    }
}

bool judge(node* tr, int n) {
    int num; scanf("%d", &num);
    bool conflict = false;
    if (num != tr->num) conflict = true;
    else tr->visited = true;
    for (int i = 1; i < n; ++i) {
        scanf("%d", &num);
        if (!conflict && !check(tr, num)) conflict = true; // 把!conflict放在前面 减少check运行次数
    }
    if (conflict) return false;
    else return true;
}

void resetTree(node* tr) {
    if (tr->left) resetTree(tr->left);
    if (tr->right) resetTree(tr->right);
    tr->visited = false;
}

void freeTree(node* tr) {
    if (tr->left) freeTree(tr->left);
    if (tr->right) freeTree(tr->right);
    delete tr;
}
