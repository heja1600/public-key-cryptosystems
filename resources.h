#ifndef RESOURCES
#define RESOURCES
#include <math.h>   
#include <bitset>
#include <iostream>
#include "bitstream.h"
#include "prime-factor.h"


using u_long = unsigned long long int;

class resources {
public: 
    static u_long gcd(const u_long a, const u_long b) {
        if (b == 0) return a; 
        return resources::gcd(b, a % b);  
    }
    static u_long fi(const u_long n, u_long result = 1) {
        for (u_long i = 2; i < n; i++) 
            if (resources::gcd(i, n) == 1) 
                result++; 
        return result; 
    }
    static u_long lambda(const u_long n) {
        u_long k=1,x,a,b,t,d=1;
        for(;d;)for(d=x=0;++x<n;d=a<2&t>1?k++:d){
            for(a=x,b=n;t=b;a=t)b=a%b;
            for(t=1,b=k;b--;t=t*x%n);
        }
        return k;   
    }

    static u_long get_relative_prime(const u_long p) {
        std::vector<u_long> primes = prime_factor::start(p - 1);
        for(u_long a = 2; a < p; a++) {
            for(auto prime: primes) {
                u_long exp = resources::high_exponents(a, prime, p);
                if(resources::gcd(exp - 1, p) != p) return a;
            }        
        }
    }

    static u_long generate_e(const u_long n) {
        return 17;
    }
    static u_long mult_inverse(u_long n, const u_long mod) {
        n %=mod;
        for(u_long x = 1; x < mod; x++) {
            if((n*x) % mod == 1) {
                return x;
            }
        }
    }
    static u_long generate_prime(const u_long max) {

    }
    static u_long high_exponents(const u_long a, const u_long e, const u_long mod) {
        u_long value = a;
        bitstream bit_stream(e);
        for(u_long i = 1; i < bit_stream.size(); i++) {;
            value = (value*value)% mod;
            if(bit_stream[i])     value = (value * a) % mod;             
        }
        return value;
    }
};


#endif