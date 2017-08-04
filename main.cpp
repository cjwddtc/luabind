#include <iostream>
#include <type_traits>
#include <boost/mpl/string.hpp>

template <class NAME,class T,T a,class Enable = void>
struct class_field_impl;

template <class NAME,class T,T a>
struct class_field_impl<NAME,T,a, std::enable_if_t<std::is_member_function_pointer_v<T> >>
{
    static constexpr const char* name="mfp";
};

template <class NAME,class T,T a >
struct class_field_impl<NAME,T,a, std::enable_if_t<std::is_member_object_pointer_v<T> >>
{
    static constexpr  const char* name="mop";
};

struct f
{
    int a;
    void w();
};

#define class_filed(name,arg) class_field_impl<boost::mpl::string<>>

#define f(a,b,c) a##b##c

template <const char* str, int len, char... suffix>
struct append {
    static constexpr const char* value() {
        return append<str, len-1, str[len-1], suffix...>::value();
    }
};


int main() {
    constexpr char a[]="asd";
    append<a,3>::value();
    //std::cout << boost::mpl::c_str<a>::value << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}