#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int hashtable[128] = {0}; // 下标为字符ascii码 128h够用 值0-没记录过 值1-记录过了
    string s1, s2; cin >> s1 >> s2;
    int i = 0, j = 0;
    int len1 = s1.length(), len2 = s2.length();
    for (; i < len1; ++i) {
        s1[i] = toupper(s1[i]);
        if (s1[i] != toupper(s2[j])) {
            if (!hashtable[s1[i]]) {
                cout << s1[i]; hashtable[s1[i]] = 1;
            }
        } else ++j;
    }
    cout << endl;
    return 0;
}


/***
 本来想用unordered_set来做的 结果人家是真·乱序而不是保留插入位置= =。
 还发现一个坑 toupper只能暂时转化大写 返回其大写字母的ascii码 ch = toupper(ch) 才行
 把字符转换成大写字母,非字母字符不做出处理
 Anyway 字符hash的初体验~
 ***/
