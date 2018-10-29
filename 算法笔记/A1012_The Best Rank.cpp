#include <iostream>
#include <algorithm>
using namespace std;

int ranks[1000000][4] = {0}; // 空间换时间 为了高效索引；按优先级存储 ranka rankc rankm ranke
int subjectindex;
char subject[4] = {'A', 'C', 'M', 'E'};

struct stu {
    int id;
    int grade[4]; // 也按优先级存储
};

bool cmp(stu a, stu b) {
    return a.grade[subjectindex] > b.grade[subjectindex];
}

int main() {
    int n, m; cin >> n >> m;
    stu students[n];
    for (int i = 0; i < n; ++i) {
        int total = 0;
        cin >> students[i].id;
        for (int j = 1; j < 4; ++j) {
            cin >> students[i].grade[j]; total += students[i].grade[j];
        }
        students[i].grade[0] = total; // 大家平均数的分母都是4 取分子就行了
    }
    
    for (subjectindex = 0; subjectindex < 4; ++subjectindex) { // 填ranks
        sort(students, students+n, cmp);
        int rank = 1, premark = students[0].grade[subjectindex];
        for (int j = 0; j < n; ++j) {
            if (students[j].grade[subjectindex] != premark) {
                rank = j + 1;
                premark = students[j].grade[subjectindex];
            }
            ranks[students[j].id][subjectindex] = rank;
        }
    }
    
    for (int i = 0; i < m; ++i) {
        int tmp; cin >> tmp;
        if (!ranks[tmp][0]) cout << "N/A" << endl;
        else {
            int minindex = 0;
            for (int j = 0; j < 4; ++j) {
                if (ranks[tmp][j] < ranks[tmp][minindex]) minindex = j;
            }
            cout << ranks[tmp][minindex] << ' ' << subject[minindex] << endl;
        }
    }
    return 0;
}
