#include <iostream>
#include <cstdio>
using namespace std;

struct money {
    int gall, sick, knut;
};

int main() {
    money m[2];
    for (int i = 0; i < 2; ++i) {
        scanf("%d.%d.%d", &m[i].gall, &m[i].sick, &m[i].knut);
    }
    bool add = false;
    if (m[0].knut + m[1].knut >= 29) {
        m[1].knut = (m[0].knut + m[1].knut) % 29;
        add = true;
    } else m[1].knut = m[0].knut + m[1].knut;
    int tmp = m[0].sick + m[1].sick;
    if (add) {
       tmp++; add = false;
    }
    if (tmp >= 17) {
        m[1].sick = tmp % 17;
        add = true;
    } else m[1].sick = tmp;
    m[1].gall = m[0].gall + m[1].gall;
    if (add) m[1].gall++;
    printf("%d.%d.%d\n", m[1].gall, m[1].sick, m[1].knut);
    return 0;
}
