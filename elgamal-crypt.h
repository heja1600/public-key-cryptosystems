#ifndef ELGAMAL
#define ELGAMAL

#include <cstdlib> 
#include "resources.h"

using u_long = unsigned long long int;

class ELGAMAL_CRYPT {
    u_long pub_p, pub_g, pub_b, pub_k_e;
    u_long bob_priv_d, 
public:
    ELGAMAL_CRYPT(const u_long pub_p, const u_long pub_g, const u_long bob_priv_d)
        :pub_p(pub_p), pub_g(pub_p), bob_priv_d(d) {
            pub_b = resources::high_exponents(g, d, p);
        }
    }
    u_long encrypt(const u_long x, const u_long alice_priv_k = -1) const {

    }
    u_long decrypt(const u_long y) const {
        
    } 

};

#endif