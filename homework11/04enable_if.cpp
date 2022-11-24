#include <iostream>

template <bool Cond, typename True_Type>
struct enable_if
{
	using type = True_Type;
};

template <typename True_Type>
struct enable_if <false, True_Type>
{
};

template <bool Cond, typename True_Type>
using enable_if_t = typename enable_if <Cond, True_Type>::type;
