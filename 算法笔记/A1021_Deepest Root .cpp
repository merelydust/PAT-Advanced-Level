/***
 注意IO格式～～！一行一个啊喂
 
 判断树是否为图：只有一个连通块 -> 用并查集判断
 如果不是图 输出连通块(connected components)数量
 ***/

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100010;
vector<int> G[maxn];

int isRoot[maxn] = {0};
int father[maxn];

int findFather(int x) {
    int a = x;
    while (x != father[x]) x = father[x];
    while (a != father[a]) {
        int b = a;
        a = father[a];
        father[b] = x; // 要等a从father[a]移走了才能对原来的father[a]做操作
    }
    return x;
}

void unionFather(int a, int b) {
    int faA = findFather(a), faB = findFather(b);
    if (faA != faB) father[faA] = faB;
}

int cntBlock(int n) {
    int block = 0;
    for (int i = 1; i <= n; ++i) isRoot[findFather(i)] = 1;
    for (int i = 1; i <= n; ++i) block += isRoot[i];
    return block;
}

int maxH = 0;
vector<int> tmp, ans;  // tmp存放临时DFS最远节点结果 ans保存答案
void DFS(int u, int height, int pre) { // pre是u的父节点 防止走回头路
    if (height > maxH) {
        tmp.clear(); tmp.push_back(u);
        maxH = height;
    }
    else if (height == maxH) tmp.push_back(u);
    for (int i = 0; i < G[u].size(); ++i) { // 遍历u的所有子节点
        if (G[u][i] == pre) continue; // 由于是无向图 跳过回去的边
        DFS(G[u][i], height+1, u);
    }
}

int main() {
    int a, b, n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) father[i] = i;
    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &a, &b);
        G[a].push_back(b); G[b].push_back(a);
        unionFather(a, b);
    }
    int block = cntBlock(n);
    if (block != 1) printf("Error: %d components\n", block);
    else {
        DFS(1, 1, -1);
        ans = tmp;
        DFS(ans[0], 1, -1);
        for (int i = 0; i < tmp.size(); ++i) ans.push_back(tmp[i]);
        sort(ans.begin(), ans.end());
        printf("%d\n", ans[0]);
        for (int i = 1; i < ans.size(); ++i) {
            if (ans[i] != ans[i-1]) printf("%d\n", ans[i]);
        }
    }
    return 0;
}
