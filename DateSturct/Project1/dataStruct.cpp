#include "DataSturct.h"
#include <iostream>
using namespace std;
using namespace Tree;
int main()
{
	//
	//StackSequence<int> stack(10);
	//LoopQueue<int> loop(10);
	//LinkQueue<int> link;
	//for (int i = 0; i < 20; i++)
	//{
	//	//stack.push(i);
	//	link.enQueue(i);
	//}
	//for (int i = 0; i < 22; i++)
	//{
	//	cout << link.OutQueue() << endl;
	//}
	//system("pause");
	/*BinaryTree<char> binary(nullptr);

	binary.CreateTree('@');
	binary.PreOrder();
	cout << binary.Hight() << endl;
	cout << binary.size() << endl;*/
	/*Calc *ca=new Calc();
	const char *s = "(2+4)*2+3";
	ca->Create(s);
	ca->MidOrder();
	cout << endl;
	cout << ca->result();*/
	char s[7] = {'a','b','c','d','e','f','g'};
	int w[7] = { 10,15,12,3,4,13,1 };
	Hftree<char> hftree(w,s,7,'@');
	hftree.serach();


	system("pause");
}



