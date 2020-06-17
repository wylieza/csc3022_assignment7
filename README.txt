>>> Assignment 7 - Artificial Neural Networks <<<


--- Instructions for use ---
This git repository contains code to answer sections 1 and 2 from assignment 7.
The answers are provided in a seperate text file called 'answers.txt'. Running
the program will produce the same answers, displayed in the terminal.


The application is executed by typeing "make run" (which launches both applications)

-- Program Arguments --

 > This program take no arguments <


--- MAKEFILE ---
The makefile allows for compilation, execution and removel of binaries.

Command -> Action
_________________________________________________________________________________________________
>> Standard Commands <<
make                            -> Compile source code
make clean                      -> Remove binaries and results file
make run                        -> Runs both applications
make runxor                     -> Runs only section 1's application
make runann                     -> Runs only section 2's application
_________________________________________________________________________________________________

Note: The application can also be executed in the terminal using the usual ./<binary name>


--- Source Code Description ---
>> xor_drive.cpp <<
This is the driver class for the xor perceptron based logic gate. (Answers section 1)

>> perceptron.hpp <<
This is the header code for the perceptron class.

>> perceptron.cpp <<
This is the source code for the perceptron class, containing the implementation.

>> ann_driver.cpp <<
This is the driver class for the neuron based ANN. (Answers section 2)

>> neuron.cpp <<
This is the neuron class and contains both the definition and implemention to decrease the
number of files being submitted for such a specific implementation.


--- Student Details ---
Work of Justin Wylie
Student number: WYLJUS002