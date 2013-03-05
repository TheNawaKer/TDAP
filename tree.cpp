#include <iostream>
using namespace std;

typedef int Item;

struct node
{
	Item item;
	node * left;
	node * right;
};

typedef node * TREE;

TREE createTREE()
{
	return null
}

int myRandom (void)
{
	int random_integer;
	static int first = 0;
	if(first == 0) srand((unsigned)time(NULL));
	first++;
	random_integer = rand()%maxRange;
	return(random_integer);
}

TREE buildTREE(int N)
{

}