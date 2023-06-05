#include "test_vector_operations.h"
#include <stdio.h>

int main() {
  testAllOperationPosCases();
  testAllParseVectorCases();
  testVectorAddition();
  testVectorSubtraction();
  testVectorMultiplication();
  testVectorDivision();

  printf("All tests passed successfully!\n");

  return 0;

}