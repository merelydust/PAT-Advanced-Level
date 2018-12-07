#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    const int maxn = 110; int arr[maxn];
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &arr[i]);
    int w1 = -1, w2 = -1; // 两狼编号
    for (int i = 1; i <= n; ++i) {
        if (w1 != -1) break;
        for (int j = 1; j <= n; ++j) { // 枚举两狼为i j
            if (i == j) continue;
            int wliar = 0, hliar = 0; // 必须只有一狼一人撒谎
            for (int k = 1; k <= n; ++k) { // 枚举判定
                if (arr[k] < 0) { // 对狼的判定
                    if (abs(arr[k]) != i && abs(arr[k]) != j) { // 说谎了
                        if (k == i || k == j) wliar++; // 说谎的是狼
                        else hliar++;
                    }
                }
                else { // 对人的判定
                    if (arr[k] == i || arr[k] == j) { // 说谎了
                        if (k == i || k == j) wliar++;
                        else hliar++;
                    }
                }
            }
            if (wliar == 1 && hliar == 1) {
                w1 = i; w2 = j; break;
            }
        }
    }
    if (w1 == -1) printf("No Solution\n");
    else printf("%d %d\n", w1, w2);
    return 0;
}

/***
 九月考乙级的时候被这道题搞的心态崩了 一直没敢回头看
 现在模拟九月甲级 20来分钟写完一遍AC
 真是 轻舟已过万重山～
 变强的感觉真好～
 ***/
