#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define MAX_NUM 9223372036854775807
string n1, n2; int tag;
long long radix1;
unsigned long long lln1, lln2;

unsigned long long transfer(string stringN,   unsigned long long radix) { // 把字符串从radix进制转成十进制
    unsigned long long longN = 0;   unsigned long long mul = 1;unsigned long len = stringN.length();
    for (long i = len - 1; i >= 0; --i) {
        if (stringN[i] >= 'a') longN += (stringN[i] - 'a' + 10) * mul;
        else longN += (stringN[i] - '0') * mul;
        if (longN >= MAX_NUM) return MAX_NUM; // 判断溢出
        mul *= radix;
    }
    return longN;
}

unsigned long long findLeft(string num) {
    unsigned long long digit = 0, len = num.length(), tmp;
    for (int i = 0; i < len; ++i) {
        if (num[i] >= 'a') tmp = num[i] - 'a' + 10;
        else tmp = num[i] - '0';
        if (tmp > digit) digit = tmp;
    }
    return digit+1;
}

unsigned long long search() { // 二分查找是否存在一个radix使条件成立
    unsigned long long left = findLeft(n2), right = max(left, lln1)+1, mid;
    if (lln1 == MAX_NUM) return 0;
    while (left <= right) { // 查询元素必须存在 所以使用<=
        mid = (left + right) / 2; lln2 = transfer(n2, mid);
        if (lln2 == lln1) return mid;
        else if(lln2 < lln1) { // 每位的权重（radix）要增加
            left = mid + 1;
        }
        else if(lln2 > lln1 || lln2 >= MAX_NUM) { // 每位的权重要减小
            right = mid - 1;
        }
    }
    return 0;
}

void swap(  unsigned long long& a,   unsigned long long& b) {
    unsigned long long tmp = a; a = b; b = tmp;
}

int main() {
    cin >> n1 >> n2 >> tag >> radix1;
    if (n1.compare(n2) == 0){
        cout << radix1 << endl;
        return 0;
    }
    if (radix1 ==1 || radix1==0){
        cout << "Impossible" << endl;
        return 0;
    }
    if (tag == 2) swap(n1, n2);
    lln1 = transfer(n1, radix1);
    unsigned long long ans = search();
    if (!ans) cout << "Impossible" << endl;
    else cout << ans << endl;
}
