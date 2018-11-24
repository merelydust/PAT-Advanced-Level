/***
 科学计数法 最后输出的形式时 0.x * 10^x
 base和exp都相同时输出YES 否则输出NO
 输入数据小数点前可能会有前导0 erase掉
 -> 如果删成了.xxx 指针从小数点往后找第一个非0数字 每移动一位pow--
 -> 如果移到最后都没找到非0 说明这个数字就是0 base=0 pow=0
 -> 如果删成了ddd.xxx 指针从小数点往前移到d前面 每移动一位pow++
 ***/
#include <iostream>
#include <string>
using namespace std;

int n; // 有效位数
string deal(string s, int& e) {
    int k = 0; // s的下标
    while(s.length() > 0 && s[0] == '0') s.erase(0, 1);
    if (s[0] == '.') {
        s.erase(0, 1);
        while (s.length() > 0 && s[0] == '0') {
            s.erase(0, 1); e--;
        }
    }
    else {
        while (s[k] != '.'  && k < s.length()) {
            ++k; ++e;
        }
        if (k < s.length()) s.erase(k, 1); // 碰到了小数点 删除
    }
    if (s.length() == 0) e = 0;
    int num = 0; k = 0;
    string res;
    while (num < n) {
        if (k < s.length()) res += s[k++];
        else res += '0';
        num++;
    }
    return res;
}

int main() {
    string s1, s2, s3, s4;
    cin >> n >> s1 >> s2;
    int e1 = 0, e2 = 0;
    s3 = deal(s1, e1); s4 = deal(s2, e2);
    if (s3 == s4 && e1 == e2) cout << "YES 0." << s3 << "*10^" << e1 << endl;
    else cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2 << endl;
    return 0;
}
