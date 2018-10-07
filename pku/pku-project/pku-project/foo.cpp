#include <iostream>
#include <list>
using namespace std;

int main() {
    int n, m;
    list <int> monkeys;
    while (true) {
        cin >> n >> m;
        if (!n && !m) break;
        monkeys.clear();
        for (int i = 1; i <= n; ++i) monkeys.push_back(i);
        list<int>::iterator it = monkeys.begin();
        while (monkeys.size() > 1) {
            for (int i = 1; i < m; ++i) {
                ++it;
                if (it == monkeys.end()) it = monkeys.begin();
            }
            it = monkeys.erase(it);
            if (it == monkeys.end()) it = monkeys.begin();
        }
                cout << monkeys.front() << endl;
    }
                return 0;
}
