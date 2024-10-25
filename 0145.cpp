#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
// �������
class Solution 
{
public:
	struct Tree
	{
		TreeNode* root;
		int tag = -1;
		
	};
	//vector<int> postorderTraversal(TreeNode* root) 
	//{
	//	vector<int> ans;
	//	traversal(root, ans);
	//	return ans;
	//}

	//void traversal(TreeNode* root, vector<int>& ans)
	//{
	//	if (root == NULL)
	//		return;
	//	traversal(root->left, ans);
	//	traversal(root->right, ans);
	//	ans.push_back(root->val);
	//}
	//// ������� �ǵݹ�
	//vector<int> postorderTraversal(TreeNode* root)
	//{
	//	stack<TreeNode*> st;
	//	vector<int> ans;
	//	if (root == NULL)
	//		return ans;
	//	st.push(root);
	//	while (!st.empty())
	//	{
	//		TreeNode* node = st.top();
	//		ans.push_back(node->val);
	//		st.pop();
	//		if (node->left != NULL)
	//			st.push(node->left);
	//		if (node->right != NULL)
	//			st.push(node->right);
	//	}
	//	reverse(ans.begin(), ans.end());
	//	return ans;
	//}
	// ������� �ǵݹ� ��־�� �ȱ�������ײ���������ٿ�ʼ����
	vector<int> postorderTraversal(TreeNode* root)
	{
		stack<Tree> st;
		vector<int> ans;
		TreeNode* cur = root;
		while (cur != NULL || !st.empty())
		{
			if (cur != NULL)
			{
				Tree t1;
				t1.root = cur;

				t1.tag = 0;			// ��ʾ������������
				cur = cur->left;	// ��������ײ�����������
				st.push(t1);
			}
			else
			{
				Tree t2 = st.top();
				// �������Ѿ����ʹ�
				if (t2.tag == 1)
				{
					ans.push_back(t2.root->val);
					st.pop();
				}
				// ��������δ���ʹ����ȷ���������
				else if(t2.tag == 0)
				{
					cur = t2.root->right;
					st.top().tag = 1;
				}
			}
		}
		return ans;
	}
	// ������� ͳһ�ǵݹ���
	vector<int> postorderTraversal(TreeNode* root)
	{
		stack<TreeNode*> st;
		vector<int> ans;
		if (root != NULL)
			st.push(root);
		else
			return ans;
		while (!st.empty())
		{
			TreeNode* node = st.top();
			// δ����
			if (node != NULL)
			{
				st.pop();
				st.push(node);
				st.push(NULL);
				if (node->right != NULL)
					st.push(node->right);
				if (node->left != NULL)
					st.push(node->left);
			}
			// ���ʹ�δ����
			else
			{
				st.pop();			// �ȵ����ս��
				// ��ʼ����
				node = st.top();
				ans.push_back(node->val);
				st.pop();
			}
		}
		return ans;
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* node = root;
	node->right = new TreeNode(2);
	node = node->right;
	node->left = new TreeNode(3);

	Solution S;
	S.postorderTraversal(root);

	return 0;
}