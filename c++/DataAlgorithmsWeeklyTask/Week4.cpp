#include <iostream>
#include <vector>
#include <chrono>

class DoubleMatrix{
    private:
        // Private attributes
        int Columns, Rows;
        std::vector<double> data;

    public:
        // public attributes
    DoubleMatrix(int Rows, int Columns, double initaliser = 0.0)
        : Rows(Rows), Columns(Columns), data(Rows * Columns, initaliser) {}

    // Operators
    double& operator()(int r, int c){
        if (r >= Rows || c >= Columns){
            throw std::out_of_range("index out of range");
        }
        return data[r * Columns + c];
    }

    double operator()(int r, int c) const{
        if (r >= Rows || c >= Columns){
            throw std::out_of_range("index out of range");
        }
        return data[r * Columns + c];
    }

    void displayMatrix(){
        // Display all elements of matrix
        std::cout<<"Matrix: " << '\n';
            for (int i = 0; i < Rows; i++){
                for (int j = 0; j < Columns; j++){
                    // Display elements of this matrix
                    std::cout << (*this)(i,j) << " ";
                }
                // New line
                std::cout << '\n';
            }
        }
    
    void sumMatrix(){
        // Sums all elements in the matrix
        double sum = 0;
            for (int i = 0; i < Rows; i++) {
                for (int j = 0; j < Columns; j++){
                    // Adds current element of matrix to sum
                    sum += (*this)(i,j);
                }
            }
            //Displays sum
            std::cout << "Sum of Matrix is: " << sum << std::endl;;
        }

    DoubleMatrix matrixAdd(const DoubleMatrix &A, const DoubleMatrix &B, int SIZE){
        // Adds matrices
        DoubleMatrix resultingMatrix(SIZE, SIZE, 0.0);
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                // Adds both matrices together storing there values
                resultingMatrix(i,j) = A(i,j) + B(i,j);
            }
        }
        // Returns result matrix
        return resultingMatrix;
    } 

    void matrixDivide(const DoubleMatrix &A, DoubleMatrix &A11, DoubleMatrix &A12, DoubleMatrix &A21, DoubleMatrix &A22, int SIZE){
        // Divides matrices into smaller sub matrices
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                A11(i,j) = A(i,j);                
                A12(i,j) = A(i,j+SIZE);            
                A21(i,j) = A(i+SIZE,j);            
                A22(i,j) = A(i+SIZE,j+SIZE); 
            }
        }
    }

    void matrixMultiplyRecursive(const DoubleMatrix &A, const DoubleMatrix &B, DoubleMatrix &C, int SIZE){
        // Base Case
        if(SIZE == 1){
            C(0,0) = A(0,0) * B(0,0);
            return;
        }

        // Divide and Conquer

        int updatedSize = SIZE / 2;
        DoubleMatrix A11(updatedSize, updatedSize, 0.0),  A12(updatedSize, updatedSize, 0.0);
        DoubleMatrix A21(updatedSize, updatedSize, 0.0),  A22(updatedSize, updatedSize, 0.0);

        DoubleMatrix B11(updatedSize, updatedSize, 0.0),  B12(updatedSize, updatedSize, 0.0);
        DoubleMatrix B21(updatedSize, updatedSize, 0.0),  B22(updatedSize, updatedSize, 0.0);

        DoubleMatrix C11(updatedSize, updatedSize, 0.0),  C12(updatedSize, updatedSize, 0.0);
        DoubleMatrix C21(updatedSize, updatedSize, 0.0),  C22(updatedSize, updatedSize, 0.0);
        
        matrixDivide(A, A11, A12, A21, A22, updatedSize);
        matrixDivide(B, B11, B12, B21, B22, updatedSize);

        DoubleMatrix M1(updatedSize, updatedSize, 0.0), M2(updatedSize, updatedSize, 0.0);

        matrixMultiplyRecursive(A11, B11, M1, updatedSize);
        matrixMultiplyRecursive(A12, B21, M2, updatedSize);
        C11 = matrixAdd(M1, M2, updatedSize);

        matrixMultiplyRecursive(A11, B12, M1, updatedSize);
        matrixMultiplyRecursive(A12, B22, M2, updatedSize);
        C12 = matrixAdd(M1, M2, updatedSize);

        matrixMultiplyRecursive(A21, B11, M1, updatedSize);
        matrixMultiplyRecursive(A22, B21, M2, updatedSize);
        C21 = matrixAdd(M1, M2, updatedSize);

        matrixMultiplyRecursive(A21, B12, M1, updatedSize);
        matrixMultiplyRecursive(A22, B22, M2, updatedSize);
        C22 = matrixAdd(M1, M2, updatedSize);

        for(int i=0;i<updatedSize;i++){
            for(int j=0;j<updatedSize;j++){
                C(i,j) = C11(i,j);                     
                C(i,j + updatedSize) = C12(i,j);      
                C(i + updatedSize, j) = C21(i,j);         
                C(i + updatedSize, j + updatedSize) = C22(i,j);
            }
        }
    }
};

int main(){
    int SIZE = 4;
    DoubleMatrix matrix1(SIZE, SIZE, 2.0);
    DoubleMatrix matrix2(SIZE, SIZE, 2.0);
    DoubleMatrix matrix3(SIZE, SIZE, 0.0);
    //Times sum of matrix
    auto start = std::chrono::high_resolution_clock::now();
    matrix1.sumMatrix();
    auto end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "duration of execution (microseconds): " << duration.count() << std::endl;
    
    std::cout << std::endl;
    std::cout << "Matrix 3:" << std::endl;
    
    // Recursive multiply
    matrix1.matrixMultiplyRecursive(matrix1,matrix2,matrix3,SIZE);

    matrix3.displayMatrix();
    

    return 0;
}



