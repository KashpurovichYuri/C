#include <iostream>
#include <vector>

class Class
{
public:

	Class() = default;

	Class(double d);

	Class(double d, double num);

	Class(const double* d_array);

	Class(const std::vector<double>& num_array);

	Class(const double* d_array, const std::vector<double>& num_array);
	
	Class(const Class& other);

	Class(Class&& other);

	~Class();

	Class& operator= (const Class& other);

	Class& operator= (Class&& other);

	friend std::ostream& operator<< (std::ostream& stream, const Class& object);

	std::size_t length() const;

private:
	void initWithDouble(double d);
	void initWithArray(const double* d_array);
	void deepCopy(const Class& other);
	void transfer(Class&& other);

	double* 			m_array;
	std::size_t 		m_len;
	std::vector<double> m_vector;

};

Class::Class(double d)
{
	initWithDouble(d);
}

Class::Class(double d, double num): m_vector{ static_cast<std::vector<double>>(num) } 
{
	initWithDouble(d);
}

Class::Class(const double* d_array)
{
	initWithArray(d_array);
}

Class::Class(const std::vector<double>& num_array): m_vector{ num_array }
{

}

Class::Class(const double* d_array, const std::vector<double>& num_array): m_vector{ num_array }
{
	initWithArray(d_array);
}

Class::Class(const Class& other):
	m_len{ other.m_len }, m_vector{ other.m_vector }
{
	deepCopy(other);
}

Class::Class(Class&& other):
	m_len{ other.m_len }, m_vector{ std::move(other.m_vector) }
{
	transfer(std::move(other));
}


Class& Class::operator= (const Class& other)
{
	if (this != &other)
		deepCopy(other);
	
	return *this;
}

Class& Class::operator= (Class&& other)
{
	if (this != &other)
		transfer(std::move(other));
	
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
		stream << ", ";
	}
	stream << std::endl << "And also class keeps in safety some other elements with assistance of std::vector: ";
	for (std::size_t i = 0; i < object.length(); ++i)
	{
		stream << object.m_vector[i];
		stream << ", ";
	};

	return stream;
}

std::size_t Class::length() const
{
	return m_len;
}

void Class::initWithDouble(double d)
{
	delete[] m_array;

	m_array = new double;
	*m_array = d;
	m_len = 1;
}

void Class::initWithArray(const double* d_array)
{
	delete[] m_array;

	if (d_array != nullptr)
	{
		m_len = sizeof(d_array) / sizeof(d_array[0]);
		m_array = new double[m_len];

		for(std::size_t i = 0; i < m_len; ++i)
			m_array[i] = d_array[i];
	}
	else
		m_array = nullptr;
}

void Class::deepCopy(const Class& other)
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
}

void Class::transfer(Class&& other)
{
	delete[] m_array;

	m_array = other.m_array;
	other.m_array = nullptr;
}

int main()
{
	Class object1;
	Class object2 { 2.0 };
	Class object3 { 13, 20};

	double arr[5] {1.0, 2.0, 3.0, 4.0, 5.0};
	std::vector<double> vect {20.0, 77.5, 100.0};

	Class object4 { arr };
	Class object5 { vect };
	Class object6 { arr, vect };

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
	std::cout << "Hello" << std::endl;
}
