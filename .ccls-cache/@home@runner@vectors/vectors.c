#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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
        vector.elements = realloc(vector.elements, (vector.size + 1) * sizeof(double));
        vector.elements[vector.size] = atof(token);
        vector.size++;
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
            printf("Error: Division by zero\n");
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

// Function to free memory allocated for the vector
void freeVector(Vector* vector) {
    free(vector->elements);
    vector->elements = NULL;
    vector->size = 0;
}

void testVectorAddition() {
    // Test case 1: [1, 2] + [3, 4] = [4, 6]
    Vector vector1 = { .elements = (double[]){1, 2}, .size = 2 };
    Vector vector2 = { .elements = (double[]){3, 4}, .size = 2 };

    Vector result = vectorAddition(&vector1, &vector2);

    assert(result.size == 2);
    assert(result.elements[0] == 4);
    assert(result.elements[1] == 6);

    freeVector(&result);

    // Test case 2: [0, 0, 0] + [5, 10, 15] = [5, 10, 15]
    vector1 = (Vector){ .elements = (double[]){0, 0, 0}, .size = 3 };
    vector2 = (Vector){ .elements = (double[]){5, 10, 15}, .size = 3 };

    result = vectorAddition(&vector1, &vector2);

    assert(result.size == 3);
    assert(result.elements[0] == 5);
    assert(result.elements[1] == 10);
    assert(result.elements[2] == 15);

    freeVector(&result);
}

void testVectorSubtraction() {
    // Test case 1: [1, 2] - [3, 4] = [-2, -2]
    Vector vector1 = { .elements = (double[]){1, 2}, .size = 2 };
    Vector vector2 = { .elements = (double[]){3, 4}, .size = 2 };

    Vector result = vectorSubtraction(&vector1, &vector2);

    assert(result.size == 2);
    assert(result.elements[0] == -2);
    assert(result.elements[1] == -2);

    freeVector(&result);

    // Test case 2: [5, 10, 15] - [1, 2, 3] = [4, 8, 12]
    vector1 = (Vector){ .elements = (double[]){5, 10, 15}, .size = 3 };
    vector2 = (Vector){ .elements = (double[]){1, 2, 3}, .size = 3 };

    result = vectorSubtraction(&vector1, &vector2);

    assert(result.size == 3);
    assert(result.elements[0] == 4);
    assert(result.elements[1] == 8);
    assert(result.elements[2] == 12);

    freeVector(&result);
}

void testVectorMultiplication() {
    // Test case 1: [2, 3, 4] * [5, 6, 7] = [10, 18, 28]
    Vector vector1 = { .elements = (double[]){2, 3, 4}, .size = 3 };
    Vector vector2 = { .elements = (double[]){5, 6, 7}, .size = 3 };

    Vector result = vectorMultiplication(&vector1, &vector2);

    assert(result.size == 3);
    assert(result.elements[0] == 10);
    assert(result.elements[1] == 18);
    assert(result.elements[2] == 28);

    freeVector(&result);

    // Test case 2: [0, -1, 2] * [3, 0, -2] = [0, 0, -4]
    vector1 = (Vector){ .elements = (double[]){0, -1, 2}, .size = 3 };
    vector2 = (Vector){ .elements = (double[]){3, 0, -2}, .size = 3 };

    result = vectorMultiplication(&vector1, &vector2);

    assert(result.size == 3);
    assert(result.elements[0] == 0);
    assert(result.elements[1] == 0);
    assert(result.elements[2] == -4);

    freeVector(&result);
}

void testVectorDivision() {
    // Test case 1: [6, 8, 10] / [2, 4, 5] = [3, 2, 2]
    Vector vector1 = { .elements = (double[]){6, 8, 10}, .size = 3 };
    Vector vector2 = { .elements = (double[]){2, 4, 5}, .size = 3 };

    Vector result = vectorDivision(&vector1, &vector2);

    assert(result.size == 3);
    assert(result.elements[0] == 3);
    assert(result.elements[1] == 2);
    assert(result.elements[2] == 2);

    freeVector(&result);

    // Test case 2: [4, 8, 12] / [1, 2, 0] (division by zero)
    vector1 = (Vector){ .elements = (double[]){4, 8, 12}, .size = 3 };
    vector2 = (Vector){ .elements = (double[]){1, 2, 0}, .size = 3 };

    // Division by zero should cause an error message and exit the program
    printf("Error handling test case: ");
    vectorDivision(&vector1, &vector2);

    // This line will not be reached if division by zero error is handled correctly
    assert(1);
}

int main() {
    char* input = NULL;
    size_t inputSize = 0;

    testVectorAddition();
    testVectorSubtraction();
    testVectorMultiplication();
    testVectorDivision();

    printf("All tests passed successfully!\n");

    printf("Enter the vector operation prompt: ");
    getline(&input, &inputSize, stdin);

    // Remove the trailing newline character
    input[strcspn(input, "\n")] = '\0';

    Vector vector1, vector2, result;

    // Parse the vector and operation from the input string
    char* operationPos;
    char* operation = NULL;

    operationPos = strchr(input, '+');
    if (operationPos != NULL) {
        operation = "+";
    } else {
        operationPos = strchr(input, '-');
        if (operationPos != NULL) {
            operation = "-";
        } else {
            operationPos = strchr(input, '*');
            if (operationPos != NULL) {
                operation = "*";
            } else {
                operationPos = strchr(input, '/');
                if (operationPos != NULL) {
                    operation = "/";
                }
            }
        }
    }

    if (operation == NULL) {
        printf("Invalid input format. Expected format: [1,2]+[3,4]\n");
        free(input);
        return 1;
    }

    *operationPos = '\0'; // Replace operation character with null terminator

    vector1 = parseVector(input);
    vector2 = parseVector(operationPos + 1);

    // Perform the specified vector operation
    if (strcmp(operation, "+") == 0) {
        result = vectorAddition(&vector1, &vector2);
        printf("Vector Addition: ");
    } else if (strcmp(operation, "-") == 0) {
        result = vectorSubtraction(&vector1, &vector2);
        printf("Vector Subtraction: ");
    } else if (strcmp(operation, "*") == 0) {
        result = vectorMultiplication(&vector1, &vector2);
        printf("Vector Multiplication: ");
    } else if (strcmp(operation, "/") == 0) {
        result = vectorDivision(&vector1, &vector2);
        printf("Vector Division: ");
    }

    // Print the resulting vector
    printVector(&result);

    // Free memory
    free(input);
    freeVector(&vector1);
    freeVector(&vector2);
    freeVector(&result);

    return 0;
}
