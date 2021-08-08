#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    system("cd /home/K/桌面/安卓代码片段");
    system("git add -A");
    cout<<"是否要为本次提交输入自定义说明？[Y/N]";
    string input;
    cin>>input;
    if(input=="N"||input=="n")
    {
        system("timenow=$(date +\"%Y-%m-%d %H:%M:%S\")")
        system("commitinfo=\"$timenow Linux提交\")");
    }
    else if(input=="Y"||input=="y")
    {
        cout<<"请输入提交说明："<<endl;
        static string commitinfo;
        cin>>commitinfo;
        string command="git commit -m "+commitinfo;
    }
}
//未完工