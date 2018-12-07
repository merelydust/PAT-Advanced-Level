#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 500, INF = 10<<9;
int G[maxn][maxn] = {0};

int judge(int cities) { // 返回一条路径的距离
    int n; scanf("%d", &n); vector<int> path(n);
    for (int i = 0; i < n; ++i) scanf("%d", &path[i]);
    int dis = 0; bool simple = true;
    bool vis[maxn] = {0}; vis[path[0]] = true; // 标记起点已经访问
    for (int i = 1; i < n; ++i) {
        if (!G[path[i-1]][path[i]]) { // 如果两点之间没有连通
            printf("NA (Not a TS cycle)\n"); return INF;
        }
        if (vis[path[i]] && i != n-1) simple = false; // 重复访问了节点
        vis[path[i]] = true; dis += G[path[i-1]][path[i]];
    }
    int cnt = 0;
    for (int i = 1; i <= cities; ++i) cnt += vis[i];
    if (cnt < cities || path[0] != path[n-1]) {
        printf("%d (Not a TS cycle)\n", dis); // 没有访问到所有的节点或者没有回到起点
        return INF;
    }
    else if (!simple) printf("%d (TS cycle)\n", dis);
    else printf("%d (TS simple cycle)\n", dis);
    return dis;
}

int main() {
    int n, m; scanf("%d %d", &n, &m); // n顶点数 m边数
    int u, v, dis;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &dis);
        G[u][v] = dis; G[v][u] = dis;
    }
    int k; scanf("%d", &k);
    int minDis = INF, idx = -1;
    for (int i = 1; i <= k; ++i) {
        printf("Path %d: ", i);
        int tmp = judge(n);
        if (tmp < minDis) {
            minDis = tmp; idx = i;
        }
    }
    printf("Shortest Dist(%d) = %d\n", idx, minDis);
    return 0;
}

