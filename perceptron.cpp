#include "perceptron.hpp"

namespace WYLJUS002{

    perceptron::perceptron(const int &dimension){
        idim = dimension;
        w0 = 0; //offset
        n = 0.3; //default learning rate???
        theta = 0; //threshold
        w = std::vector<double>(idim); //weights
        
    }

    int perceptron::compute(std::vector<double> x_inputs){
        double summation = w0;
        for (int i = 0; i < idim; i++){
           summation += x_inputs[i]*w[i];
        }

        if (summation > theta)
            return 1;
        return 0;
    }

    void perceptron::train(std::vector<double> x_inputs, const int &expected){
        int output = this->compute(x_inputs);

        for(int i = 0; i < idim; i++){
            double deltawi = n*(expected - output)*x_inputs[i];
            w[i] += deltawi;
        }
    }

}