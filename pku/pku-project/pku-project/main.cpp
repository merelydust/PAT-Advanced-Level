#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int> poly;
    map<int, int> m1;
    map<int, int> m2;
    int ex, co;
    int n1, n2;
    cin >> n1;
    while (n1--) {
        scanf("%d %d", &ex, &co);
        poly[ex] = co;
    }
    cin >> n2;
    while (n2--) {
        scanf("%d %d", &ex, &co);
        map<int, int>::iterator it;
        for (it = poly.begin(); it != poly.end(); it++) {
            m1[it->first + ex] = it->second + co;
        }
        m2[ex] += co;
    }
    map<int, int>::iterator it1;
    int tmpcnt = 0;
    for (it1 = m1.begin(); it1 != m1.end(); it1++) {
        if (tmpcnt) cout << ' ';
        if (it1->second) {
            cout << it1->first << ' ' << it1->second;
            tmpcnt++;
        }
    }
    if (!tmpcnt) cout << "0 0";
    cout << endl;
    map<int, int>::iterator it2;
    tmpcnt = 0;
    for (it2 = m2.begin(); it2 != m2.end(); it2++) {
        if (tmpcnt) cout << ' ';
         if (it1->second) {
             cout << it2->first << ' ' << it2->second;
             tmpcnt++;
         }
        if (!tmpcnt) cout << "0 0";
        cout << endl;
    }
    return 0;
}

