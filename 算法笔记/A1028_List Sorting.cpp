/***
 vector<stu> students;
 students.resize(n);
 ***/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int c;
struct stu {
    string inf[3]; // 按序存储id name grade
};

bool cmp(stu a, stu b) {
    if (a.inf[c] != b.inf[c]) return a.inf[c] < b.inf[c];
    else return a.inf[0] < b.inf[0];
}

int main() {
    int n = 0; scanf("%d %d", &n, &c);
    c--; // 因为索引 所以-1
//    stu students[n]; 这样写会导致段错误
    vector<stu> students;
    students.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            char tmp[10]; scanf("%s", tmp);
            students[i].inf[j] = tmp;
        }
    }
    if (n == 1) {
        for (int j = 0; j < 3; ++j) {
            if (j) printf(" ");
            printf("%s", students[0].inf[j].c_str());
        }
        prinf("\n"); return 0;
    }
    sort(students, students+n, cmp);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (j) printf(" ");
            printf("%s", students[i].inf[j].c_str());
        }
        printf("\n");
    }
    return 0;
}
