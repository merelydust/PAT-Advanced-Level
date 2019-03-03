#include <cstdio>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    int sqr = int(sqrt(1.0 * n));
    for (int i = 2; i <= sqr; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n; scanf("%d", &n);
    bool flag = true;
    if (isPrime(n)) {
        if (isPrime(n-6)) printf("Yes\n%d\n", n-6);
        else if (isPrime(n+6)) printf("Yes\n%d\n", n+6);
        else flag = false;
    }
    else flag = false;
    if (!flag) {
        printf("No\n");
        while (!isPrime(n) || !( isPrime(n+6) || isPrime(n-6)) ) ++n;
        printf("%d\n", n);
    }
    return 0;
}
