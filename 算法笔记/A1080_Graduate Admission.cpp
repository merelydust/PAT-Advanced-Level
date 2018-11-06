#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct stu {
    int id;
    double g1, g2, g3;
    int choice[5];
};

bool cmp(stu a, stu b) {
    if (a.g3 != b.g3) return a.g3 > b.g3;
    return a.g1 > b.g1;
}
bool cmpId(stu a, stu b) {
    return a.id < b.id;
}

int main() {
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    int schoolsLimit[100]; vector<stu> inschool[100];
    vector<stu> students; stu tmp;
    for (int i = 0; i < m; ++i) scanf("%d", &schoolsLimit[i]);
    for (int i = 0; i < n; ++i) {
        tmp.id = i;
        scanf("%lf %lf", &tmp.g1, &tmp.g2);
        tmp.g3 = (tmp.g1 + tmp.g2) / 2;
        for (int j = 0; j < k; ++j) scanf("%d", &tmp.choice[j]);
        students.push_back(tmp);
    }
    
    sort(students.begin(), students.end(), cmp); // rank靠前的先安排
    for (int i = 0; i < n; ++i) {
        // printf("%d\n", students[i].id);
        for (int j = 0; j < k; ++j) {
            int want = students[i].choice[j];
            if (inschool[want].size() < schoolsLimit[want]) { // 想去的学校还有名额
                inschool[want].push_back(students[i]); break;
            }
            else {
                if (inschool[want].back().g3 == students[i].g3 && inschool[want].back().g1 == students[i].g1) { // 没名额了 但是该考生和该校录取的最后一名高考总分相同
                    inschool[want].push_back(students[i]); break;
                }
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        if (inschool[i].size() == 0) printf("\n");
        else {
            sort(inschool[i].begin(), inschool[i].end(), cmpId);
            for (int j = 0; j < inschool[i].size(); ++j) {
                if (j) printf(" ");
                printf("%d", inschool[i][j].id);
            }
            printf("\n");
        }
    }
    return 0;
}
