/***
 开哈希表会超时
 用map
 ***/
#include <cstdio>
#include <map>
using namespace std;

int main() {
    int m, n, tmp; scanf("%d %d", &m, &n);
    map<int, int> mp;
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < m; ++ col) {
            scanf("%d", &tmp); mp[tmp]++;
        }
    }
    int half = m * n / 2;
    map<int, int>::iterator it = mp.begin();
    for (; it != mp.end(); ++it) {
        if (it->second > half) {
            printf("%d\n", it->first); break;
        }
    }
    return 0;
}
