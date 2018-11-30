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
    if (time1 >= 60 ||(time1 < 60 && mma > mmb)) {
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
