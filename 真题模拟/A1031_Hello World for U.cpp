#include <iostream>
#include <string>
using namespace std;

int main() {
    string s; cin >> s;
    int len = s.length(); int n = len + 2;
    int n1 = n/3, n2 = n/3, n3 = n/3; n2 += n % 3;
    int space = n2 - 2;
    for (int i = 0; i < n1-1; ++i) {
        cout << s[i];
        for (int j = 0; j < space; ++j) cout << ' ';
        cout << s[len-1-i] << endl;
    }
    for (int i = n1-1; i < n1+n2-1; ++i) {
        cout << s[i];
    }
    cout << endl;
    return 0;
}
