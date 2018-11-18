// two pointer解法
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, p; scanf("%d %d", &n, &p);
    long long arr[100010];
    for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
    sort(arr, arr+n);
    int i = 0, j = 0, cnt = 1;
    while (i < n && j < n) {
        while (j < n && arr[i] * p >= arr[j]) {
            cnt = max(j-i+1, cnt); j++;
        }
        i++;
    }
    printf("%d\n", cnt);
    return 0;
}
