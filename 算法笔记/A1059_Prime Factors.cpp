// 对素数打表 遍历素数表 n反复除某一素数直到除不尽为止 某一素数个数累加
// 目前看来 题目说的long int就是int = =?
#include <iostream>
#include <cmath>
using namespace std;
struct fac{                            //x为质因子，cnt为其个数
    int x,cnt;
}fac[20];
bool isprime(int n){                   //判断是否为素数
    if(n<=1) return false;
    if(n==2) return true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    int n,temp,num=0;                 //num为n的不同质因子个数
    cin>>n;
    temp=n;
    if(n==1) cout<<"1=1";             //特例
    else{
        int sqr=(int)sqrt(1.0*n);
        for(int i=2;i<=sqr;i++){
            if(isprime(i)){          //若为素数
                if(n%i==0){          //且为n的因子
                    fac[num].x=i;    //先记录该因子并初始化个数
                    fac[num].cnt=0;
                    while(n%i==0){   //计算该质因子个数
                        fac[num].cnt++;
                        n/=i;
                    }
                    num++;           //不同质因子个数加1
                }
            }
            if(n==1) break;          //及时推出循环
        }
        if(n!=1){                    //无法被根号n以内的质因子除尽
            fac[num].x=n;            //必有一个大于根号n(即n本身)的质因子
            fac[num++].cnt=1;
        }
        cout<<temp<<"=";
        for(int i=0;i<num;i++){
            cout<<fac[i].x;
            if(fac[i].cnt!=1) cout<<"^"<<fac[i].cnt;
            if(i<num-1)cout<<"*";
        }
        return 0;
    }
}
