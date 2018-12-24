#include <cstdio>
using namespace std;

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) printf("%d\n", gcd(a, b));
    return 0;
}
