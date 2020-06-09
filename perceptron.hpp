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
    double n; //learning rate
    double theta = 0; //threshold
    std::vector<double> w; //weights

    perceptron(const int &dimension);

    void train(const int &i, const int &expected);
    void train(const int &i, const int &expected, const double &xi);

    int compute(std::vector<double> x_inputs);


};

}


#endif