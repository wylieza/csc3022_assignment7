#include "perceptron.hpp"

using namespace WYLJUS002;

void print_compute(std::vector<double> &x_inputs, perceptron &pcp){
    int result = pcp.compute(x_inputs);
    std::cout << "Input of " << x_inputs[0] << ", " << x_inputs[1] << " => " << result << std::endl; 
}

bool check_and(std::vector<double> &x_inputs, const int &result){
    return ((int)x_inputs[0] & (int)x_inputs[1]) == result;
}

bool check_or(std::vector<double> &x_inputs, const int &result){
    return ((int)x_inputs[0] | (int)x_inputs[1]) == result;
}

bool check_nand(std::vector<double> &x_inputs, const int &result){
    return !((int)x_inputs[0] & (int)x_inputs[1]) == result;
}

int main(int argc , const char** argv){
    std::vector<std::vector<std::vector<double>>> training_xor = {{{0,0},{0}}, {{0, 1},{1}}, {{1,0},{1}}, {{1,1},{0}}};
    std::vector<std::vector<std::vector<double>>> training_and = {{{0,0},{0}}, {{0, 1},{0}}, {{1,0},{0}}, {{1,1},{1}}};
    std::vector<std::vector<std::vector<double>>> training_or = {{{0,0},{0}}, {{0, 1},{1}}, {{1,0},{1}}, {{1,1},{1}}};
    std::vector<std::vector<std::vector<double>>> training_nand = {{{0,0},{1}}, {{0, 1},{1}}, {{1,0},{1}}, {{1,1},{0}}};

    perceptron and_perceptron(2);
    perceptron or_perceptron(2);
    perceptron nand_perceptron(2);

    int max_iterations = 10000;

    std::vector<double> x = {0, 1};
    std::cout << "stefaaann my boi... watch dis space -> " << check_nand(x, 1) << '\n';

    //Train AND Gate

    for(int i = 0; i < max_iterations; i++){
        and_perceptron.train(training_and[i%4][0], (int) training_and[i%4][1][0]);
    }

    std::cout << "and training complete\n";

    for(int i = 0; i < 4; i++){
        print_compute(training_and[i][0], and_perceptron);
    }


    //Or gate
    for(int i = 0; i < 4*1000; i++){
        or_perceptron.train(training_or[i%4][0], (int) training_or[i%4][1][0]);
    }

    std::cout << "or training complete\n";

    for(int i = 0; i < 4; i++){
        print_compute(training_or[i][0], or_perceptron);
    }

    //NAND gate
    nand_perceptron.theta = -1;
    for(int i = 0; i < 4*1000; i++){
        nand_perceptron.train(training_nand[i%4][0], (int) training_nand[i%4][1][0]);
    }

    std::cout << "nand training complete\n";

    for(int i = 0; i < 4; i++){
        print_compute(training_nand[i][0], nand_perceptron);
    }

}