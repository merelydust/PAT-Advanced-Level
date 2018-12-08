#include <cstdio>
#include <map>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    map<int, int> mp; int tmp;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tmp); mp[tmp]++;
    }
    int num = 0;
    while(++num) { // 没给key取值范围 可能很大很大 就让while一直找嘛
        if (!mp[num]) {
            printf("%d\n", num); break;
        }
    }
    return 0;
}
