#include <iostream>
#include <chrono>
#include <vector>

typedef std::vector<std::vector<int>> matrix;

matrix initaliseMatrix(int rows, int cols){
	// Generate zero matrix
	return matrix(rows, std::vector<int>(cols, 0));
}

matrix randomMatrix(int rows, int cols){
	// Generate random matrix
	std::srand(std::time(0));
	matrix returnMatrix(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            returnMatrix[i][j] = std::rand() % 10 + 1; 
        }
    }
	return returnMatrix;
}

void matrixDivide(const matrix &A, matrix &A11, matrix &A12, matrix &A21, matrix &A22){
	int size = A.size() / 2;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			// Split matrices into smaller sub matrices
			A11[i][j] = A[i][j];                
            A12[i][j] = A[i][j + size];            
            A21[i][j] = A[i + size][j];            
            A22[i][j] = A[i + size][j + size]; 
		}
	}
}

matrix matrixAddRecursive(const matrix &A, const matrix &B){
    int size = A.size();
	matrix resultingMatrix = initaliseMatrix(size, size);
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
            resultingMatrix[i][j] = A[i][j] + B[i][j];
		}
	}
	return resultingMatrix;
}

matrix matrixSubRecursive(const matrix &A, const matrix &B){
    int size = A.size();
	matrix resultingMatrix = initaliseMatrix(size, size);
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			// Subtracting the two matrices
            resultingMatrix[i][j] = A[i][j] - B[i][j];
		}
	}
	// Returns matrices
	return resultingMatrix;
}

matrix matrixMultiplyNaive(const matrix &A, const matrix &B){
    int size = A.size();
	// Calculates naive matrix multiplication
	matrix resultingMatrix = initaliseMatrix(size, size);
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			for(int k=0;k<size;k++){
				// Sums matrix
            	resultingMatrix[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	// returns matrix
	return resultingMatrix;
}

void matrixMultiplyRecursive(const matrix &A, const matrix &B, matrix &C, int n){
	// Base Case
	if(n == 1){
		C[0][0] = A[0][0] * B[0][0];
		return;
	}

	// Divide and Conquer
	int updatedSize = n / 2;
	matrix A11 = initaliseMatrix(updatedSize, updatedSize),  A12 = initaliseMatrix(updatedSize, updatedSize);
	matrix A21 = initaliseMatrix(updatedSize, updatedSize),  A22 = initaliseMatrix(updatedSize, updatedSize);

	matrix B11 = initaliseMatrix(updatedSize, updatedSize),  B12 = initaliseMatrix(updatedSize, updatedSize);
	matrix B21 = initaliseMatrix(updatedSize, updatedSize),  B22 = initaliseMatrix(updatedSize, updatedSize);

	matrix C11 = initaliseMatrix(updatedSize, updatedSize),  C12 = initaliseMatrix(updatedSize, updatedSize);
	matrix C21 = initaliseMatrix(updatedSize, updatedSize),  C22 = initaliseMatrix(updatedSize, updatedSize);
	
	// Create new submatrices
	matrixDivide(A, A11, A12, A21, A22);
	matrixDivide(B, B11, B12, B21, B22);

    matrix M1 = initaliseMatrix(updatedSize, updatedSize), M2 = initaliseMatrix(updatedSize, updatedSize);

	matrixMultiplyRecursive(A11, B11, M1, updatedSize);
    matrixMultiplyRecursive(A12, B21, M2, updatedSize);
    C11 = matrixAddRecursive(M1, M2);

    matrixMultiplyRecursive(A11, B12, M1, updatedSize);
    matrixMultiplyRecursive(A12, B22, M2, updatedSize);
    C12 = matrixAddRecursive(M1, M2);

    matrixMultiplyRecursive(A21, B11, M1, updatedSize);
    matrixMultiplyRecursive(A22, B21, M2, updatedSize);
    C21 = matrixAddRecursive(M1, M2);

    matrixMultiplyRecursive(A21, B12, M1, updatedSize);
    matrixMultiplyRecursive(A22, B22, M2, updatedSize);
    C22 = matrixAddRecursive(M1, M2);

	for(int i=0;i<updatedSize;i++){
		for(int j=0;j<updatedSize;j++){
            C[i][j] = C11[i][j];                     
            C[i][j + updatedSize] = C12[i][j];      
            C[i + updatedSize][j] = C21[i][j];         
            C[i + updatedSize][j + updatedSize] = C22[i][j];
		}
	}
}

void StressenAlgorithm(const matrix &A, const matrix &B, matrix &C, int n){
	// Base Case
	if(n == 1){
		C[0][0] = A[0][0] * B[0][0];
		return;
	}

	// Divide and Conquer
	int updatedSize = n / 2;
	matrix A11 = initaliseMatrix(updatedSize, updatedSize),  A12 = initaliseMatrix(updatedSize, updatedSize);
	matrix A21 = initaliseMatrix(updatedSize, updatedSize),  A22 = initaliseMatrix(updatedSize, updatedSize);

	matrix B11 = initaliseMatrix(updatedSize, updatedSize),  B12 = initaliseMatrix(updatedSize, updatedSize);
	matrix B21 = initaliseMatrix(updatedSize, updatedSize),  B22 = initaliseMatrix(updatedSize, updatedSize);

	matrix C11 = initaliseMatrix(updatedSize, updatedSize),  C12 = initaliseMatrix(updatedSize, updatedSize);
	matrix C21 = initaliseMatrix(updatedSize, updatedSize),  C22 = initaliseMatrix(updatedSize, updatedSize);
	
	// Create new sub matrices
	matrixDivide(A, A11, A12, A21, A22);
	matrixDivide(B, B11, B12, B21, B22);

    matrix M1 = initaliseMatrix(updatedSize, updatedSize);
	matrix M2 = initaliseMatrix(updatedSize, updatedSize);
	matrix M3 = initaliseMatrix(updatedSize, updatedSize);
	matrix M4 = initaliseMatrix(updatedSize, updatedSize);
	matrix M5 = initaliseMatrix(updatedSize, updatedSize);
	matrix M6 = initaliseMatrix(updatedSize, updatedSize);
	matrix M7 = initaliseMatrix(updatedSize, updatedSize);

	StressenAlgorithm(matrixAddRecursive(A11, A22), matrixAddRecursive(B11, B22), M1, updatedSize);
	StressenAlgorithm(matrixAddRecursive(A21, A22),B11, M2, updatedSize);
	StressenAlgorithm(A11, matrixSubRecursive(B12,B22), M3, updatedSize);
	StressenAlgorithm(A22, matrixSubRecursive(B21,B11), M4, updatedSize);
	StressenAlgorithm(matrixAddRecursive(A11, A12), B22, M5, updatedSize);
	StressenAlgorithm(matrixSubRecursive(A21, A11), matrixAddRecursive(B11,B12), M6, updatedSize);
	StressenAlgorithm(matrixSubRecursive(A12, A22), matrixAddRecursive(B21,B22), M7, updatedSize);

    C11 = matrixAddRecursive(matrixSubRecursive(matrixAddRecursive(M1, M4), M5), M7);
    C12 = matrixAddRecursive(M3, M5);
    C21 = matrixAddRecursive(M2, M4);
    C22 = matrixAddRecursive(matrixSubRecursive(matrixAddRecursive(M1,M3), M2), M6);

	for(int i=0;i<updatedSize;i++){
		for(int j=0;j<updatedSize;j++){
            C[i][j] = C11[i][j];                     
            C[i][j + updatedSize] = C12[i][j];      
            C[i + updatedSize][j] = C21[i][j];         
            C[i + updatedSize][j + updatedSize] = C22[i][j];
		}
	}
}


void displayMatrix(const matrix &Matrix){
std::cout<<"Displaying matrix: " << '\n';
	for (const auto &row : Matrix) {
        for (const auto &val : row)
            std::cout << val << " ";
        	std::cout << '\n';
    }
}

int main( ) 
{  
	int SIZE = 16;


	matrix rand1 = randomMatrix(SIZE,SIZE);
	matrix rand2 = randomMatrix(SIZE,SIZE);

	matrix C2 = initaliseMatrix(SIZE, SIZE);
	matrix C3 = initaliseMatrix(SIZE, SIZE);

	// Times recursive
	auto start = std::chrono::high_resolution_clock::now();
	matrixMultiplyRecursive(rand1, rand2, C2, SIZE);
	auto end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	// Times naive
	auto start2 = std::chrono::high_resolution_clock::now();
	matrix testMatrix = matrixMultiplyNaive(rand1, rand2);
	auto end2 = std::chrono::high_resolution_clock::now();

	auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);

	// Times strassen
	auto start3 = std::chrono::high_resolution_clock::now();
	StressenAlgorithm(rand1, rand2, C3, SIZE);
	auto end3 = std::chrono::high_resolution_clock::now();

	auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3);

	// Output the result matrix
    std::cout << "Result Matrix C:" << '\n';
    displayMatrix(C2);
	std::cout << std::endl;
	std::cout << "Result Matrix C:" << '\n';
    displayMatrix(testMatrix);
	std::cout << std::endl;
	std::cout << "Result Matrix C:" << '\n';
    displayMatrix(C3);
	std::cout << std::endl;

	std::cout << "Time taken: recursive: " << duration.count() << " microseconds" << std::endl;
    std::cout << "Time taken: naive: " << duration2.count() << " microseconds" << std::endl;
	std::cout << "Time taken: stressen: " << duration3.count() << " microseconds" << std::endl;

    return 0;
}

