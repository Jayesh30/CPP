//g++ -std=c++11 -pthread Thread_even_odd.cpp

#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

std::mutex mu;
//std::condition_variable cond, cond1, cond2;

void even(int *i,int n){
while(*i < n){
if(*i%2 == 0){
std::unique_lock<std::mutex> lk(mu);
cout<<"EVEN :"<< *i<<endl;
*i = *i+1;
}
}
}

void odd(int *i, int n){
while(*i< n){
if(*i%2 == 1){
std::unique_lock<std::mutex> lk(mu);
cout<<"ODD  :"<< *i<<endl;
*i = *i+1;
}
}
}


int main(){
cout<<"before "<<endl;

int i = 0;
thread t1(odd, &i, 20);
thread t2(even, &i, 20);

t1.join();
t2.join();

cout<<"after"<<endl;
return 0;
}
