/***
 while n不是回文数 做操作 step++
 step > maxstep 退出循环
 ***/
#include <cstdio>
#include <string.h>
using namespace std;

struct bign {
    int digit[1000], len;
    bign() {
        memset(digit, 0, sizeof(digit)); len = 0;
    }
};

bign change(char str[]) {
    bign a; a.len = strlen(str);
    for (int i = 0; i < a.len; ++i) a.digit[i] = str[a.len-1-i] - '0';
    return a;
}

bign add(bign a, bign b) {
    bign ans; int carry = 0;
    for(int i=0;i<a.len||i< b.len;i++){
        int temp=a.digit[i]+b.digit[i]+carry;
        ans.digit[ans.len++]=temp%10;
        carry=temp/10;
    }
    if (carry != 0) ans.digit[ans.len++] = carry;
    return ans;
}

void printBigN(bign a) {
    for (int i = a.len-1; i >= 0; --i) printf("%d", a.digit[i]);
    printf("\n");
}

bool isPalin(int arr[], int len) {
    if (arr[len-1]==0) return false;
    if (arr[0]==0) return false;
    for (int i = 0, half = len/2; i < half; ++i) {
        if (arr[i] != arr[len-1-i]) return false;
    }
    return true;
}

bign operate(bign a) {
    bign ra; ra.len = a.len;
    for (int i = 0; i < a.len; ++i) ra.digit[i] = a.digit[a.len-1-i];
    return add(a, ra);
}

int main() {
    char tmp[1000] = {0}; int k, step = 0;
    scanf("%s %d", tmp, &k);
    bign a = change(tmp);
    while (!isPalin(a.digit, a.len) && step < k) {
        a = operate(a); step++;
    }
    printBigN(a); printf("%d\n", step);
    return 0;
}
