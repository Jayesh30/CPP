#include<iostream>
using namespace std;

int left(int i){
return 2*i+1;
}

int right(int i){
return 2*i+2;
}

void hepify(int *a, int n, int i){
int tmp;
int l = left(i), r = right(i);
int max = i;
if(l < n && a[max] < a[l]) max = l;
if(r < n && a[max] < a[r]) max = r;
if(a[i] < a[max]){
cout<<"swap "<<i<< " : "<<max<<endl; 
tmp = a[i];
a[i] = a[max];
a[max] = tmp;
hepify(a,n,max);
}
}

int main(){
int n,i=0;
cout<<"No of element : ";
cin>>n;
int a[n];
for(i=0;i<n;i++)
cin>>a[i];

for(i=n/2;i>=0;i--)
hepify(a,n,i);

for(i=0;i<n;i++)
cout<<a[i]<<"-";

return 0;
}
