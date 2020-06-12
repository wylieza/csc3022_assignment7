all: ann_driver xor_driver

ann_driver: ann_driver.cpp neuron.cpp
	g++ ann_driver.cpp -o ann_driver -std=c++11

xor_driver: xor_driver.cpp perceptron.o
	g++ xor_driver.cpp perceptron.o -o xor_driver -std=c++11

perceptron.o: perceptron.cpp perceptron.hpp
	g++ -c perceptron.cpp -o perceptron.o -std=c++11

clean:
	rm -rf xor_driver perceptron.o ann_driver

runxor: xor_driver
	./xor_driver

runann: ann_driver
	./ann_driver

run: runxor runann