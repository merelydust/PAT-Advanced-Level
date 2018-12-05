/***
 大数加法运算 用字符串模拟
 ***/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 1010;
char bign[maxn] = {0};

bool isP(string str) {
    string rs = str; reverse(rs.begin(), rs.end());
    if (rs == str) return true;
    else return false;
}

string addBign(string a, string b) {
    int len = a.length(), carry = 0;
    string ans = "";
    for (int i = 0; i < len; ++i) {
        ans += to_string((a[i]-'0'+b[i]-'0'+carry) % 10);
        carry = (a[i]-'0'+b[i]-'0'+carry) / 10;
    }
    if (carry != 0) ans += to_string(carry);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string s; cin >> s; int cnt = 0;
    while (!isP(s) && cnt < 10) {
        string rs = s; reverse(rs.begin(), rs.end());
        cout << s << " + " << rs << " = ";
        s = addBign(s, rs); cout << s << endl;
        cnt++;
    }
    if (!isP(s)) cout << "Not found in 10 iterations." << endl;
    else cout << s << " is a palindromic number." << endl;
    return 0;
}

/***
 模拟反思:
 一紧张代码风格就变纯c是什么毛病。。越写越难受 最后干脆全部删掉用c++重新来过
 越是紧张越是抱牢C++的大腿呀！！
 涉及字符串必须C++!!!
 I love C++!!!(^_^)v
 ***/
