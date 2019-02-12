#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

string word[] = {"negative","zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety","hundred","thousand","million"};
int number[] = {-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,30,40,50,60,70,80,90,100,1000,1000000};
string str;
int num,temp;
vector<string> res;//存放分割的字符
vector<string>::iterator ite;
int pos;

//分割输入的字符串
void split(){
    res.clear();
    char *cstr,*p;
    cstr = new char[str.size()+1];
    cstr = strcpy(cstr,str.c_str());
    p = strtok(cstr," ");//空格作为分隔符
    while (p != NULL){
        res.push_back(p);
        p = strtok(NULL," ");//第一次调用后再次调用要将字符串参数置空
    }
}

void Eng2Num(){
    temp = 0;
    for (ite = res.begin();ite != res.end();ite++){
        for (string::size_type i = 0;i < 32;i++){
            if (*ite == word[i]){
                pos = i;
                break;
            }
        }
        
        //若第一个字符为negative，则为负数
        if (pos == 0){
            cout << "-";
        }else if (pos == 29){//出现hundred的情况
            temp *= number[pos];
        }else if (pos >= 30){//不会出现thousand和million一起的情况，放在一起讨论
            temp *= number[pos];
            num += temp;
            temp = 0;
        }else{//小于100直接相加即可
            temp += number[pos];
        }
    }
    num += temp;
    cout << num << endl;
}

int main() {
    while (getline(cin,str)){//字符串中有空格，选用getline（）输入
        if (str.empty()) break;
        num = 0;
        split();//分割输入的字符串
        Eng2Num();//将英语转换为数字
    }
    return 0;
}
