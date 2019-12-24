#pragma once
#include <vector>
using namespace std;


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
	// 通过 Queue 继承
	
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
				if (root != nullptr)
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

	void doublespacep();

	Piorydeque(int capacity = 100) 
	{
		type = new ElemType[capacity];
		Maxsize = capacity;
		Currentsize = 0;
	}
	~Piorydeque() 
	{
		delete[] type;
	}
	bool Isempty() const {
		return Currentsize == 0;
	}
	void enQueue(const ElemType& ty);

	ElemType deQueue();

	ElemType gethead()
	{
		return type[1];
	}


private:
	void Doublesapce();
	void bulidHeap();
	void percolateDown(int hole);
	int Maxsize;
	int Currentsize;
	ElemType* type;
};





template<class ElemType>
inline void Piorydeque<ElemType>::Doublesapce()
{
}

template<class ElemType>
inline void Piorydeque<ElemType>::bulidHeap()
{
}

template<class ElemType>
inline void Piorydeque<ElemType>::percolateDown(int hole)
{
}

template<class ElemType>
inline void Piorydeque<ElemType>::doublespacep()
{
	Doublesapce();
}

template<class ElemType>
inline void Piorydeque<ElemType>::enQueue(const ElemType & ty)
{
	++Currentsize;
	if (Currentsize == Maxsize-1) {
		doublespacep();
	}
	type[Currentsize] = ty;
	ElemType eletype = ty;
	int size = Currentsize;
	for (;   eletype> type[size/2]&&size>1; size /=2)
	{
		ElemType t = type[size / 2];
		type[size / 2] = eletype;
		type[size] = t;

	}

}

template<class ElemType>
inline ElemType Piorydeque<ElemType>::deQueue()
{

	ElemType result = type[1];
	type[1] = type[Currentsize];
	--Currentsize;
	ElemType left,right,temp;
	
	for (int i = 1; i*2 <= Currentsize;)
	{
		left = type[i * 2];
		right = type[i * 2 + 1];
		if (i*2!=Currentsize)
		{
			if (left > right)
			{
				temp = left;
				type[i * 2] = type[i];
				type[i] = left;
				i *= 2;
			}
			else
			{
				temp = right;
				type[i * 2 + 1] = type[i];
				type[i] = right;
				i = i * 2 + 1;
			}
		}

	}

	return result;
}


template <class type> int
Binarysearch(const vector<type> &datas, const type &data) {
	int low = 1, high = datas.size() - 1;
	int mid;
	while (high >low) 
	{
		mid = (low + high) / 2;

		if (datas[mid] == data)
		{
			return mid;
		}
		else if (datas[mid] > data) {
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}

	}
	return 0;
}

template <class Type>
class BinarySerarchTree {
private:
	struct treenode
	{
		treenode *left;
		treenode *right;
		Type data;
		treenode(treenode *lf, treenode* ri, const Type& x) :left(lf), right(ri), data(x) {};

	};
	treenode* root;

	void remove(const Type&x,treenode* root);
	void insert(const Type&x, treenode* &root);
	bool find(const Type&x, treenode* root);
public:
	void remove(const Type& x);
	void insert(const Type& x);
	bool find(const Type& x);

};

template<class Type>
inline void BinarySerarchTree<Type>::remove(const Type & x, treenode * node)
{
	if (node == nullptr)
	{
		return;
	}

	


	if (x < node->data) 
	{
		remove(x, node->left);
	}
	else if (x > node->data)
	{
		remove(x, node->right);
	}
	else
	{ 
		if (node->left != nullptr&&node->right != nullptr)
		{
			treenode* temp = node->right;
			if (temp->left != nullptr)
			{
				temp = temp->left;
			}
			node->data = temp->data;
			remove(temp->data, node->right);

		}
		else 
		{
			treenode* treenode = node;
			node = (node->left != nullptr) ? node->left: node->right;
			delete treenode;
		}



	}

}

template<class Type>
inline void BinarySerarchTree<Type>::insert(const Type & x, treenode* &node)
{
	if (node == nullptr) {
		node = new treenode(nullptr, nullptr, x);
		return;
	}

	if (x <= node->left->data) 
	{
		insert(x, node->left);
		
	}
	if (x > node->right->data)
	{
		insert(x, node->right);
	}




}

template<class Type>
inline bool BinarySerarchTree<Type>::find(const Type & x, treenode * node)
{
	if (node == nullptr) 
	{
		return false;
	}

	if (x < node->left->data)
	{
		return find(x, root->left);
	}
	else if (x > root->right->data)
	{
		return find(x, root->right);
	}
	return true;

}

template<class Type>
inline void BinarySerarchTree<Type>::remove(const Type & x)
{
	if (root != nullptr)
	{
		remove(x,root);
	}


}

template<class Type>
inline void BinarySerarchTree<Type>::insert(const Type & x)
{
	insert(x, root);
}

template<class Type>
inline bool BinarySerarchTree<Type>::find(const Type & x)
{
	if (root != nullptr)
	{
		return find(x, root);
	}
	else {
		return false;
	}

}

template<class Emetype>
class Avltree {
public:
	struct AvlNode
	{
		Emetype data;
		AvlNode* left;
		AvlNode* right;
		int height;
		AvlNode(const Emetype& elemnt, AvlNode *lf, AvlNode* rg, int h = 0): data(elemnt), left(lf), right(rg), height(h) {}
	};
	AvlNode* root;
	Avltree(AvlNode *t = nullptr) :root(t) {}
	~Avltree() {}
	bool find(const Emetype& x) 
	{
		return Find(x,root);
	}

	bool remove(const Emetype& x)
	{
		remove(x, root);
	}
	void insert(const Emetype& x)
	{
		insert(x, root);
	}
private:
	bool Find(const Emetype& x, AvlNode* &node) const ;
	bool remove(const Emetype& x, AvlNode* &node);
	void insert(const Emetype& x, AvlNode* &node);
	int height(AvlNode* node) 
	{
		if (node != nullptr)
		{
			return node->height;
		}
		return 0;
	
	}
	void LL(AvlNode* &node);
	void LR(AvlNode* &node);
	void RL(AvlNode* &node);
	void RR(AvlNode* &node);
	int max(int a, int b) { return a > b?a:b; }
};



template<class Emetype>
inline bool Avltree<Emetype>::Find(const Emetype & x, AvlNode *& node) const
{
	if (node == nullptr)
	{
		return false;
	}
	if (x < node->data)
	{
		return Find(x, node->left);
	}
	else if (x < node->data)
	{
		return Find(x, node->right);
	}
	else
	{
		return true;
	}
	
}

template<class Emetype>
inline bool Avltree<Emetype>::remove(const Emetype & x, AvlNode* &node)
{
	return false;
}

template<class Emetype>
inline void Avltree<Emetype>::insert(const Emetype & x, AvlNode* &node)
{

	if (node == nullptr)
	{
		node = new AvlNode(x, nullptr, nullptr);
	}
	if (x < node->data)
	{
		insert(x, node->left);
		if (height(node->left) - height(node->right) == 2)
		{
			if (x < node->left->data)
			{
				LL(node);
			}
			else
			{
				LR(node);
			}
		}
	}
	else if (x > node->data)
	{
		insert(x, node->right);
		if (height(node->right) - height(node->left) == 2)
		{
			if (x > node->right->data)
			{
				RR(node);
			}
			else
			{
				RL(node);
			}
		}

	}
	

	
}

template<class Emetype>
inline void Avltree<Emetype>::LL(AvlNode *& node)
{
	AvlNode *t1 = node->left;
	node->left = t1->right;
	t1->left = node;
	node->height = max(height(node->left), height(node->right)) + 1;
	t1->height = max(height(t1->left), height(node->right)) + 1;
	node = t1;

}

template<class Emetype>
inline void Avltree<Emetype>::LR(AvlNode * &node)
{
	RR(node->left);
	LL(node);

}

template<class Emetype>
inline void Avltree<Emetype>::RL(AvlNode * &node)
{
	LL(node->right);
	RR(node);
	
}

template<class Emetype>
inline void Avltree<Emetype>::RR(AvlNode * &node)
{
	AvlNode* t1 = node->right;
	node->right = t1->left;
	t1->left = node;
	node->height = max(height(node->left),height(node->right))+1;
	t1->height = max(height(t1->left), height(t1->right)) + 1;
	node = t1;
}

enum color_set1 { RED, BLACK };


template<class Emetype>
class RedBlackTree
{
public:
	enum setcolor
	{
		red,
		black
	};
	struct Treenode
	{
		Treenode* left;
		Treenode* right;
		Treenode* parent;
		Emetype data;
		int color;
		Treenode(Treenode* lf, Treenode* ri,const Emetype &da, int c) :left(lf), right(ri), color(c), data(da) {}

	};

	bool find(const Emetype &da)
	{
		find(da, root);
	}
	void insert(const Emetype& da)
	{
		insert(da, root);

	}
	bool remove(const Emetype& da)
	{
		remove(da, root);
	}
	
private:
	Treenode* root;
	bool find(const Emetype &da, Treenode* node) const;
	void insert(const Emetype& da, Treenode* &node);
	bool remove(const Emetype& da, Treenode* node);
	void solveDoubleRed(Treenode* node);
	void solveLostBlack(Treenode *node);
	void LL(Treenode* &node);
	void LR(Treenode* &node);
	void RL(Treenode* &node);
	void RR(Treenode* &node);

};

template<class Emetype>
inline bool RedBlackTree<Emetype>::find(const Emetype & da, Treenode * node) const
{
	return false;
}

template<class Emetype>
inline void RedBlackTree<Emetype>::insert(const Emetype & da, Treenode* &node)
{

	if (node == nullptr)
	{	
		Treenode *node = new Treenode(nullptr, nullptr, da, setcolor::red);
		//solveDoubleRed(node);
		return;
	}

	if (node->data < da)
	{
		insert(da, node->right);
		if (node->right->parent != nullptr)
		{
			node->right->parent = node;
			solveDoubleRed(node->right);
		}
	}
	else if (node->data > da)
	{
		insert(da, node->left);
		if (node->left->parent != nullptr)
		{
			node->left->parent = node;
			solveDoubleRed(node->left);
		}
	}
	



}

template<class Emetype>
inline bool RedBlackTree<Emetype>::remove(const Emetype & da, Treenode * node)
{

	while (node->parent != root && node->parent->color==setcolor::black )
	{
		Treenode* parent = node->parent;
		Treenode* uncle=nullptr;
		if (parent->left == node)
		{
			uncle = parent->right;
		}
		else
		{
			uncle = parent->left;
		}
		if (parent->left == uncle)
		{
			if (uncle->color == setcolor::red)
			{
				uncle->color = setcolor::black;
				node->parent->color = setcolor::red;
				RR(node->parent);

			}
			if ((uncle->left == nullptr || uncle->left->color == setcolor::black)&&(uncle->right == nullptr || uncle->right->color == setcolor::black))
			{
				uncle->color = setcolor::red;
				node = node->parent;
			}
			else
			{
				if (uncle->right != nullptr&&uncle->right->color == setcolor::black)
				{
					uncle->left->color = setcolor::black;
					uncle->color= setcolor::black;
					RR(uncle);
					uncle = parent->left;
				}
				uncle->color = node->parent->color;
				parent->color = setcolor::black;
				uncle->right->color = setcolor::black;
				LL(parent);
				node = root;

			}
		}
		else
		{

		}



	}
	return false;
}

template<class Emetype>
inline void RedBlackTree<Emetype>::solveDoubleRed(Treenode * node)
{
		while (node->parent != nullptr&&node->parent->color== setcolor::red)
	{
		Treenode* father = node->parent;
		Treenode* grandfahter = node->parent->parent;
		Treenode* brother = nullptr;
		if (grandfahter->left == father)
		{
			brother = grandfahter->right;
		}
		else
		{
			brother = grandfahter->left;
		}
		if (brother->color == setcolor::black)
		{ //旋转

			if (father == grandfahter->left)
			{
				if (node == father->left)
				{
					LL(grandfahter);
				}
				else
				{
					LR(grandfahter);
				}
				grandfahter->color = setcolor::black;
				grandfahter->left->color = setcolor::red;
				grandfahter->right->color = setcolor::red;
			}
			else
			{
				if (node == father->left)
				{
					RL(grandfahter);
				}
				else
				{
					RR(grandfahter);
				}
				grandfahter->color = setcolor::black;
				grandfahter->left->color = setcolor::red;
				grandfahter->right->color = setcolor::red;

			}

		}
		else
		{//着色旋转
			
			father->color = setcolor::black;
			brother->color = setcolor::black;
			grandfahter->color = setcolor::red;
			node = grandfahter;
			
		}
	}
		root->color = setcolor::black;


}

template<class Emetype>
inline void RedBlackTree<Emetype>::solveLostBlack(Treenode * node)
{
}

template<class Emetype>
inline void RedBlackTree<Emetype>::LL(Treenode * &node)
{
	Treenode *t1 = node->left;

	if (t1->right != nullptr)
	{
		node->left = t1->right;
		t1->right->parent = node;
	}
	t1->left = node;
	node->parent = t1;
	node = t1;
}

template<class Emetype>
inline void RedBlackTree<Emetype>::LR(Treenode * &node)
{
	RR(node->left);
	LL(node);
}

template<class Emetype>
inline void RedBlackTree<Emetype>::RL(Treenode * &node)
{
	LL(node->right);
	RR(node);
}

template<class Emetype>
inline void RedBlackTree<Emetype>::RR(Treenode * &node)
{
	Treenode* t1 = node->right;
	if (t1->left != nullptr)
	{
		node->right = t1->left;
		t1->left->parent = node;
	}
	t1->left = node;
	node->parent = t1;
	node = t1;
}




template<class Type>
class AAtree {
public:
	struct AAnode
	{
		AAnode* left;
		AAnode* right;
		int level;
		Type type;
		AAnode(const Type &ty, AAnode *le, AAnode* ri, int lv = 1) :left(le), right(ri), level(lv), type(ty) {}
	};
	AAnode *root;
	AAtree(AAnode* t = NULL) { root =t ; }
	~AAtree() { makeEmpty(root); }
	void find(const Type &ty) { find(ty, root); }
	void add(const Type &ty) { add(ty, root); }
	void remove(const Type &ty) {
		remove(ty, root);
	}

private:
	void find(const Type ty, AAnode* &node);
	void add(const Type ty, AAnode* &node);
	void remove(const Type ty, AAnode* &node);
	void LL(AAnode* &node);
	void RR(AAnode*& node);
	void makeEmpty(AAnode* &node); 

};

template<class Type>
inline void AAtree<Type>::find(const Type ty, AAnode *& node)
{
}

template<class Type>
inline void AAtree<Type>::add(const Type ty, AAnode *& node)
{
}

template<class Type>
inline void AAtree<Type>::remove(const Type ty, AAnode *& node)
{
}

template<class Type>
inline void AAtree<Type>::LL(AAnode *& node)
{
}

template<class Type>
inline void AAtree<Type>::RR(AAnode *& node)
{
}

template<class Type>
inline void AAtree<Type>::makeEmpty(AAnode *& node)
{
}
