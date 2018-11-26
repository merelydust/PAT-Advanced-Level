// 坑题
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string n1, n2; int tag;
long long radix1, lln1, lln2;

long long transfer(string stringN, long long radix) { // 把字符串从radix进制转成十进制
    long long longN = 0; long long mul = 1, len = stringN.length();
    for (int i = len - 1; i >= 0; --i) {
        if (stringN[i] >= 97) longN += (stringN[i] - 'a' + 10) * mul;
        else longN += (stringN[i] - '0') * mul;
        if (longN < 0) return -1; // 判断溢出
        mul *= radix;
    }
    return longN;
}

long long findLeft(string num) {
    long long digit = -1, len = num.length(), tmp;
    for (int i = 0; i < len; ++i) {
        if (num[i] >= 97) tmp = num[i] - 'a' + 10;
        else tmp = num[i] - '0';
        if (tmp > digit) digit = tmp;
    }
    return digit+1;
}

long long search() { // 二分查找是否存在一个radix使条件成立
    long long left = findLeft(n2), right = max(left, lln1)+1, mid;
    while (left <= right) { // 查询元素必须存在 所以使用<=
        mid = (left + right) / 2; lln2 = transfer(n2, mid);
        if (lln2 == lln1) return mid;
        else if(lln2 < lln1) { // 每位的权重（radix）要增加
            left = mid + 1;
        }
        else if(lln2 > lln1 || lln2 < 0) { // 每位的权重要减小
            right = mid - 1;
        }
    }
    return 0;
}

void swap(long long& a, long long& b) {
    long long tmp = a; a = b; b = tmp;
}

int main() {
    cin >> n1 >> n2 >> tag >> radix1;
    if (tag == 2) swap(n1, n2);
    lln1 = transfer(n1, radix1);
    long long ans = search();
    if (!ans) cout << "Impossible" << endl;
    else cout << ans << endl;
}
