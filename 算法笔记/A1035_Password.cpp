#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

struct stu {
    string name, pwd;
};

int modif(stu &a) {
    bool ismo = false;
    for (int i = 0; i < a.pwd.length(); ++i) {
        switch (a.pwd[i]) {
            case '1':
                a.pwd[i] = '@';
                ismo = true;
                break;
            case '0':
                a.pwd[i] = '%';
                ismo = true;
                break;
            case 'l':
                a.pwd[i] = 'L';
                ismo = true;
                break;
            case 'O':
                a.pwd[i] = 'o';
                ismo = true;
                break;
            default:
                break;
        }
    }
    return ismo;
}

int main() {
    int n; cin >> n;
    stu students[n];
    vector<stu> v;
    for (int i = 0; i < n; ++i) {
        cin >> students[i].name >> students[i].pwd;
        if (modif(students[i])) v.push_back(students[i]);
    }
    if (v.size()) {
        cout << v.size() << endl;
        vector<stu>::iterator it;
        for (it = v.begin(); it != v.end(); ++it) cout << (*it).name << ' ' << (*it).pwd << endl; // .优先级h高于*
    }
    else {
        if (n == 1) cout << "There is 1 account and no account is modified" << endl;
        else printf("There are %d accounts and no account is modified\n", n);
    }
    return 0;
}
