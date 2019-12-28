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
	//char s[7] = {'a','b','c','d','e','f','g'};
	//int w[7] = { 10,15,12,3,4,13,1 };
	//Hftree<char> hftree(w,s,7,'@');
	//hftree.serach();

	unsigned int uRes32 = 0xffff;

	const unsigned int sign2 = ((uRes32 >> 16) & 0x8000);
	const unsigned int exp2 = ((((const int)((uRes32 >> 23) & 0xff)) - 127 + 15) << 10);
	const unsigned int mant2 = ((uRes32 >> 13) & 0x3ff);
	const unsigned int bits = (sign2 | exp2 | mant2);
	const unsigned int result = bits - 1024;
	cout<<result<<endl;
	cout << float(1111111111111);


	system("pause");
}



