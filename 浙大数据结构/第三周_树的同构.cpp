#include <iostream>
using namespace std;

struct node {
    char element;
    int left, right;
}tree1[10], tree2[10]; // 用静态链表存储树
int check[10] = {0}; // 标记是否为子节点

int buildTree() { // 返回根节点在静态链表中的索引
    int num; cin >> num;
    if (!num) return -1;
    int check[10] = {0};
    for (int i = 0; i < num; ++i) {
        char tmp1, tmp2;
        cin >> tree[i].element >> tmp1 >> tmp2;
        if (tmp1 != '-') {
            tree[i].left = tmp1 - '0';
            check[tree[i].left] = 1;
        } else tree[i].left = -1;
        if (tmp2 != '-') {
            tree[i].right = tmp2 - '0';
            check[tree[i].right] = 1;
        } else tree[i].right = -1;
    }
    for (int i = 0; i < num; ++i) { // 找到根节点返回
        if (!check[i]) return i;
    }
    return -1;
}

bool isSame(int root1, int root2) {
    if (root1 == -1 && root2 == -1) return true; // 两棵树都是空的
    if (root1 == -1 || root2 == -1) return false; // 只有一棵树是空的
    if (tree1[root1].element != tree2[root2].element) return false; // 树1根节点值不等于树2根节点值
    // tree1[root1].left是下一个要判断的新根在静态链表中的索引
    if (tree1[tree1[root1].left].element == tree2[tree2[root2].left].element) return isSame(tree1[root1].right, tree2[root2].right);
    // 如果树1的左半边不等于树2的左半边 则左右交换比较 树1左对应树2右 树1右对应树1左
    else return isSame(tree1[root1].left, tree2[root2].right) && isSame(tree1[root1].right, tree2[root2].left);
}

int main() {
    int root1 = buildTree(tree1);
    int root2 = buildTree(tree2);
    if (isSame(root1, root2)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
