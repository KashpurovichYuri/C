#include <iostream>

// realization with fold
template <typename T, typename... Types>
auto getMemoryValueByFold(T pack0, Types... packs)
{
	return (sizeof(pack0) + ... + sizeof(packs)); // <=> (sizeof(pack0) + ... + getMemoryValueByFold(packs)), but what is better?
}

// realization without fold
auto getMemoryValue()
{
	return 0;
}

template <typename T, typename... Types>
auto getMemoryValue(T pack0, Types... packs)
{
	return sizeof(pack0) + getMemoryValue(packs...);
}

int main()
{
	std::cout << getMemoryValueByFold(20, 1.0, 5) << std::endl;
	std::cout << 	   getMemoryValue(20, 1.0, 5) << std::endl;
	std::cout << sizeof(20) << " + " << sizeof(1.0) << " + " << sizeof(5) << std::endl;
}