//g++ -std=c++11 -pthread thread_dining_philosopher.cpp

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

#define NO_OF_PHILOSOPHERS 5
int forks[NO_OF_PHILOSOPHERS];
//int plate =100;

std::mutex mu;

void init(){
for(int i=0;i<NO_OF_PHILOSOPHERS;i++)
forks[i] = 0;
}

void philosopher(int i, int *j){
int right = i;
int left = (i+1) % NO_OF_PHILOSOPHERS;
bool locked;
while(*j < 20){
locked = false;
while(!locked){
mu.lock();
if(forks[left] || forks[right]){
cout<<i<<" :Dont have both the fork, go give up"<<endl;
mu.unlock();
std::this_thread::sleep_for(std::chrono::seconds(2));
continue;
}
forks[left] = forks[right] = 1;
mu.unlock();
locked = true;
}
cout<<i<<" :take both the fork, and start eating"<<endl;
mu.lock();
forks[left] = forks[right] = 0;
*j= *j+1;
cout<<i<<" :relese both the fork, stop eating"<<endl;
mu.unlock();
std::this_thread::sleep_for(std::chrono::seconds(2));
}
}

int main(){
init();
int i,j=0;
cout<<"before "<<endl;
thread *t[NO_OF_PHILOSOPHERS];

 for(i=0; i<NO_OF_PHILOSOPHERS; i++)
        t[i] = new thread(philosopher, i, &j);
 
for(i=0; i<NO_OF_PHILOSOPHERS; i++)
        t[i]->join();

//delete t;
cout<<"after"<<endl;
return 0;
}
