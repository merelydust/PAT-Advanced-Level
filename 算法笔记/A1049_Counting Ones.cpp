#include <cstdio>
using namespace std;

int main() {
    int n, a = 1, ans = 0;
    int left, now, right;
    scanf("%d", &n);
    while (n / a != 0) {
        left = n / (a * 10);
        now = n / a % 10;
        right = n % a;
        if (now == 0) ans += left * a;
        else if (now == 1) ans += left * a + right + 1;
        else ans += (left + 1) * a;
        a *= 10;
    }
    printf("%d\n", ans);
    return 0;
}
