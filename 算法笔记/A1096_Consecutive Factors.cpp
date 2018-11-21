/***
 从1～sqr遍历数字 寻找最长的一组连续数字 都能被n整除
 当i～j长度>maxLen的时候 更新 start= i maxLen = j-i
 ***/

#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    long long n; scanf("%lld", &n);
    long long sqr = (long long)(sqrt(1.0 * n));
    long long start = 0, maxLen = 0;
    for (long long i = 2; i <= sqr; ++i) {
        long long tmp = 1, j = i;
        while (true) {
            tmp *= j;
            if (n % tmp) break;
            if (j - i + 1 > maxLen) {
                start = i; maxLen = j - i + 1;
            }
            ++j;
        }
    }
    if (maxLen == 0) printf("1\n%lld", n);
    else {
        printf("%lld\n", maxLen);
        for (long long i = 0; i < maxLen; ++i) {
            if (i) printf("*");
            printf("%lld", start+i);
        }
    }
    return 0;
}
