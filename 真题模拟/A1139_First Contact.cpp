#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int maxn = 10000;
unordered_map<int, bool> arr; // 标记一段关系（同性异性都有）是否存在
struct node {
    int a, b;
};

bool cmp(node x, node y) {
    return x.a != y.a ? x.a < y.a : x.b < y.b;
}

int main() {
    int n, m, k;
    scanf("%d %d", &n, &m);
    vector<int> v[maxn]; // 只放同性朋友
    for (int i = 0; i < m; ++i) {
        string a, b; cin >> a >> b;
        int tmpa = abs(stoi(a)), tmpb = abs(stoi(b));
        if (a.length() == b.length()) { // 每个人只能找自己的同性朋友传小纸条
            v[tmpa].push_back(tmpb); v[tmpb].push_back(tmpa);
        }
        arr[tmpa*maxn+tmpb] = arr[tmpb*maxn+tmpa] = true; // 这样就能在一个关键字里涵盖两个人的信息了
    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        int c, d; cin >> c >> d;
        c = abs(c); d = abs(d);
        vector<node> ans;
        for (int j = 0; j < v[c].size(); ++j) {
            for (int k = 0; k < v[d].size(); ++k) {
                if (v[c][j] == d || v[d][k] == c) continue;
                if (arr[v[c][j]*maxn + v[d][k]]) ans.push_back(node{v[c][j], v[d][k]});
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", int(ans.size()));
        for (int j = 0; j < ans.size(); ++j) printf("%04d %04d\n", ans[j].a, ans[j].b);
    }
    return 0;
}
