#include <iostream>

template <typename T>
struct add_const // if T is already const???
{
	using type = T const;
};

template <typename T>
using add_const_t = typename add_const<T>::type;

template <typename T>
struct remove_const
{
	using type = T;
};

template <typename T>
struct remove_const<T const>
{
	using type = T;
};

template <typename T>
using remove_const_t = typename remove_const<T>::type;
