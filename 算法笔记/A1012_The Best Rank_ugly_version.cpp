#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct stu {
    string id;
    double gradea, gradec, gradem, gradee;
    int ranks[4]; // 按优先级存储 ranka rankc rankm ranke
};
char subject[4] = {'A', 'C', 'M', 'E'};
// 重复度很高 感觉可以使用模版和虚函数 不过无脑突突突写的更快 就先这样吧>_<
bool cmpa(stu a, stu b) {
    return a.gradea > b.gradea;
}
bool cmpc(stu a, stu b) {
    return a.gradec > b.gradec;
}
bool cmpm(stu a, stu b) {
    return a.gradem > b.gradem;
}
bool cmpe(stu a, stu b) {
    return a.gradee > b.gradee;
}

void outresult(int arr[]) {
    int min = arr[0];
    int minindex = 0;
    for (int i = 0; i < 4; ++i) {
        if (arr[i] < min) {
            min = arr[i]; minindex = i;
        }
    }
    cout << min << ' ' << subject[minindex] << endl;
}

int main() {
    int n, m; cin >> n >> m;
    stu students[n];
    for (int i = 0; i < n; ++i) {
        stu tmp;
        cin >> tmp.id >> tmp.gradec >> tmp.gradem >> tmp.gradee;
        tmp.gradea = (tmp.gradec + tmp.gradem + tmp.gradee) / 3;
        students[i] = tmp;
    }
    
    sort(students, students+n, cmpa);
    double premark = students[0].gradea;
    int rank = 1;
    for (int i = 0; i < n; ++i) {
        if (students[i].gradea != premark) {
            rank = i + 1;
            students[i].ranks[0] = i+1; premark = students[i].gradea;
        }
        else students[i].ranks[0] = rank;
    }
    
    sort(students, students+n, cmpc);
    premark = students[0].gradec;
    rank = 1;
    for (int i = 0; i < n; ++i) {
        if (students[i].gradec != premark) {
            rank = i + 1;
            students[i].ranks[1] = i+1; premark = students[i].gradec;
        }
        else students[i].ranks[1] = rank;
    }
    
    sort(students, students+n, cmpm);
    premark = students[0].gradem;
    rank = 1;
    for (int i = 0; i < n; ++i) {
        if (students[i].gradem != premark) {
            rank = i + 1;
            students[i].ranks[2] = i+1; premark = students[i].gradem;
        }
        else students[i].ranks[2] = rank;
    }
    
    sort(students, students+n, cmpe);
    premark = students[0].gradee;
    rank = 1;
    for (int i = 0; i < n; ++i) {
        if (students[i].gradee != premark) {
            rank = i + 1;
            students[i].ranks[3] = i+1; premark = students[i].gradee;
        }
        else students[i].ranks[3] = rank;
    }
    
    for (int i = 0; i < m; ++i) {
        string tmp; cin >> tmp;
        bool find = false;
        for (int j = 0; j < n; ++j) {
            if (students[j].id == tmp) {
                find = true;
                outresult(students[j].ranks);
            }
        }
        if (!find) cout << "N/A" << endl;
    }
    return 0;
}
