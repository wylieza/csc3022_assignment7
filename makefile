xor_driver: xor_driver.cpp perceptron.o
	g++ xor_driver.cpp perceptron.o -o xor_driver -std=c++11

perceptron.o: perceptron.cpp perceptron.hpp
	g++ -c perceptron.cpp -o perceptron.o -std=c++11

debug:
	g++ xor_driver.cpp perceptron.cpp -o xor_driver -std=c++11 -g
	gdb xor_driver

clean:
	rm -rf xor_driver perceptron.o

runxor: xor_driver
	./xor_driver