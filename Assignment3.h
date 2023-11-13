#ifndef ASSIGNMENT3_H
#define ASSIGNMENT3_H

#include <string>
#include <queue>

// Declaration for functions related to ExpressionManager
bool isOperator(char c);
int getWeight(char op);
std::string infixToPostfix(const std::string& infix);
bool areParenthesesBalanced(const std::string& expression);

// Declaration for CustomQueue class
class CustomQueue {
private:
    std::queue<int> q;

public:
    void insert(int element);
    int remove();
    int front();
    bool isEmpty() const;
    size_t size() const;
    void display(); // Function to display the contents of the queue
};

#endif // ASSIGNMENT3_H