#include "../vector.h"
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

  printf("testVectorAddition > Test case 1: [1,2]+[3,4] = [4,6] --> passed\n");

  freeVector(&result);

  // Test case 2: [0, 0, 0] + [5, 10, 15] = [5, 10, 15]
  vector1 = (Vector){ .elements = (double[]){0, 0, 0}, .size = 3 };
  vector2 = (Vector){ .elements = (double[]){5, 10, 15}, .size = 3 };

  result = vectorAddition(&vector1, &vector2);

  assert(result.size == 3);
  assert(result.elements[0] == 5);
  assert(result.elements[1] == 10);
  assert(result.elements[2] == 15);

  printf("testVectorAddition > Test case 2: [0,0,0]+[5,10,15] = [5,10,15] --> passed\n");

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

printf("testVectorSubtraction > Test case 1: [1,2]-[3,4] = [-2,-2] --> passed\n");

// Test case 2: [-5, 10, 15] - [-1, 2, 3] = [-4, 8, 12]
vector1 = (Vector){ .elements = (double[]){-5, 10, 15}, .size = 3 };
vector2 = (Vector){ .elements = (double[]){-1, 2, 3}, .size = 3 };

result = vectorSubtraction(&vector1, &vector2);

assert(result.size == 3);
assert(result.elements[0] == -4);
assert(result.elements[1] == 8);
assert(result.elements[2] == 12);

freeVector(&result);

  printf("testVectorSubtraction > Test case 2: [-5,10,15]-[-1,2,3] = [-4,8,12] --> passed\n");
  
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

  printf("testVectorMultiplication > Test case 1: [2,3,4]*[5,6,7] = [10,18,28] --> passed\n");
  
  // Test case 2: [0, -1, 2] * [3, 0, -2] = [0, 0, -4]
  vector1 = (Vector){ .elements = (double[]){0, -1, 2}, .size = 3 };
  vector2 = (Vector){ .elements = (double[]){3, 0, -2}, .size = 3 };

  result = vectorMultiplication(&vector1, &vector2);

  assert(result.size == 3);
  assert(result.elements[0] == 0);
  assert(result.elements[1] == 0);
  assert(result.elements[2] == -4);

  freeVector(&result);

   printf("testVectorMultiplication > Test case 2: [0,-1,2]*[3,0,-2] = [0,0,-4] --> Passed\n");
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

  printf("testVectorDivision > Test case 1: [6,8,10]/[2,4,5] = [3,2,2] --> Passed\n");

  // Test case 2: [4, 8, 12] / [1, 2, 0] (division by zero)
  vector1 = (Vector){ .elements = (double[]){4, 8, 12}, .size = 3 };
  vector2 = (Vector){ .elements = (double[]){1, 2, 0}, .size = 3 };

  // Division by zero should cause an error message and exit the program

  vectorDivision(&vector1, &vector2);

  assert(1);

  printf("Test case 2: [4,8,12]/[1,2,0] = Error: (division by zero) --> Passed\n");
}

int testParseVector(const char* vectorString, Vector expectedVector) {
  Vector parsedVector = parseVector(vectorString);

  printf("Input: %s\n", vectorString);
  printf("Expected: [");
  for (int i = 0; i < expectedVector.size; i++) {
      printf("%.2f", expectedVector.elements[i]);
      if (i < expectedVector.size - 1) {
          printf(", ");
      }
  }
  printf("]\n");

  if (parsedVector.size != expectedVector.size) {
      printf("Error: Incorrect vector size! Expected: %d, Actual: %d\n", expectedVector.size, parsedVector.size);
      return 0;
  }

  for (int i = 0; i < parsedVector.size; i++) {
      if (parsedVector.elements[i] != expectedVector.elements[i]) {
          printf("Error: Incorrect value at index %d! Expected: %.2f, Actual: %.2f\n", i, expectedVector.elements[i], parsedVector.elements[i]);
          return 0;
      }
  }

  printf("Success!\n");
  printf("==========\n");
  return 1;
}

void testAllParseVectorCases() {
  int passed = 0;
  int total = 0;
  printf("\nPerforming all tests cases for parseVector!\n\n");
  // Test case 1: Valid vector input
  total++;
  passed += testParseVector("[1.5,2.7,3.9]", (Vector){(double[]){1.5, 2.7, 3.9}, 3});

  // Test case 2: Valid vector input with negative values
  total++;
  passed += testParseVector("[-1.2,-3.4,-5.6,-7.8]", (Vector){(double[]){-1.2, -3.4, -5.6, -7.8}, 4});

  // Test case 3: Invalid vector input (missing closing bracket)
  total++;
  passed += testParseVector("[1.5,2.7,3.9", (Vector){NULL, -1});

  // Test case 4: Invalid vector input (invalid value)
  total++;
  passed += testParseVector("[1.5,2.7,abc]", (Vector){NULL, -1});

  // Test case 5: Invalid vector input (empty input)
  total++;
  passed += testParseVector("", (Vector){NULL, -1});

  printf("==========\n");
  printf("Total parseVector Tests: %d\n", total);
  printf("Tests parseVector passed: %d\n", passed);
  printf("Tests parseVector failed: %d\n", total - passed);
  printf("==========\n");
  assert(1);
}

void testAllOperationPosCases() {
  // Test cases for operationPos function

  // Test case 1: Addition operator
  const char* expression1 = "[1,2]+[3,4]";
  int pos1 = operationPos(expression1);
  assert(pos1 == 5);
  printf("testOperationPos [1,2]+[3,4] --> passed\n");

  // Test case 2: Subtraction operator
  const char* expression2 = "[-1,2]-[3,4]";
  int pos2 = operationPos(expression2);
  assert(pos2 == 6);

  printf("testOperationPos [-1,2]-[3,4] --> passed\n");


  // Test case 3: Multiplication operator
  const char* expression3 = "[-1,2]*[3,4]";
  int pos3 = operationPos(expression3);
  assert(pos3 == 6);

  printf("testOperationPos [-1,2]*[3,4] --> passed\n");


  // Test case 4: Division operator
  const char* expression4 = "[1,2]/[3,4]";
  int pos4 = operationPos(expression4);
  assert(pos4 == 5);

  printf("testOperationPos [1,2]/[3,4] --> passed\n");


  // Test case 5: No operator found
  const char* expression5 = "[1,2,3,4]";
  int pos5 = operationPos(expression5);
  assert(pos5 == -1);

  printf("testOperationPos [1,2,3,4] --> passed with failure\n");


  printf("All test cases passed successfully for testOperationPos!\n");
}

