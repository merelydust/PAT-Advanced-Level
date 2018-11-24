/***
 地球数字转火星数字:a*13^1 + b -> hDigit[a] + digit[b]
 火星数字转地球数字:str1 str2 -> str1对应的索引*13^1 + str对应的索引
 ***/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string digit[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun",
    "jly", "aug", "sep", "oct", "nov", "dec",};
string hDigit[] = {"", "tam", "hel", "maa", "huh", "tou", "kes",
    "hei", "elo", "syy", "lok", "mer", "jou"};

string total[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun",
    "jly", "aug", "sep", "oct", "nov", "dec", "", "tam", "hel", "maa", "huh", "tou", "kes",
    "hei", "elo", "syy", "lok", "mer", "jou"};

string earth2Mars(int n) {
    if (!n) return "tret";
    string ans = ""; bool add = false;
    if (n >= 13) {
        ans += hDigit[n/13]; n %= 13; add = true;
    }
    if (n) {
        if (add) ans += " ";
        ans += digit[n];
    }
    return ans;
}

int mars2Earth(string n) {
    int ans = 0;
    if (n.length() > 4) { // 如果有两部分 长度一定会大于4
        string s = n.substr(0, n.find(" "));
        for (int i = 1; i <= 12; ++i) {
            if (hDigit[i] == s) {
                ans += 13 * i; break;
            }
        }
        n.erase(0, n.find(" ")+1);
    }
    for (int i = 0; i <= 25; ++i) {
        if (total[i] == n) {
            if (i <= 12) ans += i;
            else ans += (i-13) * 13;
        }
    }
    return ans;
}

int main() {
    int N; cin >> N; string tmp;
    getchar(); // 吸收换行符
    while (N--) {
        getline(cin, tmp);
        if (isdigit(tmp[0])) cout << earth2Mars(stoi(tmp)) << endl;
        else cout << mars2Earth(tmp) << endl;
    }
    return 0;
}
