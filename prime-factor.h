#ifndef PRIME_FACTOR
#define PRIME_FACTOR
#include <vector>
#include "resources.h"


using u_long = unsigned long long int;

class prime_factor {
    static const u_long tests = 50;
    static const u_long fak = 50;
    static std::vector<u_long> primes;
public:
    static void pollard(u_long mod) {
        bool finnished = false;
        for(u_long i = 2;i <tests && !finnished; i++) {
            u_long number = i;
            for(u_long f = 1; f < fak && !finnished; f++) {
                number = (std::pow(number, f));
                number = number % mod;
                if(resources::gcd(number - 1, mod) != 1 && number != 1 && number != 0) {
                    pollard(resources::gcd(number - 1, mod));
                    pollard(mod / resources::gcd(number - 1, mod));
                    finnished = true;
                }
            }   
        }
        if(!finnished) prime_factor::primes.push_back(mod);
    }
    static std::vector<u_long> start(u_long value) {
        primes.resize(0);
        pollard(value);
        return primes;
    }
};



#endif