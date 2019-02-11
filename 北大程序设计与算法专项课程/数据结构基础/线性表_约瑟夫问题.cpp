#include <cstdio>
#include <list>
using namespace std;

int main() {
    int n, m; scanf("%d %d", &n, &m);
    m = m % n;
    list<int> lst;
    for (int i = 1; i <= n; ++i) lst.push_back(i);
    list<int>::iterator it = lst.begin();
    while (lst.size() > 1) {
        for (int i = 1; i < m; ++i) {
            if (++it == lst.end()) it = lst.begin();
        }
        it = lst.erase(it);
        if (it == lst.end()) it = lst.begin();
    }
    printf("%d\n", *it);
    return 0;
}
