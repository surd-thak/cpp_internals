
#include<iostream>
#include<thread>
#include<mutex>
#include<string>
#include<fstream>

std::mutex mu;

void shared_print(std::string msg, int i) { //shared resource: std::cout
    std::lock_guard<std::mutex> guard(mu); //RAII
    //mu.lock();
    std::cout << msg << " " << i << "\n";
    //mu.unlock(); //resource will end up being locked forever if any exception thrown above
}


//still an external thread can access std::cout (defined as extern std::ostream cout;), for complete protection of resource; we need to make sure mutex is bounded with resource

class LogFile{
private:
    std::mutex m_mutex;
    std::ofstream f;
public:
    LogFile(){
        f.open("log.txt");
    }
    void shared_print(std::string& msg, int val){
        std::lock_guard<std::mutex> guardLog(m_mutex); //RAII
        f << "From " << msg << ": " << val << std::endl;
    }  
    ~LogFile(){
        f.close();
    }
};

void func1(){
    for(int i = 0; i < 5; i++){
        shared_print(std::string("From t1: "), 1);
    }
}

int main(){
    std::thread t1 (func1);
    for(int i = 0; i < 5; i++){
        shared_print(std::string("From main: "), 1);
    }
    t1.join();
}
