#include <iostream>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

int pr(char el) {
	if (el == '+' || el == '-') {
		return 1;
	}
	else if (el == '*' || el == '/') {
		return 2;
	}
	return 0;
}

void toPostfix(string expr) {
	stack < char > st;
	for (const auto& el : expr) {
		if (el>='0' && el<='9') {
			cout << el;
		}
		else {
			if (el == '('){
				st.push(el);
				continue;
			}
			else if (el == ')') {
				while (st.top() != '(') {
					cout << st.top();
					st.pop();
				}
				st.pop();
				continue;
			}
			while (!st.empty() && pr(el) <= pr(st.top())) {
					cout << st.top();
					st.pop();
			}
			st.push(el);
		}
	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}

int main() {
	string expr = "(1+2)*3";
	toPostfix(expr);
	return 0;
}