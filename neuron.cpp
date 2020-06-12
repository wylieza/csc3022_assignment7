#ifndef NEURON
#define NEURON

//Includes
#include <vector>
#include <iostream>
#include <cmath>
//#include <ctime>

namespace WYLJUS002{

class neuron{
    public:
    int idim; //input dimension (no. of incomming xi's)
    double w0; //bias values
    std::vector<double> w; //weights

    neuron(const int &dimension);

    int compute(std::vector<double> x_inputs);

    double sigmoid(double y);

};

}


#endif

