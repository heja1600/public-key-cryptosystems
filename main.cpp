#include <iostream>
#include <bitset>
#include <math.h>  

#include "rsa-crypt.h"
#include "elgamal-crypt.h"
#include "resources.h"

int main() {
  ELGAMAL_CRYPT eg(23);
  eg.decrypt(eg.encrypt(10));
}

