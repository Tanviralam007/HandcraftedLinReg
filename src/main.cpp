#include <iostream>
#include "../include/DataHandler.h"
#include "../include/LinearRegression.h"

int main(int argc, char** argv) {
    double learning_rate = 0.001;
    int num_iterations = 1000;

    DataHandler train_data("../data/train.csv");
    DataHandler test_data("../data/test.csv");

    std::vector<std::pair<double, double>>& train_set = train_data.get_dataset();
    std::vector<std::pair<double, double>>& test_set = test_data.get_dataset();

    if(train_set.empty() || test_set.empty()){
        std::cout << "Error: No train and test data set found" << std::endl;
        return 1;
    }

    std::cout << "train dataset size: " << train_set.size() << std::endl;
    std::cout << "test dataset size: " << test_set.size() << std::endl;

    // train the linear regression model
    LinearRegression model(learning_rate, num_iterations);
    model.fit(train_set);

    std::cout << "\ntrain completed" << std::endl;
    std::cout << "slope: " << model.get_slope() << std::endl;
    std::cout << "intercept: " << model.get_intercept() << std::endl;

    // make prediction
    std::cout << "enter the years of experience: ";
    int input; std::cin >> input;

    double predict_salary = model.predict(input);
    std::cout << "predict salary: " << predict_salary << std::endl;

    return 0;
}