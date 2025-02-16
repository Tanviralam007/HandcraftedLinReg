#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include <vector>
#include <iostream>
class LinearRegression{
    private:
        double m;
        double b;
        double learning_rate;
        int num_iterations;
    
    public:
        LinearRegression(double learning_rate = 0.01, int num_iterations = 1000);

        // method to train(fit) the model using the training data
        void fit(const std::vector<std::pair<double, double>>& training_data);

        // method to make predictions using the trained model
        double predict(double experience);

        // method to calculate the mean squared error (MSE) of the model
        double mean_squared_error(const std::vector<std::pair<double, double>>& data);

        // getter methods for the model parameters (m and b)
        double get_slope();
        double get_intercept();
};

#endif // LINEAR_REGRESSION_H