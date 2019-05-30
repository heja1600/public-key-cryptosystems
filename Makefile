output: main.cpp resources.h rsa-crypt.h elgamal-crypt.h bitstream.h prime-factor.h
	g++ -std=c++11 main.cpp -o output

clean:
	rm *.o output
