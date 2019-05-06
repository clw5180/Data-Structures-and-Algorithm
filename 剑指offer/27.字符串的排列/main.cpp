#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(char &a, char &b)
{
	char tmp = a;
	a = b;
	b = tmp; 
}

void FindCombination(string str, int start, string& resultStr, vector<string>& resultVec)
{
	int len = str.size();
	if (start == len)
	{
		cout << str << endl;
		resultVec.push_back(resultStr);
		return;
	}
		
	
	for (int i = start; i < len - 1; ++i)
	{
		resultStr.push_back(str[i]);
		swap(str[start], str[i]);
		FindCombination(str, start+1 , resultStr, resultVec);
	}
}


vector<string> Permutation(string str) 
{
	if (str.empty())
		return {};

	string resultStr;
	vector<string> resultVec;
	FindCombination(str, 0, resultStr, resultVec);
}

int main()
{
	Permutation("abc");
	return 0;
}