#include "perceptron.hpp"

using namespace WYLJUS002;

int main(int argc , const char* argv){
    std::vector<perceptron> input_layer(2);
    std::vector<perceptron> hidden_layer(2);
    std::vector<perceptron> output_layer(1);

    std::vector<std::vector<std::vector<int>>> training_sets = {{{0,0},{0}}, {{0, 1},{1}}, {{1,0},{1}}, {{1,1},{0}}};

    

}