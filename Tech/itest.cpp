#include<cstdio>


// ITest.h
class ITest
{
public:
	static ITest* CreateInstance();
       	static void ReleaseInstance(ITest* p);
public:
	virtual void foo() = 0;
};

// CTest.h

class CTest : public ITest
{
public:
	virtual void foo()
	{
		printf("Hello, test!\n");
	}
};

ITest* ITest::CreateInstance()
{
	return new CTest;
}

void ITest::ReleaseInstance(ITest* test)
{
	CTest* t = static_cast<CTest*>(test);
	delete t;
}


int main(void)
{
	ITest* test = ITest::CreateInstance();
	test->foo();
	ITest::ReleaseInstance(test);
	return 0;
}

