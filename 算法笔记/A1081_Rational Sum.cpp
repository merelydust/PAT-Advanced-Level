#include <cstdio>
#include <cmath>
using namespace std;

struct fract {
    long long up, down;
};
fract ans, tmp;

long long abs(long long n) {
    if (n < 0) return -n;
    else return n;
}

long long gcd(long long a, long long b) {
    return !b ? a : gcd(b, a % b);
}

void simplify() {
    if (ans.down < 0) { // 保证负号一定在分子前面
        ans.up = -ans.up; ans.down = - ans.down;
    }
    if (ans.up == 0) ans.down = 1;
    else {
        long long d = gcd(abs(ans.up), ans.down);
        ans.up /= d; ans.down /= d;
    }
}

void add() {
    ans.up = ans.up * tmp.down + tmp.up * ans.down;
    ans.down *= tmp.down;
    simplify();
}

int main() {
    int n; scanf("%d", &n); ans.up = 0; ans.down = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%lld/%lld", &tmp.up, &tmp.down);
        add();
    }
    if (ans.down == 1) printf("%lld\n", ans.up);
    else if (ans.up > ans.down) {
        printf("%lld %lld/%lld\n", abs(ans.up) / ans.down, abs(ans.up) % ans.down, ans.down);
    }
    else printf("%lld/%lld\n", ans.up, ans.down);
    return 0;
}
