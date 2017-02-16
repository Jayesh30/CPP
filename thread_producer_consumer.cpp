//g++ -std=c++11 -pthread thread_basic.cpp

#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

std::mutex mu,pu, cu;
std::condition_variable cond;
bool flag = true;
std::queue<int> q;

void prdoucer(int n){
int i=1;
while(i < n){
{
	std::unique_lock<std::mutex> lk(mu);
	q.push(i);
	cout<<"producer :"<<i<<endl;
//	cond.notify_one();
}
i++;
}
//cond.notify_one();
flag = false;
}

void consumer(){
int data;
while(flag || !q.empty()){
std::unique_lock<std::mutex> lk(mu);
//cond.wait(lk);

if(!q.empty()){
data = q.front();
q.pop();
cout<<"consumer :"<<data<<endl;
}

}
}

//===============


int main(){
cout<<"before "<<endl;

thread t1(prdoucer,20);
thread t2(consumer);

t1.join();
t2.join();

cout<<"after"<<endl;
return 0;
}
