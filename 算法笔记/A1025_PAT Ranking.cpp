#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct tee {
    int place;
    string index;
    int mark, locrank;
};

bool cmp(tee t1, tee t2) {
    if (t1.mark != t2.mark) return t1.mark > t2.mark;
    return t1.index < t2.index;
}

int main() {
    int n; cin >> n;
    vector<tee> v;
    for (int i = 1; i <= n; ++i) { // n个考场
        int k; cin >> k; // 每个考场k个人
        tee tmp; tmp.place = i; // 该考场每个考生的考场号都是i
        tee tees[k];
        for (int j = 0; j < k; ++j) { // 读入考生证件号和考分
            cin >> tmp.index >> tmp.mark;
            tees[j] = tmp; // 每一位考生信息存在数组里
        }
        sort(tees, tees+k, cmp);
        int rank = 1, premark = tees[0].mark; // 两个并列第一的话就没有第二了 还是要仔细观察用例 不能想当然
        for (int j = 0; j < k; ++j) {
            if (tees[j].mark != premark) { // 一段同分考生后的第一位考生 其排名等于在数组中的位置 因为数组已经有序
                rank = j+1; premark = tees[j].mark; // 数组从0开始计数 所以j+1
            }
            tees[j].locrank = rank;
            v.push_back(tees[j]);
        }
    }
    cout << v.size() << endl;
    sort(v.begin(), v.end(), cmp);
    vector<tee>::iterator it = v.begin();
    int rank = 1, premark = v[0].mark, cnt = 0; // cnt相当于j+1
    for (; it != v.end(); ++it) {
        cnt++;
        if ((*it).mark != premark) {
            rank = cnt; premark = (*it).mark;
        }
        cout << (*it).index << ' ' << rank << ' ' << (*it).place << ' ' << (*it).locrank << endl;
    }
    return 0;
}
