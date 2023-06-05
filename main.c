#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main() {
  char* input = NULL;
  size_t inputSize = 0;

  printf("Enter the vector operation prompt: ");
  getline(&input, &inputSize, stdin);

  // Remove the trailing newline character
  input[strcspn(input, "\n")] = '\0';

  Vector vector1, vector2, resultVector;

  int operatorPos = operationPos(input);

  char* vector1String = strndup(input, operatorPos);
  char* vector2String = strndup(input + operatorPos + 1, strlen(input) - operatorPos - 2);
 
  char operator = input[operatorPos];

  vector1 = parseVector(vector1String);
  vector2 = parseVector(vector2String);


  // Perform the specified vector operation

  switch (operator) {
        case '+':
            resultVector = vectorAddition(&vector1, &vector2);
            break;
        case '-':
            resultVector = vectorSubtraction(&vector1, &vector2);
            break;
        case '*':
            resultVector = vectorMultiplication(&vector1, &vector2);
            break;
        case '/':
            resultVector = vectorDivision(&vector1, &vector2);
            break;
        default:
            printf("Invalid operator!\n");
            return 1;
    }

    // Print the resulting vector
    printVector(&resultVector);

    // Free memory
    free(input);
    freeVector(&vector1);
    freeVector(&vector2);
    freeVector(&resultVector);

    return 0;
}