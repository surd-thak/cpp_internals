// lock_variable.cpp
#include<iostream>
#include<thread>
using namespace std;


//used volatile to avoid Compiler Optimizations 
volatile int lock = 0; //shared lock //A plain int cannot act as a lock safely in multithreaded code.

//callable class // functor
//trying to tie lock and shared resource together
class thread_object0{
public:
    //issue the lock is not atomic
    void operator()(int& x){
        for(int i = 0; i < 1000; i++){
            while(lock!=0); //spinlock //both thread may see this as lock = 0 at the same time and enter critical section
            lock = 1;
            x+=1;  // both thread were here read x; but context switching happened; other thread updates x; first thread updates old value of x; 
            lock = 0;
        }
    }
};

int main(){
    int x = 0;
    thread_object0 obj;
    thread t1(obj, std::ref(x));
    thread t2(obj, std::ref(x));
    t1.join();
    t2.join();

    cout <<  " lock variable " << "final value of x = " << x << endl;
    return 0;
}
