#include "neuron.cpp"

using namespace WYLJUS002;

int main(int argc , const char** argv){
    std::vector<double> x_inputs = {1.3, 2.7, 0.8};
    double y_expected = 0.36;

    //Neuron creation
    neuron hidden_1(3);
    neuron hidden_2(3);
    neuron output(2);

    //Neuron tweaking
    hidden_1.w = {0.1, 0.2, 0.5};
    hidden_1.w0 = 0.1;
    hidden_2.w = {-0.4, 1.0, -0.6};
    hidden_2.w0 = -0.3;
    output.w = {0.8, 1.0};
    output.w0 = -0.3;

    //Find the hidden layer neuron values
    std::cout << "Question 3) Hidden layer neuron values:\n";
    std::cout << "Hidden Neuron 1 -> " << hidden_1.compute(x_inputs) << '\n';
    std::cout << "Hidden Neuron 2 -> " << hidden_2.compute(x_inputs) << '\n';


    //Find the output neuron value
    std::cout << "Question 4) Output neuron value:\n";
    std::cout << "Output Neuron -> " << output.compute({hidden_1.compute(x_inputs), hidden_2.compute(x_inputs)}) << '\n';


    

    



}