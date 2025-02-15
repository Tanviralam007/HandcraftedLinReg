#include "../include/DataHandler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>

DataHandler::DataHandler(const std::string& filename){
    std::ifstream file(filename);
    if(!file.is_open()){
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    bool first_line = true; 
    
    while(std::getline(file, line)){
        if(first_line){
            first_line = false; // top row of the file
            continue;
        }

        std::stringstream ss(line);
        double experience, salary;
        char comma;

        if(ss >> experience >> comma >> salary){
            dataset.push_back({experience, salary});
        }
    }
    file.close();
}

void DataHandler::split_data(double train_ratio){
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(dataset.begin(), dataset.end(), g);

    size_t train_size = static_cast<size_t>(train_ratio * dataset.size());

    std::vector<std::pair<double, double>> train_set(dataset.begin(), dataset.begin() + train_size);
    std::vector<std::pair<double, double>> test_set(dataset.begin() + train_size, dataset.end());

    save_to_file("../data/train.csv", train_set);
    save_to_file("../data/test.csv", test_set);
}

void DataHandler::save_to_file(const std::string& filename, const std::vector<std::pair<double, double>>& data){
    std::ofstream file(filename);
    if(!file.is_open()){
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    file << "Experience,Salary\n"; // write header
    for(const auto& pair : data){
        file << pair.first << "," << pair.second << "\n";
    }
    file.close();
}

