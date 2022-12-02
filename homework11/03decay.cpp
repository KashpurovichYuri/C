#include <iostream>
#include <type_traits>

template <bool C, typename True_Type, typename False_Type>
struct if_then_else
{
	using type = True_Type;
};

template <typename True_Type, typename False_Type>
struct if_then_else<false, True_Type, False_Type>
{
	using type = False_Type;
};

template <bool C, typename TT, typename FT>
using if_then_else_t = typename if_then_else<C, TT, FT>::type;

template <typename T>
struct decay
{
private:
	using NT = std::remove_reference_t<T>;
public:
	using type = if_then_else_t<
		std::is_array_v<NT>,
		std::add_pointer_t<NT>,
		if_then_else_t<
			std::is_function_v<NT>,
			std::add_pointer_t<NT>,
			std::remove_const_t<NT>
		>
	>;
};

template <typename T>
using decay_t = typename decay<T>::type;
