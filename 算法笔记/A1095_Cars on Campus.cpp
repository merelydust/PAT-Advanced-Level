#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

struct car {
    char id[8];
    int time;
    char status[4];
}all[10010], valid[10010];

int timetoint(int hh, int mm, int ss) {
    return hh * 3600 + mm * 60 + ss;
}

bool cmpByIdAndTime(car a, car b) {
    if (strcmp(a.id, b.id)) return strcmp(a.id, b.id) < 0;
    return a.time < b.time;
}

bool cmpByTime(car a, car b) {
    return a.time < b.time;
}

int main() {
    int n, k, hh, mm, ss;
    map<string, int> parktime; // car->staytime
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%s %d:%d:%d %s", all[i].id, &hh, &mm, &ss, all[i].status);
        all[i].time = timetoint(hh, mm, ss);
    }
    sort(all, all+n, cmpByIdAndTime);
    int maxtime = -1; int validnum = 0;
    for (int i = 0; i < n-1; ++i) {
        if (!strcmp(all[i].id, all[i+1].id) &&
            !strcmp(all[i].status, "in") &&
            !strcmp(all[i+1].status, "out")) {
            valid[validnum++] = all[i]; valid[validnum++] = all[i+1];
            int intime = all[i+1].time - all[i].time;
            parktime[all[i].id] += intime;
            maxtime = max(maxtime, parktime[all[i].id]);
            }
    }
    sort(valid, valid+validnum, cmpByTime);
    int now = 0, numcar = 0;
    for (int i = 0; i < k; ++i) {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int time = timetoint(hh, mm, ss);
        while (now < validnum && valid[now].time <= time) {
            if (!strcmp(valid[now].status, "in")) numcar++;
            else numcar--;
            now++;
        }
        printf("%d\n", numcar);
    }
    map<string, int>::iterator it;
    for (it = parktime.begin(); it != parktime.end(); ++it) {
        if (it->second == maxtime) printf("%s ", it->first.c_str());
    }
    printf("%02d:%02d:%02d\n", maxtime/3600, maxtime % 3600 / 60, maxtime % 60);
    return 0;
}
