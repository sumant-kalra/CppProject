// Matrix Multiplication
#include <iostream>
int main(int argc, char* argv[])
{
    int m = 3;
    int n = 2;
    int p = 3;

    int matrix1[m][n]; // m x n = 3x2
    int matrix2[n][p]; // n x p = 2x3
    // Resulting matrix after multiplication = m x p
    int matrix3[m][p];

    matrix1[0][0] = 1;
    matrix1[0][1] = 2;
    matrix1[1][0] = 1;
    matrix1[1][1] = 2;
    matrix1[2][0] = 1;
    matrix1[2][1] = 2;

    matrix2[0][0] = 1;
    matrix2[0][1] = 2;
    matrix2[0][2] = 3;
    matrix2[1][0] = 1;
    matrix2[1][1] = 2;
    matrix2[1][2] = 3;

    // Formulating the resulting matrix of size m x p
    for(int i=0; i<m; ++i)  // m
    {
        for(int j=0; j<p; ++j)  // p
        {
            matrix3[i][j] = 0;
            for(int k=0; k<n; ++k)
            {   // m x p       =  m x n  --Inner--  n x p
                matrix3[i][j] += matrix1[i][k]*matrix2[k][j];
            }
        }
    }

    for(int i=0;i<m;++i)
    {
        for(int j=0;j<p;++j)
        {
            std::cout<<matrix3[i][j]<<" ";
        }
        std::cout<<"\n";
    }

    return 0;
}

/*

Sparse Matrix Operations:
https://www.geeksforgeeks.org/operations-sparse-matrices/

*/