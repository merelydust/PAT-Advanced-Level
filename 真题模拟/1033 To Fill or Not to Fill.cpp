#include <cstdio>
#include <algorithm>
using namespace std;

struct station {
    double price, distance;
}stations[510];

bool cmp(station a, station b) {
    return a.distance < b.distance;
}

int main() {
    double cap, aimDistance, unitRun; int n;
    scanf("%lf %lf %lf %d", &cap, &aimDistance, &unitRun, &n);
    double FULLRUN = cap * unitRun;
    stations[n].price = 0; stations[n].distance = aimDistance;
    for (int i = 0; i < n; ++i) scanf("%lf %lf", &stations[i].price, &stations[i].distance);
    sort(stations, stations+n+1, cmp);
    if (stations[0].distance) {
        printf("The maximum travel distance = 0.00\n"); return 0;
    }
    double money = 0, nowGas = 0, needGas; int now = 0;
    while (now != n) {
        int minPrice = 1000100, minIndex = -1;
        for (int i = now+1; i <= n && stations[i].distance-stations[now].distance <= FULLRUN; ++i) {
            if (stations[i].price < minPrice) {
                minPrice = stations[i].price; minIndex = i;
                if (stations[i].price < stations[now].price) break; // 关键一步
            }
        }
        if (minIndex == -1) {
            printf("The maximum travel distance = %.2f\n", stations[now].distance + FULLRUN);
            return 0;
        }
        needGas = (stations[minIndex].distance - stations[now].distance) / unitRun;
        if (stations[minIndex].price < stations[now].price) {
            if (nowGas < needGas) {
                money += (needGas - nowGas) * stations[now].price; nowGas = 0;
            }
            else nowGas -= needGas;
        }
        else {
            money += (cap - nowGas) * stations[now].price; nowGas = cap - needGas;
        }
        now = minIndex;
    }
    printf("%.2f", money);
    return 0;
}
