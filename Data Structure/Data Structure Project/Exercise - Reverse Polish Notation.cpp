/*

#include<iostream>
#include"LinkStack.cpp"
using namespace std;

int priority(char c) {
	if (c == '+' or c == '-') {
		return 1;
	}
	else if (c == '*' or c == '/') {
		return 2;
	}
}

int main()
{
	char ch[50];
	char result[50];
	char x;
	cin.getline(ch, 50);
	LinkStack<char> S;
	int i = 0;
	int len = 0;
	while (ch[i] != '\0') {
		if (ch[i] >= 'A' && ch[i] <= 'Z') {
			result[len++] = ch[i];//操作数直接入栈
		}
		else if (ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/') {
			while (S.gettop(x) && (x!='(') && priority(x) >= priority(ch[i])) {//先看一下栈顶的运算符是不是优先级大于等于当前运算符，
																   //如果是则弹出栈顶运算符,加入表达式
																   //如果栈空或遇到（则不会进入while循环
				S.pop(x);
				result[len++] = x;
			}
			S.push(ch[i]);//当前运算符入栈
		}
		else if (ch[i] == '(') {
			S.push(ch[i]);
		}
		else if (ch[i] == ')') {
			while (S.gettop(x) && x != '(') {
				S.pop(x);
				result[len++] = x;
			}
			if (S.gettop(x) && x == '(') {
				S.pop(x);
			}
		}
		i++;
	}
	while (!S.isEmpty()) {//处理完毕后再弹出栈中剩余运算符
		S.pop(x);
		result[len++] = x;
	}
	for (int i = 0; i < len; i++) {
		cout << result[i];
	}
	cout << endl;
	return 0;
}

*/