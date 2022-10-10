#include <iostream>

class Client
{
public:
	Client(int val1=0, int val2=0): a{ val1 }, b{ val2 }
	{

	}

private:
	int a;
	int b;

	auto check() const
	{
		return (a == b);
	}

	void exchange()
	{
		// do smth
	}

	friend class Attorney;
};

class Attorney
{
private:
	static auto ClientCheck(const Client & client)
	{
		return client.check();
	}

	friend auto funcCheck(const Client &);
};

auto funcCheck(const Client & client)
{
	return Attorney::ClientCheck(client);
}

int main()
{
	Client client { 5, 10 };
	std::cout << funcCheck(client) << std::endl;
}
