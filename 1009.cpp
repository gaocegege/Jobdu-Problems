#include <iostream>
#include <string>

using namespace std;

struct Node
{
	Node* leftNode;
	Node* rightNode;
	int value;
};

class BinaryTree
{
public:
	BinaryTree(string str);
	~BinaryTree();
	string preorder(Node* node);
	string inorder(Node* node);
	string postorder(Node* node);
	Node* getRoot();
	
private:
	int charToInt(char c);
	char intToChar(int a);
	void setRoot(int value);
	void addNode(int value);
	Node* root;
};

Node* BinaryTree::getRoot()
{
	return root;
}

int BinaryTree::charToInt(char c)
{
	return c - '0';
}

char BinaryTree::intToChar(int a)
{
	return '0' + a;
}

void BinaryTree::setRoot(int value)
{
	root = new Node();
	root->leftNode = NULL;
	root->rightNode = NULL;
	root->value = value;
}

void BinaryTree::addNode(int value)
{
	Node* buf = root;
	Node* addPos = root;
	while (buf != NULL)
	{
		if (value > buf->value)
		{
			addPos = buf;
			buf = buf->rightNode;
		}
		else if (value < buf->value)
		{
			addPos = buf;
			buf = buf->leftNode;
		}
	}

	Node* needAdd = new Node();
	needAdd->leftNode = NULL;
	needAdd->rightNode = NULL;
	needAdd->value = value;

	if (value > addPos->value)
	{
		addPos->rightNode = needAdd;
	}
	else
	{
		addPos->leftNode = needAdd;
	}
}

string BinaryTree::preorder(Node* node)
{
	Node* buf = node;
	string result = "";
	if (buf != NULL)
	{
		result = result + intToChar(buf->value);
		result += preorder(buf->leftNode);
		result += preorder(buf->rightNode);
	}
	return result;
}

string BinaryTree::inorder(Node* node)
{
	Node* buf = node;
	string result = "";
	if (buf != NULL)
	{
		result += inorder(buf->leftNode);
		result = result + intToChar(buf->value);
		result += inorder(buf->rightNode);
	}
	return result;
}

string BinaryTree::postorder(Node* node)
{
	Node* buf = node;
	string result = "";
	if (buf != NULL)
	{
		result += postorder(buf->leftNode);
		result += postorder(buf->rightNode);
		result = result + intToChar(buf->value);
	}
	return result;
}

BinaryTree::BinaryTree(string str)
{
	setRoot(charToInt(str[0]));
	for (int i = 1; i < str.size(); i++)
	{
		addNode(charToInt(str[i]));
	}
}

BinaryTree::~BinaryTree(){}

int main()
{
	int n;
	while (cin >> n,n)
	{
		string str = "";
		cin >> str;
		BinaryTree bt = BinaryTree(str);
		Node* buf = bt.getRoot();
		// cout << "preorder: " << bt.preorder(buf) << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> str;
			BinaryTree btbuf = BinaryTree(str);
			Node* bufbuf = btbuf.getRoot();
			if (bt.inorder(buf) == btbuf.inorder(bufbuf) && bt.preorder(buf) == btbuf.preorder(bufbuf))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}