#include <iostream>
#include <cstdio>
using namespace std;

struct money {
    int gall, sick, knut;
};

bool isbigger(money a, money b) {
    if (a.gall != b.gall) return a.gall > b.gall;
    if (a.sick != b. sick ) return a.sick > b.sick;
    return a.knut > b.knut;
}

int main() {
    money m[3];
    for (int i = 0; i < 2; ++i) scanf("%d.%d.%d", &m[i].gall, &m[i].sick, &m[i].knut);
    bool add = false;
    if (isbigger(m[0], m[1])) {
        money tmp = m[0];
        m[0] = m[1];
        m[1] = tmp;
        add = true;
    }
    if (m[1].knut >= m[0].knut) m[2].knut = m[1].knut - m[0].knut;
    else {
        m[1].sick--;
        m[2].knut = m[1].knut + 29 - m[0].knut;
    }
    if (m[1].sick >= m[0].sick) m[2].sick = m[1].sick - m[0].sick;
    else {
        m[1].gall--;
        m[2].sick = m[1].sick + 17 - m[0].sick;
    }
    m[2].gall = m[1].gall - m[0].gall;
    if (add) cout << '-';
    cout << m[2].gall << '.' << m[2].sick << '.' << m[2].knut << endl;
    return 0;
}
