#include "Assignment3.h"
#include <iostream>
#include <stack>
#include <queue>
#include <string>

// Function implementations for ExpressionManager

bool isOperator(char c) {
    // Check if the character is an operator
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

int getWeight(char op) {
    // Get the weight of the operator for infix to postfix conversion
    int weight = -1;
    switch (op) {
    case '+':
    case '-':
        weight = 1;
        break;
    case '*':
    case '/':
    case '%':
        weight = 2;
        break;
    }
    return weight;
}

std::string infixToPostfix(const std::string& infix) {
    // Convert infix expression to postfix using a stack
    std::stack<char> s;
    std::string postfix = "";
    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else if (isOperator(c)) {
            while (!s.empty() && s.top() != '(' && getWeight(s.top()) >= getWeight(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

bool areParenthesesBalanced(const std::string& expression) {
    // Check if the parentheses in the expression are balanced
    std::stack<char> stack;
    for (char c : expression) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (stack.empty()) {
                return false;
            }
            char top = stack.top();
            stack.pop();
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return stack.empty();
}

// Function implementations for CustomQueue

void CustomQueue::insert(int element) {
    // Insert an element at the rear of the queue
    q.push(element);
}

int CustomQueue::remove() {
    // Remove and return the front element of the queue
    if (q.empty()) {
        throw std::out_of_range("Queue is empty");
    }
    int front = q.front();
    q.pop();
    return front;
}

int CustomQueue::front() {
    // Return the front element of the queue without removing it
    if (q.empty()) {
        throw std::out_of_range("Queue is empty");
    }
    return q.front();
}

bool CustomQueue::isEmpty() const {
    // Check if the queue is empty
    return q.empty();
}

size_t CustomQueue::size() const {
    // Return the total number of elements in the queue
    return q.size();
}

// Function to display the contents of the queue
void CustomQueue::display() {
    std::queue<int> tempQueue = q;
    std::cout << "\nQueue content: ";
    if (tempQueue.empty()) {
        std::cout << "Empty";
    }
    while (!tempQueue.empty()) {
        std::cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    std::cout << std::endl;
}

// Main program to demonstrate both ExpressionManager and CustomQueue

int main() {
    // Expression Manager Demonstration
    std::string expression;
    std::cout << "Enter an infix expression: ";
    std::getline(std::cin, expression);

    if (!areParenthesesBalanced(expression)) {
        std::cout << "Invalid expression: the parentheses are not balanced." << std::endl;
        return 1;
    }

    std::string postfix = infixToPostfix(expression);
    std::cout << "The postfix expression is: " << postfix << std::endl;

    // Queue Demonstration
    CustomQueue queue;

    // Initially, the queue should be empty
    std::cout << "Initial queue content (should be empty): ";
    queue.display();

    // Insert elements into the queue
    queue.insert(10);
    queue.insert(20);
    queue.insert(30);
    std::cout << "Queue content after inserting elements: ";
    queue.display();

    // Remove the front element and display the updated queue
    queue.remove();
    std::cout << "Queue content after removing the front element: ";
    queue.display();

    // Display the current front element without removing it
    std::cout << "Current front element: " << queue.front() << std::endl;

    // Check if the queue is empty
    std::cout << "Is the queue empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl;

    // Display the total number of elements in the queue
    std::cout << "Total number of elements in the queue: " << queue.size() << std::endl;

    return 0;
}