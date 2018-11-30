// 普通性质的树 -> 结构体数组模拟
// 最后输出要从大到小 -> 对每个节点的直系子节点合集vector排序
// 优先遍历权值较大的节点
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 110;
struct node {
    int weight;
    vector<int> child; // 存放的是子节点的序号
}Node[maxn];

bool cmp(int a, int b) {
    return Node[a].weight > Node[b].weight;
}

int n, m, s;
int path[maxn]; // 记录路径

//index当前访问节点序号 numNode为当前path上节点个数
void DFS(int index, int numNode, int sum) {
    if (sum > s) return;
    if (sum == s) {
        if (Node[index].child.size() != 0) return; // 最后一个不是叶节点
        for (int i = 0; i < numNode; ++i) {
            if (i) printf(" ");
            printf("%d", Node[path[i]].weight);
        }
        printf("\n"); return;
    }
    for (int i = 0; i < Node[index].child.size(); ++i) {
        int child = Node[index].child[i]; // 节点index的第i个子节点编号
        path[numNode] = child;
        DFS(child, numNode+1, sum+Node[child].weight);
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < n; ++i) scanf("%d", &Node[i].weight);
    int id, k, child;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &id, &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &child); Node[id].child.push_back(child);
        }
        sort(Node[id].child.begin(), Node[id].child.end(), cmp);
    }
    path[0] = 0; // 路径的第一个节点为0号节点
    DFS(0, 1, Node[0].weight);
    return 0;
}
