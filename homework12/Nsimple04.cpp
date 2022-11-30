#include <iostream>
#include <array>

template <int K>
constexpr int N_prime()
{
	std::array<int, K> array;
	int count = 0;
	int cand = 2;
	while (count < K)
	{
		int j = 0;
		while (j < count)
		{
			if (cand % array[j] == 0)
			{
				++cand;
				j = 0;
			}
			++j;
		}

		array[count] = cand;
		++count;
		++cand;
	}

	return array.back();
}

int main()
{	
	std::cout << N_prime<10>() << std::endl; // 23
}