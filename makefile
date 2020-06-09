driver: driver.cpp perceptron.o
	g++ driver.cpp perceptron.o -o driver -std=c++11

perceptron.o: perceptron.cpp perceptron.hpp
	g++ -c perceptron.cpp -o perceptron.o -std=c++11

clean:
	rm -rf driver perceptron.o

run: driver
	./driver