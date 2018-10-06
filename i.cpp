//
//  i.cpp
//  pku
//
//  Created by Shadow on 2018/8/11.
//  Copyright © 2018年 Shadow. All rights reserved.
//

#include <iostream>
using namespace std;

void recur();

char sentence[501] = {0};
int i = 0;

int main() {
    cin.getline(sentence, 501);
    while (sentence[i]) {
        recur();
        cout << ' ';
    }
    cout << endl;
    return 0;
}

void recur() {
    char ch = sentence[i];
    if (ch == ' ') {
        return;
    }
    recur();
    cout << ch;
}
