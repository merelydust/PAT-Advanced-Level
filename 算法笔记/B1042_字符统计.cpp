#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s; getline(cin, s);
    int hash[129] = {0};
    for (int i = 0, len = s.length(); i < len; ++i) hash[tolower(s[i])]++;
    int max = -1; char maxch = 'a';
    for (int i = 97; i <= 122; ++i) {
        if (hash[i] > max) {
            max = hash[i]; maxch = i;
        }
    }
    cout << maxch << ' ' << max << endl;
    return 0;
}
