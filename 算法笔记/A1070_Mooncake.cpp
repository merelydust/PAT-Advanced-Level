#include <cstdio>
#include <algorithm>
using namespace std;

struct moon {
    double inventory, totalp, price;
}cakes[1010];

bool cmp(moon a, moon b) {
    return a.price > b.price;
}

int main() {
    int n, d; scanf("%d %d", &n, &d);
    for (int i = 0; i < n; ++i) scanf("%lf", &cakes[i].inventory);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &cakes[i].totalp); cakes[i].price = cakes[i].totalp / cakes[i].inventory;
    }
    sort(cakes, cakes+n, cmp);
    double wage = 0.0;
    for (int i = 0; i < n && d; ++i) {
        if (d >= cakes[i].inventory) {
            wage += cakes[i].totalp; d -= cakes[i].inventory;
        }
        else {
            wage += cakes[i].price * d; d = 0;
        }
    }
    printf("%.2f\n", wage);
    return 0;
}
