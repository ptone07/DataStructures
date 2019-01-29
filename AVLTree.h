/*
	Anthony Hanna
	AVLTree header file
  AVL tree is a self balancing binary search tree, requires Tree.h header file
*/

#ifndef AVLTREE_H
#define AVLTREE_H
#include "Tree.h"


class AVLTree : public Tree
{
    private:
    int height( Node* ) const;
    int difference( Node* ) const;
    void rotateRight( Node*& );
    void rotateLeft( Node*& );
    void rotateLeftRight( Node*& );
    void rotateRightLeft( Node*& );
    void balance( Node*& );
    void remove( Node*&, int );
    void add( Node*&, int );
    
    public:
    void remove( int );
    void add( int );
};

int AVLTree::height( Node* r ) const // check the height of the tree
{
    if( r == 0 )
    {
        return 0;
    }
    
    int LH, RH;
    
    LH = height( r->left );
    RH = height( r->right );
    
    if( LH > RH )
    {
        return( 1 + LH );
    }
    else
    {
        return( 1 + RH );
    }
}

int AVLTree::difference( Node* r ) const // checks for difference in hieght between left and right node
{
    return height( r->left ) - height( r->right );
}

void AVLTree::rotateRight( Node*& r ) // rotate right
{
    Node* p;
    p = r->left;
    r->left = p->right;
    p->right = r;
    r = p;
}

void AVLTree::rotateLeft( Node*& r ) // rotate left
{
    Node* p;
    p = p->right;
    r->right = p->left;
    p->left = r;
    r = p;
}

void AVLTree::rotateLeftRight( Node*& r ) // rotate left right
{
    rotateLeft( r->left );
    rotateRight( r );
}

void AVLTree::rotateRightLeft( Node*& r ) // rotate right left
{
    rotateRight( r->right );
    rotateLeft( r );
}

void AVLTree::balance( Node*& r ) // balance the tree
{
    if( difference( r ) == -2 )
    {
        if( difference( r->right ) == -1 )
        {
            rotateLeft( r );
        }
        else
        {
            rotateRightLeft( r );
        }
    }
    else if( difference( r ) == 2 )
    {
        if( difference( r->left ) == 1 )
        {
            rotateRight( r );
        }
        else
        {
            rotateLeftRight( r );
        }
    }
}

void AVLTree::add( Node*& r, int i ) // add new node to the tree
{
	if(r == 0)
		r = new Node { i, 0, 0 };
	else if(i < r->i)
		add(r->left, i);
	else 
		add(r->right, i);
    balance( r );
}

void AVLTree::add( int i ) // balance the tree after adding
{
	add( root, i );
	balance( root );
}

void AVLTree::remove( Node*& r, int i ) // remove a node
{
	if( r == 0 )
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
    balance( r );
}

void AVLTree::remove( int i ) // balance tree after removal
{
	remove( root, i );
	balance( root );
}

#endif
