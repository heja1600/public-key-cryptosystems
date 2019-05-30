output: main.cpp resources.h rsa-crypt.h bitstream.h
	g++ -std=c++11 main.cpp -o output

clean:
	rm *.o output
