#include<iostream>
using namespace std;

/*
modular; reusable; scalable
class --> user defined data type that is used as blueprint for creating objects
          design and functionality is decided in the blueprint
object --> instance of a class
         brings the structure to life with specific data
constructor --> used to initialize object, ensures valid states of object after creation
                do not have a return type
                automatic invocation, overloading possible
                pvt constructor for singleton design pattern
                constructor is not inherited
                cannot be static: has no this pointer; not associated with any particular object instance
this --> avoid disambiguity between parameter and data member 
         constructor chaining
         method chaining using return this
         pass current object as parameter 
         not used in static because used for specific instance
polymorhism-->
compile time/static --> method resolution at compile time
                        overloading function/operator
                        different number/type of arguments
runtime --> method overriding using virtual functions

inheritance -->
                reusability, extensibility
                disadv - increased coupling
encapsulation --> 
                    data security, integrity

abstraction --> hiding implementation details
                create an interface (must have member functions for anyone sharing same behaviour)
                decrease tight coupling compared from inheritance
                abstract method - uses virtual key word and child will have to overwrite it no matter what
                concrete method -






*/

class vehicle{
    public:
        virtual void accelerate() = 0; 
        virtual void brake() = 0; 
        void startEngine() {
            cout << "Vehicle's Engine started!" << endl;
        }
        virtual ~vehicle() { }
        // If you don’t declare the destructor as virtual, and delete an object through a base class pointer,
        // only the base class destructor will be called. This can result in resource leaks or undefined behavior,
        // as the derived class destructor (and any resources it might have allocated) will not be invoked.
};

class car : virtual public vehicle{
    private: 
        //privacty is maintained on class level and not at object level, 
        //even its own object outside the class can not access them
        // void showoff(){
        //     cout << "my car is amazing!" << endl;
        // }
    public : 
        virtual void showoff(){  //if virtual is not used base class functions will be called
            cout << "my car is amazing!" << endl;
        }
        void accelerate() override{
            cout << "Car is accelerating!" << endl;
        }
        void brake() { //writing override is not compulsory
            cout << "Car's brake applied!" << endl;
        }
};

class porche: public car{
    private:
        
    public :
        void showoff() override{
            cout << "porche is amazing!" << endl;
        }
        // void accelerate() override{
        //     cout << "Porche is accelerating!" << endl;
        // }
        // void brake() { //writing override is not compulsory
        //     cout << "Porche's brake applied!" << endl;
        // }
};

class truck : virtual  public vehicle{
    public: 
        void accelerate() override{
            cout << "Truck is accelerating!" << endl;
        }
        void brake() { //writing override is not compulsory
            cout << "Truck's brake applied!" << endl;
        }
        
};
class cyberTruck: public car,  public truck{
    //diamond problem 
    //only inheritance with virtual word doesnot solve the problem we will have to override 
    //conflicting functions even in non abstract or abstract class
   public:
       void accelerate() override{
            truck::accelerate();
        }
        void brake() { //writing override is not compulsory
            truck::brake();
        } 
};

int main(){
    //vehicle A; //not allowed (has pure virtual function -> abstract class)
    car B;
    B.accelerate();
    //B.showoff(); private member
    porche P;
    P.showoff();
    P.accelerate();

    car* P2 = new porche();
    P2->showoff();

    P2 = &(B);
    P2->showoff();
    cyberTruck ct;
    ct.accelerate(); //ambiguous if conficts not resolved


    
    car C = P;  // ❌ object slicing! virtuals won't work
    C.showoff();

    // vehicle* v = new car();
    // v->showoff();   A base class pointer (vehicle*) can only call methods defined in the base class.


}


