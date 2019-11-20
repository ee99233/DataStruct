#pragma once

template<class EnumType>
class Stack
{
public:
	virtual EnumType pop()  = 0;
	virtual void push(const EnumType& X) = 0;
	virtual bool isEmpty() const = 0;
	virtual EnumType Toppop() const = 0;
	virtual ~Stack() {};
};

template<class EnumType>
class StackSequence: Stack<EnumType>
{
public:
	 virtual EnumType pop()  override;
	 virtual  void push(const EnumType& X) override;
	 virtual bool isEmpty() const override;
	 virtual EnumType Toppop() const override;
	~StackSequence();
	StackSequence(int size);
private:
	EnumType* elem;
	int top ;
	int maxsize;
	void DoubleSize();
	
};

template<class EnumType>
inline StackSequence<EnumType>::StackSequence(int size)
{
	elem = new EnumType[size];
	top = -1;
	maxsize = size;
}

template<class EnumType>
EnumType  StackSequence<EnumType>::pop() 
{
	if (top >= 0)
	{
		EnumType temp = elem[top];
		--top;
		return temp;
	}

}

template<class EnumType>
inline void StackSequence<EnumType>::push(const EnumType & X)
{
	if (top < maxsize-1)
	{
		top += 1;
		elem[top] = X;

	}
	else
	{
		DoubleSize();
		top += 1;
		elem[top] = X;
	}
}

template<class EnumType>
inline bool StackSequence<EnumType>::isEmpty() const
{
	return top == -1;
}

template<class EnumType>
inline EnumType StackSequence<EnumType>::Toppop() const
{
	if (top >= 0)
	{
		EnumType temp = elem[top];
		return temp;
	}
	
}

template<class EnumType>
inline StackSequence<EnumType>::~StackSequence()
{
	delete []elem;
		
}



template<class EnumType>
inline void StackSequence<EnumType>::DoubleSize()
{
	EnumType* eletemp = new EnumType[maxsize * 2];
	for (int i = 0; i< maxsize; i++)
	{
		eletemp[i] = elem[i];
	}
	delete []elem;
	elem = eletemp;
	maxsize *= 2;
}

template<class Elem> class Queue
{
public:
	virtual void enQueue(const Elem& x)=0;
	virtual Elem OutQueue()=0;
	virtual ~Queue() {};
	virtual bool isEmepty()=0;
	virtual Elem GetHead() const =0;

};

template<class Elem> 
class LoopQueue:public Queue<Elem>
{
public:
	virtual void enQueue(const Elem & x) override;
	virtual Elem OutQueue() override;
	virtual bool isEmepty() override;
	virtual Elem GetHead() const override;

	LoopQueue(int size);
	~LoopQueue();
private:
	void DoubleSize();
	int Front;
	int Rear;
	Elem* elem; 
	int maxsize;
	// Í¨¹ý Queue ¼Ì³Ð
	
};

template<class Elem>
inline void LoopQueue<Elem>::enQueue(const Elem & x)
{
	if (((Rear + 1) % maxsize) != Front)
	{
		Rear = (Rear + 1) % maxsize;
		elem[Rear] = x;


	}
	else
	{
	
		DoubleSize();
		Rear = (Rear + 1) % maxsize;
		elem[Rear] = x;
	}

}

template<class Elem>
inline Elem LoopQueue<Elem>::OutQueue()
{
	if (Front != Rear)
	{
		Front = (Front + 1) % maxsize;
		return elem[Front];
	}
}

template<class Elem>
inline bool LoopQueue<Elem>::isEmepty()
{
	return Front == Rear;
}

template<class Elem>
inline Elem LoopQueue<Elem>::GetHead() const
{
	return elem[(Front+1)%maxsize];
}

template<class Elem>
inline LoopQueue<Elem>::LoopQueue(int size)
{

	elem = new Elem[size];
	Front = 0;
	Rear = 0;
	maxsize = size;

}

template<class Elem>
inline LoopQueue<Elem>::~LoopQueue()
{
	delete []elem;


}

template<class Elem>
inline void LoopQueue<Elem>::DoubleSize()
{

	Elem* eletemp = new Elem[maxsize * 2];
	for (int i = 1; i < maxsize; i++)
	{
		eletemp[i] = elem[(Front+i)%maxsize];
	}
	Rear = maxsize - 1;
	Front = 0;
	maxsize *= 2;
	delete[]elem;
	elem = eletemp;

}


//linkQueue

template<class Elem> 
class LinkQueue :public Queue<Elem>
{
public:
	virtual void enQueue(const Elem & x) override;
	virtual Elem OutQueue() override;
	virtual bool isEmepty() override;
	virtual Elem GetHead() const override;
	LinkQueue() ;
	~LinkQueue();
private:
	struct Node
	{
		Elem elem;
		Node *next;
		Node() :next(nullptr) {};
	};
	Node *Front;
	Node *Rear;
};

template<class Elem>
inline void LinkQueue<Elem>::enQueue(const Elem & x)
{
	Node* node = new Node();
	node->elem = x;
	node->next = nullptr;
	if (Rear == nullptr)
	{
		
		Front=Rear = node;
	}
	else
	{
		Rear->next = node;
		Rear = node;
	}

}

template<class Elem>
inline Elem LinkQueue<Elem>::OutQueue() 
{
	
	
	
		Elem elem = Front->elem;
		Node* tep  = Front->next;
		delete Front;
		Front = tep;
		if (Front == nullptr)
		{
			Front = Rear = nullptr;

		}
		return elem;
	
}

template<class Elem>
inline bool LinkQueue<Elem>::isEmepty()
{
	return Front == nullptr;
}

template<class Elem>
inline Elem LinkQueue<Elem>::GetHead() const
{
	if (Front != nullptr)
	{
		return Front->elem;
	}
}

template<class Elem>
inline LinkQueue<Elem>::LinkQueue()
{
	Front = Rear = nullptr;

}

template<class Elem>
inline LinkQueue<Elem>::~LinkQueue()
{
	while (Front != nullptr)
	{
		Node* tep = Front->next;
		delete Front;
		Front = tep;
	}

}


 namespace Tree{

	template<class ElemType>
	class BinaryTree
	{
	private:
		struct TreeNode
		{
			TreeNode* left;
			TreeNode* right;
			ElemType elem;
			TreeNode() :left(nullptr), right(nullptr) {};
			TreeNode(ElemType x, TreeNode* L = nullptr, TreeNode* R = nullptr) :elem(x), left(L), right(R) {};
			~TreeNode() {};
		};
		void clear();
		int size(TreeNode *node);
		int Hight(TreeNode *node);
		void PreOrder(TreeNode *node) const;
		void MidOrder(TreeNode *node) const;
		void NexOrder(TreeNode *node) const;
		void Clear(TreeNode* node);
		
		TreeNode* Root;
	public:
		BinaryTree(TreeNode* p) :Root(p) {};
		BinaryTree(const ElemType& elem) { Root = new TreeNode(elem); };
		~BinaryTree() { clear(); }
		ElemType GetRoot() const { return Root->elem; }
		ElemType Getleft() const { return Root->left->elem; }
		ElemType Getright() const { return Root->right->elem; }
		int size();
		int Hight()
		{
			return Hight(Root);
		}
		void PreOrder() const
		{
			if (Root != nullptr)
			{
				PreOrder(Root);
			}
		}
		void MideOrder() const
		{
			if (Root != nullptr)
			{
				MidOrder(Root);
			}
		}
		void NexOrder() const
		{
			if (Root != nullptr)
			{
				NexOrder(Root);
			}
		}
		void Clear()
		{
			if (Root != nullptr)
			{
				Clear(Root);
			}
			Root = nullptr;
		}
		void CreateTree(ElemType flag);

	};

	template<class ElemType>
	inline void BinaryTree<ElemType>::clear()
	{
	}

	template<class ElemType>
	inline int BinaryTree<ElemType>::size(TreeNode * node)
	{

		if (node == nullptr)
		{
			return 0;
		}
		return  size(node->left) + size(node->right) + 1;
	}

	template<class ElemType>
	inline int BinaryTree<ElemType>::Hight(TreeNode * node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		int n1 = Hight(node->left) + 1;
		int n2 = Hight(node->right) + 1;
		if (n1 >= n2)
		{
			return n1;
		}
		else
		{
			return n2;
		}

	}
	template<class ElemType>
	inline void BinaryTree<ElemType>::PreOrder(TreeNode * node) const
	{
		
		if (node == nullptr)return;

		std::cout << node->elem << std::endl;

		PreOrder(node->left);

		PreOrder(node->right);

		/*if (node != nullptr)
		{
			cout << node->elem << endl;

			PreOrder(node->left);

			PreOrder(node->right);
		}*/


	}
	template<class ElemType>
	inline void BinaryTree<ElemType>::MidOrder(TreeNode * node) const
	{


		if (node == nullptr)
		{
			return;
		}

		MidOrder(node->left);

		std::cout << node->elem << std::endl;

		MidOrder(node->right);
		/*if (node != nullptr)
		{
			

			MidOrder(node->left);
			std::cout << node->elem << std::endl;

			MidOrder(node->right);
		}*/


	}
	template<class ElemType>
	inline void BinaryTree<ElemType>::NexOrder(TreeNode * node) const
	{

		if (node == nullptr)return;

		MidOrder(node->left);
		MidOrder(node->right);
		std::cout << node->elem << std::endl;

	}
	template<class ElemType>
	inline void BinaryTree<ElemType>::Clear(TreeNode * node)
	{
		if (node == nullptr)
			return;
		Clear(node->left);
		Clear(node->right);
		delete node;
	}

	template<class ElemType>
	inline int BinaryTree<ElemType>::size()
	{
		return size(Root);
	}

	template<class ElemType>
	inline void BinaryTree<ElemType>::CreateTree(ElemType flag)
	{

		LinkQueue<TreeNode*> linkqueue;
		ElemType x, ldata, rdata;
		std::cin >> x;
		Root  = new TreeNode(x);
		linkqueue.enQueue(Root);
		TreeNode* temp;
		while (!linkqueue.isEmepty())
		{
			temp = linkqueue.OutQueue();
			std::cout << "insert"<<std::endl;
			std::cin >> ldata >> rdata;

			if (ldata != flag)
			{
				
				temp->left = new TreeNode(ldata);
				linkqueue.enQueue(temp->left);
				
			}
			if (rdata != flag)
			{
				
				temp->right = new TreeNode(rdata);
				linkqueue.enQueue(temp->right);
			}
			
		}
		std::cout << "complete create"<< std::endl;
;


	}

	class Calc
	{
	private:
		enum Type{Data,Add,Sub,Multi,Div,Oparan,Cparan,Eol};
		struct Node
		{
			Type type;
			int Data;
			Node* Left;
			Node* Right;
			Node(Type t, int data = 0,Node *left=nullptr, Node* right=nullptr) 
			{
				type = t;
				Data = data;
				Left = left;
				Right = right;
			}
		};
		Node* root;
		void Clear(Node* node)
		{
			if (node == nullptr)
				return;
			Clear(node->Left);
			Clear(node->Right);
			delete node;
		}
		int result(Node* node);


		public:
			Calc() :root(nullptr) {};
			~Calc()
			{
				if (root != nullptr);
				Clear(root);
			}
			int result()
			{
				if (root != nullptr)
				{
					return result(root);
				}

			}
			Node* Create(const char* &s);
			Node* CreateOP(const char*&s);
			Type GetToken(char s, int& value);
			char coutType(Type type, int value);
			void MidOrder(Node *node);
			void MidOrder()
			{
				if (root != nullptr)
				MidOrder(root);
			}
		
	};
	template<class ElemType> class Hftree
	{
		public:
			Hftree(int *weight, ElemType* type,int size, ElemType flag);
			void serach();
		private:
			struct Node
			{
				ElemType type;
				int Parent, Right, Left;
				int weight;
				Node(int Weight, ElemType Type) :Parent(0), Right(0), Left(0) {
					weight = Weight;
					type = Type;
				};
				Node() : Parent(0), Right(0), Left(0) {};
			};
			Node* elem;
			int length;

	};


	template<class ElemType>
	inline Hftree<ElemType>::Hftree(int * weight, ElemType * type, int size, ElemType flag)
	{
		length = 2 * size - 1;
		elem = new Node[length+1];
		Node *Onenode;
		Node *Twonode;
		int one = 0;
		int two = 0;
		for (int i = 0; i < size; i++)
		{
			Node node = Node(weight[i], type[i]);
			elem[size+i] = node;
		}
		//elem[0] = Node(1000000, type[0]);
		Onenode = &elem[length];
		Twonode = &elem[length-1];
		one = length;
		two = length - 1;
		Node TempNode = Node(1000000, type[0]);
		for (int i = size; i > 1; i--)
		{
			
			for (int j = length; j >= i; j--)
			{
				if (elem[j].Parent == 0)
				{

					if (elem[j].weight < Onenode->weight)
					{
						Onenode = &elem[j];
						one = j;
					}
				}
			}
			for (int j = length; j >= i; j--)
			{
				if (elem[j].Parent == 0)
				{

					if ((elem[j].weight < Twonode->weight)&&(elem[j].weight>= Onenode->weight)&&(j!=one))
					{
						Twonode = &elem[j];
						two = j;
					}
				}
			}
			Node node = Node(Onenode->weight+Twonode->weight,flag);
			//std::cout << node.weight <<std::endl; //
			if (Onenode->type == flag)
			{
				node.Left = one;
				node.Right = two;
			}
			else
			{
				node.Left = two;
				node.Right = one;
			}
			
			Onenode->Parent = i-1;
			Twonode->Parent = i-1;
			Onenode = nullptr;
			Twonode = nullptr;
			one = i - 1;
			two = 0;
			elem[i-1] = node;
			Onenode = &elem[i-1];
			Twonode = &TempNode;

		}
		
		elem[1].Parent = -1;


	}

	template<class ElemType>
	inline void Hftree<ElemType>::serach()
	{
		for (int i = 1; i <= length; i++)
		{
			std::cout << elem[i].weight <<" left "<< elem[i].Left << " right " << elem[i].Right<<" parent"<<elem[i].Parent <<std::endl;
		}

	}

};



template<class ElemType>
class Piorydeque
{

public:



private:
	int Maxsize;
	int Currentsize;

};