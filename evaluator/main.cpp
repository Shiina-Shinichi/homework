#include <iostream>
#include <string>
#include <stdexcept>
#include "expression_evaluator.h"

void testEvaluateExpression(const std::string& expr) {
    try {
        double result = ExpressionEvaluator::evaluate(expr);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "ILLEGAL" << std::endl;
    }
}

int main() {
    std::string expr;
    
    std::cout << "Enter a mathematical expression (or 'exit' to quit): " << std::endl;

    while (true) {
        std::getline(std::cin, expr);  // 获取用户输入的表达式

        if (expr == "exit") {
            break;  // 如果输入 'exit'，退出程序
        }

        testEvaluateExpression(expr);  // 评估表达式
    }

    return 0;
}
