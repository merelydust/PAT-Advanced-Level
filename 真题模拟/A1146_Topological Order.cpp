#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 1010;
vector<int> adj[maxn];
int in[maxn] = {0}; // 记录每个顶点的入度


int main() {
    int n, m; scanf("%d %d", &n, &m);
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v); in[v]++;
    }
    int k; scanf("%d", &k);
    vector<int> ans;
    for (int q = 0; q < k; ++q) {
        vector<int> tmpIn(in, in+maxn); // 拷贝一份入度数组的副本
        bool flag = true;
        for (int i = 0; i < 6; ++i) {
            scanf("%d", &u);
            if (tmpIn[u] != 0) flag = false;
            if (!flag) continue;
            for (int j = 0; j < adj[u].size(); ++j) tmpIn[adj[u][j]]--;
        }
        if (!flag) ans.push_back(q);
    }
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d", ans[i]);
        if (i != ans.size()-1) printf(" ");
        else printf("\n");
    }
    return 0;
}

