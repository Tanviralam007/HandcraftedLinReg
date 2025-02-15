#ifndef DATA_HANDLER_H
#define DATA_HANDLER_H

#include <vector>
#include <string>

class DataHandler{
    public:
        DataHandler(const std::string& filename);
        void split_data(double train_ratio);
        void save_to_file(const std::string& filename, const std::vector<std::pair<double, double>>& data);
    
        private:
        std::vector<std::pair<double, double>> dataset;
};
#endif