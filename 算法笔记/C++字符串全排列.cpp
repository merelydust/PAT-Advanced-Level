//输入一个字符串 输出该字符串字符的全排序 无顺序要求

#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100; int n;
char arr[maxn] = {0}; int hashtable[128] = {0};
char ans[maxn] = {0};

void generateP(int index) {
    if (index == n) {
        for (int i = 0; i < n; ++i) printf("%c", ans[i]);
        printf("\n"); return;
    }
    for (int i = 0; i < n; ++i) {
        if (!hashtable[arr[i]]) {
            ans[index] = arr[i]; hashtable[arr[i]] = 1;
            generateP(index+1);
            hashtable[arr[i]] = 0;
        }
    }
}

int main() {
    scanf("%s", arr);
    n = strlen(arr);
    generateP(0);
    return 0;
}
