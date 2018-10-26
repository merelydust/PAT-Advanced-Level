#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

string lcs(string text, string aim) { // 寻找最长公共后缀
    if (text == "" || aim == "") return "";
    int len1 = text.length(), len2 = aim.length();
    string kuchi = "";
    int minlen = len1 < len2 ? len1 : len2;
    reverse(text.begin(), text.end()); // 反转以后就可以从前往后做比较 比较方便
    reverse(aim.begin(), aim.end());
    for (int i = 0; i < minlen; ++i) {
        if (text[i] == aim[i]) kuchi += aim[i];
        else break;
    }
    reverse(kuchi.begin(), kuchi.end());
    return kuchi;
}

int main() {
    int n; cin >> n;
    getchar(); // 把n后面的换行符吃掉
    string tmp1; getline(cin, tmp1); n--;
    while (n--) {
        string tmp2; getline(cin, tmp2);
        tmp1 = lcs(tmp2, tmp1);
    }
    if (tmp1[0] == ' ') tmp1.erase(0); // kuchi字符串第一位可能是空格
    if (tmp1 != "") cout << tmp1 << endl;
    else cout << "nai" << endl;
    return 0;
}
