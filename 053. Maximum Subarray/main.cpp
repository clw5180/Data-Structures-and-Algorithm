#include <iostream>
#include <string>
#include <vector>

using namespace std;

//�ҵķ������ο�����https://blog.csdn.net/ljianhui/article/details/13950509���ǳ��õķ�����
int maxSubArray(vector<int>& nums) 
{
	int len = nums.size();
	if (len <= 0)
		return -1;
	int negativeCnt = 0;
	int maxNumber = nums[0];
	int subSum = 0;
	int SubSumMax = 0;

	for (int i = 0; i < len; ++i)
	{
		subSum += nums[i];
		if (subSum > SubSumMax) //�����ǰ�ҵ�������֮�ʹ���֮ǰ�����������֮��
			SubSumMax = subSum;  //���������֮��Ϊ���������֮��
		else if (subSum < 0) //���������֮��С��0��ֱ���������һ������ʼ�ң���Ϊһ���������������
			subSum = 0;

		if (nums[i] < 0) //ͳ�Ƹ����ĸ��������ֻ���ȫΪ��������
			++negativeCnt;
		if (nums[i] > maxNumber) //�ҵ������е����ֵ�����ֻ���ȫΪ��������
			maxNumber = nums[i];
	}
	if (negativeCnt == len) //�����ȫΪ�������飬ֱ��ȡ���ֵ��Ϊ���������
		SubSumMax = maxNumber;
	return SubSumMax;
}

int main()
{
	//vector<int> myVec = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	//vector<int> myVec = { 1 };
	//vector<int> myVec = { -2 };
	//vector<int> myVec = { -2, 1 };
	//vector<int> myVec = { -2, -1 };
	//vector<int> myVec = { 1, -2 };
	//vector<int> myVec = { 1, -2, 3};
	//vector<int> myVec = { 1, -2, 3, -4};
	vector<int> myVec = { -5, 6, -5 };

	cout << maxSubArray(myVec) << endl;
	return 0;
}