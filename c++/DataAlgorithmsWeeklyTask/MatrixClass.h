#ifndef MATRIXCLASS_H
#define MATRIXCLASS_H

#include <iostream>
#include <vector>

class DoubleMatrix{
    private:
        int Columns, Rows;
        std::vector<double> data;

    public:
    DoubleMatrix(int Rows, int Columns, double initaliser = 0.0)
        : Rows(Rows), Columns(Columns), data(Rows * Columns, initaliser) {}

    double& operator()(int r, int c) {
        if (r >= Rows || c >= Columns) {
            throw std::out_of_range("Matrix index out of range");
        }
        return data[r * Columns + c];
    }

    double operator()(int r, int c) const {
        if (r >= Rows || c >= Columns) {
            throw std::out_of_range("Matrix index out of range");
        }
        return data[r * Columns + c];
    }

    void displayMatrix(){
        std::cout<<"Displaying matrix: " << '\n';
            for (int i = 0; i < Rows; i++) {
                for (int j = 0; j < Columns; j++){
                    std::cout << (*this)(i,j) << " ";
                }
                std::cout << '\n';
            }
        }

    void swapRow(int firstRow, int secondRow){
        for(int col = 0; col < Columns; ++col){
                std::swap((*this)(firstRow, col), (*this)(secondRow, col));
            }
        }

    void eliminateRows(int rowPivot, int columnPivot, int target){
        // Transforms augmented matrix to a row echolon form
        double multiplyingFactor = (*this)(target, columnPivot) / (*this)(rowPivot, columnPivot);
        for(int col = 0; col < Columns; ++col){
            (*this)(target, col) = (*this)(target, col) - (multiplyingFactor * (*this)(rowPivot, col));
        }
    }

    void gaussianElimination(){
        for(int rowPivot = 0; rowPivot < Rows; ++rowPivot){
            int columnPivot = rowPivot;

            if((*this)(rowPivot, columnPivot) == 0){
                for(int i = rowPivot + 1; i < Rows; i++){
                    if((*this)(i, columnPivot) != 0)
                    swapRow(rowPivot, i);
                }
            }

            for(int i = rowPivot + 1; i < Rows; i++){
                eliminateRows(columnPivot, rowPivot, i);
            }
        }
    }

    std::vector<double> backSubstitution(){
        std::vector<double> answer(Rows,0.0);
        for(int r = Rows - 1; r >= 0; --r){
            answer[r] = (*this)(r,Columns - 1);
            for(int c = r + 1; c < Columns - 1; ++c){
                answer[r] -= (*this)(r,c) * answer[c];
            }
            // Normilise by diagonal
            answer[r] /= (*this)(r, r); 
        }
        return answer;
    }

    std::vector<double> gaussianSolver(){
        gaussianElimination(); 
        displayMatrix();
        return backSubstitution(); 
    }
    
    void sumMatrix(){
        double sum = 0;
            for (int i = 0; i < Rows; i++) {
                for (int j = 0; j < Columns; j++){
                    sum += (*this)(i,j);
                }
            }
            std::cout << "Sum of Matrix is: " << sum;
        }

    DoubleMatrix matrixAdd(const DoubleMatrix &A, const DoubleMatrix &B, int SIZE){
        DoubleMatrix resultingMatrix(SIZE, SIZE, 0.0);
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                resultingMatrix(i,j) = A(i,j) + B(i,j);
            }
        }
        //resultingMatrix.displayMatrix();
        return resultingMatrix;
    } 

    void matrixDivide(const DoubleMatrix &A, DoubleMatrix &A11, DoubleMatrix &A12, DoubleMatrix &A21, DoubleMatrix &A22, int SIZE){
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




#endif
