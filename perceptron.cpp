#include "perceptron.hpp"

namespace WYLJUS002{

    perceptron::perceptron(const int &dimension){
        idim = dimension;
        w0 = 0; //offset
        n = 0.6; //default learning rate???
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

    void perceptron::train(const int &i, const int &expected){
        if(!computed){
            std::cout << "Attempt to train without computing iteration first, attempting to compute\n";
            compute();
        }

        double deltawi = n*(expected - output)*x[i];
        w[i] += deltawi;
    }

    void perceptron::train(const int &i, const int &expected, const double &xi){
        double temp = x[i];
        x[i] = xi;
        train(i, expected);
        x[i] = temp;
    }



}