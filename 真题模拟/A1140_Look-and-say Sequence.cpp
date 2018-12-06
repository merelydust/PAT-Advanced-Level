// 从前往后读 当前字符与前一个字符pre相同的话累加cnt
// 否则 之前字符串的后面加上to_string(cnt) cnt清零 pre等于现在的字符
// 继续往后读 直到读到原来字符串的末尾
// 以上操作做n次
#include <iostream>
#include <string>
using namespace std;

int main() {
    string d; int n; cin >> d >> n;
    n--;
    while (n--) {
        string newd = ""; int i = 0;
        while (i < d.length()) {
            char add = d[i];
            newd += add; int cnt = 1;
            while (d[++i] == add && i < d.length()) cnt++;
            newd += to_string(cnt);
        }
        d = newd;
    }
    cout << d << endl;
    return 0;
}

/***
 没读清楚题目多循环了一轮
 以为是自己写错了换了三种方法实现
 二十分钟能AC的题折腾了快五十分钟md
 
 逐！字！逐！句！读！题！目！
 ***/
