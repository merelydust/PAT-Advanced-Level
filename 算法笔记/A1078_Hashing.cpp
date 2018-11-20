/***
 数字key的index = key % TSize
 msize如果不是质数 把它变成离它最近的质数
 如果index > msize或者index位已经被占用 输出 “-” 否则 输出index
 ***/

#include <cstdio>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    int sqr = int(sqrt(1.0 * n));
    for (int i = 2; i <= sqr; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int msize, n, tmp; scanf("%d %d", &msize, &n);
    while (!isPrime(msize)) msize++;
    int hashtable[10010] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tmp); int index = tmp % msize;
        if (i) printf(" ");
        if (!hashtable[index]) {
            printf("%d", index); hashtable[index] = 1;
        }
        else { // 处理冲突
            int step = 1, cpyIndex = index; bool find = false;
            while (step < msize) { // / 正向二次方探查 如果step在msize里找不到 比它大的更找不到
                cpyIndex = (index + step * step) % msize;
                if (!hashtable[cpyIndex]) {
                    printf("%d", cpyIndex); hashtable[cpyIndex] = 1; find = true; break;
                }
                step++;
            }
            if (!find) printf("-");
        }
    }
    printf("\n");
    return 0;
}
