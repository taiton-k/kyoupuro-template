#include <bits/stdc++.h>




using swallow = std::initializer_list<bool>;

template<bool B>using enabler = std::enable_if_t<B,std::nullptr_t>;

constexpr auto call_begin = [](auto a)->decltype(std::begin(std::declval<decltype(a)>()),void()){};
template<class T>using is_container = std::is_invocable<decltype(call_begin),T>;
template<class T>constexpr bool is_container_v = is_container<T>::value;

//template<class T>using is_two_dimensional_container = std::is_invocable<decltype(call_begin),typename T::value_type>;
template<class T,typename U = typename T::value_type>auto has_value_type_f(int)->decltype(std::declval<typename T::value_type>(),std::true_type{}){}
template<class T>auto has_value_type_f(long)->decltype(std::false_type{}){}
template<class T>using has_value_type = decltype(has_value_type_f<T>(0));
template<class T>constexpr bool has_value_type_v = has_value_type<T>::value;

template<class T>using is_two_dimensional_container = std::conditional<is_container_v<T> and has_value_type_v<T>,std::is_invocable<decltype(call_begin),typename T::value_type>,std::false_type>;
template<class T>constexpr bool is_two_dimensional_container_v = is_two_dimensional_container<T>::value;

template<class T>using is_one_dimensional_container = std::conditional<is_container_v<T> and !is_two_dimensional_container_v<T>,std::true_type,std::false_type>;
template<class T>constexpr bool is_one_dimensional_container_v = is_one_dimensional_container<T>::value;

template<typename T,typename U>using if_integral = std::enable_if_t<std::is_integral_v<T>,U>;
template<typename T,typename U>using if_floating_point = std::enable_if_t<std::is_floating_point_v<T>,U>;
template<typename T,typename U>using if_container = std::enable_if_t<is_container_v<T>,U>;
template<typename T,typename U>using if_two_dimensional_container = std::enable_if_t<is_two_dimensional_container_v<T>,U>;
template<typename T,typename U>using if_one_dimensional_container = std::enable_if_t<is_one_dimensional_container_v<T>,U>;
template<typename T,typename U>using if_other = std::enable_if_t<!std::is_integral_v<T> and !std::is_floating_point_v<T> and !is_container_v<T>,U>;

template<class T>auto call_emplace_back = []()->void{std::declval<T>().emplace_back();};
template<class T>using has_emplace_back = std::is_invocable<decltype(call_emplace_back<T>)>;
template<class T>constexpr bool has_emplace_back_v = has_emplace_back<T>::value;

template<class T>auto call_emplace = []()->void{std::declval<T>().emplace();};
template<class T>using has_emplace = std::is_invocable<decltype(call_emplace<T>)>;
template<class T>constexpr bool has_emplace_v = has_emplace<T>::value;

template<class T,class U>using if_emplace_back = std::enable_if_t<has_emplace_back_v<T>,U>;
template<class T,class U>using if_emplace = std::enable_if_t<has_emplace_v<T>,U>;





using namespace std;


void yorn(bool flag){
        cout << (flag ? "Yes" : "No") << endl;
}

int main(void){
        yorn(has_value_type_v<int>);
        yorn(has_value_type_v<vector<int>>);
}
