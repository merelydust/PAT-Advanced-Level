#include <iostream>
#include <string>
using namespace std;

int sum(int arr[], int n) {
    int ans = 0;
    for (int i = 0; i < n; ++i) ans += arr[i];
    return ans;
}

int main() {
    string s; cin >> s;
    int hash[6] = {0}; // 对应PATest
    string meta = "PATest";
    for (int i = 0, len = s.length(); i < len; ++i) {
        if (meta.find(s[i]) != string::npos) hash[meta.find(s[i])]++;
    }
    while (sum(hash, 6)) {
        for (int i = 0; i < 6; ++i) {
            if (hash[i]) {
                cout << meta[i]; hash[i]--;
            }
        }
    }
    cout << endl;
    return 0;
}
