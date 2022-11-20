#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <exception>

class VectorError: public std::exception
	{
	public:

		VectorError() = default;

		explicit VectorError(const char* strerr):
			what_arg { strerr }
		{

		}

		virtual const char* what() const noexcept override
		{
			return what_arg;
		}

	private:
		const char* what_arg;
	};


template < typename T >
class Vector
{
public:

	using value_type = T;
	using pointer = T * ;
	using const_pointer = const T *;
	using reference = T & ;
	using const_reference = const T &;
	using size_type = std::size_t;

	using iterator = pointer;
	using const_iterator = const_pointer;

public:

	Vector() = default;

	explicit Vector(size_type size);
	explicit Vector(size_type size, const value_type initial);
	Vector(const Vector & other);
	Vector(Vector && other);
	Vector & operator=(const Vector &);
	Vector & operator= (Vector && other);


	~Vector() noexcept
	{
		delete[] m_data;
		m_size = 0;
		m_capacity = 0;
	}

public:

	reference operator[] (size_type index)
	{
		if (index < 0 || index > m_size - 1)
			throw VectorError("Index out of range");
		return m_data[index];
	}
	const_reference operator[](size_type index) const
	{
		if (index < 0 || index > m_size - 1)
			throw VectorError("Index out of range");
		return m_data[index];
	}

	reference front()
	{
		if (m_size == 0)
			throw VectorError("There are no elements in this Vector object");
		return m_data[0];
	}
	reference back()
	{
		if (m_size == 0)
			throw VectorError("There are no elements in this Vector object");
		return m_data[m_size - 1];
	}

	const_reference front() const
	{
		if (m_size == 0)
			throw VectorError("There are no elements in this Vector object");
		return m_data[0];
	}
	const_reference back() const
	{
		if (m_size == 0)
			throw VectorError("There are no elements in this Vector object");
		return m_data[m_size - 1];
	}

	iterator begin() noexcept
	{
		return m_data;
	}
	iterator end() noexcept
	{
		return m_data + m_size;
	}

	const_iterator begin() const noexcept
	{
		return m_data;
	}
	const_iterator end() const noexcept
	{
		return m_data + m_size;
	}

	size_type size() const noexcept
	{
		return m_size;
	}
	size_type capacity() const noexcept
	{
		return m_capacity;
	}

	void push_back(const value_type value);
	void pop_back()
	{
		if (m_size == 0)
			throw VectorError("Invalid operation: size of Vector is 0 (no elements to pop)");
		m_size--;
	}

	void resize(size_type size);
	void resize(size_type size, const value_type initial); // can we make default initial value?

	void swapMove(Vector < value_type > other);

private:

	pointer m_data{ nullptr };
	size_type m_size{ 0 };
	size_type m_capacity{ 0 };
};

template < typename T >
Vector < T > ::Vector(size_type size) :
	m_size{size}, m_capacity{size}
{
	if (m_size < 0)
		throw VectorError("Invalid value of initial size");

	m_data = new value_type[m_size];
}

template < typename T >
Vector < T > ::Vector(size_type size, const value_type initial) :
	m_size{size}, m_capacity{size}
{
	if (m_size < 0)
		throw VectorError("Invalid value of initial size");
	if (typeid(initial).name() != typeid(value_type).name())
		throw VectorError("Invalid type of initial value");

	m_data = new value_type[m_size];
	for (std::size_t i = 0; i < m_size; ++i)
		m_data[i] = initial;
}

template < typename T >
Vector < T > ::Vector(const Vector < value_type > & other):
	m_size{ other.m_size },	m_capacity{ other.m_capacity }
{
	if (typeid(other).name() != typeid(Vector < value_type >).name())
		throw VectorError("Invalid type of initial Vector");

	if (other.m_data != nullptr)
	{
		m_data = new value_type[m_size];
		std::copy(other.begin(), other.end(), m_data);
	}
	else
		m_data = nullptr;
}

template < typename T >
Vector < T > ::Vector(Vector<value_type>&& other):
	m_size{ other.m_size }, m_capacity{ other.m_capacity }
{
	if (typeid(other).name() != typeid(Vector < value_type >).name())
		throw VectorError("Invalid type of initial Vector");

	m_data = other.m_data;
	other.m_data = nullptr;
}

template < typename T >
Vector < T > & Vector < T > ::operator= (const Vector<value_type>& other)
{
	if (typeid(other).name() != typeid(Vector < value_type >).name())
		throw VectorError("Invalid type of initial Vector");

	if (this != &other)
	{
		delete[] m_data;

		m_size = other.m_size;
		m_capacity = other.m_capacity;

		if (other.m_data != nullptr)
		{
			m_data = new value_type[m_size];

			std::copy(other.begin(), other.end(), m_data);
		}
		else
			m_data = nullptr;
	}

	return *this;
}

template < typename T >
Vector < T > & Vector < T > ::operator= (Vector<value_type>&& other)
{
	if (typeid(other).name() != typeid(Vector < value_type >).name())
		throw VectorError("Invalid type of initial Vector");

	if (this != &other)
	{	
		delete[] m_data;

		m_data = other.m_data;
		m_size = other.m_size;
		m_capacity = other.m_capacity;
		other.m_data = nullptr;
		other.m_size = 0;
		other.m_capacity = 0;
	}
	
	return *this;
}

template < typename T >
void Vector < T > ::push_back(const value_type value)
{
	if (typeid(value).name() != typeid(value_type).name())
		throw VectorError("Invalid type of pushing value");

	if (m_size >= m_capacity)
	{
		auto new_capacity = m_capacity == 0 ? 1 : 2 * m_capacity;
		auto new_data = new value_type[new_capacity];
		std::copy(this->begin(), this->end(), new_data);

		delete[] m_data;
		m_data = new_data;
		m_capacity = new_capacity;
	}
	m_data[m_size] = value;
	++m_size;
}

template < typename T >
void Vector < T > ::resize(size_type size)
{
	if (size < 0)
		throw VectorError("Invalid value of size for Vector's resize");

	if (size > m_size)
	{
		auto new_capacity = m_capacity == 0 ? 1 : 2 * m_capacity;
		while (new_capacity < size)
			new_capacity *= 2;
		auto new_data = new value_type[new_capacity];
		std::copy(this->begin(), this->end(), new_data);
		for (auto i = m_size; i < new_capacity; ++i)
			new_data[i] = 0;

		delete[] m_data;
		m_data = new_data;
		m_capacity = new_capacity;
	}
	else
		for (auto i = m_size; i > size; --i)
			pop_back();
	
	m_size = size;
}

template < typename T >
void Vector < T > ::resize(size_type size, const value_type initial)
{
	if (size < 0)
		throw VectorError("Invalid value of size for Vector's resize");

	if (size > m_size)
	{
		auto new_capacity = m_capacity == 0 ? 1 : 2 * m_capacity;
		while (new_capacity < size)
			new_capacity *= 2;
		auto new_data = new value_type[new_capacity];
		std::copy(this->begin(), this->end(), new_data);
		for (auto i = m_size; i < new_capacity; ++i)
			new_data[i] = initial;

		delete[] m_data;
		m_data = new_data;
		m_capacity = new_capacity;
	}
	else
		for (auto i = m_size; i > size; --i)
			pop_back();
	
	m_size = size;
}

template < typename T >
void Vector < T > ::swapMove(Vector < value_type > other)
{
	if (typeid(other).name() != typeid(Vector < value_type >).name())
		throw VectorError("Invalid type of swapped Vector");

	Vector < value_type > new_vector;
	new_vector = std::move(*this)
	*this = std::move(other);
	other = std::move(new_vector);
}

template <  >
class Vector < std::string >
{
public:

	using value_type = std::string;
	using pointer = std::string * ;
	using const_pointer = const std::string *;
	using reference = std::string & ;
	using const_reference = const std::string &;
	using size_type = std::size_t;

	using iterator = pointer;
	using const_iterator = const_pointer;

public:

	Vector() = default;

	explicit Vector(size_type size);
	explicit Vector(size_type size, const value_type & initial);
	Vector(const Vector & other);
	Vector(Vector && other);
	Vector & operator=(const Vector &);
	Vector & operator= (Vector && other);


	~Vector() noexcept
	{
		delete[] m_data;
		m_size = 0;
		m_capacity = 0;
	}

public:

	reference operator[] (size_type index)
	{
		if (index < 0 || index > m_size - 1)
			throw VectorError("Index out of range");
		return m_data[index];
	}
	const_reference operator[](size_type index) const
	{
		if (index < 0 || index > m_size - 1)
			throw VectorError("Index out of range");
		return m_data[index];
	}

	reference front()
	{
		if (m_size == 0)
			throw VectorError("There are no elements in this Vector object");
		return m_data[0];
	}
	reference back()
	{
		if (m_size == 0)
			throw VectorError("There are no elements in this Vector object");
		return m_data[m_size - 1];
	}

	const_reference front() const
	{
		if (m_size == 0)
			throw VectorError("There are no elements in this Vector object");
		return m_data[0];
	}
	const_reference back() const
	{
		if (m_size == 0)
			throw VectorError("There are no elements in this Vector object");
		return m_data[m_size - 1];
	}

	iterator begin() noexcept
	{
		return m_data;
	}
	iterator end() noexcept
	{
		return m_data + m_size;
	}

	const_iterator begin() const noexcept
	{
		return m_data;
	}
	const_iterator end() const noexcept
	{
		return m_data + m_size;
	}

	size_type size() const noexcept
	{
		return m_size;
	}
	size_type capacity() const noexcept
	{
		return m_capacity;
	}

	void push_back(const value_type & value);
	void pop_back()
	{
		if (m_size == 0)
			throw VectorError("Invalid operation: size of Vector is 0 (no elements to pop)");
		m_size--;
	}

	void resize(size_type size);
	void resize(size_type size, const value_type & initial);

	void swapMove(Vector < value_type > & other);

private:

	pointer m_data{ nullptr };
	size_type m_size{ 0 };
	size_type m_capacity{ 0 };
};

Vector < std::string > ::Vector(size_type size) :
	m_size{size}, m_capacity{size}
{
	if (m_size < 0)
		throw VectorError("Invalid value of initial size");

	m_data = new value_type[m_size];
}

Vector < std::string > :: Vector(size_type size, const value_type & initial):
	m_size { size }
{
	if (m_size < 0)
		throw VectorError("Invalid value of initial size");
	if (typeid(initial).name() != typeid(value_type).name())
		throw VectorError("Invalid type of initial value");

	m_data = new value_type[m_size];
	for (std::size_t i = 0; i < m_size; ++i)
		m_data[i] = initial;
}

Vector < std::string > ::Vector(const Vector < value_type > & other):
	m_size{ other.m_size },	m_capacity{ other.m_capacity }
{
	if (typeid(other).name() != typeid(Vector < value_type >).name())
		throw VectorError("Invalid type of initial Vector");

	if (other.m_data != nullptr)
	{
		m_data = new value_type[m_size];
		std::copy(other.begin(), other.end(), m_data);
	}
	else
		m_data = nullptr;
}

Vector < std::string > ::Vector(Vector<value_type> && other):
	m_size{ other.m_size }, m_capacity{ other.m_capacity }
{
	if (typeid(other).name() != typeid(Vector < value_type >).name())
		throw VectorError("Invalid type of initial Vector");

	m_data = other.m_data;
	other.m_data = nullptr;
}

Vector < std::string > & Vector < std::string > ::operator= (const Vector<value_type> & other)
{
	if (typeid(other).name() != typeid(Vector < value_type >).name())
		throw VectorError("Invalid type of initial Vector");

	if (this != &other)
	{
		delete[] m_data;

		m_size = other.m_size;
		m_capacity = other.m_capacity;

		if (other.m_data != nullptr)
		{
			m_data = new value_type[m_size];

			std::copy(other.begin(), other.end(), m_data);
		}
		else
			m_data = nullptr;
	}

	return *this;
}

Vector < std::string > & Vector < std::string > ::operator= (Vector<value_type>&& other)
{
	if (typeid(other).name() != typeid(Vector < value_type >).name())
		throw VectorError("Invalid type of initial Vector");

	if (this != &other)
	{	
		delete[] m_data;

		m_data = other.m_data;
		m_size = other.m_size;
		m_capacity = other.m_capacity;
		other.m_data = nullptr;
		other.m_size = 0;
		other.m_capacity = 0;
	}
	
	return *this;
}

void Vector < std::string > ::push_back(const value_type & value)
{
	if (typeid(value).name() != typeid(value_type).name())
		throw VectorError("Invalid type of pushing value");

	if (m_size >= m_capacity)
	{
		auto new_capacity = m_capacity == 0 ? 1 : 2 * m_capacity;
		auto new_data = new value_type[new_capacity];
		std::copy(this->begin(), this->end(), new_data);

		delete[] m_data;
		m_data = new_data;
		m_capacity = new_capacity;
		delete[] new_data;
	}
	m_data[m_size] = value;
	++m_size;
}

void Vector < std::string > ::resize(size_type size)
{
	if (size < 0)
		throw VectorError("Invalid value of size for Vector's resize");

	if (size > m_size)
	{
		auto new_capacity = size;
		auto new_data = new value_type[new_capacity];
		std::copy(this->begin(), this->end(), new_data);
		for (auto i = m_size; i < new_capacity; ++i)
			new_data[i] = std::string("");

		delete[] m_data;
		m_data = new_data;
		m_capacity = new_capacity;
		delete[] new_data;
	}
	else
		for (auto i = m_size; i > size; --i)
			pop_back();
	
	m_size = size;
}

void Vector < std::string > ::resize(size_type size, const value_type & initial)
{
	if (size < 0)
		throw VectorError("Invalid value of size for Vector's resize");

	if (size > m_size)
	{
		auto new_capacity = m_capacity == 0 ? 1 : 2 * m_capacity;
		while (new_capacity < size)
			new_capacity *= 2;
		auto new_data = new value_type[new_capacity];
		std::copy(this->begin(), this->end(), new_data);
		for (auto i = m_size; i < new_capacity; ++i)
			new_data[i] = initial;

		delete[] m_data;
		m_data = new_data;
		m_capacity = new_capacity;
	}
	else
		for (auto i = m_size; i > size; --i)
			pop_back();
	
	m_size = size;
}

void Vector < std::string > ::swapMove(Vector < value_type > & other)
{
	if (typeid(other).name() != typeid(Vector < value_type >).name())
		throw VectorError("Invalid type of swapped Vector");

	swap (*this, other);
}

template < typename T >
void swapCall(Vector < T > & vector1, Vector < T > & vector2) // should I write version in symmetric form?
{
	vector1.swapMove(vector2);
}

int main() try
{
	int a = 5, b = 10;

	Vector < int > v1 { b - a };
	v1[a + b];

	Vector < int > v2 { 10, 15 };

	int* ptr = &a;
	Vector < int* > v3 { 10, ptr };

	Vector < bool > v4;

}
catch(const VectorError& except)
{
	std::cerr << except.what() << std::endl;
	return 0;
}
catch(const std::exception& except)
{
	std::cerr << except.what() << std::endl;
	return 0;
}
catch(...)
{
	std::cerr << "There is an exception" << std::endl;
	return 0;
}
