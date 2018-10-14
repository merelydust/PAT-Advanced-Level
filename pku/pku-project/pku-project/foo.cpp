#include <iostream>
using namespace std;

struct record {
    int left, right;
};

struct node {
    int num;
    node* left;
    node* right;
};

struct queNode {
    node* tr;
    queNode* next;
};

void buildTree(int root, node* &nodep, record* rec) {
    nodep = new node;
    nodep->num = root;
    nodep->left = nodep->right = nullptr;
    if (rec[root].left != -1) {
        nodep->left = new node;
        buildTree(rec[root].left, nodep->left, rec);
    }
    if (rec[root].right != -1) {
        nodep->right = new node;
        buildTree(rec[root].right, nodep->right, rec);
    }
}

void inque(node* tr, queNode* &front, queNode* &rear) {
    if (rear) {
        rear->next = new queNode;
        rear = rear->next;
        rear->tr = tr;
        rear->next = nullptr;
    }
    else {
        front = new queNode;
        rear = front;
        rear->tr = tr;
        rear->next = nullptr;
    }
}

void deque(queNode* front, queNode* rear) {
    if (front) {
        if (front->next) {
            queNode* tmp = front->next;
            delete front;
            front = tmp;
        }
        else {
            delete front;
            front = rear = nullptr;
        }
    }
}

void printLeaves(node* nodep) {
    if (!nodep) return;
    queNode* front = nullptr;
    queNode* rear = nullptr;
    inque(nodep, front, rear);
    bool isFirst = true;
    while (front) {
        if (!front->tr->left && !front->tr->right) {
            if (isFirst) {
                cout << front->tr->num;
                isFirst = false;
            }
            else cout << ' ' << front->tr->num;
        }
        if (front->tr->left)  inque(front->tr->left, front, rear);
        if (front->tr->right) inque(front->tr->right, front, rear);
        deque(front, rear);
    }
}

int main() {
    int n; cin >> n;
    record rec[n];
    int check[10] = {0};
    for (int i = 0; i < n; ++i) {
        char tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        if (tmp1 != '-') {
            rec[i].left = tmp1 - '0';
            check[rec[i].left] = 1;
        }
        else rec[i].left = -1;
        if (tmp2 != '-') {
            rec[i].right = tmp2 - '0';
            check[rec[i].right] = 1;
        }
        else rec[i].right = -1;
    }
    int root = -1;
    node* nodep = nullptr;
    for (int i = 0; i < n; ++i) {
        if (!check[i]) {
            root = i;
            break;
        }
    }
    buildTree(root, nodep, rec);
    printLeaves(nodep);
    return 0;
}
