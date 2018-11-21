/***
 高精度数除低精度数
 ***/
#include <cstdio>
#include <string.h>
using namespace std;

struct bign {
    int d[1010], len;
    bign() {
        len = 0; memset(d, 0, sizeof(d));
    }
};

bign assign(char arr[]) {
    bign a; a.len = strlen(arr);
    for (int i = 0; i < a.len; ++i) {
        a.d[i] = arr[a.len-1-i] - '0'; // 数字低位对应数组低位 高位对应高位
    }
    return a;
}

bign div(bign a, int b, int& r) {
    bign ans; ans.len = a.len;
    for (int i = ans.len-1; i >= 0; --i) {
        r = r * 10 + a.d[i];
        if (r < b) ans.d[i] = 0;
        else {
            ans.d[i] = r / b; r %= b;
        }
    }
    while (ans.len-1 > 0 && ans.d[ans.len - 1] == 0) ans.len--;
    return ans;
}

void printBign(bign a) {
    for (int i = a.len-1; i >= 0; --i) printf("%d", a.d[i]);
}

int main() {
    int b, r = 0; char tmp[1010] = {0};
    scanf("%s %d", tmp, &b);
    bign a = assign(tmp);
    printBign(div(a, b, r)); printf(" %d\n", r);
    return 0;
}
