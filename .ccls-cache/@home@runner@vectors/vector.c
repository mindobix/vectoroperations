#include <stdio.h>

int main(int argc, char *argv[]) {
  char* vector1 = argv[1];
  char* vector2 = argv[3];
  char* operand = argv[2];
  
  printf("%s", vector1);
  printf(" %s ", operand);
  printf("%s", vector2);
  printf("\n");
  return 0;
}