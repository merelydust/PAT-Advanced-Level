#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string code[4];
    for (int i = 0; i < 4; ++i) cin >> code[i];
    string week[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int len1 = code[0].length();
    int len2 = code[1].length();
    int i;
    for (i = 0; i < len1 && i < len2; ++i) {
        if (code[0][i] == code[1][i] && code[0][i] >= 'A' && code[0][i] <= 'G') {
            cout << week[code[0][i]-'A'] << ' ';
            break;
        }
    }
    for (i++; i < len1 && i < len2; ++i) {
        if (code[0][i] == code[1][i]) {
            if (isdigit(code[0][i])) {
                printf("%02d:", code[0][i]-'0');
                break;
            }
            else if (code[0][i] >= 'A' && code[0][i] <= 'N') {
                printf("%02d:", code[0][i]-'A'+10);
                break;
            }
        }
    }
    int len3 = code[2].length();
    int len4 = code[3].length();
    for (i = 0; i < len3 && i < len4; ++i) {
        if (code[2][i] == code[3][i]) {
            if (isalpha(code[2][i])) {
                printf("%02d\n", i);
                break;
            }
        }
    }
    return 0;
}
