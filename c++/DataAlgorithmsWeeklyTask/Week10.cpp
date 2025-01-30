#include <iostream>
#include "MatrixClass.h"

// Gaussian solver method found in MatrixClass.h 

int main(){
    int SIZE = 3;
    // Creates augmentented Matrix
    DoubleMatrix augmentedMatrix(SIZE,SIZE + 1,1.0);
    augmentedMatrix(1,1) = 2.0;
    augmentedMatrix(1,2) = 4.0;
    augmentedMatrix(2,2) = 9.0;
    augmentedMatrix(2,1) = 3.0;
    augmentedMatrix(0,3) = 1.0;
    augmentedMatrix(1,3) = -1.0;
    augmentedMatrix(2,3) = 1.0;

    // Displays augmented matrix
    augmentedMatrix.displayMatrix();

    std::vector<double> answer = augmentedMatrix.gaussianSolver();

    // Displays answer
    std::cout << "Solution for this matrix is: ";
    for(int i = 0; i < SIZE; i++){
        std::cout << answer[i] << " ";
    }
    return 0;
}