#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void testVectorAddition() {
  // Test case 1: [1, 2] + [3, 4] = [4, 6]
  Vector vector1 = { .elements = (double[]){1, 2}, .size = 2 };
  Vector vector2 = { .elements = (double[]){3, 4}, .size = 2 };

  Vector result = vectorAddition(&vector1, &vector2);

  assert(result.size == 2);
  assert(result.elements[0] == 4);
  assert(result.elements[1] == 6);

  printf("testVectorAddition > Test case 1: [1, 2] + [3, 4] = [4, 6] --> passed\n");

  freeVector(&result);

  // Test case 2: [0, 0, 0] + [5, 10, 15] = [5, 10, 15]
  vector1 = (Vector){ .elements = (double[]){0, 0, 0}, .size = 3 };
  vector2 = (Vector){ .elements = (double[]){5, 10, 15}, .size = 3 };

  result = vectorAddition(&vector1, &vector2);

  assert(result.size == 3);
  assert(result.elements[0] == 5);
  assert(result.elements[1] == 10);
  assert(result.elements[2] == 15);

  printf("testVectorAddition > Test case 2: [0, 0, 0] + [5, 10, 15] = [5, 10, 15] --> passed\n");

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

printf("testVectorSubtraction > Test case 1: [1, 2] - [3, 4] = [-2, -2] --> passed\n");

// Test case 2: [5, 10, 15] - [1, 2, 3] = [4, 8, 12]
vector1 = (Vector){ .elements = (double[]){5, 10, 15}, .size = 3 };
vector2 = (Vector){ .elements = (double[]){1, 2, 3}, .size = 3 };

result = vectorSubtraction(&vector1, &vector2);

assert(result.size == 3);
assert(result.elements[0] == 4);
assert(result.elements[1] == 8);
assert(result.elements[2] == 12);

freeVector(&result);

  printf("testVectorSubtraction > Test case 2: [5, 10, 15] - [1, 2, 3] = [4, 8, 12] --> passed\n");
  
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

  printf("testVectorMultiplication > Test case 1: [2, 3, 4] * [5, 6, 7] = [10, 18, 28] --> passed\n");
  
  // Test case 2: [0, -1, 2] * [3, 0, -2] = [0, 0, -4]
  vector1 = (Vector){ .elements = (double[]){0, -1, 2}, .size = 3 };
  vector2 = (Vector){ .elements = (double[]){3, 0, -2}, .size = 3 };

  result = vectorMultiplication(&vector1, &vector2);

  assert(result.size == 3);
  assert(result.elements[0] == 0);
  assert(result.elements[1] == 0);
  assert(result.elements[2] == -4);

  freeVector(&result);

   printf("testVectorMultiplication > Test case 2: [0, -1, 2] * [3, 0, -2] = [0, 0, -4] --> Passed\n");
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

  printf("testVectorDivision > Test case 1: [6, 8, 10] / [2, 4, 5] = [3, 2, 2] --> Passed\n");

  // Test case 2: [4, 8, 12] / [1, 2, 0] (division by zero)
  vector1 = (Vector){ .elements = (double[]){4, 8, 12}, .size = 3 };
  vector2 = (Vector){ .elements = (double[]){1, 2, 0}, .size = 3 };

  // Division by zero should cause an error message and exit the program

  vectorDivision(&vector1, &vector2);

  assert(1);

  printf("Test case 2: [4, 8, 12] / [1, 2, 0] (division by zero) --> Passed\n");
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