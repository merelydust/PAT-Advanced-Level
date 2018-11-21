/***
 从小到大枚举素数 n除它除到不能除为止
 结构体数组存储质因数和它对应的个数
 ***/
#include <cstdio>
#include <cmath>
using namespace std;

struct fac {
    long long x, cnt;
}factors[11];

bool isPrime(long long n) {
    if (n < 2) return false;
    long long sqr = (long long)sqrt(1.0 * n);
    for (int i = 2; i <= sqr; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    long long n; scanf("%lld", &n); int facCnt = 0;
    if (n == 1) {
        printf("1=1\n"); return 0;
    }
    printf("%lld=", n);
    long long sqr = (long long)sqrt(1.0 * n);
    for (int i = 2; i <= sqr; ++i) {
        if (isPrime(i) && n % i == 0) {
            factors[facCnt].x = i; factors[facCnt].cnt = 0;
            while (n % i == 0) {
                factors[facCnt].cnt++; n /= i;
            }
            facCnt++;
        }
        if (n == 1) break;
    }
    if (n != 1) {
        factors[facCnt].x = n; factors[facCnt++].cnt = 1;
    }
    for (int i = 0; i < facCnt; ++i) {
        if (i) printf("*");
        printf("%lld", factors[i].x);
        if (factors[i].cnt > 1) printf("^%lld", factors[i].cnt);
    }
    printf("\n");
    return 0;
}
