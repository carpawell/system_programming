#include <iostream>
#include <string>

template<class FirstArg>
void printOut(std::ostream& STR, const char* String, FirstArg first_arg){
    while(*String != '%'){
        STR << *String;
        String++;
    }
    STR << first_arg;
    String++;

    while(*String != '\0' ){
        STR << *String;
        String++;
    }
}

template<class FirstArg, class ... Tail>
void printOut(std::ostream& STR, const char* String, FirstArg first_arg, Tail ... tail){
    while(*String != '%'){
        STR << *String;
        String++;
    }
    STR << first_arg;
    String++;
    printOut(STR, String, tail...);
}

template<class ... Types>
bool message(std::ostream& STR, const char* string, Types ... args){
    int num_of_string_args = 0;
    const char* copy_of_str = string;
    while(*copy_of_str != '\0' ){
        if(*copy_of_str == '%')
            num_of_string_args++;
        copy_of_str++;
    }

    if(sizeof...(args) != num_of_string_args){
        return false;
    }

    printOut(STR, string, args...);
    return true;
}