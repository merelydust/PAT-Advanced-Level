/**
由于AVL树是动态生成，为保证 传入的指针参数的指向 在函数体中被改变，需要使用引用符号 ‘&’
 **/
#include <iostream>
#include <cmath>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;
    int height;
};

int getHeight(node* tr) {
    return tr == nullptr ? -1 : tr->height;
}

void LLRotate(node* &tr) { // 左左 右旋(右边节点降下去叫右旋)
    node* tmp = tr->left; // tr是离扰乱节点最近的子树 处理它下面
    tr->left = tmp->right; // tmp的右子树挂上tr的左边
    tmp->right = tr; // tr挂到tmp的右边
    tmp->height = max(getHeight(tmp->left), getHeight(tmp->right))+1;
    tr->height = max(getHeight(tr->left), getHeight(tr->right))+1;
    tr = tmp;
}

void RRRotate(node* &tr) {
    node* tmp = tr->right;
    tr->right = tmp->left;
    tmp->left = tr;
    tmp->height = max(getHeight(tmp->left), getHeight(tmp->right))+1;
    tr->height = max(getHeight(tr->left), getHeight(tr->right))+1;
    tr = tmp;
}

void RLRotate(node* &tr) { // 总体来看是右孩子扰乱了整棵树
    LLRotate(tr->right); // 右孩子的左子树有新增节点 先调整右孩子让它左右平衡
    RRRotate(tr); // 树的右孩子是捣乱因素 调整树的左右孩子
}

void LRRotate(node* &tr) {
    RRRotate(tr->left);
    LLRotate(tr);
}

void insert(const int &x, node* &tr) {
    if (tr == nullptr) {
        tr = new node;
        tr->val = x;
        tr->height = 0;
        tr->left = tr->right = nullptr;
    }
    else if (x < tr->val) {
        insert(x, tr->left);
        if (abs(getHeight(tr->left) - getHeight(tr->right)) == 2) {
            if (x < tr->left->val) LLRotate(tr);
            else LRRotate(tr);
        }
    }
    else if (x > tr->val) {
        insert(x, tr->right);
        if (abs(getHeight(tr->left) - getHeight(tr->right)) == 2) {
            if (x > tr->right->val) RRRotate(tr);
            else RLRotate(tr);
        }
    }
    tr->height = max(getHeight(tr->left), getHeight(tr->right))+1;
}

int main() {
    node* root = nullptr;
    int n; cin >> n;
    while (n--) {
        int tmp; cin >> tmp;
        insert(tmp, root);
    }
    cout << root->val << endl;
    delete root;
    return 0;
}
