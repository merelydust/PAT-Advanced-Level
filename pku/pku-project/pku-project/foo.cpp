#include <iostream>
using namespace std;

int recur(int n) {
    if (n == 1) return 1;
    else return n * recur(n-1);
}
