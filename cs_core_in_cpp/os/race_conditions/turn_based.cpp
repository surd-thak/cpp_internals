// turn_based.cpp
#include<iostream>
#include<thread>
using namespace std;

// Using a shared turn variable to implement turn-based access for threads
// Separate functor classes per thread with similar code; could be generalized

int turn  = 0;

class thread_object1{
public:
    void non_critical_section(){
        int a = 0;
        while(++a < 10);
    }
    void operator()(int& x){
        while(true){
            while(turn!=0); //spin lock
            x+=1;
            cout << "thread_object1 " << x << endl;
            turn = 1;
            non_critical_section();
        }
    }
};

class thread_object2{
public:
    void non_critical_section(){
        int a = 0;
        while(++a < 10000);
    }
    void operator()(int& x){
        while(true){
            while(turn!=1); //spin lock
            x+=1;
            cout << "thread_object2 " << x << endl;
            turn = 0;
            non_critical_section();
        }
    }
};

int main(){
    int x = 0;

    thread_object1 obj1;
    thread_object2 obj2;

    thread t1(obj1, std::ref(x));
    thread t2(obj2, std::ref(x));
    t1.join();
    t2.join();

    cout <<  " turn-based " << "final value of x = " << x << endl;
    return 0;
}
