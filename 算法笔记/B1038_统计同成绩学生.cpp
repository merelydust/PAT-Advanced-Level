//#include <iostream> // 用这个会超时= =。
#include <cstdio>
using namespace std;

int main() {
    int score[101] = {0};
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int tmp; scanf("%d", &tmp); score[tmp]++;
    }
    int k; scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        int tmp; scanf("%d", &tmp);
        if (i) printf(" ");
        printf("%d", score[tmp]);
    }
    return 0;
}
