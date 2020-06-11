#include "perceptron.hpp"

using namespace WYLJUS002;

void print_compute(std::vector<double> &x_inputs, perceptron &pcp){
    int result = pcp.compute(x_inputs);
    std::cout << "Input of " << x_inputs[0] << ", " << x_inputs[1] << " => " << result << std::endl; 
}

/*
bool check_and(std::vector<double> &x_inputs, const int &result){
    return ((int)x_inputs[0] & (int)x_inputs[1]) == result;
}

bool check_or(std::vector<double> &x_inputs, const int &result){
    return ((int)x_inputs[0] | (int)x_inputs[1]) == result;
}

bool check_nand(std::vector<double> &x_inputs, const int &result){
    return !((int)x_inputs[0] & (int)x_inputs[1]) == result;
}
*/

bool check_weights(std::vector<double> &w_old, std::vector<double> &w_new){
    double epsilon = 1e-10;
    for (int i = 0; i < w_old.size(); ++i){
        if (fabs(w_old[i] - w_new[i]) > epsilon){
            return false;
        }
    }
    return true;
}

int main(int argc , const char** argv){
    std::vector<std::vector<std::vector<double>>> training_and = {{{0,0},{0}}, {{0, 1},{0}}, {{1,0},{0}}, {{1,1},{1}}};
    std::vector<std::vector<std::vector<double>>> training_or = {{{0,0},{0}}, {{0, 1},{1}}, {{1,0},{1}}, {{1,1},{1}}};
    std::vector<std::vector<std::vector<double>>> training_nand = {{{0,0},{1}}, {{0, 1},{1}}, {{1,0},{1}}, {{1,1},{0}}};

    perceptron and_perceptron(2);
    perceptron or_perceptron(2);
    perceptron nand_perceptron(2);

    int max_iterations = 10000;

    //Training variables
    int points = 0;
    int i;
    std::vector<double> w_old;
    std::vector<double> w_new;

    //Train AND Gate
    for(i = 0; i < max_iterations && points < 4; i++){
        w_old = and_perceptron.get_weights();
          
        and_perceptron.train(training_and[i%4][0], (int) training_and[i%4][1][0]);

        if (check_weights(w_old, w_new = and_perceptron.get_weights()))
            points++;
        else
            points = 0;           
    }

    std::cout << "AND - training complete in " << i << " iterations\n";
    for(int i = 0; i < 4; i++){
        print_compute(training_and[i][0], and_perceptron);
    }


    //Train OR Gate
    points = 0;
    for(i = 0; i < max_iterations && points < 4; i++){
        w_old = or_perceptron.get_weights();
        
        or_perceptron.train(training_or[i%4][0], (int) training_or[i%4][1][0]);

        if (check_weights(w_old, w_new = or_perceptron.get_weights()))
            points++;
        else
            points = 0; 
    }

    std::cout << "OR - training complete in " << i << " iterations\n";
    for(int i = 0; i < 4; i++){
        print_compute(training_or[i][0], or_perceptron);
    }


    //Train NAND Gate
    points = 0;
    for(i = 0; i < max_iterations && points < 4; i++){
        w_old = nand_perceptron.get_weights();

        nand_perceptron.train(training_nand[i%4][0], (int) training_nand[i%4][1][0]);

        if (check_weights(w_old, w_new = nand_perceptron.get_weights()))
            points++;
        else
            points = 0;      
    }

    std::cout << "NAND - training complete in " << i << " iterations\n";
    for(int i = 0; i < 4; i++){
        print_compute(training_nand[i][0], nand_perceptron);
    }

}