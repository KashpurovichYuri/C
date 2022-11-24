#include <iostream>
#include <type_traits>

template <typename... Elements>
class Typelist
{
};

template <typename T>
struct is_function: std::false_type
{
};

template <typename T, typename... Args>
struct is_function<T(Args...)>: std::true_type
{
	using type = T;
	using Arguments = Typelist<Args...>;
	static constexpr bool variadic = false;
};

template <typename T, typename... Args>
struct is_function<T(Args..., ...)>: std::true_type
{
	using type = T;
	using Arguments = Typelist<Args...>;
	static constexpr bool variadic = true;
};

template <typename T, typename... Args>
struct is_function<T(Args...) const>: std::true_type
{
	using type = T;
	using Arguments = Typelist<Args...>;
	static constexpr bool variadic = false;
};

template <typename T, typename... Args>
struct is_function<T(Args..., ...)&> : std::true_type
{
	using type = T;
	using Arguments = Typelist<Args...>;
	static constexpr bool variadic = true;
};

// + another qualificators + Constructors? + Destructors?

template <typename T>
using is_function_v = typename is_function<T>::type;
