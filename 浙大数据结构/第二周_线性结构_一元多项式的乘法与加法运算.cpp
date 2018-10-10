#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n1, n2;
    map<int, int, greater<int> > poly;
    map<int, int, greater<int> > mul;
    map<int, int, greater<int> > sum;
    cin >> n1;
    while (n1--) {
        int co, ex;
        cin >> co >> ex;
        poly[ex] = co;
        sum[ex] += co;
    }
    cin >> n2;
    while (n2--) {
        int co, ex;
        cin >> co >> ex;
        // mul
        map<int, int>::iterator it;
        for (it = poly.begin(); it != poly.end(); it++) {
            mul[it->first+ex] += it->second * co;
        }
        sum[ex] += co;
    }
    
    int cnt = 0;
    map<int, int>::iterator it1;
    for (it1 = mul.begin(); it1 != mul.end(); it1++) {
        if (it1->second) {
            if (cnt) cout << ' ';
            cout << it1->second << ' ' << it1->first;
            cnt++;
        }

    }
    if (!cnt) cout << "0 0";
    cout << endl;
    
    map<int, int>::iterator it2;
    cnt = 0;
    for (it2 = sum.begin(); it2 != sum.end(); it2++) {
        if (it2->second) {
            if (cnt) cout << ' ';
            cout << it2->second << ' ' << it2->first;
            cnt++;
        }
    }
    if (!cnt) cout << "0 0";
    cout << endl;
    
    return 0;
}
