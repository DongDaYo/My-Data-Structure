/*

#include<iostream>
#include "LinkStack.cpp"
using namespace std;

int main() {
	bool result = true;
	char ch[20];
	char x;
	cin.getline(ch,20);
	LinkStack<char> S;
	int i = 0;
	while (ch[i] != '\0') {
		if (ch[i] == '(' || ch[i] == '[' || ch[i] == '{') {
			S.push(ch[i]);
		}
		else {
			if (S.pop(x)) {
				if ((ch[i] == ')' && x == '(') || (ch[i] == ']' && x == '[') || (ch[i] == '}' && x == '{')) {
				}else {
					result = false;
					break;
				}
			}
			else {
				result = false;
				break;
			}
		}
		i++;
	}
	if (!S.isEmpty()) {
		result = false;
	}
	if (result) {
		cout << "Æ¥Åä³É¹¦£¡" << endl;
	}
	else {
		cout << "Æ¥ÅäÊ§°Ü" << endl;
	}
	return 0;
}

*/