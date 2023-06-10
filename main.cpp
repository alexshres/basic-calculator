// basic calc program using the std::stack
// data structure

#include <iostream>
#include "stack.h"

double read_and_eval(std::istream &ins);

void evaluate_stack_tops(basic_calculator::Stack<double> &numbers, basic_calculator::Stack<char> &operations);

int main() {
    double answer;

    std::cout << "Fully parenthesized arithmetic expression: " << std::endl;
    answer = read_and_eval(std::cin);

    std::cout << "Evaluates to " << answer << std::endl;

    return EXIT_SUCCESS;
}


double read_and_eval(std::istream &ins) {
    const char DECIMAL = '.';
    const char RIGHT_PAR = ')';

    basic_calculator::Stack<double> numbers;
    basic_calculator::Stack<char> operations;

    double number;
    char symbol;

    while (ins && ins.peek() != '\n') {
        // checks if the value (using ins.peek()) is a digit or
        // decimal and if so pushes into std::stack
        if (std::isdigit(ins.peek()) || (ins.peek() == DECIMAL)) {
            ins >> number;
            numbers.push(number);
        } else if (std::strchr("+_*/", ins.peek()) != NULL) {
            ins >> symbol;
            operations.push(symbol);
        } else if (ins.peek() == RIGHT_PAR) {
            ins.ignore();
            evaluate_stack_tops(numbers, operations);
        } else
            ins.ignore();
    }

    return numbers.pop();
}

void evaluate_stack_tops(basic_calculator::Stack<double> &numbers, basic_calculator::Stack<char> &operations) {
    double operand1, operand2;

    operand2 = numbers.pop();

    operand1 = numbers.pop();

    switch (operations.pop()) {
        case '+':
            numbers.push(operand1 + operand2);
            break;

        case '-':
            numbers.push(operand1 - operand2);
            break;

        case '*':
            numbers.push(operand1 * operand2);
            break;

        case '/':
            numbers.push(operand1 / operand2);
            break;
    }
}