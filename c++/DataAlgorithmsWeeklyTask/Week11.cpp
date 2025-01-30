#include <iostream>
#include <vector>
#include <cstring>

const int MAXSIZE = 100;

void LUDecomposition(int matrix[][MAXSIZE], int SIZE, int lowerPart[][MAXSIZE], int upperPart[][MAXSIZE]){
    // Initialise upper and lower
    memset(lowerPart, 0, sizeof(int) * MAXSIZE * MAXSIZE);
    memset(upperPart, 0, sizeof(int) * MAXSIZE * MAXSIZE);

    for(int i = 0; i < SIZE; i++){
        // Start LU decomposition
        // Upper section
        for(int j = i; j < SIZE; j++){
            int total = 0;
            // Sum over all lower and upper
            for(int k = 0; k < i; k++){
                total = total + (lowerPart[i][k] * upperPart[k][j]);
            }
            // Evaluate upper part
            upperPart[i][j] = matrix[i][j] - total;
        } 

        for(int j = i; j < SIZE; j++){
            // Checks if is diagonal element then sets value to 1 
            if(i == j){
                lowerPart[i][i] = 1;
            }
            else{
                // Sum over all lower and upper
                int total = 0;
                for(int k = 0; k < i; k++){
                    total = total + (lowerPart[j][k] * upperPart[k][i]);
                }
                // Evaluate lower part
                lowerPart[j][i]= (matrix[j][i] - total) / upperPart[i][i];
            }
        }
    }

    // Prints all the values of the matrix
    std::cout << "Lower part" << std::endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Prints current value
            std::cout << lowerPart[i][j] << " | ";
        }
        // Starts new line
        std::cout << std::endl;
    }

    // Prints all the values of the matrix
    std::cout << "Upper part" << std::endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Prints current value
            std::cout << upperPart[i][j] << " | ";
        }
        // Starts new line
        std::cout << std::endl;
    }
}



// Forward substitiion
std::vector<double> forwardSubstitution(int lowerPart[][MAXSIZE], int SIZE, const std::vector<double>& bVector) {
        // Initialise y vector
        std::vector<double> yValue(SIZE, 0);
        for(int i = 0; i < SIZE; i++){
            // Initialise total
            double total = 0;
            for(int j = 0; j < SIZE; j++){
                // Sum total
                total = total + lowerPart[i][j] * yValue[j];
            }
            // Calculate value for y vector
            yValue[i] = bVector[i] - total;
        }
    return yValue;
}

// Back substitution
std::vector<double> backSubstitution(int upperPart[][MAXSIZE], int SIZE, const std::vector<double>& yValue) {
        // Initialise x vector
        std::vector<double> xValue(SIZE, 0);
        for(int i = SIZE - 1; i >= 0; i--){
            // Initialise total
            double total = 0;
            for(int j = i + 1; j < SIZE; j++){
                // Sum total
                total = total + upperPart[i][j] * xValue[j];
            }
            // Calculate value for x vector
            xValue[i] = (yValue[i] - total) / upperPart[i][i];
        }
    return xValue;
}

// Solve linear system Ax = b
std::vector<double> solveLinearSystem(int matrix[][MAXSIZE], int SIZE, const std::vector<double>& bVector){
    // Initilise lower and upper matrix
    int lowerPart[MAXSIZE][MAXSIZE] = {0};
     int upperPart[MAXSIZE][MAXSIZE] = {0};

    // Performs LU Decomposition
    LUDecomposition(matrix, SIZE, lowerPart, upperPart);

    // Forward substitution 
    std::vector<double> yValue = forwardSubstitution(lowerPart, SIZE, bVector);

    // Backward substitution
    std::vector<double> xValue = backSubstitution(upperPart, SIZE, yValue);

    return xValue;
}


int main(){
    // Size of matrix
    int SIZE = 3;

    // Matrix
    int matrix[][MAXSIZE] = { { 2, -1, -2 },
                        { -4, 6, 3 },
                        { -4, -2, 8 } };
    
    // Bias vector
    std::vector<double> bVector = {1, -2, 5};

    // Solve Ax = b
    std::vector<double> solution = solveLinearSystem(matrix, SIZE, bVector);

    // Display the solution 
    std::cout << "Solution: " << std::endl;
    for(double output : solution){
        std::cout << output << std::endl;
    }

    return 0;
}