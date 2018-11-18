#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    const int maxn = 100010, INF = (1<<31)-1; int arr[maxn];
    int leftMax[maxn], rightMin[maxn]; leftMax[0] = -1; rightMin[n-1] = INF;
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    for (int i = 1; i < n; ++i) leftMax[i] = max(leftMax[i-1], arr[i-1]);
    for (int i = n - 2; i >= 0; --i) rightMin[i] = min(rightMin[i+1], arr[i+1]);
    int ans[maxn]; int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] >= leftMax[i] && arr[i] <= rightMin[i]) ans[cnt++] = arr[i];
    }
    printf("%d\n", cnt);
    sort(ans, ans+cnt);
    for (int i = 0; i < cnt; ++i) {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
