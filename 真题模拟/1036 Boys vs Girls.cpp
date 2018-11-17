#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct stu {
    string name, id;
    char gender;
    int grade;
};

bool toSmall(stu a, stu b) {
    return a.grade > b.grade;
}

bool toBig(stu a, stu b) {
    return a.grade < b.grade;
}
int main() {
    int n; cin >> n;
    vector<stu> girls; vector<stu> boys;
    stu tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp.name >> tmp.gender >> tmp.id >> tmp.grade;
        if (tmp.gender == 'F') girls.push_back(tmp);
        else boys.push_back(tmp);
    }
    if (!girls.size()) cout << "Absent" << endl;
    else {
        sort(girls.begin(), girls.end(), toSmall); cout << girls[0].name << " " << girls[0].id << endl;
    }
    if (!boys.size()) cout << "Absent" << endl;
    else {
        sort(boys.begin(), boys.end(), toBig); cout << boys[0].name << " " << boys[0].id << endl;
    }
    if (!girls.size() || !boys.size()) cout << "NA" << endl;
    else cout << girls[0].grade - boys[0].grade << endl;
    return 0;
}
