<<<<<<< HEAD
//// 一眼就看出是括号匹配题的变体--变态复杂版= =
//#include <iostream>
//#include <cstdio>
//#include <string>
//#include <stack>
//#include <map>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//bool cmp(string a, string b) { // 根据通话发生的时间排序
//    return a.substr(a.find('0'), 11) < b.substr(b.find('0'), 11);
//}
//
//int caltime(string a, string b) { // a是开始 b是结束
//    int minutesa = 0, minutesb = 0;
//    int dda = stoi(a.substr(3,2)), ddb = stoi(b.substr(3,2)); // 调试后才加的变量...有人电话打了两天多？？太假了吧
//    if (dda < ddb) minutesb += (ddb - dda) * 24 * 60;
//    string timea = a.substr(6);
//    string timeb = b.substr(6);
//    int hha = stoi(timea.substr(0,2)), hhb = stoi(timeb.substr(0,2));
//    int mma = stoi(timea.substr(3,2)), mmb = stoi(timeb.substr(3,2));
//    minutesa += hha * 60 + mma; minutesb += hhb * 60 + mmb;
//    return minutesb - minutesa;
//}
//int rate[24]; int daymoney = 0;
//double calmoney(string a, string b) {
//    int money = 0;
//    string timea = a.substr(6);
//    string timeb = b.substr(6);
//    int hha = stoi(timea.substr(0,2)), hhb = stoi(timeb.substr(0,2));
//    int mma = stoi(timea.substr(3,2)), mmb = stoi(timeb.substr(3,2));
//    int dda = stoi(a.substr(3,2)), ddb = stoi(b.substr(3,2));
//    if (dda < ddb) {
//        money += calmoney(a, a.substr(0,6)+"23:60");
//        dda++;
//        while (dda < ddb) {
//            dda++; money += daymoney;
//        }
//        hha = 0; mma = 0;
//    }
//    if (hha < hhb) money += rate[hha] * (60-mma);
//    hha++; mma = 0;
//    while (hha < hhb) {
//        hha++; money += rate[hha] * 60;
//    }
//    money += rate[hhb] * (mmb - mma);
//    return double(money);
//}
//
//int main() {
//    for (int i = 0; i < 24; ++i) {
//        cin >> rate[i]; daymoney += 60 * rate[i];
//    }
//    int n; cin >> n;
//    getchar(); // 把n后面的换行符吃掉 不然会影响getline
//    string badrecord[n]; // 先观察样例 通话记录居然是乱序md 不能一边读入一边处理了
//    for (int i = 0; i < n; ++i) getline(cin, badrecord[i]);
//    sort(badrecord, badrecord+n, cmp);
//    map<string, stack<string> > m; // 每个人名对应一个字符串栈 (判断有效记录）
//    map<string, vector<string> > records; // 每个人名对应一些通话记录（判断后）
//    for (int i = 0; i < n; ++i) {
//        string name = badrecord[i].substr(0, badrecord[i].find('0'));
//        string time = badrecord[i].substr(badrecord[i].find('0'), 11);
//        string status = badrecord[i].substr(badrecord[i].find('0')+12); // time子串后两位开始status子串
//        if (status == "on-line") {
//            if (!m[name].empty()) m[name].pop();
//            m[name].push(time);
//        }
//        else if (status == "off-line") {
//            if (m[name].empty()) continue; // off-line前没有on-line 无效记录
//            string starttime = m[name].top();
//            records[name].push_back(starttime);
//            m[name].pop();
//            records[name].push_back(time);
//        }
//    }
//    map<string, vector<string> >::iterator getmonth = records.begin();
//    string month = getmonth->second[0].substr(0,2);
//
//    map<string, vector<string> >::iterator it = records.begin();
//    for (; it != records.end(); ++it) {
//        vector<string>& tmp = it->second; // 太长了 起个别名
//        cout << it->first << ' ' << month << endl;
//        double totalmoney = 0.0;
//        for (int i = 1; i < tmp.size(); i += 2) { // 一条通话一对时间
//            cout << tmp[i-1].substr(3) << ' ' << tmp[i].substr(3) << ' '; // 原来时间里的月份不打印
//            double money = calmoney(tmp[i-1], tmp[i]); totalmoney += money;
//            cout << caltime(tmp[i-1], tmp[i]) << ' ';
//            printf("$%.2f\n", money / 100);
//        }
//        printf("Total amount: $%.2f\n", totalmoney / 100);
//    }
//    return 0;
//}
=======
>>>>>>> 20dc18026255f8a1e0a1537b4c0d9ba95ed0fd56
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct reocde {
    string name;
    string time;
    string status;
};
bool cmp(reocde a, reocde b) {
    return a.time < b.time;
}

int caltime(string a, string b) {
    int minutesa = 0, minutesb = 0;
    int dda = stoi(a.substr(3,2)), ddb = stoi(b.substr(3,2));
    if (dda < ddb) minutesb += (ddb - dda) * 24 * 60;
    string timea = a.substr(6);
    string timeb = b.substr(6);
    int hha = stoi(timea.substr(0,2)), hhb = stoi(timeb.substr(0,2));
    int mma = stoi(timea.substr(3,2)), mmb = stoi(timeb.substr(3,2));
    minutesa += hha * 60 + mma; minutesb += hhb * 60 + mmb;
    return minutesb - minutesa;
}
int rate[24]; int daymoney = 0;
double calmoney1(string a, string b,int time){
    int money =0;
    string timea = a.substr(6);
    string timeb = b.substr(6);
    int hha = stoi(timea.substr(0,2)), hhb = stoi(timeb.substr(0,2));
    int mma = stoi(timea.substr(3,2)), mmb = stoi(timeb.substr(3,2));
    int time1 = time;
<<<<<<< HEAD
    if (time1 >= 60 ||(time1 < 60 && mma > mmb)) {
=======
    if (time1 > 60||(time1 < 60 & &mma > mmb)) {
>>>>>>> 20dc18026255f8a1e0a1537b4c0d9ba95ed0fd56
        money += rate[hha%24] * (60 - mma);
        money += rate[hhb%24] * mmb;
        hha++;
        time1-=60-mma;
        time1-=mmb;
        while (time1>0) {
            money+= rate[hha%24] * 60;
            hha++;
            time1-=60;
        }
    }else{
        //03:00:01    //03:00:02
        money += rate[hha%24] * (mmb-mma);
    }
    return double(money);
}
int main() {
    for (int i = 0; i < 24; ++i) {
        cin >> rate[i]; daymoney += 60 * rate[i];
    }
    int n; cin >> n;
    vector<reocde> badrecord;
    badrecord.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> badrecord[i].name;
        cin >> badrecord[i].time;
        cin >> badrecord[i].status;
    }
    
    sort(badrecord.begin(), badrecord.end(), cmp);
    map<string, stack<reocde> > m;
    map<string, vector<reocde> > records;
    for (int i = 0; i < n; ++i) {
        string name =badrecord[i].name;
        string time = badrecord[i].time;
        string status = badrecord[i].status;
        if (status == "on-line") {
            if (!m[name].empty()) m[name].pop();
            m[name].push(badrecord[i]);
        }
        else if (status == "off-line") {
            if (m[name].empty()) continue;
            reocde recodeTmp = m[name].top();
            if (recodeTmp.status == "off-line") continue;
            records[name].push_back(recodeTmp);
            m[name].pop();
            records[name].push_back(badrecord[i]);
        }
    }
    map<string, vector<reocde> >::iterator getmonth = records.begin();
    string month = getmonth->second[0].time.substr(0,2);
    
    map<string, vector<reocde> >::iterator it = records.begin();
    for (; it != records.end(); ++it) {
        vector<reocde>& tmp = it->second;
        cout << it->first << ' ' << month << endl;
        double totalmoney = 0.0;
        for (int i = 1; i < tmp.size(); i += 2) {
            cout << tmp[i-1].time.substr(3) << ' ' << tmp[i].time.substr(3) << ' ';
            int time = caltime(tmp[i-1].time, tmp[i].time);
            double money = calmoney1(tmp[i-1].time, tmp[i].time,time);
            totalmoney += money;
            cout << caltime(tmp[i-1].time, tmp[i].time) << ' ';
            printf("$%.2f\n", money / 100);
        }
        printf("Total amount: $%.2f\n", totalmoney / 100);
    }
    return 0;
}
