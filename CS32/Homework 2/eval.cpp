#include <string>
#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

bool precedence_checker(char top_left, char ch_right);

int evaluate(string infix, string& postfix, bool& result) {

	//infix to postfix conversion with error checking
	//almost all syntax errors can be detected by noting whether it is legal for the current nonblank character to follow the nearest nonblank character before it.
	//When converting infix to postfix, a unary operator like ! behaves a lot more like an open parenthesis than like a binary operator.
	
	//Check syntactical errors that cannot be checked during conversion
	if (infix.length() == 0) return 1;
	
	//Check for invalid characters
	for (int i = 0; i < infix.length(); i++) {
		char ch = infix[i];
		if (ch != 'T' && ch != 'F' && ch != '&' && ch != '(' && ch != ')' && ch != '|' && ch != '!' && ch != ' ')
			return 1;
	}

	//Check that it has at least one T or at least one F, ex: "()" not a valid expression
	int T_counter = 0;
	int F_counter = 0;

	for (int i = 0; i < infix.length(); i++) {
		if (infix[i] == 'T') T_counter++;
		if (infix[i] == 'F') F_counter++;
	}

	if (T_counter == 0 && F_counter == 0) return 1;

	//Check if number of open and closed parentheses are the same
	int counter_1 = 0;

	int counter_2 = 0;
	for (int i = 0; i < infix.size(); i++) {
		if (infix[i] == '(') counter_1++;
		if (infix[i] == ')') counter_2++;
	}
	if (counter_1 != counter_2) return 1;


	//Create an infix string without spaces to make error checking easier.
	string infix_without_spaces = "";
	for (int i = 0; i < infix.length(); i++) {
		if (infix[i] == ' ') continue;
		else {
			infix_without_spaces += infix[i];
		}
	}
	
	//empyt out the postfix string
	postfix = "";

	stack <char> OPERATOR;


	////////////////CONVERSION AND INNER ERROR CHECKING//////////////////////////////////
	int open_parentheses_counter = 0;
	int closed_parentheses_counter = 0;
	for (int i = 0; i < infix_without_spaces.length(); i++) {
		char ch = infix_without_spaces[i];

		switch (ch) {
		case 'T':
			if (i < infix_without_spaces.length() - 1) {
				//Strings like TT or FF don't make sense or T!
				if (infix_without_spaces[i + 1] == 'T' || infix_without_spaces[i + 1] == 'F' || infix_without_spaces[i + 1] == '!') return 1;
			}
			postfix += ch;
			break;
		case 'F':
			if (i < infix_without_spaces.length() - 1) {
				//Strings like TT or FF don't make sense of F!
				if (infix_without_spaces[i + 1] == 'T' || infix_without_spaces[i + 1] == 'F' || infix_without_spaces[i + 1] == '!') return 1;
			}
			postfix += ch;
			break;
		case '(':
			//Can have anything after except & of | or ')'
			open_parentheses_counter++;
			if (i < infix_without_spaces.length() - 1) {
				if (infix_without_spaces[i + 1] == '&' || infix_without_spaces[i + 1] == '|' || infix_without_spaces[i + 1] == ')') return 1;
			}
			OPERATOR.push(ch);
			break;
		case ')':
			closed_parentheses_counter++;
			//Can have anything after it
			//number of closed parentheses can never exceed number of open parenthses
			if (open_parentheses_counter == 0) return 1;
			if (closed_parentheses_counter > open_parentheses_counter) return 1;
			//Can't have first characterbe closed parentheses
			if (i == 0) return 1;
			while (OPERATOR.top() != '(') {
				postfix += OPERATOR.top();
				if (!OPERATOR.empty())
					OPERATOR.pop();
				else return 1;
			}
			if (!OPERATOR.empty())
				OPERATOR.pop();
			else return 1;
			break;
		case '!':
			//can't have & or |or ) after this operator
			if (i < infix_without_spaces.length() - 1) {
				if (infix_without_spaces[i + 1] == '&' || infix_without_spaces[i + 1] == '|' || infix_without_spaces[i + 1] == ')') return 1;
			}
			//Can't be at the end
			if (i == infix_without_spaces.length() - 1) return 1;
			//Can't have !after a T or F
			if (i > 0) {
				if (infix_without_spaces[i - 1] == 'T' || infix_without_spaces[i - 1] == 'F') return 1;
			}
			while (!OPERATOR.empty() && OPERATOR.top() != '(' && precedence_checker(OPERATOR.top(), ch)) {
				postfix += OPERATOR.top();
				if (!OPERATOR.empty())
					OPERATOR.pop();
				else return 1;
			}
			OPERATOR.push(ch);
			break;
		case '&':
			//can't have & or | after this operator, also can't be at the end OR START
			if (i < infix_without_spaces.length() - 1) {
				if (infix_without_spaces[i + 1] == '&' || infix_without_spaces[i + 1] == '|' || infix_without_spaces[i + 1] == ')') return 1;
			}
			if (i == 0) return 1;
			//can't have (&)
			if (i > 0) {
				if (infix_without_spaces[i - 1] == '(') return 1;
			}
			//Can't be at the end OR START
			if (i == infix_without_spaces.length() - 1 || i == 0) return 1;
			while (!OPERATOR.empty() && OPERATOR.top() != '(' && precedence_checker(OPERATOR.top(), ch)) {
				postfix += OPERATOR.top();
				if (!OPERATOR.empty())
					OPERATOR.pop();
				else return 1;
			}
			OPERATOR.push(ch);
			break;
		case '|':
			//can't have & or | after this operator can't be at the end OR START
			if (i < infix_without_spaces.length() - 1) {
				if (infix_without_spaces[i + 1] == '&' || infix_without_spaces[i + 1] == '|' || infix_without_spaces[i + 1] == ')') return 1;
			}
			if (i == 0) return 1;
			//Can't have (||)
			if (i > 0) {
				if (infix_without_spaces[i - 1] == '(') return 1;
			}
			//Can't be at the end OR START in infix string
			if (i == infix_without_spaces.length() - 1 || i == 0) return 1;
			while (!OPERATOR.empty() && OPERATOR.top() != '(' && precedence_checker(OPERATOR.top(), ch)) {
				postfix += OPERATOR.top();
				if (!OPERATOR.empty())
					OPERATOR.pop();
				else return 1;
			}
			OPERATOR.push(ch);
			break;
		}
	}

	while (!OPERATOR.empty()) {
		postfix += OPERATOR.top();
		OPERATOR.pop();
	}
	/////////////////////////Evaluation of the postfix expression/////////////////////////
	stack<bool> OPERAND;

	for (int i = 0; i < postfix.length(); i++) {
		char ch = postfix[i];
		if (ch == 'T'){
			OPERAND.push(true);
		}
		else if (ch == 'F') {
			OPERAND.push(false);
		}
		else {
			if (ch == '!') {
				bool operand1 = OPERAND.top();
				if (!OPERAND.empty())
					OPERAND.pop();
				else return 1;
				OPERAND.push(!operand1);
			}
			else if (ch == '&') {
				bool operand2 = OPERAND.top();
				if (!OPERAND.empty())
					OPERAND.pop();
				else return 1;
				bool operand1 = OPERAND.top();
				if (!OPERAND.empty())
					OPERAND.pop();
				else return 1;
				OPERAND.push(operand1 && operand2);
			}
			else if (ch == '|') {
				bool operand2 = OPERAND.top();
				if (!OPERAND.empty())
					OPERAND.pop();
				else return 1;
				bool operand1 = OPERAND.top();
				if (!OPERAND.empty())
					OPERAND.pop();
				else return 1;
				OPERAND.push(operand1 || operand2);
			}
		}
	}

	//Last-ditch check to see if something went wrong in the evaluation 
	if (OPERAND.size() != 1) return 1;
	
	result = OPERAND.top();

	//Final check
	/*cerr << "infix: " << infix << endl;
	cerr << "postfix: " << postfix << endl;
	cerr << "result: " << result << endl;
*/

	return 0;


}
// Evaluates a boolean expression
//   If infix is a syntactically valid infix boolean expression,
//   then set postfix to the postfix form of that expression, set
//   result to the value of the expression, and return zero.  If
//   infix is not a syntactically valid expression, return 1; in
//   that case, postfix may or may not be changed, but result must
//   be unchanged.


bool precedence_checker(char top_left, char ch_right) {
	if (ch_right == '!') {
		if (top_left == '!') return true;
		else return false;
	}
	else if (ch_right == '&') {
		if (top_left == '!' || top_left == '&') return true;
		else return false;
	}
	else if (ch_right == '|') {
		if (top_left == '!' || top_left == '&' || top_left == '|') return true;
		else return false;
	}

	return true;
}
//Need ch precedence <= stack top precedence.


int main()
{
	string pf;
	bool answer;
	assert(evaluate("T| F", pf, answer) == 0 && pf == "TF|"  &&  answer);
	assert(evaluate("T|", pf, answer) == 1);
	assert(evaluate("F F", pf, answer) == 1);
	assert(evaluate("TF", pf, answer) == 1);
	assert(evaluate("()", pf, answer) == 1);
	assert(evaluate("T(F|T)", pf, answer) == 1);
	assert(evaluate("T(&T)", pf, answer) == 1);
	assert(evaluate("(T&(F|F)", pf, answer) == 1);
	assert(evaluate("", pf, answer) == 1);
	assert(evaluate("F  |  !F & (T&F) ", pf, answer) == 0
		&& pf == "FF!TF&&|" && !answer);
	assert(evaluate(" F  ", pf, answer) == 0 && pf == "F" && !answer);
	assert(evaluate("((T))", pf, answer) == 0 && pf == "T"  &&  answer);
	//cout << "Passed all tests" << endl;
}