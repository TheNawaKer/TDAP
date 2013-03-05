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

void visit(TREE h,string s)
{
	cout<<s<<h->item<<endl;
}

void traverser(TREE h,string s="")
{
	if(h!=NULL)
	{
		traverser(h->left,s+"    ");
		visit(h,s);
		traverser(h->right,s+"    ");
	}
}


int count(TREE h)
{
	if (h == 0) return 0;
	return count(h->left) + count(h->right) + 1;
}

int countLeaves(TREE h)
{
	if(h!=NULL && h->left==NULL && h->right==NULL)
	{
		return 1;
	}
	else if(h!=NULL)
	{
		return countLeaves(h->left) + countLeaves(h->right);
	}
}

int height(TREE h)
{
	if (h == 0) return -1;
	int u = height(h->left), v = height(h->right);
	if (u > v) return u+1; else return v+1;
}


int pathLenght(TREE h,int level=-1)
{
	if(h==NULL)
	{
		return 0;
	}
	else
	{
		return pathLenght(h->left,level+1) + pathLenght(h->right,level+1) + level+1;
	}
}


int main()
{
	TREE arbre = createTREE();
	arbre=buildTREE(0);
	cout<<"comptage: "<<count(arbre)<<endl;
	cout<<"leaves: "<<countLeaves(arbre)<<endl;
	cout<<"height: "<<height(arbre)<<endl;
	cout<<"affichage: "<<endl;
	traverser(arbre);
	return 0;
}


