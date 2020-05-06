#include <sstream>
#include <stack>
#include "ExpressionManager.h"

const string ERROR = "invalid";

bool ExpressionManager::isBalanced(string expression){
	cout << "isBalanced: " << expression << endl; 
	
	stack<string> parens;
	istringstream ss(expression);
        string next;
        while (ss >> next){ //reads each space-separated token from the expression
		if (next == "(" || next == "[" || next == "{") {
			parens.push(next);
		}
		else if (next == ")" || next == "]" || next == "}") {
			if (parens.empty()) {
				return false;
			}
			string last = parens.top();
			parens.pop();
			if ((next == ")" && last != "(") || 
				(next == "}" && last != "{") ||
				(next == "]" && last != "[")) {
				return false;
			}
		}
	}
	if (!parens.empty()) {
		return false;
	}
	return true;
}

string ExpressionManager::postfixEvaluate(string postfixExpression){
	cout << "postfixEvaluate: " << postfixExpression << endl; 
	
	stack<int> working;
	istringstream ss(postfixExpression);
        string next;
        while (ss >> next){ 
		if (isdigit(next[0])) {
			if (next.find('.') != std::string::npos) {
				return ERROR;
			}
			int num = stoi(next);
			working.push(num);
		}
		else if	(next == "+" || next == "-" || next == "*" || next == "/" || next == "%") {
			if (working.size() < 2) {
				return ERROR;
			}
			int right = working.top();
			working.pop();
			int left = working.top();
			working.pop();
			
			int result = 0;
			char op = next[0];
			switch(op) {
				case '+':
					result = left + right;
					break;
				case '-':
					result = left - right;
					break;
				case '*':
					result = left * right;
					break;
				case '/':
					if (right == 0) {
						return ERROR;
					}
					result = left / right;
					break;
				case '%':
					result = left % right;
					break;
			}
			working.push(result);
		}
		else {
			return ERROR;
		}
	}
	if (working.size() != 1) {
		return ERROR;
	}
	int answer = working.top();
	return std::to_string(answer);
}

string ExpressionManager::postfixToInfix(string postfixExpression){
	cout << "postfixToInfix: " << postfixExpression << endl; 
	
	stack<string> exprs;
	istringstream ss(postfixExpression);
        string next;
        while (ss >> next){ 
		if (isdigit(next[0])) {
			if (next.find('.') != std::string::npos) {
				return ERROR;
			}
			exprs.push(next);
		}
		else if (next == "+" || next == "-" || next == "*" || next ==  "/" || next == "%") {
			if (exprs.size() < 2) {
				return ERROR;
			}
			string right = exprs.top();
			exprs.pop();
			string left = exprs.top();
			exprs.pop();

			string exp = "( " + left + " " + next + " " + right + " )";
			exprs.push(exp);
		}
		else {
			return ERROR;
		}
	}
	if (exprs.size() != 1) {
		return ERROR;
	}
	return exprs.top(); 
}
