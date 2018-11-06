#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct stu {
    int id;
    int score[6]; // 开6个 在接收输入的时候就不用对题号做处理了
    int total, perfect;
    bool submit; // 是否有能过编译的提交过决定是否被输出
}students[100010]; // 因为考生考号为5位 0太多了三位一个1

bool cmp(stu a, stu b) {
    if (a.total != b.total) return a.total > b.total;
    else if (a.perfect != b.perfect) return a.perfect > b.perfect;
    return a.id < b.id;
}
int n, k, m;
void init() { // 技巧：单独init
    for (int i = 1; i <= n; ++i) { // It is then assumed that the user id's are 5-digit numbers from 00001 to N
        students[i].id = i;
        students[i].total = students[i].perfect = 0;
        students[i].submit = false;
        memset(students[i].score, -1, sizeof(students[i].score)); // 没提交过的分数为-1 跟提交了但是编译没过分数为0区别
    }
}

int main() {
    scanf("%d %d %d", &n, &k, &m);
    init();
    int full[6];
    for (int i = 1; i <= k; ++i) scanf("%d", &full[i]);
    int uid, pid, grade;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &uid, &pid, &grade);
        if (grade != -1) students[uid].submit = true; // 有能过编译的提交
        if ((grade == -1) && (students[uid].score[pid] == -1)) { // 考生提交了 编译没通过
            students[uid].score[pid] = 0;
        }
        if (grade > students[uid].score[pid]) {
            students[uid].score[pid] = grade;
            if (grade == full[pid]) students[uid].perfect++;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (students[i].score[j] == -1) continue;
            students[i].total += students[i].score[j];
        }
    }
    sort(students+1, students+1+n, cmp);
    int rank = 1;
    for (int i = 1; i <= n && students[i].submit; ++i) {
        if (!students[i].submit) continue;
        if (i > 1 && students[i].total != students[i-1].total) {
            rank = i; // 如果和前一位分数不同 其排名=其在队列中位置
        }
        printf("%d %05d %d", rank, students[i].id, students[i].total);
        for (int j = 1; j <= k; ++j) {
            if (students[i].score[j] == -1) printf(" -");
            else printf(" %d", students[i].score[j]);
        }
        printf("\n");
    }
    return 0;
}
