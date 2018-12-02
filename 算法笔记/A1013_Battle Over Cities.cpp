/***
 输入城市总数n 可用边数m 可能被毁掉的城市数量k
 输出对每一个被毁掉的城市 需要重建的路的数量
 
 本质就是一个连通图 被摘了一个节点b 同时摘除b周围的边
 问需要几条边让这个图重新全连通
 如何计算边呢？
 把断裂的图看成一个个连通块 两个连通块之间只需一条边就能连接 这种连法一定是最少的
 所以需要的边数就是连通块个数减一
 如何取得连通块数量？
 图的遍历 遍历连通块
***/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 1010;
vector<int> G[maxn]; // 邻接表
bool vis[maxn] = {false};

int currentPoint; // 当前要被删除的节点
void dfs(int v) {
    if (v == currentPoint) return; // 当遍历到已删除的节点
    vis[v] = true;
    for (int i = 0; i < G[v].size(); ++i) {
        if (!vis[G[v][i]]) dfs(G[v][i]);
    }
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        G[a].push_back(b); G[b].push_back(a);
    }
    for (int q = 0; q < k; ++q) {
        scanf("%d", &currentPoint);
        memset(vis, false, sizeof(vis));
        int block = 0;
        for (int i = 1; i <= n; ++i) {
            if (i != currentPoint && !vis[i]) {
                dfs(i); block++;
            }
        }
        printf("%d\n", block-1);
    }
    return 0;
}
