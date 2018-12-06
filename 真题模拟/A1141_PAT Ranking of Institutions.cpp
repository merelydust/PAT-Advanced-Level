/***
 参赛选手人数n(<10^5) 接下来n行
 字符串id(首位代表登记BAT) score 字符串school
 id是唯一的
 
 输出学校总数 第一行
 接下来升序输出学校排名 rank school tws 该校学生人数
 tws = int(ScoreB/1.5 + ScoreA + ScoreT*1.5)
 ScoreX is the total score of the testees belong to this institution on level X
 按照tws升序排列 如果同分则排名相同 根据学生人数升序 如果还tie 按照校名字典序排列
 ***/

#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

struct school {
    string name;
    int stuNum, tws;
    double scoreB, scoreA, scoreT;
    school() {
        scoreB = scoreA = scoreT = 0;
        stuNum = 0;
    }
};

bool cmp(school a, school b) {
    if (a.tws != b.tws) return a.tws > b.tws;
    else if (a.stuNum != b.stuNum) return a.stuNum < b.stuNum;
    else return a.name < b.name;
}

vector<school> v;
map<string, school> m;

int main() {
    int n; scanf("%d", &n);
    string id, sch; double score;
    while (n--) {
        cin >> id >> score >> sch;
        for (int i = 0; i < sch.length(); ++i) sch[i] = tolower(sch[i]);
        char level = id[0];
        if (level == 'B') m[sch].scoreB += score;
        else if (level == 'A') m[sch].scoreA += score;
        else if (level == 'T') m[sch].scoreT += score;
        m[sch].stuNum++;
    }
    map<string, school>::iterator it = m.begin();
    for (; it != m.end(); ++it) {
        (it->second).name = it->first;
        (it->second).tws = int((it->second).scoreB/1.5 + (it->second).scoreA + (it->second).scoreT*1.5);
        v.push_back(it->second);
    }
    cout << v.size() << endl;
    sort(v.begin(), v.end(), cmp);
    int rank = 1, pre = v[0].tws;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].tws != pre) {
            rank = i+1; pre = v[i].tws;
        }
        printf("%d %s %d %d\n", rank, v[i].name.c_str(), v[i].tws, v[i].stuNum);
    }
    return 0;
}
