// 有个段错误扣了一分0 0？
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

const int maxn = 10010;
int in[maxn], pre[maxn], pos[maxn];
// pos存储中序序列元素i的位置 u v位置在i/root两边 则i为lcs 都在左边 往左边找 右边亦然

int u, v;
void lfs(int preL, int preR, int inL, int inR) {
    if (preL > preR) return;
    int root = pre[preL]; int rootPos = pos[root]; // root在中序序列中位置
    int numLeft = rootPos - inL;
    if (pos[u] < rootPos && pos[v] < rootPos) lfs(preL+1,preL+numLeft, inL, rootPos-1);
    else if (pos[u] > rootPos && pos[v] > rootPos) lfs(preL+numLeft+1, preR, rootPos+1, inR);
    else if ((pos[u] < rootPos && pos[v] > rootPos) ||
             (pos[v] < rootPos && pos[u] > rootPos)
             ) {
        printf("LCA of %d and %d is %d.\n", u, v, root);
    }
    else if (pos[u] == rootPos || pos[v] == rootPos) {
        printf("%d is an ancestor of %d.\n", root, u==root?v:u);
    }
}

int main() {
    fill(pos, pos+maxn, -1); // 初始化pos
    map<int, bool> mp; // 跟上次一样的坑 用数组直接映射某key值是否出现会爆 必须map
    int m, n; scanf("%d %d", &m, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &in[i]); pos[in[i]] = i; mp[in[i]] = true;
    }
    for (int i = 0; i < n; ++i) scanf("%d", &pre[i]);
    while (m--) {
        scanf("%d %d", &u, &v);
        if (!mp[u] && !mp[v]) printf("ERROR: %d and %d are not found.\n", u ,v);
        else if (!mp[u] || !mp[v]) printf("ERROR: %d is not found.\n", !mp[u]?u:v);
        else lfs(0, n-1, 0, n-1);
    }
    return 0;
}
