#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    int owner[128] = {0};
    bool enough = true;
    int miss = 0, extra = 0;
    string s1, s2; cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); ++i) owner[s1[i]]++;
    for (int i = 0; i < s2.length(); ++i) {
        owner[s2[i]]--;
        if (owner[s2[i]] < 0) {
            enough = false; miss++;
        }
    }
    if (!enough) printf("No %d\n", miss);
    else {
        for (int i = 0; i < 128; ++i) extra += owner[i];
        printf("Yes %d\n", extra);
    }
    return 0;
}
