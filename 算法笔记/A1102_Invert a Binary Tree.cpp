// 因为题目给出的是节点的编号 所以用静态链表
// 先找到根节点 然后顺藤摸瓜
// 输出树反转过来的层序遍历和后序遍历
// 树反转套路: 后序遍历 访问时交换左右节点
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
    int left, right;
    node() {
        left = -1; right = -1;
    }
}nodes[11];

void postOrder(int root) {
    if (root == -1) return;
    postOrder(nodes[root].left);
    postOrder(nodes[root].right);
    swap(nodes[root].left, nodes[root].right);
}

int num1 = 0, n; // 记录已经输出了几个节点
void layerOrder(int root) {
    if (root == -1) return;
    queue<int> Q; Q.push(root);
    while (!Q.empty()) {
        int fro = Q.front(); Q.pop();
        printf("%d", fro); num1++;
        if (num1 < n) printf(" ");
        else printf("\n");
        if (nodes[fro].left != -1) Q.push(nodes[fro].left);
        if (nodes[fro].right != -1) Q.push(nodes[fro].right);
    }
}

int num2 = 0;
void inOrder(int root) {
    if (root == -1) return;
    inOrder(nodes[root].left);
    printf("%d", root); num2++;
    if (num2 < n) printf(" ");
    else printf("\n");
    inOrder(nodes[root].right);
}

int main() {
    scanf("%d", &n);
    bool isChild[11] = {false}; char l, r;
    for (int i = 0; i < n; ++i) {
        scanf(" %c %c", &l, &r); // 最前面的空格吸收换行符
        if (l == '-') nodes[i].left = -1;
        else {
            nodes[i].left = l - '0'; isChild[nodes[i].left] = true;
        }
        if (r == '-') nodes[i].right = -1;
        else {
            nodes[i].right = r - '0'; isChild[nodes[i].right] = true;
        }
    }
    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (!isChild[i]) {
            root = i; break;
        }
    }
    postOrder(root);
    layerOrder(root);
    inOrder(root);
    return 0;
}
