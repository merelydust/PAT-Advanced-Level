/***
 函数参数为指针type* ptr：      函数体内改变指针所指对象
 函数参数为指针引用type* &ptr：  函数体内改变指针所指方向
 
 nodep就是一棵树 相当于树节点数组的名字 指向树节点数组的指针
 ***/

#include <iostream>
using namespace std;

struct record {
    int left, right;
};

struct node {
    int num; // 树节点在数组里的序号
    node* left; // 左子树
    node* right; // 右子树
    //这样子定义 就可以实现 NodePrt->left->left...
};

struct queNode { //用队列存储树
    node* tr; // 存储一棵(子)树
    queNode* next; // 指向下一个队列节点
};

void inque(node* tr, queNode* &front, queNode* &rear) { // 入队函数
    if (rear) { // 增加在尾
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

void deque(queNode* &front, queNode* &rear) { //出队函数
    if (front) { // 取删在头
        if (front->next) {
            queNode* tmp = front->next;
            delete front;
            front = tmp;
        }
        else {
            delete front;
            front = nullptr;
            rear = nullptr;
        }
    }
}

void buildTree(record* rec, int root, node* &nodep) { //rec查询是否有孩子 root是根节点序号 nodep是树
    nodep = new node; // 新建一棵子树
    nodep->num = root; //子树的根在数组里的序号等于root
                       // 递归出口是 子树的根 其实只是个叶子
    nodep->left = nodep->right = nullptr; // 子树初始化没有叶子
    if (rec[root].left != -1) { // 如果rec中的root号树节点有左孩子
        nodep->left = new node; // 以这个左孩子为根新建一棵子树
        buildTree(rec, rec[root].left, nodep->left);
    }
    if (rec[root].right != -1) { // 右边同理
        nodep->right = new node;
        buildTree(rec, rec[root].right, nodep->right);
    }
}

void printLeaves(node* nodep) {
    if (!nodep) return;
    queNode* front = nullptr; // 新建队列
    queNode* rear = nullptr;
    inque(nodep, front, rear); // 队列存储对象是各子树 从大到小
    
    bool isFirst = true;
    while (front) {
        if (!front->tr->left && !front->tr->right) { // 如果队列里->这棵树->没有左右孩子
            if (isFirst) {
                cout << front->tr->num;
                isFirst = false;
            }
            else cout << ' ' << front->tr->num;
        }
        if (front->tr->left) inque(front->tr->left, front, rear); //把下一等级的的左子树插入队列
        if (front->tr->right) inque(front->tr->right, front, rear); // 把下一等级的右子树插入队列
        deque(front, rear); // 当前这一棵较高级子树出队
    }
}

int main() {
    int n; cin >> n;
    record rec[10];
    int check[10] = {0};
    for (int i = 0; i < n; ++i) {
        char tmp1, tmp2; cin >> tmp1 >> tmp2;
        if (tmp1 != '-') {
            rec[i].left = tmp1 - '0';
            check[rec[i].left] = 1;
        } else {
            rec[i].left = -1;
        }
        if (tmp2 != '-') {
            rec[i].right = tmp2 - '0';
            check[rec[i].right] = 1;
        } else {
            rec[i].right = -1;
        }
    }
    
    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (!check[i]) {
            root = i;
            break;
        }
    }
    if (root == -1) return 0;
    node* nodep = nullptr;
    buildTree(rec, root, nodep);
    printLeaves(nodep);
    
    return 0;
}
