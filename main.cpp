#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
double calculateFunction(int x, int n) {
    return pow(x, n) + sin(x);
}
int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    if (!inputFile || !outputFile) {
        cerr << "Помилка відкриття файлу!" << endl;
        return 1;
    }
    int rows, cols, n;
    inputFile >> rows >> cols >> n;
    int** array1 = new int*[rows];
    double** array2 = new double*[rows];
    
    for (int i = 0; i < rows; i++) {
        array1[i] = new int[cols];
        array2[i] = new double[cols];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            inputFile >> array1[i][j];
        }
    }
    cout << "Результати обчислення:" << endl;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array2[i][j] = calculateFunction(array1[i][j], n);
            printf("%.2f ", array2[i][j]);
            outputFile << array2[i][j] << " ";
        }
        cout << endl;
        outputFile << endl;
    }
    for (int i = 0; i < rows; i++) {
        delete[] array1[i];
        delete[] array2[i];
    }
    delete[] array1;
    delete[] array2;
    
    inputFile.close();
    outputFile.close();
    
    return 0;
}
