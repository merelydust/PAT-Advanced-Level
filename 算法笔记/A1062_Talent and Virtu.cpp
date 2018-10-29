#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct stu {
    string id;
    int vir, tal, total;
    int grade;
};

bool cmp(stu a, stu b) {
    if (a.grade != b.grade) return a.grade < b.grade;
    if (a.total != b.total) return a.total > b.total;
    else if (a.vir != b.vir) return a.vir > b.vir;
    return a.id < b.id;
}

int main() {
    int n, l, h; cin >> n >> l >> h;
    vector<stu> students;
    stu tmp;
    while (n--) {
        cin >> tmp.id >> tmp.vir >> tmp.tal;
        tmp.total = tmp.vir + tmp.tal;
        if (tmp.vir < l || tmp.tal < l) continue;
        if (tmp.vir >= h && tmp.tal >= h) tmp.grade = 1;
        else if (tmp.vir >= h) tmp.grade = 2;
        else if (tmp.vir >= tmp.tal) tmp.grade = 3; // 第一次取了>三个用例没过。。not below >=
        else tmp.grade = 4;
        students.push_back(tmp);
    }
    sort(students.begin(), students.end(), cmp);
    cout << students.size() << endl;
    vector<stu>::iterator it = students.begin();
    for (; it != students.end(); ++it) cout << (*it).id << ' ' << (*it).vir << ' ' << (*it).tal << endl;
    
    return 0;
}
