#include<iostream>
#include<string>
#include<thread>


//multiprogramming --> interprocess communication (files, piepes, msg queues :leads for it being slower), slow and complicated, high overhead (bunch of internal resources needed to be allocated 
//                      by os and the security os has to maintain), distributed systems  
//multithreading --> shared memory, light, fast, low overhead, cant work on distributed systems

void func(){
    std::cout << "inside func\n";
}

class functor{ //class that overloads operator ()
    public:
        void operator()(){
            std::cout << "calling functor\n";
        }
        void operator()(std::string s){
            std::cout << "calling functor with parameter\n";
        }
};

int main(){
    
    std::thread t1(func);
    
    // if a thread object is destroyed before joined or detach : terminate called without an active exception : Aborted

    
    // t1.join(); 
    //main thread waits for t1 to finish
    //always check before joining; if a thread is null thread it is not joinable and will lead to termination of program if tried to join
    
    t1.detach(); 
    
    // //t1 will free on its own -- daemon process -- depends on c++ runtime lib for reclaiming resources; 
    // // even main may end before it is executed 
    // // no way to know the order of execution unless we use some type of sycnhronization
    
    
    // // once you detach your child there is no joining back
    
    // if(t1.joinable()){
    //     t1.join();
    // }
    
     /*-----------------------xxxxxx-------------------------*/
     /*-----------------------xxxxxx-------------------------*/
     /*-----------------------xxxxxx-------------------------*/
    
    //"Most Vexing Parse"
    
    //std::thread t2(functor());
    std::thread t2((functor()));
    t2.join();
    
    //no vexing issue here if atleast one of them is not in place constructor
    std::string s ="hello";
    std::thread t3(functor(),s);
    t3.join();
    
    //a parameter to thread is always passed by value even if you use references in the constructor definition; explicity use std::ref while passing the arg
    //if you want to avoid race conditions and still be very efficient use std::move but then you wont be able share it across multiple threads
    
    
    std::cout << std::this_thread::get_id() << std::endl;
    //std::cout << t3.get_id() << std::endl; // thread::id of a non-executing thread
    
    
    
    //oversubscription : threads should be less than equal to cpu core otherwise too many context switch leading latency
    // logical core = 2*physical core; smt or hyper-threading (shares exec unit (ALU, FPU, caches but separate registers and instruction queue)
    
    std::cout << std::thread::hardware_concurrency() << std::endl;
    // for no. of logical processors; if i/o heavy : more than logical cpu core; if cpu intensive : less than equal to logical cpu core; leave atleast one extra free for background os tasks for better optimisation
    
    
    return 0;
}

