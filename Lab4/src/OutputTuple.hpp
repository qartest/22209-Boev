#pragma once
#include <iostream>
#include <tuple>

template< typename Tuple, std::size_t Index>
struct TuplePrinter
{
    static void PrintT(std::ostream& os, const Tuple& t){
        TuplePrinter<Tuple, Index - 1>::PrintT(os, t);
        os << std::get<Index>(t) << " ";
    }
};

template <typename Tuple>
struct TuplePrinter<Tuple, 0>{
    static void PrintT(std::ostream& os, const Tuple& t){
        os << std::get<0>(t) << " ";
    }
};

template <typename Ch, typename Tr, typename... Args>
auto operator<<(std::basic_ostream<Ch, Tr>& os, std::tuple<Args...>const& t) -> decltype(os){
    TuplePrinter<decltype(t), sizeof...(Args) - 1>::PrintT(os, t);
   return os;
   
}