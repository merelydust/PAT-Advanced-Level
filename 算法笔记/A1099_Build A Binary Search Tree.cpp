/***
 思路：
 结构体数组表示树
 把从小到大排好序的序列插入中序访问的树节点
 层序遍历输出树
 ***/
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 110; int n;
int numbers[maxn];

struct node {
    int data, left, right;
}nodes[maxn];

int i = 0; // numbers的索引
void inOrder(int root) {
    if (root == -1) return;
    inOrder(nodes[root].left);
    nodes[root].data = numbers[i++];
    inOrder(nodes[root].right);
}

int num = 0; // 记录已经输出的节点数
void layerOrder(int root) {
    queue<int> Q; Q.push(root);
    while (!Q.empty()) {
        int fro = Q.front(); Q.pop();
        printf("%d", nodes[fro].data); num++;
        if (num < n) printf(" ");
        else printf("\n");
        if (nodes[fro].left != -1) Q.push(nodes[fro].left);
        if (nodes[fro].right != -1) Q.push(nodes[fro].right);
    }
}

int main() {
    scanf("%d", &n); int l, r;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &l, &r);
        nodes[i].left = l; nodes[i].right = r;
    }
    for (int i = 0; i < n; ++i) scanf("%d", &numbers[i]);
    sort(numbers, numbers+n);
    inOrder(0);
    layerOrder(0);
    return 0;
}
