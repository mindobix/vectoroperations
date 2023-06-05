#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    double* elements;
    int size;
} Vector;

Vector parseVector(const char* vectorString);
Vector vectorAddition(const Vector* vector1, const Vector* vector2);
Vector vectorSubtraction(const Vector* vector1, const Vector* vector2);
Vector vectorMultiplication(const Vector* vector1, const Vector* vector2);
Vector vectorDivision(const Vector* vector1, const Vector* vector2);
void printVector(const Vector* vector);
void freeVector(Vector* vector);
int operationPos(const char* expression);

#endif /* VECTOR_H */
