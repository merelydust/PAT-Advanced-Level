#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 210; int nv, ne;
int G[maxn][maxn] = {0};

bool judge1(vector<int> q) { // 判断是否是clique
    for (int i = 0; i < q.size(); ++i) {
        for (int j = 0; j < q.size(); ++j) {
            if (q[i] == q[j]) continue;
            if (!G[q[i]][q[j]]) {
                return false;
            }
        }
    }
    return true;
}

bool judge2(vector<int> q) { // 判断是否max即是否还有额外的点
    bool flag = false;
    for (int i = 1; i <= nv; ++i) {
        if (find(q.begin(), q.end(), i) != q.end()) continue; // 已在q中
        q.push_back(i);
        flag = judge1(q);
        if (flag) return flag;
        q.pop_back();
    }
    return flag;
}

int main() {
    scanf("%d %d", &nv, &ne);
    int a, b;
    for (int i = 0; i < ne; ++i) {
        scanf("%d %d", &a, &b);
        G[a][b] = 1; G[b][a] = 1;
    }
    int m; scanf("%d", &m); int k, v;
    while (m--) {
        scanf("%d", &k);
        vector<int> q; bool isC = true, notM = true;
        for (int i = 0; i < k; ++i) {
            scanf("%d", &v); q.push_back(v);
        }
        isC = judge1(q);
        if (!isC) {
            printf("Not a Clique\n"); continue;
        }
        notM = judge2(q);
        if (notM) {
            printf("Not Maximal\n"); continue;
        }
        printf("Yes\n");
    }
}

/***
 模拟反思：
 遇到新设定不要慌 用已有的知识一定可以解决
 注意使用函数对功能的模块化 以便实代码的重用
 ***/
