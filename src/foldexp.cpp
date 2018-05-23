#include <iostream>
#include <vector>
#include <climits>
#include <cstdint>
#include <type_traits>
#include <utility>
 
/*
* Fold expressions (C++17) reduces a parameter pack over a binary operator
*
*/

template<typename ...Args>
void printer(Args&&... args) {
    (std::cout << ... << args) << '\n';
}


// Variadic pushback using C++11 or C++14 standard, starting with base case
template <typename T>
void push_back_vec_old(std::vector<T>& v){

}

template <typename T, typename... Args>
void push_back_vec_old(std::vector<T>& v, T val, Args&&... args){
    v.push_back(val);
    push_back_vec_old<T>(v, args...);
}


// Variadic push back of a vector using foldexpressions (C++17 required)
template<typename T, typename... Args>
void push_back_vec(std::vector<T>& v, Args&&... args){
    (v.push_back(args), ...);
}

template<typename... Args>
auto calcMean(Args&&... args){
    return 1.0 / sizeof...(Args) * (args + ...);
}

// 
template <class... Args>
constexpr bool all_equal(Args const&... args) {
    if constexpr (sizeof...(Args) == 0) {
        return true;
    } else {
        return [](const auto& a0, const auto&... rest){
            return ((a0 == rest) && ...);
        }(args...);
    }
}

 
// compile-time endianness swap based on http://stackoverflow.com/a/36937049 
template<class T, std::size_t... N>
constexpr T bswap_impl(T i, std::index_sequence<N...>) {
  return (((i >> N*CHAR_BIT & std::uint8_t(-1)) << (sizeof(T)-1-N)*CHAR_BIT) | ...);
}

template<class T, class U = std::make_unsigned_t<T>>
constexpr U bswap(T i) {
  return bswap_impl<U>(i, std::make_index_sequence<sizeof(T)>{});
}
 
int main()
{
    printer(1, 2, 3, "abc");
 
    std::vector<int> v;
    push_back_vec(v, 6, 2, 45, 12);
    push_back_vec(v, 1, 2, 9);

    push_back_vec_old(v, 32, 41, 42);
    for (int i : v) std::cout << i << ' ';

    double mean = calcMean(3.2, 5.2, 5.,2.,1.);
    std::cout << "\nmean: " << mean << std::endl;
 
    std::vector<int> a;
    for(int i = 0; i< 5; i++){
        int tmp;
        std::cin >> tmp;
        a.push_back(tmp);
    }
       
    static_assert(all_equal(a));

    static_assert(all_equal(3,3,3,3,3,3));
    static_assert(!all_equal(3,4,5,6,7,8));

    static_assert(bswap<std::uint16_t>(0x1234u)==0x3412u);
    static_assert(bswap<std::uint64_t>(0x0123456789abcdefULL)==0xefcdab8967452301ULL);
}