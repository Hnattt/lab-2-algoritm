#include <stdio.h>
#include <stdlib.h>
void readArrayFromFile(const char* filename, int*** array, int* rows, int* cols) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Не вдалося відкрити файл");
        exit(EXIT_FAILURE);
    }
    fscanf(file, "%d %d", rows, cols);
    *array = (int**)malloc(*rows * sizeof(int*));
    for (int i = 0; i < *rows; i++) {
        (*array)[i] = (int*)malloc(*cols * sizeof(int));
        for (int j = 0; j < *cols; j++) {
            fscanf(file, "%d", &((*array)[i][j]));
        }
    }

    fclose(file);
}
void processArray(int** input, int*** output, int rows, int cols) {
    *output = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        (*output)[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            (*output)[i][j] = input[i][j] * 2; 
        }
    }
}
void writeArrayToFile(const char* filename, int** array, int rows, int cols) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Не вдалося відкрити файл");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d ", array[i][j]);
            printf("%d ", array[i][j]); 
        }
        fprintf(file, "\n");
        printf("\n");
    }

    fclose(file);
}
void freeArray(int** array, int rows) {
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);
}

int main() {
    int** array, ** processedArray;
    int rows, cols;
    readArrayFromFile("input.txt", &array, &rows, &cols);
    processArray(array, &processedArray, rows, cols);
    writeArrayToFile("output.txt", processedArray, rows, cols);
    freeArray(array, rows);
    freeArray(processedArray, rows);

    printf("Програма виконана успішно!\n");

    return 0;
}
