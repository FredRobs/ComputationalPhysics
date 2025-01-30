#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

std::vector<std::pair<double, double>> readCSVFile(const std::string& fileName){
    std::vector<std::pair<double, double>> data;
    std::ifstream file(fileName);

    if(!file.is_open()) {
        std::cerr << "Cannot open file " << fileName << std::endl;
        return data;  
    }

    std::string lineText;
    while(std::getline(file, lineText)){
        std::stringstream ss(lineText);
        std::string timeValues, positionValues;

        while(std::getline(ss, timeValues, ',') && std::getline(ss, positionValues, ',')){
            try{
                double time = std::stod(timeValues);
                double postion = std::stod(positionValues);
                data.emplace_back(time, postion);
                }catch(const std::invalid_argument& e){
                    std::cerr << "invald data " << lineText << std::endl;
                }
            }
        }
    
    file.close();
    return data;
}

void saveCSVFile(const std::string& fileName, const std::vector<double>& data){
    std::ofstream file(fileName);

    if(!file.is_open()) {
        std::cerr << "Cannot open file " << fileName << std::endl;
        return;  
    }

    for(const auto& value : data){
        file << value << std::endl;
    }

    file.close();
    std::cout << "Saved to " << fileName << std::endl;
}