#ifndef PERCEPTRON
#define PERCEPTRON

//Includes
#include <vector>
#include <iostream>

namespace WYLJUS002{

class perceptron{
    bool computed;

    public:
    int idim; //input dimension (no. of incomming xi's)
    double w0; //bias values
    std::vector<double> w; //weights
    double n; //learning rate
    std::vector<double> x; //inputs
    int output; //output (active or not)

    perceptron(const int &dimension);

    void train(const int &i, const int &expected);
    void train(const int &i, const int &expected, const double &xi);

    int compute();

    int compute(std::vector<double> x_inputs);


};

}


#endif