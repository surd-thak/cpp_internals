#include<iostream>
#include<thread>
#include<chrono>


using namespace std;

void func(){
    this_thread::sleep_for(chrono::seconds(2));
    cout << this_thread::get_id() << " this is the time taking function" << endl;
}

int main(){
    while(1){
        thread t1(func);
    }
}
