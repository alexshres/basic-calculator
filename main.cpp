// basic calc program using the std::stack
// data structure

#include <iostream>
#include "stack.h"
#include <string>

bool is_balanced(std::string &expr);

double evaluate_expression(std::string &expr);

int main() {
    double answer;

    std::string expression;

    std::cout << "Arithmetic expression with parentheses to show ordering if needed: " << std::endl;
    std::cin >> expression;

    if (is_balanced(expression)) {
        answer = evaluate_expression(expression);
        std::cout << "The answer is: " << answer << std::endl;
    } else {
        std::cout << "Parentheses don't match, please check the expression."
    }

    return EXIT_SUCCESS;
}

bool is_balanced(std::string &expr) {
    int length = strlen(expr.c_str());
    int counter = 0;
    for (int i = 0; i < length; ++i) {
        if (expr[i] == '(')
            ++counter;
        else if (expr[i] == ')')
            --counter;
    }

    if (counter == 0)
        return true;

    return false;
}

