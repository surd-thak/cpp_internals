/*
Requirements --> 
tasks will be created continuosly
an executor exist which will assign incoming task to a thread from a threadpool
ensure if all thread is active we do not loose the incoming tasks
*/

/*
Solution structure -->
create a producer consumer type buffer queue
every new task is pushed at the back in the queue
a condition variable exist which tells how many worker threads are actively working
executor assigns a non working thread to the new task if such a thread exist otherwise wait for signal
everytime a thread completes its tasks it gives signal to executor
*/


#include<iostream>
#include<thread>
#include<queue>
#include<vector>
#include<condition_variable>
using namespace std;


// queue<int> taskq;
// queue<thread> threadpool;

void taskFunc(int& x){
    for(int i = 0; i < 10; i++){
        x++;
    }
    cout << x << "\n"; //later will create its own fstream to avoid resource sharing
}

void executor(int& x){
    // thread t = std::move(threadpool.front());
    // threadpool.pop();
    // t(taskFunc(x));

}

class myThreadpool{
    queue<int> taskq; //bounded or unbounded queue ??? 
    public:
        myThreadpool pool(int n): ;
        void submit(int &x){
            //what if queue size is full
            taskq.push(x); //later pass by reference
        }
};



int main(){
    myThreadpool pool(4);
    int i = 0;
    while(i < 1000){
        pool.submit(i);
        i++;
    }
}



