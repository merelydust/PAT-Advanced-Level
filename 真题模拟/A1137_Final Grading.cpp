/***
 P-做了大作业的学生人数 M-参加了期中考的学生人数 N-参加了期末考的学生人数 <10000
 接下来p行大作业成绩  格式：ID score
 m行期中考成绩
 n行期末考成绩
 
 根据最终成绩降序输出合法学生
 id 大作业成绩 期中成绩 期末成绩 最终成绩（四舍五入到整数）
 如果某个成绩不存在 输出-1
 如果有同分 按ID升序
 ***/

#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct stu {
    string name;
    int gp, gm, gf, G;
    int valid;
    stu() {
        gp = gm = gf = G = -1;
        valid = 0;
    }
};

bool cmp(stu a, stu b) {
    if (a.valid != b.valid) return a.valid > b.valid;
    if (a.G != b.G) return a.G > b.G;
    return a.name < b.name;
}

int round(double num) { // 四舍五入
    if (int(num+0.5) > int(num)) return int(num)+1;
    else return int(num);
}

int isValid(stu& a) { // 加引用把最终成绩算了
    if (a.gm > a.gf) a.G = round(a.gm * 0.4 + a.gf * 0.6);
    else a.G = a.gf;
    if (a.gp >= 200 && a.G >= 60) return 1;
    return 0;
}

int main() {
    int p, m, n; scanf("%d %d %d", &p, &m, &n);
    string name; char tmp[30]; int grade;
    map<string, stu> mp; // 名字对应学生信息
    vector<stu> v;
    for (int i = 0; i < p; ++i) {
        scanf("%s %d", tmp, &grade);
        name = tmp; mp[name].gp = grade;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%s %d", tmp, &grade);
        name = tmp; mp[name].gm = grade;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%s %d", tmp, &grade);
        name = tmp; mp[name].gf = grade;
    }
    map<string, stu>::iterator it = mp.begin();
    for(; it != mp.end(); ++it) {
        (it->second).name = it->first;
        (it->second).valid = isValid(it->second);
        if ((it->second).valid) v.push_back(it->second);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); ++i) {
        printf("%s %d %d %d %d\n", v[i].name.c_str(), v[i].gp, v[i].gm, v[i].gf, v[i].G);
    }
    return 0;
}


/***
 模拟反思:
 1. gf 写成 gm 找了半小时bug:) 这种变量很多的题目要边写代码边写注释！写注释！写注释！(泣
 2. 忘记删掉调试输出 答案错误 懵逼了五分钟。。删调试！删调试！删调试！
 
 这两个一解决马上AC～细心一点～！
 ***/
