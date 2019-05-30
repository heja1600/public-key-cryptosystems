
#ifndef BITSTREAM
#define BITSTREAM

#include <vector>
#include <iostream>
using u_long = unsigned long long int;

class bitstream: public std::vector<bool> {
    u_long number;
public:
    bitstream (u_long number): number(number){
        for(;number > 0; number /= 2) {
            insert(begin(),number % 2);
        }
    }
    void print() const  {
        std::cout<<number<<" ";
        for(auto e : *this) std::cout<<e;
        std::cout<<std::endl;
    }
};


#endif 