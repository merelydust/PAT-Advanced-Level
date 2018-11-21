/***
 大数运算之高精度数乘低精度数
 建立大数结构体 用数组存储数位 len存储数位长度
 建立哈希表 初始值为0 存储大数数位的个数
 高精度数双倍函数
 ***/
#include <cstdio>
#include <string.h>
using namespace std;

struct bign {
    int digit[50], len;
    bign() {
        len = 0; memset(digit, 0, sizeof(digit));
    }
};

bign assign(char arr[]) {
    bign a; a.len = strlen(arr);
    for (int i = 0; i < a.len; ++i) {
        a.digit[i] = arr[a.len-1-i] - '0';
    }
    return a;
}

bign doubleMul(bign a) {
    bign ans; int carry = 0;
    for (int i = 0; i < a.len; ++i) {
        int tmp = a.digit[i] * 2 + carry;
        ans.digit[i] = tmp % 10; ans.len++; carry = tmp / 10;
    }
    while (carry != 0) {
        ans.digit[ans.len++] = carry % 10; carry /= 10;
    }
    return ans;
}

void printBign(bign a) {
    for (int i = a.len-1; i >= 0; --i) printf("%d", a.digit[i]);
    printf("\n");
}

int main() {
    char str[21] = {0}; scanf("%s", str);
    int hashtable[10] = {0};
    for (int i = 0, len = strlen(str); i < len; ++i) hashtable[str[i] - '0']++;
    bign n = assign(str); bign doubleN = doubleMul(n);
    bool flag = true;
    for (int i = 0; i < doubleN.len; ++i) {
        if (!hashtable[doubleN.digit[i]]) {
            flag = false; break;
        } else hashtable[doubleN.digit[i]]--;
    }
    if (flag) printf("Yes\n");
    else printf("No\n");
    printBign(doubleN);
    return 0;
}
