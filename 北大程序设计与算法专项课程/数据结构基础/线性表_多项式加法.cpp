#include <cstdio>
#include <map>
#include <functional>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    while (n--) {
        int co, ex;
        map<int, int, greater<int> > mp;
        while (scanf("%d %d", &co, &ex) != EOF) {
            if (ex < 0) break;
            mp[ex] += co;
        }
        while (scanf("%d %d", &co, &ex) != EOF) {
            if (ex < 0) break;
            mp[ex] += co;
        }
        map<int, int>::iterator it = mp.begin();
        for (; it != mp.end(); ++it) {
            if (it != mp.begin()) printf(" ");
            if (it->second) printf("[ %d %d ]", it->second, it->first);
        }
        printf("\n");
    }
    return 0;
}
