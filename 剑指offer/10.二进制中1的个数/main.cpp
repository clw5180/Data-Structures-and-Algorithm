#include <iostream>
#include <string>
#include <vector>

using namespace std;

int  NumberOf1(int n) 
{
	int sum = 0;
	while (n != 0)
	{
		if(n % 2 == 1)
			sum++;
		n /= 2;
	}
	return sum;
}

int main()
{
	cout << NumberOf1(31) << endl;
	cout << NumberOf1(-1) << endl;
	return 0;
}