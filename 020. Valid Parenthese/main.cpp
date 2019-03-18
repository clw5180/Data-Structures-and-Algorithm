#include <iostream>
#include <stack>

using namespace std;

bool isMatch(const char& a, const char& b)
{
	if (a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}')
		return true;
	else
		return false;
}

bool isValid(string s) 
{
	stack<char> tempStack;
	int strLength = s.size();
	for (int i = 0; i < strLength; ++i)
	{
		if (!tempStack.empty() && isMatch(tempStack.top(), s[i]))
		{
			tempStack.pop();
		}
		else
		{
			tempStack.push(s[i]);
		}
	}
	if (tempStack.size() == 0)
		return true;
	else
		return false;
}

int main()
{
	string myStr = "()[]{}";
	//string myStr = "([)";
	if (isValid(myStr))
	    cout << "Valid Parenthese!" << endl;
	else
		cout << "Invalid Parenthese!" << endl;
	return 0;
}