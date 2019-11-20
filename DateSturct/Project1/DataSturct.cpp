#include "DataSturct.h"
#include <iostream>
int Tree::Calc::result(Node * node)
{
	if (node == nullptr)
		return 0;
	int n1=result(node->Left);
	int n2=result(node->Right);
	
		switch (node->type)
		{
		case Add: {return n1 + n2; }break;
		case Sub: {return n1 - n2; }break;
		case Multi: {return n1 * n2; }break;
		case Div: {return n1 / n2; }break;
		case Data: {return node->Data; }break;
		}
		
}
Tree::Calc::Node* Tree::Calc::Create(const char * &s)
{
	Type type;
	int value;
	while (*s)
	{
		type = GetToken(*s, value);
			++s;
		switch (type)
		{
		case Data:
			{
				if (root == nullptr)
				{
					root = new Node(Data, value, nullptr, nullptr);

				}
				else
				if (root->Right ==nullptr)
				{
					root->Right = new Node(Data, value, nullptr, nullptr);
				}
				else if (root->Right->Right == nullptr)
				{
					root->Right->Right = new Node(Data, value, nullptr, nullptr);
				}
			}break;

		case Add :
		case Sub:
		{
			/*if (root->type == Add || root->type == Sub|| root->type == Multi || root->type == Div)
			{

				root = new Node(type, value, root, nullptr);

			}
			
			if (root->type = Data)
			{
				root = new Node(type, value, root, nullptr);
			}*/
			root = new Node(type, value, root, nullptr);


		}break;
		case Multi:
		case Div:
		{
			if (root->type == Multi || root->type == Div)
			{
				root = new Node(type, value, root, nullptr);
			}
			else if (root->type == Add || root->type == Sub)
			{
				root->Right = new Node(type, value, root->Right, nullptr);
			}
			else if (root->type == Data)
			{
				root = new Node(type, value, root, nullptr);
			}

		}break;
		case Oparan:
		{
			if (root == nullptr)
			{
				root = CreateOP(s);
			}
			else if (root->Right == nullptr)
			{
			
				root->Right = CreateOP(s);
			}
			else if (root->Right->Right == nullptr)
			{
				root->Right->Right = CreateOP(s);
			}

		}break;


		}


	}

	return nullptr;
}

Tree::Calc::Node * Tree::Calc::CreateOP(const char* &s)
{
	Type type;
	int value;
	Node* Root=nullptr;
	while (*s != ')')
	{
		type = GetToken(*s, value);
		//std::cout << *s;
		++s;
		switch (type)
		{
		case Data:
		{
			if (Root == nullptr)
			{
				Root = new Node(Data, value, nullptr, nullptr);

			}
			else if (Root->Right == nullptr)
			{
				Root->Right = new Node(Data, value, nullptr, nullptr);
			}
		}break;

		case Add:
		case Sub:
		{
			/*if (root->type == Add || root->type == Sub|| root->type == Multi || root->type == Div)
			{

				root = new Node(type, value, root, nullptr);

			}

			if (root->type = Data)
			{
				root = new Node(type, value, root, nullptr);
			}*/
			Root = new Node(type, value, Root, nullptr);


		}break;
		case Multi:
		case Div:
		{
			
			
				Root = new Node(type, value, Root, nullptr);
			

		}break;

		}
	}

	++s;
	type = GetToken(*s, value);
	if (type != Type::Eol)
	{
		Root = new Node(type, value, Root, nullptr);
		++s;
	}
	return Root;

}

Tree::Calc::Type Tree::Calc::GetToken(char s,int& value)
{
	if (s >= '0'&&s <= '9')
	{
		value = s - '0';
		return Type::Data;
	}
	switch (s)
	{
	case '+':
	{
		value = -1;
		return Type::Add;

	}break;
	case '*':
	{
		value = -1;
		return Type::Multi;

	}break;
	case '/':
	{
		value = -1;
		return Type::Div;

	}break;
	case '-':
	{
		value = -1;
		return Type::Sub;

	}break;
	case '(':
	{
		value = -1;
		return Type::Oparan;

	}break;
	case ')':
	{
		value = -1;
		return Type::Cparan;

	}break;
	default:
	{
		value = -1;
		return Type::Eol;
	}
	}


}

char Tree::Calc::coutType(Type type, int value)
{
	switch (type)
	{
	case Data:
	{
		

		return '0' + value;
		
	}break;

	case Add:
	{
		return '+';
	}
	case Sub:
	{
		return '-';


	}break;
	case Multi:
	{
		return '*';
	}
	case Div:
	{


		return '/';

	}break;

	}

}

void Tree::Calc::MidOrder(Node * node)
{
	
	if (node == nullptr)
	{
		return;
	}
	MidOrder(node->Left);
	std::cout<<coutType(node->type, node->Data);
	
	MidOrder(node->Right);

}

