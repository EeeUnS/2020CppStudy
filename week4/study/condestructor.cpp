#include<iostream>

using namespace std;
class sample
{
public:
	sample() 
    {
        cout << "parent constructor" << endl;
    }
	virtual ~sample()
    {
        cout << "parent destructor" << endl;
    }
	virtual void f() { 
        printf("parent : %p\n" , &sample::f);
     }
};


class smapleInheritance : public sample
{
private:
    /* data */
public:

	void f() override
	{ 
        printf("자식 : %p\n" , &smapleInheritance::f);
     }
    smapleInheritance(/* args */);
    ~smapleInheritance();
};

smapleInheritance::smapleInheritance(/* args */)
{
    cout << "child constructor" << endl;
}

smapleInheritance::~smapleInheritance()
{
    cout << "child destructor" << endl;
}



int main()
{
//    smapleInheritance s;

    sample* ptr = new smapleInheritance();
    delete ptr;

    return 0;
}
