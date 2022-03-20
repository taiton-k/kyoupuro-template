#include <bits/stdc++.h>


using swallow = std::initializer_list<bool>;

template<bool B>using enabler = std::enable_if_t<B,std::nullptr_t>;

//####################

//       template<class T>struct is_container : public std::false_type {};
//       template<class ...Args>struct is_container<std::vector<Args...>> : public std::true_type {};
//       template<class ...Args>struct is_container<std::deque<Args...>> : public std::true_type {};
//       template<class ...Args>struct is_container<std::set<Args...>> : public std::true_type {};
//       template<class ...Args>struct is_container<std::multiset<Args...>> : public std::true_type {};
//       template<class ...Args>struct is_container<std::map<Args...>> : public std::true_type {};
//       template<class ...Args>struct is_container<std::unordered_set<Args...>> : public std::true_type {};
//       template<class ...Args>struct is_container<std::unordered_multiset<Args...>> : public std::true_type {};
//       template<class ...Args>struct is_container<std::unordered_multimap<Args...>> : public std::true_type {};
//       template<typename T,size_t N>struct is_container<std::array<T,N>> : public std::true_type {};
//       template<class T>constexpr bool is_container_v = is_container<T>::value;

template<class T>
struct is_container {
        template<class U>static constexpr auto check(U&& x) -> decltype(std::begin(x),std::true_type{});
        static constexpr auto check(...) -> std::false_type;
        static constexpr bool value = decltype(check(T{}))::value;
};
template<class T>constexpr bool is_container_v = is_container<T>::value;

template<class T>using is_multi_dimensional_container = std::conditional<is_container_v<T>,is_container<typename T::value_type>,std::false_type>;
template<class T>constexpr bool is_two_dimensional_container_v = is_multi_dimensional_container<T>::value;

template<class T>using is_one_dimensional_container = std::conditional<is_container_v<T>, std::negation<is_container<typename T::value_type>>, std::false_type>;
template<class T>constexpr bool is_one_dimensional_container_v = is_one_dimensional_container<T>::value;

//####################

template<typename T,typename U>using if_integral = std::enable_if_t<std::is_integral_v<T>,U>;
template<typename T,typename U>using if_floating_point = std::enable_if_t<std::is_floating_point_v<T>,U>;
template<typename T,typename U>using if_container = std::enable_if_t<is_container_v<T>,U>;
template<typename T,typename U>using if_two_dimensional_container = std::enable_if_t<is_two_dimensional_container_v<T>,U>;
template<typename T,typename U>using if_one_dimensional_container = std::enable_if_t<is_one_dimensional_container_v<T>,U>;
template<typename T,typename U>using if_other = std::enable_if_t<!std::is_integral_v<T> and !std::is_floating_point_v<T> and !is_container_v<T>,U>;

//####################

int main(void){
        using namespace std;

}
