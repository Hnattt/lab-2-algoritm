#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int y(int x, int n) {
    if (x < 0) {
        int result = 1;
        for (int j = 2; j < n - 1; ++j) {
            result *= (j + x);
        }
        return result;
    } else {
        int result = 0;
        for (int i = 0; i < n; ++i) {
            int prod = 1;
            for (int j = 0; j < n; ++j) {
                prod *= (x + i + pow(j, 2));
            }
            result += prod;
        }
        return result;
    }
}
int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    
    if (!inputFile) {
        cerr << "Помилка відкриття файлу!" << endl;
        return 1;
    }
    
    int rows, cols;
    inputFile >> rows >> cols;
    
    int** array = new int*[rows];
    int** resultArray = new int*[rows];
    
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
        resultArray[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            inputFile >> array[i][j];
            resultArray[i][j] = y(array[i][j], cols);
        }
    }
    
    inputFile.close();
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", resultArray[i][j]);
            outputFile << resultArray[i][j] << " ";
        }
        printf("\n");
        outputFile << endl;
    }
    
    outputFile.close();
    
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
        delete[] resultArray[i];
    }
    delete[] array;
    delete[] resultArray;
    
    return 0;
}
