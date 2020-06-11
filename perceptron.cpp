#include "perceptron.hpp"

namespace WYLJUS002{

    perceptron::perceptron(const int &dimension){
        idim = dimension;
        w0 = 0; //offset
        n = 0.2; //default learning rate???
        theta = 1.5; //threshold
        w = std::vector<double>(idim); //weights

        for (int wi = 0; wi < w.size(); ++wi){
            w[wi] = (rand() % 100)/100.0;
        }
        
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

        double deltawi;
        w0 += n*(expected - output); //Training of offset
        for(int i = 0; i < idim; i++){
            deltawi = n*(expected - output)*x_inputs[i];
            w[i] += deltawi;
        }
    }

    

}