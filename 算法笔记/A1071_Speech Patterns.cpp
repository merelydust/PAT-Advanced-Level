/***
 单词之间以非alnum为界限
 词频统计 map<string, int>
 ***/
#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

int main() {
    string s; getline(cin, s);
    map<string, int> m;
    int index = 0, len = s.length();
    while (index < len) {
        if (!isalnum(s[index])) {
            ++index; continue;
        }
        string word = "";
        while (isalnum(s[index])) word += tolower(s[index++]);
        m[word]++;
    }
    map<string, int>::iterator it = m.begin();
    string ans = ""; int cnt = 0;
    for (; it != m.end(); ++it) {
        if (it->second > cnt) {
            cnt = it->second; ans = it->first;
        }
    }
    cout << ans << " " << cnt << endl;
    return 0;
}
    
