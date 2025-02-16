#include "../include/LinearRegression.h"

LinearRegression::LinearRegression(double learning_rate, int num_iterations) {
    this->learning_rate = learning_rate;
    this->num_iterations = num_iterations;
}

double LinearRegression::predict(double experience){
    return m * experience + b;
}

double LinearRegression::get_slope(){
    return m;
}

double LinearRegression::get_intercept(){
    return b;
}

// compute loss function
double LinearRegression::mean_squared_error(const std::vector<std::pair<double, double>>& data){
    double mse = 0;
    int n = data.size();

    for(auto& data_point : data){
        double x = data_point.first;
        double y = data_point.second;

        double prediction = predict(x);

        mse = mse + (prediction - y) * (prediction - y);
    } 
    return mse / n;
}

void LinearRegression::fit(const std::vector<std::pair<double, double>>& training_data){
    int n = training_data.size();

    for(int i = 0; i < num_iterations; i++){
        double cost_m = 0;
        double cost_b = 0;

        for(auto& data_point : training_data){
            double x = data_point.first;
            double y = data_point.second;

            double prediction = m * x + b;
            
            cost_b = cost_b + (prediction - y) * x;
            cost_m = cost_m + (prediction - y);
        }

        // updating m and b
        m = m - (learning_rate / n) * cost_m;
        b = b - (learning_rate / n) * cost_b;

        if(i % 100 == 0){
            double mse = mean_squared_error(training_data);
            std::cout << "error: " << mse << std::endl;
        }
    }
}