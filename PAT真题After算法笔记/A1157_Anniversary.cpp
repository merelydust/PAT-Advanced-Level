#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
    return a.substr(6, 13) < b.substr(6, 13);
}

int main() {
    int n, m; string name;
    unordered_map<string, bool> mp;
    vector<string> all, ans;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> name; mp[name] = true;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> name;
        all.push_back(name);
        if (mp[name]) ans.push_back(name);
    }
    printf("%d\n", ans.size());
    if (!ans.empty()) {
        sort(ans.begin(), ans.end(), cmp);
        printf("%s\n", ans[0].c_str());
    }
    else {
        sort(all.begin(), all.end(), cmp);
        printf("%s\n", all[0].c_str());
    }
    return 0;
}
