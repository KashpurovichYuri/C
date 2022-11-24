#include <iostream>
#include <type_traits>

template <typename T>
struct  decay: std::remove_const<T>
{
};

template <typename T>
struct decay<T[]>: std::add_pointer<T[]>
{
};

template <typename T, std::size_t N>
struct decay<T[N]>: std::add_pointer<T[N]>
{
};

template <typename T, typename... Args>
struct decay<T(Args...)>: std::add_pointer<T(Args...)>
{
};

template <typename T, typename... Args>
struct decay<T(Args..., ...)>: std::add_pointer<T(Args..., ...)>
{
};

template <typename T>
using decay_t = typename decay<T>::type;
