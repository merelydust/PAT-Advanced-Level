#include <iostream>
#include <string>
using namespace std;

int main() {
    string num; cin >> num;
    int sum = 0;
    for (int i = 0; i < num.length(); ++i) sum += num[i] - '0';
    string arr[] = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
    };
    string ssum = to_string(sum);
    for (int i = 0; i < ssum.length(); ++i) {
        if (i) cout << ' ';
        cout << arr[ssum[i]-'0'];
    }
    cout << endl;
    return 0;
}
