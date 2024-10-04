#include <iostream>
#include <vector>

using namespace std;

void LU_Decomposition(vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U, int n) {
    for (int i = 0; i < n; i++) {
        // Upper Triangular
        for (int k = i; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += (L[i][j] * U[j][k]);
            }
            U[i][k] = A[i][k] - sum;
        }

        // Lower Triangular
        for (int k = i; k < n; k++) {
            if (i == k)
                L[i][i] = 1; // Diagonal as 1
            else {
                double sum = 0;
                for (int j = 0; j < i; j++) {
                    sum += (L[k][j] * U[j][i]);
                }
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
}

void printMatrix(const vector<vector<double>>& matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n;

    // Solicitar el tamaño de la matriz
    cout << "Introduce el número de filas (m): ";
    cin >> m;
    cout << "Introduce el número de columnas (n): ";
    cin >> n;

    // Declarar la matriz A de tamaño m x n
    vector<vector<double>> A(m, vector<double>(n));

    // Ingresar los valores de la matriz A
    cout << "Introduce los elementos de la matriz A:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    // Para que LU funcione, la matriz debe ser cuadrada, por lo tanto verificamos si es m = n
    if (m != n) {
        cout << "La matriz debe ser cuadrada (m = n) para aplicar la descomposición LU." << endl;
        return 1;
    }

    // Matrices L y U de tamaño n x n
    vector<vector<double>> L(n, vector<double>(n, 0));
    vector<vector<double>> U(n, vector<double>(n, 0));

    // Llamada a la descomposición LU
    LU_Decomposition(A, L, U, n);

    // Imprimir las matrices L y U
    cout << "Lower Triangular Matrix L:" << endl;
    printMatrix(L, n, n);
    cout << "Upper Triangular Matrix U:" << endl;
    printMatrix(U, n, n);

    return 0;
}