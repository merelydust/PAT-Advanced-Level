#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 510;
const int INF = 10 << 9;

// n为顶点数 m为边书 st和ed分别为起点和终点
// G为距离矩阵 cost为花费矩阵
// d[]记录最短距离 c[]记录最小花费
int n, m, st, ed, G[maxn][maxn], cost[maxn][maxn];
int d[maxn], c[maxn], pre[maxn];
bool vis[maxn] = {false};

void Dijkstr(int s) { // s为起点
    fill(d, d + maxn, INF);
    fill(c, c + maxn, INF);
    for (int i = 0; i < n; ++i) pre[i] = i;
    d[s] = 0; c[s] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && d[j] < MIN) { // 找到未访问节点中d[]最小的
                u = j; MIN = d[u];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < n; ++v) { // 更新以u为中介可以优化的最短路径
            if (!vis[v] && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    c[v] = c[u] + cost[u][v];
                    pre[v] = u;
                }
                else if (d[u] + G[u][v] == d[v]) {
                    if (c[u] + cost[u][v] < c[v]) {
                        c[v] = c[u] + cost[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
}

void DFS(int v) { // 打印路径
    if (v == st) {
        printf("%d ", v); return;
    }
    DFS(pre[v]);
    printf("%d ", v);
}

int main() {
    scanf("%d %d %d %d", &n, &m, &st, &ed);
    int u, v;
    fill(G[0], G[0] + maxn*maxn, INF);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        scanf("%d %d", &G[u][v], &cost[u][v]);
        G[v][u] = G[u][v]; cost[v][u] = cost[u][v];
    }
    Dijkstr(st);
    DFS(ed);
    printf("%d %d\n", d[ed], c[ed]);
    return 0;
}
