#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 510;
const int INF = 10 << 9;

// n为顶点数 m为边数 Cmax为最大容量 sp为问题站点
// G为邻接矩阵 weight为点权 d[]记录最短距离
// minNeed记录最少携带数目 minRemain记录最少带回数目
int n, m, Cmax, sp, numPath = 0, G[maxn][maxn], weight[maxn];
int d[maxn], minNeed = INF, minRemain = INF;
bool vis[maxn] = {false};
vector<int> pre;
vector<int> tmpPath, path; // 临时路径和最优路径

void Dijkstra(int s) {
    fill(d, d+maxn, INF);
    d[s] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1, MIN = INF;
        for (int j = 0; i < n; ++i) {
            if (!vis[j] && d[j] < MIN) {
                u = j; MIN = d[j];
            }
        }
    }
}
