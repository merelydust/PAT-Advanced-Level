#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
using namespace std;
#define MAX 100
string change(char *p) {
    string cnt;
    int len=strlen(p);
    stack<char>astack;
    for(int i=0; i<=len; i++) {
        if((p[i]>='0' && p[i]<='9') || (p[i]>='a' && p[i]<='z'))
            cnt+=p[i];
        else if(p[i]=='(')
            astack.push('(');
        else if(p[i]==')') {
            while(astack.top()!='(') {
                cnt+=astack.top();
                astack.pop();
            }
            astack.pop();
        }
        else if(p[i]=='+' || p[i]=='-') {
            while(!astack.empty() && astack.top()!='(') {
                cnt+=astack.top();
                astack.pop();
            }
            astack.push(p[i]);
        }
        else if(p[i]=='*') {
            while(!astack.empty() && astack.top()!='(' && astack.top()=='*') {
                cnt+=astack.top();
                astack.pop();
            }
            astack.push(p[i]);
        }
        else if(p[i]==' ' || p[i]=='    ')
            continue;
    }
    while(!astack.empty()) {
        cnt+=astack.top();
        astack.pop();
    }
    return cnt;
}
int getsum(string num) {
    int len=num.length();
    stack<int>astack;
    for(int i=0; i<len; i++) {
        if(num[i]<='z' && num[i]>='a') {
            int ascii=num[i];
            astack.push(ascii);
        }
        else if(num[i]>='0' && num[i]<='9')
            astack.push((int)num[i]-'0');
        else if(num[i]=='+') {
            int n=astack.top();
            astack.pop();
            int m=astack.top();
            astack.pop();
            m+=n;
            astack.push(m);
        }
        else if(num[i]=='*') {
            int n=astack.top();
            astack.pop();
            int m=astack.top();
            astack.pop();
            n*=m;
            astack.push(n);
        }
        else if(num[i]=='-') {
            int n=astack.top();
            astack.pop();
            int m=astack.top();
            astack.pop();
            m-=n;
            astack.push(m);
        }
    }
    int result=astack.top();
    astack.pop();
    return result;
}
int main() {
    int N;
    scanf("%d", &N);
    cin.get();
    while(N--) {
        char s1[MAX], s2[MAX];
        cin.getline(s1, MAX);
        string p1=change(s1);
        int a=getsum(p1);
        cin.getline(s2, MAX);
        string p2=change(s2);
        int b=getsum(p2);
        if(a==b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

