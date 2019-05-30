#ifndef RSA
#define RSA
#include "resources.h"
using u_long = unsigned long long int;

class RSA_CRYPT {
    u_long p, q, n, e, d;
    bool fi;
public:
    RSA_CRYPT(const u_long p, const u_long q, const bool fi)
        : p(p),q(q), fi(fi), n(p*q) {
            this->e = resources::generate_e((p-1)*(q-1));
            this->d = resources::mult_inverse(e , (p-1)*(q-1));
    } 
    u_long encrypt(const u_long x) const{
        std::cout<<" e: "<<e<<" n:"<<n<<" x:"<<x;
        u_long y = resources::high_exponents(x, e, n);
        std::cout<<" y = "<<y<<std::endl;
        return y;
    }
    u_long decrypt(const u_long y) const{
        std::cout<<" d: "<<d<<" n:"<<n<<" y:"<<y;
        u_long x = resources::high_exponents(y, d, n);
        std::cout<<" x = "<<x<<std::endl;
        return x;
    }
};


#endif