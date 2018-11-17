#include <iostream>
#include <string>
#include <numeric>
using namespace std;

struct stu {
    string name, pwd;
}students[1010];
int hashtable[1010] = {0};

int main() {
    int n; cin >> n;
    for (int i = 0 ; i < n; ++i) {
        cin >> students[i].name >> students[i].pwd;
        for (int j = 0, len = students[i].pwd.length(); j < len; ++j) {
            switch (students[i].pwd[j]) {
                case '1':
                    students[i].pwd[j] = '@';
                    hashtable[i] = 1;
                    break;
                case '0':
                    students[i].pwd[j] = '%';
                    hashtable[i] = 1;
                    break;
                case 'l':
                    students[i].pwd[j] = 'L';
                    hashtable[i] = 1;
                    break;
                case 'O':
                    students[i].pwd[j] = 'o';
                    hashtable[i] = 1;
                    break;
                default:
                    continue;
            }
        }
    }
    int cnt = accumulate(hashtable, hashtable+1000, 0);
    if (!cnt) {
        if (n==1) cout << "There is 1 account and no account is modified" << endl;
        else cout << "There are " << n << " accounts and no account is modified" << endl;
    }
    else {
        cout << cnt << endl;
        for (int i = 0; i < 1000; ++i) {
            if (hashtable[i]) cout << students[i].name << " " << students[i].pwd << endl;
        }
    }
    return 0;
}
