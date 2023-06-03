# Vector Operations by chatGPT

The `vector_operations` project is a C program that provides functions for performing vector operations, including addition, subtraction, multiplication, and division. It includes unit tests to ensure the correctness of the vector operations and allows user input for vector calculations. 

## Prerequisites

To compile and run the `vector_operations` program, ensure that you have the following installed on your system:

- C compiler (e.g., GCC)

## Getting Started

Follow the steps below to get started with the `vector_operations` program:

1. Clone the repository or download the source code files to your local machine.
2. Open a terminal or command prompt and navigate to the project directory.

## Compiling the Program

To compile the program, use the following command:

make



This will compile the source files (`main.c` and `vector.c`) and generate an executable named `vector_operations`.

## Running the Unit Tests

The `vector_operations` program includes unit tests to verify the correctness of the vector operations. To execute the unit tests, run the following command:

./vector_operations

The program will run the unit tests and display the test results in the console. If all tests pass successfully, you will see the message "All tests passed successfully!".

## Performing Vector Operations with User Input

The `vector_operations` program allows you to perform vector calculations with user input. It prompts you to enter two vectors in the following format: [x1,y1]+[x2,y2], [x1,y1]-[x2,y2], [x1,y1]*[x2,y2], or [x1,y1]/[x2,y2].

Here are some examples of valid input formats:

- Vector Addition:
  - Example input: [1,2]+[3,4]
  - Example output: Result: [4,6]

- Vector Subtraction:
  - Example input: [1,2]-[3,4]
  - Example output: Result: [-2,-2]

- Vector Multiplication:
  - Example input: [1,2]*[3,4]
  - Example output: Result: [3,8]

- Vector Division:
  - Example input: [1,2]/[3,4]
  - Example output: Result: [0.333333,0.5]

To run the program with user input, use the following command:

./vector_operations

Follow the prompts to enter the vectors in the specified format and press Enter. The program will perform the corresponding vector operation and display the result.

## Cleaning Up

To clean up the compiled files, run the following command:

make clean

This will remove the executable and any object files generated during the compilation process.

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgements

The `vector_operations` project was developed by chatGPT as a demonstration of vector operations in C programming.

chatGPT conversation

https://chat.openai.com/share/adb359a2-b340-4a84-aa74-666f8a708bcb
