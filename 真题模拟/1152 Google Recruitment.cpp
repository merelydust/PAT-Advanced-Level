#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2) return true;
    int sqr = int(sqrt(n * 1.0));
    for (int i = 2; i <= sqr; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int l, k; cin >> l >> k;
    string num; cin >> num;
    for (int i = 0; i < l; ++i) {
        string tmp = num.substr(i, k);
        if (isPrime(stoll(tmp))) {
            cout << tmp << endl; return 0;
        }
    }
    cout << "404" << endl;
    return 0;
}
