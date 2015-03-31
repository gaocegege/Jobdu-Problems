#include <iostream>

using namespace std;

struct TreeNode
{
	char val;
	TreeNode *left;
	TreeNode *right;
};

class BST
{
public:
	BST(TreeNode *_head): head(_head){}
	void insert(TreeNode *node)
	{
		TreeNode *workNode = head;
		while(true) 
		{
		    if (workNode->val > node->val)
		    {
		    	if (workNode->left != nullptr)
		    	{
		    		workNode = workNode->left;
		    		continue;
		    	}
		    	else
		    	{
		    		workNode->left = node;
		    		break;
		    	}
		    }
		    else
		    {
		    	if (workNode->right != nullptr)
		    	{
		    		workNode = workNode->right;
		    		continue;
		    	}
		    	else
		    	{
		    		workNode->right = node;
		    		break;
		    	}
		    }
		}
	}

	TreeNode *find(const char &c)
	{
		
	}


private:
	TreeNode *head;
};

int main()
{
	int m, n;
	while (cin >> m)
	{
		cin >> n;
		if (m == 0 && n == 0)
			return;

	}
}