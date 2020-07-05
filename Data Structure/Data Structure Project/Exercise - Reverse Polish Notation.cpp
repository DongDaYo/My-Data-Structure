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
			result[len++] = ch[i];//������ֱ����ջ
		}
		else if (ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/') {
			while (S.gettop(x) && (x!='(') && priority(x) >= priority(ch[i])) {//�ȿ�һ��ջ����������ǲ������ȼ����ڵ��ڵ�ǰ�������
																   //������򵯳�ջ�������,������ʽ
																   //���ջ�ջ��������򲻻����whileѭ��
				S.pop(x);
				result[len++] = x;
			}
			S.push(ch[i]);//��ǰ�������ջ
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
	while (!S.isEmpty()) {//������Ϻ��ٵ���ջ��ʣ�������
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