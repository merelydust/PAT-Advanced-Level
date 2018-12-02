/***
 涉及到层数 -> BFS
 1000的量级 -> 邻接矩阵
 node从1开始编号
 only L levels of indirect followers are counted -> 发出者的layer设为0
 
 题意就是求顶点u在L层内的子节点个数
 ***/
#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 1010; int n, l;
int G[maxn][maxn] = {0};
bool vis[maxn] = {false};

int BFS(int u) {
    int cnt = 0;
    queue<int> Q;
    bool inq[maxn] = {false}; int L[maxn] = {0}; // 记录每个节点的layer
    Q.push(u); inq[u] = true;
    while (!Q.empty()) {
        int fro = Q.front(); Q.pop();
        for (int i = 1; i <= n; ++i) { // 枚举所有节点
            if (G[fro][i] && !inq[i]) { // fro可以直接到达i
                L[i] = L[fro] + 1;
                if (L[i] > l) return cnt;
                Q.push(i); inq[i] = true; cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    scanf("%d %d", &n, &l);
    int k, idol;
    for (int usr = 1; usr <= n; ++usr) {
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &idol); G[idol][usr] = 1;
        }
    }
    int qNum, q; scanf("%d %d", &qNum, &q);
    while (qNum--) {
        scanf("%d", &q); printf("%d\n", q);
        printf("%d\n", BFS(q));
    }
    return 0;
}
