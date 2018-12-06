#include <cstdio>

int main() {
    const int maxn = 10010;
    int m, n; scanf("%d %d", &m, &n);
    int hashtable[maxn] = {0}; // 标记某个key是否出现
    int pre[maxn];
    for (int i =0; i <n; ++i) {
        scanf("%d", &pre[i]); hashtable[pre[i]] = 1;
    }
    int u, v, k;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        for(int j = 0; j < n; ++j) {
            k = pre[j];
            if ((k >= u && k <= v) || (k >= v && k <= u)) break;
        }
        if (!hashtable[u] && !hashtable[v]) printf("ERROR: %d and %d are not found.\n", u, v);
        else if (!hashtable[u] || !hashtable[v]) printf("ERROR: %d is not found.\n", hashtable[u] == 0 ? u : v);
        else if (k == u || k == v) printf("%d is an ancestor of %d.\n", k, k == u ? v : u);
        else printf("LCA of %d and %d is %d.\n", u, v, k);
    }
    return 0;
}

//#include <iostream>
//#include <vector>
//#include <map>
//using namespace std;
//map<int, bool> mp;
//int main() {
//    int m, n, u, v, a;
//    scanf("%d %d", &m, &n);
//    vector<int> pre(n);
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &pre[i]);
//        mp[pre[i]] = true;
//    }
//    for (int i = 0; i < m; i++) {
//        scanf("%d %d", &u, &v);
//        for(int j = 0; j < n; j++) {
//            a = pre[j];
//            if ((a >= u && a <= v) || (a >= v && a <= u)) break;
//        }
//        if (mp[u] == false && mp[v] == false)
//            printf("ERROR: %d and %d are not found.\n", u, v);
//        else if (mp[u] == false || mp[v] == false)
//            printf("ERROR: %d is not found.\n", mp[u] == false ? u : v);
//        else if (a == u || a == v)
//            printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
//        else
//            printf("LCA of %d and %d is %d.\n", u, v, a);
//    }
//    return 0;
//}
