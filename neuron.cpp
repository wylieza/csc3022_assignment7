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


namespace WYLJUS002{

    neuron::neuron(const int &dimension){
        idim = dimension;
        w0 = 0;
        w = std::vector<double>(idim); //weights
    }

    double neuron::sigmoid(double y){
        return 1/(1.0+exp(-y));
    }

    int neuron::compute(std::vector<double> x_inputs){
        double summation = w0;
        for (int i = 0; i < idim; i++){
           summation += x_inputs[i]*w[i];
        }

        return sigmoid(summation);
    }




}





#endif

