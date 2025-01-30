#define _USE_MATH_DEFINES
#include <chrono>
#include <iostream>
#include <complex>
#include <cmath>
#include <vector>
#include "FIleReader.h"

// Standard DFT function
std::vector<std::complex<double>> DFT(const std::vector<double>& initialArray, double dx, int N){
    // Initalise empty array
    std::vector<std::complex<double>> arrayDFT(N, std::complex<double>(0.0, 0.0));

    for(int i=0; i<N; i++){
        double frequency = (i - N / 2) / (N * dx);
        for(int j=0; j<N; j++){
            double DFTangle = (-2 * M_PI * j * i) / N;
            // Equiveilent to e^i*theta
            std::complex<double> exponent = std::polar(1.0, -DFTangle); 
            // Update new Array
            arrayDFT[i] += initialArray[j] * exponent;
        }
    }
    // Return array
    return arrayDFT;    
}


// FFT function
void FFT(std::vector<std::complex<double>>& initialArray){
    // Initialise datasplit array
    size_t dataSplit = initialArray.size();

    // Basecase
    if(dataSplit <= 1){
        return;
    }

    // Split the data even and odd
    std::vector<std::complex<double>> evenArray(dataSplit / 2);
    std::vector<std::complex<double>> oddArray(dataSplit / 2);

    for(size_t i = 0; i < dataSplit / 2; i++){
        evenArray[i] = initialArray[i * 2];
        oddArray[i] = initialArray[(i * 2) + 1];
    }

    // Divide and conqueor

    FFT(evenArray);
    FFT(oddArray);
    // Combine

    for(size_t i = 0; i < dataSplit / 2; i++){
        double FFTangle = (-2 * M_PI * i) / dataSplit;
        std::complex<double> addComplex = std::polar(1.0, FFTangle) * oddArray[i];
        initialArray[i] = evenArray[i] + addComplex;
        initialArray[i + dataSplit /2] = evenArray[i] - addComplex;
    }
}

int main(){
    

    // Load and save file names
    std::string loadfileName = "data4.csv";
    std::string savefileName = "myData.csv";
    auto data = readCSVFile(loadfileName);
    int N = 2048; 


    // Parse all x position values from data file.
    std::vector<double> xValues(N);
    for (int i = 0; i < N; i++) {
        xValues[i] = data[i].second;
    }
    std::cout << "Exammple input " << xValues[0] << std::endl;

    // DFT
    /*
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::complex<double>> complexInput = DFT(xValues, 0.1, N);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    */
    // Array to complex
    std::vector<std::complex<double>> complexInput(xValues.begin(), xValues.end());

    // FFT
    
    auto start = std::chrono::high_resolution_clock::now();
    FFT(complexInput);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    

    // Save real part 
    std::vector<double> saveOutput;

    for(const auto& save : complexInput) {
        saveOutput.push_back((std::abs(save)));
    }
    
    std::cout << "Example output " << saveOutput[0] << std::endl;

    // Save output data as a csv file
    saveCSVFile(savefileName, saveOutput);
    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;

    return 0;
}