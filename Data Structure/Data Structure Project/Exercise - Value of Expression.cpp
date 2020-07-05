/*

#include<iostream>
#include"LinkStack.cpp"
using namespace std;
int priority(char c) {
	if (c == '+' || c == '-') {
		return 1;
	}
	else if (c == '*' || c == '/') {
		return 2;
	}
}

void Pop(char& c, LinkStack<char> &OPER, LinkStack<int> &OPND) {
	int a, b;
	OPER.pop(c);
	OPND.pop(b);
	OPND.pop(a);
	switch (c) {
		case ('+'):OPND.push(a + b); break;
		case ('-'):OPND.push(a - b); break;
		case ('*'):OPND.push(a * b); break;
		case ('/'):OPND.push(a / b); break;
	}
}

int main() {
	char ch[100];
	cin.getline(ch, 100);
	int i = 0;
	LinkStack<int> OPND;
	int x;
	int a, b;
	LinkStack<char> OPER;
	char c;
	int lastchar = 1;//上一个字符是数字：1，是运算符：2，是括号：0
	while (ch[i] != '\0') {
		if (ch[i] >= '0' && ch[i] <= '9') {
			if (lastchar == 1 && OPND.gettop(x)) {
				OPND.pop(x);
				OPND.push(x * 10 + (ch[i] - '0'));
				lastchar = 1;
			}
			else {
				OPND.push(ch[i] - '0');
				lastchar = 1;
			}
		}
		else if (ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/') {
			while (OPER.gettop(c) && c != '(' && priority(c) >= priority(ch[i])) {
				Pop(c, OPER, OPND);
			}
			OPER.push(ch[i]);
			lastchar = 2;
		}
		else if (ch[i] == '(') {
			OPER.push(ch[i]);
			lastchar = 0;
		}
		else if (ch[i] == ')') {
			while (OPER.gettop(c) && c != '(') {
				Pop(c, OPER, OPND);
			}
			if (OPER.gettop(c) && c == '(') {
				OPER.pop(c);
			}
		}
		i++;
	}
	while (!OPER.isEmpty()) {
		Pop(c, OPER, OPND);
	}
	int result;
	OPND.pop(result);
	cout << "计算结果为" << result << endl;
	return 0;
}

*/