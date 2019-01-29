/*
	Anthony Hanna
	Implements Tree.h file for AVLTree.h class

*/

#ifndef TREE_H
#define TREE_H

#include<iostream>
using std::cout;
using std::endl;

class Tree
{
	protected:
	struct Node
	{
		int i;
		Node* left, *right;
	} *root;
	
	private:
	void add( Node*&, int i );
	void remove( Node*&, int i );
	bool find( Node*, int i ) const;
	void print( Node* ) const;
	void clear( Node*& );
	
	public:
	Tree();
	~Tree();
	void add( int i );
	void remove( int i );
	bool find( int i ) const;
	void print() const;
	void clear();
};

Tree::Tree() // create tree
{
	root = 0;
}

Tree::~Tree() // clear tree
{
	clear( root );
}

void Tree::add( int i ) // add value to tree
{
	add( root, i );
}

void Tree::add( Node*& r, int i ) // balance tree by value after adding
{
	if( r == 0 )
		r = new Node { i };
	else if( i < r->i )
		add( r->left, i );
	else 
		add( r->right, i );
}

void Tree::remove( int i ) // remove value
{
	remove( root, i );
}

void Tree::remove( Node*& r, int i ) // balance tree after removal
{
	if(r == 0)
		return;
	else if( i < r->i )
		remove( r->left, i );
	else if( i > r->i )
		remove( r->right, i );
	else 
	{
		Node* p;
		
		if( r->left == 0 && r->right == 0 )
		{
			delete r;
			r = 0;
		}
		else if( r->left != 0 && r->right == 0 )
		{
			p = r;
			r = r->left;
			delete p;
		}
		else if( r->left == 0 && r->right != 0 )
		{
			p = r;
			r = r->right;
			delete p;
		}
		else
		{
			p = r->right;
			
			while( p->left )
				p = p->left;
			
			p->left = r->left;
			p = r;
			r = r->right;
			
			delete p;
		}
	}
}

bool Tree::find( int i ) const // return true or false after searching for value
{
	return find( root, i );
}

bool Tree::find( Node* r, int i ) const // search for value
{
	if( r == 0 )
		return false;
	else if( r->i == i )
		return true;
	else if( i < r->i )
		return find( r->left, i );
	else
		return find( r->right, i );
}

void Tree::print() const // print the tree
{
	print( root );
}

void Tree::print( Node* r ) const // travel through the tree print each value
{
	if( r != 0 )
	{
		print( r->left );
		cout << r->i<<" ";
		print( r->right );
	}
}

void Tree::clear() // delete value in the tree
{
	clear( root );
	root = 0;
}

void Tree::clear( Node*& r ) // searches the tree and delete the value
{
	if( r != 0 )
	{
		clear( r->left );
		clear( r->right );
		delete r;
	}
}


#endif
