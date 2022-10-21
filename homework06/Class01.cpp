#include <iostream>
#include <vector>

class Class
{
public:

	Class() = default;

	explicit Class(double d);

	explicit Class(double d, double num);

	explicit Class(const double* d_array, int size_d_array);

	explicit Class(const std::vector<double>& num_array);

	explicit Class(const double* d_array, int size_d_array, const std::vector<double>& num_array);
	
	Class(const Class& other);

	Class(Class&& other);

	~Class();

	Class& operator= (const Class& other);

	Class& operator= (Class&& other);

	friend std::ostream& operator<< (std::ostream& stream, const Class& object);

	std::size_t length() const
	{
		return m_len;
	}

private:
	double* m_array;
	std::size_t	m_len;
	std::vector<double> m_vector;

};

Class::Class(double d)
{
	m_array = new double[1];
	m_array[0] = d;
	m_len = 1;
}

Class::Class(double d, double num): m_vector{ std::vector<double> (1, num) }
{
	m_array = new double[1];
	m_array[0] = d;
	m_len = 1;
}

Class::Class(const double* d_array, int size_d_array)
{
	if (d_array != nullptr)
	{
		m_len = size_d_array;
		m_array = new double[m_len];

		for(std::size_t i = 0; i < m_len; ++i)
			m_array[i] = d_array[i];
	}
	else
	{
		m_array = nullptr;
		m_len = 0;
	};
}

Class::Class(const std::vector<double>& num_array): m_vector{ num_array }
{

}

Class::Class(const double* d_array, int size_d_array, const std::vector<double>& num_array):
	m_vector{ num_array }
{
	if (d_array != nullptr)
	{
		m_len = size_d_array;
		m_array = new double[m_len];

		for(std::size_t i = 0; i < m_len; ++i)
			m_array[i] = d_array[i];
	}
	else
	{
		m_array = nullptr;
		m_len = 0;
	};
}

Class::Class(const Class& other):
	m_len{ other.m_len }, m_vector{ other.m_vector }
{
	if (other.m_array != nullptr)
	{
		m_array = new double[m_len];

		for(std::size_t i = 0; i < m_len; ++i)
			m_array[i] = other.m_array[i];
	}
	else
		m_array = nullptr;
}

Class::Class(Class&& other):
	m_len{ other.m_len }, m_vector{ std::move(other.m_vector) }
{
	m_array = other.m_array;
	other.m_array = nullptr;
	other.m_len = 0;
}


Class& Class::operator= (const Class& other)
{
	if (this != &other)
	{
		delete[] m_array;

		if (other.m_array != nullptr)
		{
			m_array = new double[m_len];

			for(std::size_t i = 0; i < m_len; ++i)
				m_array[i] = other.m_array[i];
		}
		else
			m_array = nullptr;

		m_vector = other.m_vector;
	}
	
	return *this;
}

Class& Class::operator= (Class&& other)
{
	if (this != &other)
	{	
		delete[] m_array;

		m_array = other.m_array;
		other.m_array = nullptr;
		other.m_len = 0;

		m_vector = std::move( other.m_vector );
		other.m_vector.clear();
	}
	
	return *this;
}

Class::~Class()
{
	delete[] m_array;
}

std::ostream& operator<< (std::ostream& stream, const Class& object)
{
	stream << "Our class stores some elements in dynamic array: ";
	for (std::size_t i = 0; i < object.length(); ++i)
	{
		stream << object.m_array[i];
		if (i != object.length() - 1)
			stream << ", ";
	}
	stream << std::endl << "And also class keeps in safety some other elements with assistance of std::vector: ";
	for (std::size_t i = 0; i < object.length(); ++i)
	{
		stream << object.m_vector[i];
		if (i != object.length() - 1)
			stream << ", ";
	}

	return stream;
}

int main()
{
	Class object1 {};
	Class object2 { 2.0 };
	Class object3 { 13, 20};

	double arr[] {1.0, 2.0, 3.0, 4.0, 5.0};
	std::vector<double> vect {20.0, 77.5, 100.0};

	Class object4 { arr, 5 };
	Class object5 { vect };
	Class object6 { arr, 5, vect };

	Class object7 { object6 };
	Class object8 { 555.555 };

	std::cout << "Hello" << std::endl;
	std::cout << object1 << std::endl;
	std::cout << object2 << std::endl;
	std::cout << object3 << std::endl;
	std::cout << object4 << std::endl;
	std::cout << object5 << std::endl;
	std::cout << object6 << std::endl;
	std::cout << object7 << std::endl;
	std::cout << object8 << std::endl;
	std::cout << "Goodbye" << std::endl;
}
