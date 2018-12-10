#include<cstdio>
#include<cstring>
#include<set>
#include<cmath>
#include<map>
#include<stack>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 44
typedef long long ll;
string ss;
stack<string> idd;
vector<string> akk;
int vis[maxn*maxn];
struct node{
    int f;  //f=0 :file ; f=1: dir;
    string tmp;
    int weizhi;
}a[maxn*maxn];
int main(){
    int num=0,jj=1;
    while(cin>>ss){
        int tot=0; num=0;
        if(ss[0]=='#') break;
        memset(vis,0,sizeof(vis));
        if(ss[0]=='f'){
            a[num].f=0;  a[num].tmp=ss;
            a[num++].weizhi=tot;
        }
        else if(ss[0]=='d'){
            tot++;
            a[num].f=1; a[num].tmp=ss;
            a[num++].weizhi=tot;
        }
        while(cin>>ss){
            if(ss[0]=='*') break;
            if(ss[0]==']'){
                a[num].f=-2; a[num].tmp=ss;
                num++;
                tot--; continue;
            }
            else if(ss[0]=='f'){
                a[num].f=0;  a[num].tmp=ss;
                a[num++].weizhi=tot;
            }
            else if(ss[0]=='d'){
                tot++;
                a[num].f=1;  a[num].tmp=ss;
                a[num++].weizhi=tot;
            }
        }
        printf("DATA SET %d:\nROOT\n",jj++);
        tot=0;  memset(vis,0,sizeof(vis));
        for(int i=0;i<num;i++){
            if(vis[i]) continue;
            if(a[i].f==1){
                vis[i]=1;
                tot++;
                if(a[i].weizhi==tot){
                    for(int j=1;j<=tot;j++) printf("|     ");
                    cout<<a[i].tmp<<endl;
                    idd.push("[");
                    //接下来是要曲去找与之匹配的结尾了;
                    int ff=0;
                    for(int j=i+1;j<num;j++){
                        if(ff==-1) break;
                        if(a[j].tmp[0]==']'){
                            vis[j]=1;
                            ff--;
                            akk.clear();
                            while(!idd.empty()){
                                string tmp=idd.top();
                                idd.pop();
                                if(tmp[0]=='[') break;
                                akk.push_back(tmp);
                            }
                            sort(akk.begin(),akk.end());
                            int len=akk.size();
                            for(int kk=0;kk<len;kk++){
                                for(int k=1;k<=tot;k++) printf("|     ");
                                cout<<akk[kk]<<endl;
                            }
                            tot--;
                            if(ff==-1) break;
                        }
                        else if(a[j].f==1){     //如果是dir
                            vis[j]=1;
                            tot++;
                            if(a[j].weizhi==tot){
                                for(int k=1;k<=tot;k++) printf("|     ");
                                cout<<a[j].tmp<<endl;
                                ff++;
                                idd.push("[");
                            }
                        }
                        else if(a[j].f==0){
                            vis[j]=1;
                            idd.push(a[j].tmp);
                        }
                    }
                }
            }
            else idd.push(a[i].tmp);
        }
        akk.clear();
        while(!idd.empty()){
            string tmp=idd.top();
            idd.pop();
            akk.push_back(tmp);
        }
        sort(akk.begin(),akk.end());
        int len=akk.size();
        for(int i=1;i<=tot;i++) printf("|     ");
        for(int i=0;i<len;i++){
            cout<<akk[i]<<endl;
        }
        puts("");
    }
    return 0;
}
