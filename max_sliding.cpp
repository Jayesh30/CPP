#include<iostream>
#include<deque>
using namespace std;

int main(){
int n,i=0,k;
cout<<" Number of element : ";
cin>>n;
int a[n];
for(i=0;i<n;i++){
cin>>a[i];
}
cout<<" slide size: ";
cin>>k;
deque<int> q;
for(i=0;i<k;i++){
//q.push_back(a[i]);
while(!q.empty() && a[q.back()] <= a[i])
	q.pop_back();
q.push_back(i);
}
int r[n];
while(i<n){
r[i-1] = a[q.front()];
while(!q.empty() && q.front() < i-k)
	q.pop_front();
while(!q.empty() && a[q.back()] <= a[i])
	q.pop_back();
q.push_back(i);
i++;
}

r[i-1] = a[q.front()];

for(i=k-1;i<n;i++){
cout<<i<<"-"<<i-k+1<<" : "<<r[i]<<endl;}
return 0;
}
