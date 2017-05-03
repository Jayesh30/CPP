#include<iostream>
#include<string>
using namespace std;

int main()
{
string str;
cin>>str;
int n  = str.length();
int i=0, j=0, count = 1;
char ch=str[0];
char *res = new char[n];
for(i=1;i<n;i++){
if(ch == str[i])
count = count+1;
else
{
res[j++] = ch;
res[j++] = 48+count;
count = 1;
ch = str[i];
}
}
res[j++] = ch;
res[j++] = 48+count;
res[j] = '\0';
cout<<res;
return 0;
}
