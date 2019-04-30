#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果
中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
则重建二叉树并返回。
*/

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) 
{
	if (pre.empty() || vin.empty())
		return NULL;
	int nRoot = pre[0];
	int count = 0;
	vector<int> subPre, subVin;
	for (int i = 0; vin[i] != nRoot; ++i)
	{
		subVin.push_back(vin[i]);
		subPre.push_back(pre[i + 1]);
		++count;
	} 

	reConstructBinaryTree(subPre, subVin);
}

int main()
{
	vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
	vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};
	TreeNode *myTree = reConstructBinaryTree(pre, vin);
	return 0;
}