#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define maxRange 50

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
	return NULL;
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
	if(N==0)
	{
		return NULL;
	}
	else
	{
		TREE arbre = new node;
		arbre->item=myRandom();
		arbre->right=buildTREE(N-1-(N-1)/2);
		arbre->left=buildTREE((N-1)/2);
		return arbre;
	}
}

void visit(TREE h)
{
	cout<<"Item: "<<h->item<<endl;
}

void traverser(TREE h)
{
	if(h!=NULL)
	{
		visit(h);
		traverser(h->left);
		traverser(h->right);
	}
}


int count(TREE h)
{
	if (h == 0) return 0;
	return count(h->left) + count(h->right) + 1;
}


int main()
{
	TREE arbre = createTREE();
	arbre=buildTREE(15);
	cout<<"comptage: "<<count(arbre)<<endl;
	cout<<"affichage: "<<endl;
	traverser(arbre);
	return 0;
}
