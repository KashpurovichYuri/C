#include <iostream>

class SimpleUserClass
{
public:
	SimpleUserClass(int a=0, int b=1): x1 { a }, x2 { b }
	{

	}

	~SimpleUserClass()
	{
		delete this;
	}
private:
	int x1;
	int x2;
};

template <typename T, typename... Types>
auto buildDynObj(Types... packs)
{
	T* ptr = new T(packs...);

	return ptr;
}

int main()
{
	SimpleUserClass* ptr = buildDynObj<SimpleUserClass>(0, 1);
}