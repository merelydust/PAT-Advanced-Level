#include <cstdio>
#include <map>
using namespace std;

const int maxn = 10010;
int pre[maxn];
// 开一个一万大小的哈希表有两个测试点过不了
map<int, bool> hashtable; // 没有给定key取值范围的题目还是用map标记保险呀～

int main() {
    int m, n; scanf("%d %d", &m, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pre[i]); hashtable[pre[i]] = 1;
    }
    int u, v;
    while (m--) {
        scanf("%d %d", &u, &v);
        int a = -1; // 祖先的值
        for (int i = 0; i < n; ++i) {
            a = pre[i];
            if ((a >= u && a <= v) || (a >= v && a <= u)) break;
        }
        if (!hashtable[u] && !hashtable[v]) printf("ERROR: %d and %d are not found.\n", u, v);
        else if (!hashtable[u] || !hashtable[v]) printf("ERROR: %d is not found.\n", hashtable[u]?v:u);
        else if (a == u || a == v) printf("%d is an ancestor of %d.\n", a, a==u?v:u);
        else printf("LCA of %d and %d is %d.\n", u, v, a);
    }
    return 0;
}
