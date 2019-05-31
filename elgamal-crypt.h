#ifndef ELGAMAL
#define ELGAMAL

#include <cstdlib> 
#include "resources.h"

using u_long = unsigned long long int;

class ELGAMAL_CRYPT {
    u_long pub_p, pub_g, pub_b, pub_k_e;
    u_long bob_priv_d;
public:
    ELGAMAL_CRYPT(const u_long pub_p, const u_long pub_g = -1, u_long bob_priv_d = -1)
        :pub_p(pub_p) {
            this->pub_g = pub_g == -1 ? resources::get_relative_prime(pub_p) : pub_g;
            this->bob_priv_d = (bob_priv_d == -1) ? std::rand() % this->pub_p: bob_priv_d; 
            this->pub_b = resources::high_exponents(this->pub_g, this->bob_priv_d, this->pub_p);
    }
    u_long encrypt(const u_long x,  u_long k = -1)  {
        k = (k != -1) ? k : resources::get_relative_prime(pub_p);
        std::cout<<" p:"<<pub_p<<" g:"<<pub_g<<" x:"<<x<<" priv_k:"<<k;
        pub_k_e = resources::high_exponents(pub_g, k, pub_p);
        u_long pub_k_m = resources::high_exponents(pub_b, k, pub_p);
        u_long y = pub_k_m * x;
        std::cout<<" y = "<<y<<std::endl;
        return y;
    }
    u_long decrypt(const u_long y) const {
        std::cout<<" k_e: "<<pub_k_e<<" p:"<<pub_p<<" g:"<<pub_g<<" y:"<<y<<" priv_d:"<<bob_priv_d;
        u_long alice_k_m = resources::high_exponents(pub_k_e, bob_priv_d, pub_p);
        u_long x = resources::mult_inverse(alice_k_m, pub_p)*y % pub_p; 
        std::cout<<" x = "<<x<<std::endl;
        return x;
    } 
};

#endif