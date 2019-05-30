#include <iostream>
#include <bitset>
#include <math.h>  

#include "rsa-crypt.h"
#include "resources.h"

int main() {
  RSA_CRYPT rsa(7907 , 7919 , true); 
  rsa.decrypt(rsa.encrypt(2));
}

