#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s; cin >> s; int not4 = 4 - s.length();
    while (not4--) s = "0"+s;
    int big, small, ans = 0;
    do {
        sort(s.begin(), s.end(), greater<char>()); big = stoi(s);
        sort(s.begin(), s.end()); small = stoi(s);
        ans = big - small; s = to_string(ans);
        not4 = 4 - s.length(); while (not4--) s = "0"+s;
        printf("%04d - %04d = %04d\n", big, small, ans);
    } while (ans && ans != 6174);
    return 0;
}
