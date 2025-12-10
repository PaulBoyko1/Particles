#include "Matrices.h"
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

namespace Matrices
{
        Matrix::Matrix(int _rows, int _cols)
        {
                rows = _rows;
                cols = _cols;
                a.resize(rows);
                for (int i = 0; i < rows; i++) {
                        a[i].resize(cols);
                        for (int j = 0; j < cols; j++) {
                                a[i][j] = 0;
                        }
                }
        }

        Matrix operator+(const Matrix& a, const Matrix& b) {
                if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
                        throw invalid_argument("Dimensions must agree for addition.");

                }

                Matrix addedMatrix(a.getRows(), a.getCols());
                for (int i = 0; i < a.getRows(); i++) {
                        for (int j = 0; j < a.getCols(); j++) {
                                addedMatrix(i, j) = a(i, j) + b(i, j);
                        }
                }
                return addedMatrix;
        }

        Matrix operator*(const Matrix& a, const Matrix& b) {
                if (a.getCols() != b.getRows()) {
                        throw std::invalid_argument("Dimensions must agree for multiplication.");

                }

                 Matrix multMatrix(a.getRows(), b.getCols());
                for (int i = 0; i < a.getRows(); i++) {
                        for (int k = 0; k < b.getCols(); k++) {
                                double sum = 0;
                                for (int j = 0; j < a.getCols(); j++) {
                                        sum += a(i, j) * b(j, k);
                                }
                                multMatrix(i, k) = sum;
                        }
                }
                return multMatrix;
        }

        bool operator==(const Matrix& a, const Matrix& b) {
                if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) return false;
                for (int i = 0; i < a.getRows(); i++) {
                        for (int j = 0; j < a.getCols(); j++) {
                                if (std::abs(a(i, j) - b(i, j)) >= 0.001) return false;
                        }
                }
                return true;
        }

        bool operator!=(const Matrix& a, const Matrix& b) {
                return !(a == b);
        }

        ostream& operator<<(ostream& os, const Matrix& a) {
                for (int i = 0; i < a.getRows(); i++) {
                        for (int j = 0; j < a.getCols(); j++) {
                                os << setw(10) << a(i, j) << " ";
                        }
                        os << "\n";
                }
                return os;
        }
        RotationMatrix::RotationMatrix(double theta) : Matrix(2, 2)
        {
            a[0][0] = cos(theta);
            a[0][1] = -sin(theta);
            a[1][0] = sin(theta);
            a[1][1] = cos(theta);
        }
        ScalingMatrix::ScalingMatrix(double scale) : Matrix(2, 2)
        {
            a[0][0] = scale;
            a[0][1] = 0.0;
            a[1][0] = 0.0;
            a[1][1] = scale;
        }
        TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols) : Matrix(2, nCols)
        {
            for (int i = 0; i < nCols; i++) {
                a[0][i] = xShift;
                a[1][i] = yShift;
            }
        }
}
