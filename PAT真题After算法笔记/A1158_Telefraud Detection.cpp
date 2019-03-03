#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1010, base = 10000;
int k, n, m;
unordered_map<int, bool> mp; // whether call back
int father[maxn];
unordered_set<int> shortCnt[maxn];
map<int, vector<int> > gangs;

void init() {
    for (int i = 1; i <= n; ++i) father[i] = i;
}

int findFather(int x) {
    int a = x;
    while (father[x] != x) x = father[x];
    while (a != x) {
        int b = a;
        a = father[a];
        father[b] = x;
    }
    return x;
}

void unionFather(int x, int y) {
    int faX = findFather(x), faY = findFather(y);
    if (faX != faY) {
        x < y ? father[faY] = faX : father[faX] = faY;
    }
}

int main() {
    scanf("%d %d %d", &k, &n, &m);
    init();
    int a, b, time;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &time);
        mp[a*base + b] = true; // call back
        if (time > 5) continue;
        shortCnt[a].insert(b);
    }
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
        if (shortCnt[i].size() > k) {
            int notBack = 0;
            for (auto it = shortCnt[i].begin(); it != shortCnt[i].end(); ++it) {
                if (!mp[(*it)* base + i]) ++notBack;
            }
            if (double(notBack) / double(shortCnt[i].size()) > 0.8) v.push_back(i);
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v.size(); ++j) {
            if (i == j) continue;
            if (mp[v[i]*base + v[j]] && mp[v[j]*base + v[i]]) unionFather(v[i], v[j]);
        }
    }
    for (int i = 0; i < v.size(); ++i) gangs[findFather(v[i])].push_back(v[i]);
    if (v.empty()) printf("None\n");
    else {
        for (auto it = gangs.begin(); it != gangs.end(); ++it) {
            vector<int>& vec = it->second;
            sort(vec.begin(), vec.end());
            for (int i = 0; i < vec.size(); ++i) {
                printf("%d", vec[i]);
                if (i != vec.size()-1) printf(" ");
                else printf("\n");
            }
        }
    }
    return 0;
}
