#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>
//Sunny Suarez 3/18/26

#include "ArrayStack.h"

using namespace std;

// Token

struct Token {
    string value;   // number, operator, or parenthesis
};

// Tokenizer

vector<Token> tokenize(const string& line) {
    vector<Token> tokens;
    string num;

    for (char c: line) {
        if (isspace(c)) continue;

        if (isdigit(c)) {
            num += c;
        } else {
            if (!num.empty()) {
                tokens.push_back({num});
                num = "";
            }
            tokens.push_back({string(1,c)});
        }
    }

    if (!num.empty()) {
        tokens.push_back({num});
    }
    return tokens;
}

// Helpers

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int precedence(const string& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0;
}

// Detection

bool isValidPostfix(const vector<Token>& tokens) {
    ArrayStack<int> stack;

    for (const auto& t : tokens) {
        const string& s = t.value;

        bool isNum=true;
        for (char c : s) {
            if (!isdigit(c)) {
                isNum=false;
                break;
            }
        }

        if (isNum) {
            stack.push(1);
        }
        else if (isOperator(s)) {
            if (stack.size() < 2) return false;
            stack.pop();
            stack.pop();
            stack.push(1);
        }
        else return false;
        return stack.size() == 1;
    }
}

bool isValidInfix(const vector<Token>& tokens) {
    int balance = 0;

    for (const auto& t : tokens) {
        const string& s = t.value;

        bool isNum=true;
        for (char c : s) {
            if (!isdigit(c)) {
                isNum=false;
                break;
            }
        }

        if (isNum) continue;

        if (isOperator(s)) continue;

        if (s == "(") balance++;
        else if (s== ")") balance--;
        else return false;

        if (balance < 0) return false;
    }
    return balance == 0;
}

// Conversion

vector<Token> infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;
    // TODO
    return output;
}

// Evaluation

double evalPostfix(const vector<Token>& tokens) {
    ArrayStack<double> stack;
    for (const auto& t : tokens) {
        const string& s = t.value;

        bool isNum=true;
        for (char c : s) {
            if (!isdigit(c)) {
                isNum=false;
                break;
            }
        }

        if (isNum) {
            stack.push(stod(s));
        }
        else if (isOperator(s)) {
            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();

            if (s == "+") {
                stack.push(a + b);
            }
            else if (s == "-") {
                stack.push(a - b);
            }
            else if (s == "*") {
                stack.push(a * b);
            }
            else if (s == "/") {
                stack.push(a / b);
            }
        }
    }
    return stack.top();
}

// Main

int main() {
    string line;
    getline(cin, line);

    vector<Token> tokens = tokenize(line);

    if (isValidPostfix(tokens)) {
        cout << "FORMAT: POSTFIX\n";
        cout << "RESULT: " << evalPostfix(tokens) << "\n";
    }
    else if (isValidInfix(tokens)) {
        vector<Token> postfix = infixToPostfix(tokens);
        cout << "FORMAT: INFIX\n";
        cout << "POSTFIX: ";
        for (const auto& t : postfix) {
            cout << t.value << " ";
        }
        cout << "\n";
        cout << "RESULT: " << evalPostfix(postfix) << "\n";
    }
    else {
        cout << "FORMAT: NEITHER\n";
        cout << "ERROR: invalid expression\n";
    }

    return 0;
}
