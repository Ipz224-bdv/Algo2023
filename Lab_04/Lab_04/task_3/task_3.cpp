#include <iostream>
#include <cmath>
#include <cstring>

#define STACK_SIZE 100

struct Stack {
    int top;
    double data[STACK_SIZE];
};

void init(Stack* stack) {
    stack->top = -1;
}

bool is_empty(Stack* stack) {
    return stack->top == -1;
}

bool is_full(Stack* stack) {
    return stack->top == STACK_SIZE - 1;
}

void push(Stack* stack, double value) {
    if (is_full(stack)) {
        std::cout << "Переповнення стеку" << std::endl;
        exit(1);
    }
    stack->data[++stack->top] = value;
}

double pop(Stack* stack) {
    if (is_empty(stack)) {
        std::cout << "Переповнення стеку" << std::endl;
        exit(1);
    }
    return stack->data[stack->top--];
}

double eval(char* expr) {
    Stack stack;
    init(&stack);

    while (*expr) {
        if (*expr >= '0' && *expr <= '9') {
            double num = 0;
            while (*expr >= '0' && *expr <= '9') {
                num = num * 10 + (*expr - '0');
                expr++;
            }
            push(&stack, num);
        }
        else if (*expr == '+' || *expr == '-' || *expr == '*' || *expr == '/' || *expr == '^' || *expr == 's') {
            double num1, num2, result;
            switch (*expr) {
            case '+':
                num2 = pop(&stack);
                num1 = pop(&stack);
                result = num1 + num2;
                push(&stack, result);
                break;
            case '-':
                num2 = pop(&stack);
                num1 = pop(&stack);
                result = num1 - num2;
                push(&stack, result);
                break;
            case '*':
                num2 = pop(&stack);
                num1 = pop(&stack);
                result = num1 * num2;
                push(&stack, result);
                break;
            case '/':
                num2 = pop(&stack);
                num1 = pop(&stack);
                if (num2 == 0) {
                    std::cout << "Ділення на нуль" << std::endl;
                    exit(1);
                }
                result = num1 / num2;
                push(&stack, result);
                break;
            case '^':
                num2 = pop(&stack);
                num1 = pop(&stack);
                result = std::pow(num1, num2);
                push(&stack, result);
                break;
            case 's':
                num1 = pop(&stack);
                if (num1 < 0) {
                    std::cout << "Квадратний корінь з від'ємного числа" << std::endl;
                    exit(1);
                }
                result = std::sqrt(num1);
                push(&stack, result);
                break;
            }
        }
        expr++;
    }
    if (is_empty(&stack)) {
        std::cout << "Неправильний запис виразу" << std::endl;
        exit(1);
    }

    double result = pop(&stack);

    if (!is_empty(&stack)) {
        std::cout << "Неправильний запис виразу" << std::endl;
        exit(1);
    }

    return result;
}

int main() {
    char expr[STACK_SIZE];
    std::cout << "Введіть вираз, використовуючи зворотній польський запис: ";
    std::cin.getline(expr, STACK_SIZE);
    double result = eval(expr);
    std::cout << "Результат: " << result << std::endl;
    return 0;
}