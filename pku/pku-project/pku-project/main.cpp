#include <cstdio>
#include <map>
#include <set>
using namespace std;

const int maxn = 100000;
int hashtable[maxn] = {0}, couple[maxn] = {0};
int arr[maxn];

int main() {
    int n; scanf("%d", &n);
    map<int, int> mp; set<int> st;
    int a, b;
    while (n--) {
        scanf("%d %d", &a, &b);
        mp[a] = b; mp[b] = a;
        couple[a] = 1; couple[b] = 1;
    }
    int m; scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &arr[i]); hashtable[arr[i]] = 1;
    }
    for (int i = 0; i < m; ++i) {
        if (!couple[arr[i]]) st.insert(arr[i]); // 没对象
        else if (!hashtable[mp[arr[i]]]) st.insert(arr[i]); // 对象没来
    }
    printf("%d\n", st.size());
    if (!st.size()) return 0;
    for (auto it = st.begin(); it != st.end(); ++it) {
        if (it == st.begin()) printf("%05d", *it);
        else printf(" %05d", *it);
    }
    printf("\n"); return 0;
}
