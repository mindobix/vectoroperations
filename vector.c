#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double* elements;
    int size;
} Vector;

// Function to parse the vector from the input string
Vector parseVector(const char* vectorString) {
    Vector vector;
    vector.size = 0;
    vector.elements = NULL;

    char* token;
    char* vectorCopy = strdup(vectorString);

    token = strtok(vectorCopy, "[,]");
    while (token != NULL) {
        double element;
        if (sscanf(token, "%lf", &element) == 1) {
            vector.elements = realloc(vector.elements, (vector.size + 1) * sizeof(double));
            vector.elements[vector.size] = element;
            vector.size++;
        }
        token = strtok(NULL, "[,]");
    }

    free(vectorCopy);

    return vector;
}

// Function to perform vector addition
Vector vectorAddition(const Vector* vector1, const Vector* vector2) {
    Vector result;
    result.size = vector1->size;
    result.elements = malloc(result.size * sizeof(double));

    int i;
    for (i = 0; i < vector1->size; i++) {
        result.elements[i] = vector1->elements[i] + vector2->elements[i];
    }

    return result;
}

// Function to perform vector subtraction
Vector vectorSubtraction(const Vector* vector1, const Vector* vector2) {
    Vector result;
    result.size = vector1->size;
    result.elements = malloc(result.size * sizeof(double));

    int i;
    for (i = 0; i < vector1->size; i++) {
        result.elements[i] = vector1->elements[i] - vector2->elements[i];
    }

    return result;
}

// Function to perform vector multiplication
Vector vectorMultiplication(const Vector* vector1, const Vector* vector2) {
    Vector result;
    result.size = vector1->size;
    result.elements = malloc(result.size * sizeof(double));

    int i;
    for (i = 0; i < vector1->size; i++) {
        result.elements[i] = vector1->elements[i] * vector2->elements[i];
    }

    return result;
}

// Function to perform vector division
Vector vectorDivision(const Vector* vector1, const Vector* vector2) {
    Vector result;
    result.size = vector1->size;
    result.elements = malloc(result.size * sizeof(double));

    int i;
    for (i = 0; i < vector1->size; i++) {
        if (vector2->elements[i] != 0) {
            result.elements[i] = vector1->elements[i] / vector2->elements[i];
        } else {
            printf("vectorDivision > Error: Division by zero\n");
           result.elements[i] = 0.0;
        }
    }

    return result;
}

// Function to print the vector
void printVector(const Vector* vector) {
    printf("[");
    int i;
    for (i = 0; i < vector->size; i++) {
        printf("%.2lf", vector->elements[i]);
        if (i != vector->size - 1) {
            printf(",");
        }
    }
    printf("]\n");
}

int operationPos(const char* expression) {
    int len = strlen(expression);
    int operatorPos = -1;
    int bracketCount = 0;

    for (int i = 0; i < len; i++) {
        if (expression[i] == '[') {
            bracketCount++;
        } else if (expression[i] == ']') {
            bracketCount--;
        } else if ((expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') && bracketCount == 0) {
            return i;
        }
    }

    return -1;  // No operator found
}

// Function to free memory allocated for the vector
void freeVector(Vector* vector) {
    free(vector->elements);
    vector->elements = NULL;
    vector->size = 0;
}
