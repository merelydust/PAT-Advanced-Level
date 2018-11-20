// 水题 格式调了半天O_o?
#include <cstdio>
#include <algorithm>
using namespace std;

struct fraction {
    long long up, down;
};
fraction a, b;

void rightNegative(fraction& f) {
    if (f.down < 0) {
        f.up = -f.up; f.down = -f.down;
    }
}

long long gcd(long long a, long long b) {
    return !b ? a : gcd(b, a % b);
}

fraction simplify(fraction ans) {
    long long g = gcd(abs(ans.up), ans.down);
    ans.up /= g; ans.down /= g;
    return ans;
}

fraction add(fraction a, fraction b) {
    fraction ans;
    ans.up = a.up * b.down + b.up * a.down; ans.down = a.down * b.down;
    return simplify(ans);
}

fraction minus(fraction a, fraction b) {
    b.up = -b.up; return add(a, b);
}

fraction mul(fraction a, fraction b) {
    fraction ans;
    ans.up = a.up * b.up; ans.down = a.down * b.down;
    return simplify(ans);
}

fraction div(fraction a, fraction b) {
    swap(b.up, b.down); return mul(a, b);
}

void printFraction(fraction ans) {
    ans = simplify(ans); rightNegative(ans);
    if (ans.up < 0) printf("(-");
    if (ans.up == 0) printf("0");
    else if (ans.down == 1) printf("%lld", abs(ans.up));
    else if (abs(ans.up) > ans.down) printf("%lld %lld/%lld", abs(ans.up)/ans.down, abs(ans.up)%ans.down, ans.down);
    else printf("%lld/%lld", abs(ans.up), ans.down);
    if (ans.up < 0) printf(")");
}

int main() {
    scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
    rightNegative(a); rightNegative(b);
    printFraction(a); printf(" + "); printFraction(b); printf(" = "); printFraction(add(a, b)); printf("\n");
    printFraction(a); printf(" - "); printFraction(b); printf(" = "); printFraction(minus(a, b)); printf("\n");
    printFraction(a); printf(" * "); printFraction(b); printf(" = "); printFraction(mul(a, b)); printf("\n");
    printFraction(a); printf(" / "); printFraction(b); printf(" = ");
    if (b.up == 0) printf("Inf\n");
    else {
        printFraction(div(a, b)); printf("\n");
    }
    return 0;
}
