#include<iostream>
#include<cstdio>
using namespace std;
class sample
{
public:
	int b = 0;
	int ssample(){;	}
	sample() = default;
	~sample() = default;
	virtual void f() { ; }
};


class sampleInheritance : public sample
{ 
	int a = 0;
public:
	void f() override
	{ ; }
};


int main()
{
	sample sam;
	cout << sizeof(sam) << endl ;
	
	sampleInheritance mae;
	cout << sizeof(mae) << endl;

	return 0;
}
