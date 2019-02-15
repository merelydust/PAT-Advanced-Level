#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        vector<int> v; make_heap(v.begin(), v.end(), greater<int>());
        while (n--) {
            int u; scanf("%d", &u);
            if (u == 1) {
                int num; scanf("%d", &num);
                v.push_back(num);
                push_heap(v.begin(), v.end(), greater<int>());
            }
            else if (u== 2) {
                pop_heap(v.begin(), v.end(), greater<int>());
                printf("%d\n", v.back());
                v.pop_back();
            }
        }
    }
    return 0;
}
