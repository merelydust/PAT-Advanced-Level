#include <iostream>
#include <string>
using namespace std;

int main() {
    string s; cin >> s;
    int len = s.length();
    int n1 = (len+2)/3, n2 = (len+2)/3, n3 = (len+2)/3;
    n2 += (len+2) % 3;
    for (int i = 0; i < n1; ++i) {
        if (i != n1-1) {
            cout << s[i];
            for (int j = 0; j < n2-2; ++j) cout << ' ';
            cout << s[len-1-i] << endl;
        }
        else {
            for (int j = i; j < i + n2; ++j) cout << s[j];
            cout << endl;
        }
    }
    return 0;
}
