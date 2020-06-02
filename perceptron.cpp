#include "perceptron.hpp"

namespace WYLJUS002{

    perceptron::perceptron(const int &dimension){
        int idim = dimension;
        double w0 = 0;
        w = std::vector<double>(idim);
        double n = 0.6; //default learning rate???
        x = std::vector<double>(idim); //inputs
        computed = false;
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