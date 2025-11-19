// petersons_sol.cpp
#include<iostream>
#include<thread>
using namespace std;

//petersons solution --> locks+turns
//decouple dependency on a single variable --> context switch doesnt affect shared resource
//only valid for two processes
//busy wait is inefficient

#define TRUE 1
#define FALSE 0
#define N 2

int turn_ = 0;
int interested[N];
int x_ = 0;

void enter_section(int process){
    int other = 1-process;
    interested[process] = TRUE;
    turn_ = process;
    while(turn_==process && interested[other]==TRUE);
}

void leave_section(int process){
    interested[process] = FALSE;
}

class thread_object3 {
public:
    void operator()(int process) {
        for (int i = 0; i < 10000000; ++i) {
            enter_section(process);
            x_ += 1;
            std::cout<<"Thread "<<process<<" "<<x_<<std::endl;
            leave_section(process);
        }
    }
};

int main(){
    thread_object3 obj3;

    thread t1(obj3, 0);
    thread t2(obj3, 1);

    t1.join();
    t2.join();

    cout <<  " petersons solution " << "final value of x = " << x_ << endl;
    return 0;
}
