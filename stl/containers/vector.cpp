#include<iostream>
using namespace std;


template<typename T>
class myVector{
    private:
        T* data;
        size_t size_;
        size_t capacity;
        void allocate_capacity(){
            if(size_==0)capacity=1;
            else capacity = size_*2;
        }

    public:
        myVector(size_t sz, T def = T()){
            size_ = sz;
            allocate_capacity();
            data = new T[capacity];
            for(int i = 0; i < size_; i++)data[i] = def;
        }
        myVector(const myVector<T> &other){
            size_ = other.size_;
            allocate_capacity();
            data  = new T[capacity];
            for(int i = 0; i < size_; i++){
                data[i] = other.data[i];
            }
        }
        myVector(myVector<T>&& other) noexcept:
            data(other.data),
            size_(other.size_),
            capacity(other.capacity){
            other.data = nullptr;
        }


        myVector<T>& operator=(myVector<T> other) noexcept{
            //cas idiom
            if(this!= &other){
                swap(other.data, data);
                swap(other.size_, size_);
                swap(other.capacity, capacity);
            }
            return *this;
        }

        T& operator[](size_t idx){
            if(idx >= size_) throw "out of bounds";
            return data[idx];
        }

        void push_back(T data_){
            if(size_==capacity){
                allocate_capacity();
                T* temp  = new T[capacity];
                for(int i = 0; i < size_; i++){
                    temp[i] = std::move(data[i]);
                }
                delete data[]; //forgot to free old memory
                swap(data, temp);
            }
            data[size_] = data_;
            size_++;
        }

        void pop_back(){
            size_--;
        }

        T& back(){
            if(size_==0) throw "out of bounds";
            return data[size_-1];
        }
        size_t size(){
            return size_;
        }
       ~myVector(){
            delete[] data;
       }
};


int main(){
    //initialisation part, constructors, rule of 5
    myVector<int>  a(5,1); //default constructor
    cout <<  a[2]  << "\n";
    myVector<int>  b = a; //copy constructor
    myVector<int>  c(b); //copy constructor
    c = a; //copy assignment
    myVector<int>  d(std::move(b));//move constructor
    d = std::move(a);//move assignment
    // myVector f = {1,2,3,4}; //using initilizer list
    cout << c.size() << " " << d.size() << "\n";
    //operators
    cout <<  d[2]  << "\n";
    //cout << a[1] << "\n"; //should give error
    


    //member functions
    d.push_back(3);
    cout << d.back() << "\n";
    d.pop_back();
    cout << d.back() << "\n";
    //->emplace back (variadic tempelates, for checking try to use some user defined data type)

    return 0;
}