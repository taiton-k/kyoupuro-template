#pragma once

#include <initializer_list>
#include <type_traits>



using swallow = std::initializer_list<bool>;



template<class T>
struct is_container {
        template<class U>
        static constexpr auto check(U&&)
                -> decltype(std::begin(std::declval<U>()),std::true_type{});

        static constexpr auto check(...)
                -> std::false_type;

        static constexpr bool value = decltype(check(std::declval<T>()))::value;
};

template<class T>
constexpr bool is_container_v = is_container<T>::value;


template<class T>
struct is_multi_dimensional_container {
        template<class U>
        static constexpr auto check(U&&)
                -> decltype(std::begin(std::declval<typename U::value_type>()),std::true_type{});

        static constexpr auto check(...)
                -> std::false_type;

        static constexpr bool value = decltype(check(std::declval<T>()))::value;
};

template<class T>
constexpr bool is_multi_dimensional_container_v
        = is_multi_dimensional_container<T>::value;

template<class T>
constexpr bool is_one_dimensional_container_v
        = is_container_v<T> and !is_multi_dimensional_container_v<T>;

template<class T>
using is_one_dimensional_container
        = std::conditional_t<is_one_dimensional_container_v<T>,std::true_type,std::false_type>;
