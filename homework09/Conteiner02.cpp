#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <exception>

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
			throw Vector< value_type >::VectorError("Index out of range");
			// maybe it would be better to use std::range_error (derived from std::runtime_error derived from std::exception)?
		return m_data[index];
	}
	const_reference operator[](size_type index) const
	{
		if (index < 0 || index > m_size - 1)
			throw Vector< value_type >::VectorError("Index out of range");
		return m_data[index];
	}

	reference front()
	{
		if (m_size == 0)
			throw Vector< value_type >::VectorError("There are no elements in this Vector object");
		return m_data[0];
	}
	reference back()
	{
		if (m_size == 0)
			throw Vector< value_type >::VectorError("There are no elements in this Vector object");
		return m_data[m_size - 1];
	}

	const_reference front() const
	{
		if (m_size == 0)
			throw Vector< value_type >::VectorError("There are no elements in this Vector object");
		return m_data[0];
	}
	const_reference back() const
	{
		if (m_size == 0)
			throw Vector< value_type >::VectorError("There are no elements in this Vector object");
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
			throw Vector< value_type >::VectorError("Invalid operation: size of Vector is 0 (no elements to pop)");
		m_size--;
	}

	void resize(size_type size);

	void swapCopy(Vector < value_type > & other);
	void swapMove(Vector < value_type > & other);


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
		throw Vector< value_type >::VectorError("Invalid value of initial size");

	m_data = new value_type[m_size];
}

template < typename T >
Vector < T > ::Vector(size_type size, const value_type & initial) :
	m_size{size}, m_capacity{size}
{
	if (m_size < 0)
		throw Vector< value_type >::VectorError("Invalid value of initial size");
	if (typeid(initial).name() != typeid(value_type).name())
		throw Vector< value_type >::VectorError("Invalid type of initial value");

	m_data = new value_type[m_size];
	for (std::size_t i = 0; i < m_size; ++i)
		m_data[i] = initial;
}

template < typename T >
Vector < T > ::Vector(const Vector < value_type > & other):
	m_size{ other.m_size },	m_capacity{ other.m_capacity }
{
	if (typeid(other).name() != typeid(Vector < value_type >).name())
		throw Vector< value_type >::VectorError("Invalid type of initial Vector");

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
		throw Vector< value_type >::VectorError("Invalid type of initial Vector");

	m_data = other.m_data;
	other.m_data = nullptr;
}

template < typename T >
Vector < T > & Vector < T > ::operator= (const Vector<value_type>& other)
{
	if (typeid(other).name() != typeid(Vector < value_type >).name())
		throw Vector< value_type >::VectorError("Invalid type of initial Vector");

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
		throw Vector< value_type >::VectorError("Invalid type of initial Vector");

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
void Vector < T > ::push_back(const value_type & value)
{
	if (typeid(value).name() != typeid(value_type).name())
		throw Vector< value_type >::VectorError("Invalid type of pushing value");

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

template < typename T >
void Vector < T > ::resize(size_type size)
{
	if (size < 0)
		throw Vector< value_type >::VectorError("Invalid value of size for Vector's resize");

	if (size > m_size)
	{
		auto new_capacity = size;
		auto new_data = new value_type[new_capacity];
		std::copy(this->begin(), this->end(), new_data);
		for (auto i = m_size; i < new_capacity; ++i)
			new_data[i] = 0;

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

template < typename T >
void Vector < T > ::swapCopy(Vector < value_type > & other)
{
	if (typeid(other).name() != typeid(Vector < value_type >).name())
		throw Vector< value_type >::VectorError("Invalid type of swapped Vector");

	Vector < value_type > new_vector = *this;
	*this = other;
	other = new_vector;
}

template < typename T >
void Vector < T > ::swapMove(Vector < value_type > & other)
{
	if (typeid(other).name() != typeid(Vector < value_type >).name())
		throw Vector< value_type >::VectorError("Invalid type of swapped Vector");

	Vector < value_type > new_vector;
	new_vector = std::move(*this)
	*this = std::move(other);
	other = std::move(new_vector);
}


template < typename T >
class Vector < T* >
{
public:

	using value_type = T*;
	using pointer = T ** ;
	using const_pointer = const T **;
	using reference = T* & ;
	using const_reference = const T* &;
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
			throw Vector< value_type >::VectorError("Index out of range");
			// maybe it would be better to use std::range_error (derived from std::runtime_error derived from std::exception)?
		return m_data[index];
	}
	const_reference operator[](size_type index) const
	{
		if (index < 0 || index > m_size - 1)
			throw Vector< value_type >::VectorError("Index out of range");
		return m_data[index];
	}

	reference front()
	{
		if (m_size == 0)
			throw Vector< value_type >::VectorError("There are no elements in this Vector object");
		return m_data[0];
	}
	reference back()
	{
		if (m_size == 0)
			throw Vector< value_type >::VectorError("There are no elements in this Vector object");
		return m_data[m_size - 1];
	}

	const_reference front() const
	{
		if (m_size == 0)
			throw Vector< value_type >::VectorError("There are no elements in this Vector object");
		return m_data[0];
	}
	const_reference back() const
	{
		if (m_size == 0)
			throw Vector< value_type >::VectorError("There are no elements in this Vector object");
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
	T * pop_back()
	{
		if (m_size == 0)
			throw Vector< value_type >::VectorError("Invalid operation: size of Vector is 0 (no elements to pop)");
		m_size--;
		return m_data[m_size - 1];
	}

	void resize(size_type size);

	void swapCopy(Vector < value_type > & other);
	void swapMove(Vector < value_type > & other);


	class VectorError: public std::exception // is it ok to use the same error class?
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

private:

	pointer m_data{ nullptr };
	size_type m_size{ 0 };
	size_type m_capacity{ 0 };
};

template < typename T >
Vector < T* > ::Vector(size_type size) :
	m_size{size}, m_capacity{size}
{
	if (m_size < 0)
		throw Vector< value_type >::VectorError("Invalid value of initial size");

	m_data = new value_type[m_size];
}

template < typename T >
Vector < T* > :: Vector(size_type size, const value_type initial):
	m_size { size }
{
	if (m_size < 0)
		throw Vector< value_type >::VectorError("Invalid value of initial size");
	if (typeid(initial).name() != typeid(value_type).name())
		throw Vector< value_type >::VectorError("Invalid type of initial value");

	m_data = new T*[m_size];
	for (std::size_t i = 0; i < m_size; ++i)
		m_data[i] = initial;
}

template < typename T >
Vector < T* > ::Vector(const Vector < value_type > & other):
	m_size{ other.m_size },	m_capacity{ other.m_capacity }
{
	if (typeid(other).name() != typeid(Vector < value_type >).name())
		throw Vector< value_type >::VectorError("Invalid type of initial Vector");

	if (other.m_data != nullptr)
	{
		m_data = new value_type[m_size];
		std::copy(other.begin(), other.end(), m_data);
	}
	else
		m_data = nullptr;
}

template < typename T >
Vector < T* > ::Vector(Vector<value_type>&& other):
	m_size{ other.m_size }, m_capacity{ other.m_capacity }
{
	if (typeid(other).name() != typeid(Vector < value_type >).name())
		throw Vector< value_type >::VectorError("Invalid type of initial Vector");

	m_data = other.m_data;
	other.m_data = nullptr;
}

template < typename T >
Vector < T* > & Vector < T* > ::operator= (const Vector<value_type>& other)
{
	if (typeid(other).name() != typeid(Vector < value_type >).name())
		throw Vector< value_type >::VectorError("Invalid type of initial Vector");

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
Vector < T* > & Vector < T* > ::operator= (Vector<value_type>&& other)
{
	if (typeid(other).name() != typeid(Vector < value_type >).name())
		throw Vector< value_type >::VectorError("Invalid type of initial Vector");

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
void Vector < T* > ::push_back(const value_type & value)
{
	if (typeid(value).name() != typeid(value_type).name())
		throw Vector< value_type >::VectorError("Invalid type of pushing value");

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

template < typename T >
void Vector < T* > ::resize(size_type size)
{
	if (size < 0)
		throw Vector< value_type >::VectorError("Invalid value of size for Vector's resize");

	if (size > m_size)
	{
		auto new_capacity = size;
		auto new_data = new value_type[new_capacity];
		std::copy(this->begin(), this->end(), new_data);
		for (auto i = m_size; i < new_capacity; ++i)
			new_data[i] = 0;

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

template < typename T >
void Vector < T* > ::swapCopy(Vector < value_type > & other)
{
	if (typeid(other).name() != typeid(Vector < value_type >).name())
		throw Vector< value_type >::VectorError("Invalid type of swapped Vector");

	Vector < value_type > new_vector = *this;
	*this = other;
	other = new_vector;
}

template < typename T >
void Vector < T* > ::swapMove(Vector < value_type > & other)
{
	if (typeid(other).name() != typeid(Vector < value_type >).name())
		throw Vector< value_type >::VectorError("Invalid type of swapped Vector");

	Vector < value_type > new_vector;
	new_vector = std::move(*this)
	*this = std::move(other);
	other = std::move(new_vector);
}

struct BitField
{
	char bit0: 1;
	char bit1: 1;
	char bit2: 1;	
	char bit3: 1;
	char bit4: 1;	
	char bit5: 1;
	char bit6: 1;
	char bit7: 1;
};

template < >
class Vector < bool >
{
public:

	using value_type = BitField;
	using pointer = BitField * ;
	using const_pointer = const BitField *;
	using reference = char & ;
	using const_reference = const char &;
	using size_type = std::size_t;

	using iterator = pointer;
	using const_iterator = const_pointer;

public:

	Vector() = default;

	explicit Vector(size_type size);
	explicit Vector(size_type size, const bool & initial);
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
	// Be carious! It doesn't work because we can't take non-const references to bitfields... So I need to modify implementation of Vector < bool >
	reference realValueIndex(size_type index)
	{
		switch (index % 8)
		{
			case 0: return m_data[index / 8].bit0;
			case 1: return m_data[index / 8].bit1;
			case 2: return m_data[index / 8].bit2;
			case 3: return m_data[index / 8].bit3;
			case 4: return m_data[index / 8].bit4;
			case 5: return m_data[index / 8].bit5;
			case 6: return m_data[index / 8].bit6;
			case 7: return m_data[index / 8].bit7;
		}		
	}

	const_reference realValueIndex(size_type index) const
	{
		switch (index % 8)
		{
			case 0: return m_data[index / 8].bit0;
			case 1: return m_data[index / 8].bit1;
			case 2: return m_data[index / 8].bit2;
			case 3: return m_data[index / 8].bit3;
			case 4: return m_data[index / 8].bit4;
			case 5: return m_data[index / 8].bit5;
			case 6: return m_data[index / 8].bit6;
			case 7: return m_data[index / 8].bit7;
		}		
	}

	reference operator[] (size_type index)
	{	
		if (index < 0 || index > m_size - 1)
			throw Vector< bool >::VectorError("Index out of range");
		return realValueIndex(index);
	}
	const_reference operator[](size_type index) const
	{
		if (index < 0 || index > m_size - 1)
			throw Vector< bool >::VectorError("Index out of range");		
		return realValueIndex(index);
	}

	reference front()
	{
		if (m_size == 0)
			throw Vector< bool >::VectorError("There are no elements in this Vector object");
		return realValueIndex(0);
	}
	reference back()
	{
		if (m_size == 0)
			throw Vector< bool >::VectorError("There are no elements in this Vector object");
		return realValueIndex(m_size - 1);
	}

	const_reference front() const
	{
		if (m_size == 0)
			throw Vector< bool >::VectorError("There are no elements in this Vector object");
		return realValueIndex(0);
	}
	const_reference back() const
	{
		if (m_size == 0)
			throw Vector< bool >::VectorError("There are no elements in this Vector object");
		return realValueIndex(m_size - 1);
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

	void push_back(const bool & value);
	bool pop_back()
	{
		if (m_size == 0)
			throw Vector< bool >::VectorError("Invalid operation: size of Vector is 0 (no elements to pop)");
		m_size--;
	}

	void resize(size_type size);

	void swapCopy(Vector < bool > & other);
	void swapMove(Vector < bool > & other);


	class VectorError: public std::exception // is it ok to use the same error class? Or we should make friend class for all specialization?
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

private:

	BitField* m_data{ nullptr };
	size_type m_size{ 0 };
	size_type m_capacity{ 0 };
};

Vector < bool > ::Vector(size_type size) :
	m_size{size}
{
	if (m_size < 0)
		throw Vector< bool >::VectorError("Invalid value of initial size");

	m_data = new BitField[m_size / 8 + 1];
	m_capacity = m_size / 8 + 8;
}

Vector < bool > ::Vector(size_type size, const bool & initial) :
	m_size{size}
{
	if (m_size < 0)
		throw Vector< bool >::VectorError("Invalid value of initial size");
	if (typeid(initial).name() != typeid(bool).name())
		throw Vector< bool >::VectorError("Invalid type of initial value");

	m_data = new BitField[m_size / 8 + 1];
	m_capacity = m_size / 8 + 8;
	for (auto i = 0; i < m_size; ++i)
		realValueIndex(i) = initial;
}

Vector < bool > ::Vector(const Vector < bool > & other):
	m_size{ other.m_size },	m_capacity{ other.m_capacity }
{
	if (typeid(other).name() != typeid(Vector < bool >).name())
		throw Vector< bool >::VectorError("Invalid type of initial Vector");

	if (other.m_data != nullptr)
	{
		if (m_size % 8 == 0)
			m_data = new BitField[m_size / 8];
		else
			m_data = new BitField[m_size / 8 + 1];

		for (auto i = 0; i < m_size; ++i)
			realValueIndex(i) = other.realValueIndex(i);
	}
	else
		m_data = nullptr;
}

Vector < bool > ::Vector(Vector<bool>&& other):
	m_size{ other.m_size }, m_capacity{ other.m_capacity }
{
	if (typeid(other).name() != typeid(Vector < bool >).name())
		throw Vector< bool >::VectorError("Invalid type of initial Vector");

	m_data = other.m_data;
	other.m_data = nullptr;
}

Vector < bool > & Vector < bool > ::operator= (const Vector<bool>& other)
{
	if (typeid(other).name() != typeid(Vector < bool >).name())
		throw Vector< bool >::VectorError("Invalid type of initial Vector");

	if (this != &other)
	{
		delete[] m_data;

		m_size = other.m_size;
		m_capacity = other.m_capacity;

		if (other.m_data != nullptr)
		{
			if (m_size % 8 == 0)
				m_data = new BitField[m_size / 8];
			else
				m_data = new BitField[m_size / 8 + 1];

			for (auto i = 0; i < m_size; ++i)
				realValueIndex(i) = other.realValueIndex(i);
		}	
		else
			m_data = nullptr;
	}

	return *this;
}

Vector < bool > & Vector < bool > ::operator= (Vector<bool>&& other)
{
	if (typeid(other).name() != typeid(Vector < bool >).name())
		throw Vector< bool >::VectorError("Invalid type of initial Vector");

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

void Vector < bool > ::push_back(const bool & value)
{
	if (typeid(value).name() != typeid(bool).name())
		throw Vector< bool >::VectorError("Invalid type of pushing value");

	if (m_size >= m_capacity)
	{
		auto new_capacity = m_capacity == 0 ? 1 : 2 * m_capacity;
		Vector< bool > new_vector { new_capacity };
		new_vector = *this;

		delete[] m_data;
		m_data = new_vector.m_data;
		m_capacity = new_capacity;
	}
	realValueIndex(m_size) = value;
	++m_size;
}

void Vector < bool > ::resize(size_type size)
{
	if (size < 0)
		throw Vector< bool >::VectorError("Invalid value of size for Vector's resize");

	if (size > m_size)
	{
		auto new_capacity = size;
		Vector< bool > new_vector { new_capacity };
		new_vector = *this;
		for (auto i = m_size; i < new_capacity; ++i)
			new_vector.realValueIndex(i) = 0;

		delete[] m_data;
		m_data = new_vector.m_data;
		m_capacity = new_capacity;
	}
	else
		for (auto i = m_size; i > size; --i)
			pop_back();
	
	m_size = size;
}

void Vector < bool > ::swapCopy(Vector < bool > & other)
{
	if (typeid(other).name() != typeid(Vector < bool >).name())
		throw Vector< bool >::VectorError("Invalid type of swapped Vector");

	Vector < bool > new_vector = *this;
	*this = other;
	other = new_vector;
}

/*
void Vector < bool > ::swapMove(Vector < bool > & other)
{
	if (typeid(other).name() != typeid(Vector < bool >).name())
		throw Vector< bool >::VectorError("Invalid type of swapped Vector");

	Vector < bool > new_vector;
	new_vector = std::move(*this)
	*this = std::move(other);
	other = std::move(new_vector);
}
*/

int main() try
{
	int a = 5, b = 10;

	Vector < int > v1 { a - b };

	Vector < int > v2 { 10, 15 };

	int* ptr = &a;
	Vector < int* > v3 { 10, ptr };

	Vector < bool > v4;

}
catch(const Vector<int>::VectorError& except)
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
