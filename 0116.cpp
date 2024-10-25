#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct Node
{
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() :val(0), left(NULL), right(NULL), next(NULL) {}
	Node(int _val) :val(_val), left(NULL), right(NULL), next(NULL) {}
	Node(int _val, Node* _left, Node* _right, Node* _next) :val(_val), left(_left), right(_right), next(_next) {}
};

class Solution 
{
public:
	Node* connect(Node* root) 
	{
		deque<Node*> que;
		if (root != NULL)
			que.push_back(root);
		while (!que.empty())
		{
			int size = que.size();
			for (int i = 0; i < size; i++)
			{
				Node* node1 = que.front();
				que.pop_front();
				if (i != size - 1)
				{
					Node* node2 = que.front();
					node1->next = node2;
				}
				if (node1->left != NULL)
					que.push_back(node1->left);
				if (node1->right != NULL)
					que.push_back(node1->right);
			}
		}
		return root;
	}
};