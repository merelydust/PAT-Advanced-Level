// 核心思想：尽量在便宜的加油站充钱
#include <cstdio>
#include <algorithm>
using namespace std;

struct station {
    double distance, price;
}stations[510];

bool cmp(station a, station b) {
    return a.distance < b.distance;
}

int main() {
    double cap, aimDistance, unitRun; int n;
    scanf("%lf %lf %lf %d", &cap, &aimDistance, &unitRun, &n);
    double FULLRUN = cap * unitRun;
    station tmp; tmp.distance = aimDistance; tmp.price = 0;
    stations[n] = tmp; // 把终点也看作一个加油站
    for (int i = 0; i < n; ++i) scanf("%lf %lf", &stations[i].price, &stations[i].distance);
    sort(stations, stations+n+1, cmp);
    if (stations[0].distance) { // 如果出生点没有充钱的地方
        printf("The maximum travel distance = 0.00\n"); return 0;
    }
    int now = 0; // 当前所在加油站编号
    double money = 0, gas = 0;
    while (now < n) { // 每次循环都选择前方加油站里最便宜的加油站
        // within FULLRAN 找到第一个油价低于当前加油站的加油站 如果没有 就高个里挑最矮
        int minPriceIndex = -1; double minPrice = 100000;
        for (int i = now+1; i <= n && stations[i].distance-stations[now].distance <= FULLRUN; ++i) {
            if (stations[i].price < minPrice) {
                minPrice = stations[i].price; minPriceIndex = i; // 高个里挑最矮
                if (minPrice < stations[now].price) break; // 最好是比now还矮的矮个 找到就去充钱
            }
        }
        if (minPriceIndex == -1) break; // FULLRANK内找不到续命的加油站 退出循环
        // 能找到 算钱
        double needGas = (stations[minPriceIndex].distance - stations[now].distance) / unitRun;
        if (minPrice < stations[now].price) { // 如果下一轮最便宜的比now还便宜 这站充enough的钱就行（涵盖了终点的情况 终点的price是0 是最低的）
            if (gas < needGas){
                money += (needGas - gas) * stations[now].price;
                gas = 0; // 到达下一站 正好耗尽gas
            } else gas -= needGas;
        }
        else { // 下一轮最便宜的比now贵 now加满油
            money += (cap - gas) * stations[now].price;
            gas = cap - needGas; // 到达下一站后剩下的油
        }
        now = minPriceIndex; // 到达下一站 进入下一轮循环
    }
    if (now == n) printf("%.2lf\n", money);
    else printf("The maximum travel distance = %.2lf\n", stations[now].distance + FULLRUN);
    return 0;
}
