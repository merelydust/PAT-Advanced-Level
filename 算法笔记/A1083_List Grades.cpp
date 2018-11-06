#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct stu {
    string name, id;
    int grade;
};

bool cmp(stu a, stu b) {
    return a.grade < b.grade;
}

int main() {
    int n; cin >> n;
    vector<stu> students;
    stu tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp.name >> tmp.id >> tmp.grade;
        students.push_back(tmp);
    }
    int grade1, grade2; cin >> grade1 >> grade2;
    sort(students.begin(), students.end(), cmp);
    bool find = false;
    for (int i = n-1; i >= 0; --i) {
        if (students[i].grade < grade1) break;
        if (students[i].grade >= grade1 && students[i].grade <= grade2) {
            cout << students[i].name << ' ' << students[i].id << endl;
            find = true;
        }
    }
    if (!find) cout << "NONE" << endl;
    return 0;
}
