#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Node
{
public:
	int val;
	vector<Node*> children;
	Node() {}
	Node(int _val)
	{
		val = _val;
	}

	Node(int _val, vector<Node*> _children)
	{
		val = _val;
		children = _children;
	}
};

class Solution 
{
public:
	vector<vector<int>> levelOrder(Node* root) 
	{
		vector<vector<int>> ans;
		deque<Node*> que;
		if (root != NULL)
			que.push_back(root);
		while (!que.empty())
		{
			int size = que.size();
			vector<int> temp;
			for (int i = 0; i < size; i++)
			{
				Node* node = que.front();
				temp.push_back(node->val);
				que.pop_front();
				for (int i = 0; i < node->children.size(); i++)
				{
					que.push_back(node->children[i]);
				}
			}
			ans.push_back(temp);
		}
		return ans;
	}
};