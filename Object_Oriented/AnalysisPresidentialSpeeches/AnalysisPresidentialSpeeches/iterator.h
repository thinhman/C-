#pragma once
#ifndef ITERATOR_H
#define ITERATOR_H
#include "LinkedListInterface.h"

/**
*Class Iterator is designed to iterate a binary tree data structure
*according to some pre-defined tree traversal scheme. The class has as a data
*member a singly linked list, which would containe the members of
*of iteration in the order of iteration from front to back.
*/
template<typename Type>
class Iterator
{
	public:
		/**
		*Stores the objects in order from frint to back as per iteration
		*scheme.
		*/
		SinglyLinkedList<Type> List;
		/**
		*Node type pointer, used to iterate the data member List.
		*/
		Node<Type> * Itr;
		/**
		*keeps track of the number of members iterated in the list. When
		*iteration is complete then cursor is equal to the number of
		*members in the list.
		*/
		int cursor;
		/**
		*Returns true if there is a next non-null(valid) object present in the
		*the list, else returns false.
		*/
		bool hasNext() const;
		/**
		*Returns the data field of next object as Type.
		*/
		Type next( ) ;
		/**
		*Default/explicit constructor, sets the List ane other members
		*to default values, or the values associated with the 
		*SinglyLinkedList passed as the constructor argument.
		*/
		Iterator(SinglyLinkedList<Type> List1=SinglyLinkedList<Type>());
		/**
		*Virtual destructor: needs no code as there is no dynamic
		*memory allocation done inside the member functions of class]
		*Iterator.
		*/
		virtual ~Iterator( );
		/**
		*De-allocates the memory allocated to the List member, sets
		*other data members to reset the Iterator object for fresh 
		*use.
		*/
		void reset();


};
////////////////////////////////////////////////////
template<typename Type>
void Iterator<Type>::reset()
{
	List.destroy();
	cursor = 0;
	Itr = List.retrieveHead( );
}
/////////////////////////////////////////////////////////////
template<typename Type>
Iterator<Type>::Iterator(SinglyLinkedList<Type> List1):List(List1)
{
	cursor = 0;
	Itr = List.retrieveHead( );
}
///////////////////////////////////////////////////////////
template<typename Type>
Iterator<Type>::~Iterator()
{
	//no code needed
}
///////////////////////////////////////////////////////////
template<typename Type>
bool Iterator<Type>::hasNext()const
{
	return cursor != List.size(); 	
}
/////////////////////////////////////////////////////////////
template<typename Type>
Type Iterator<Type>::next()
{
	if(List.isEmpty())
	{
		cerr<<"The list is empty. Exiting the program.\n";
		exit(1);
	}
	Type Value = Itr->data;
	cursor++;
	Itr = Itr->Next;
	return Value;
}
////////////////////////////////////////////////////////////////
/**
*Abstract class Binary tree defines the essential functions
*to be contained by the concrete binary tree class derived from
*the class BinaryTree.
*/
template<typename Type>
class BinaryTree 
{
	public:
	/**
	*Resets to BinaryTree to original state, where all tree
	*members are deleted and root is set to NULL.
	*/
	virtual void makeEmpty() = 0;
	/**
	 * Function isEmpty returns a true or false depending upon, whether tree is 
	 * non-null or not.
	 * @return true if tree is empty, else returns false.
	 */
	virtual bool isEmpty() const = 0;
	/**
	 * Function size resturns the number of members in the tree
	 * structure.
	 * @return the number of members in the tree structure.
	 */
	virtual int size() const = 0;
	/**
	 * Function traverseInorder returns an Iterator, which can be used to traverse
	 * the given binary tree in-order.
	 * Returns by reference Iterator to traverse the tree in-order.
	 */
	virtual void traverseInorder(Iterator<Type>& It)  = 0;
	/**
	 * Function traversePreorder returns an Iterator, which can be used to traverse
	 * the given binary tree pre-order.
	 * Returns by reference  Iterator to traverse the tree pre-order.
	 */
	virtual void traversePreorder(Iterator<Type>& It)= 0;
	/**
	 * Function traversePreorder returns an Iterator, which can be used to traverse
	 * the given binary tree post-order.
	 * Returns by reference  Iterator to traverse the tree post-order.
	 */
	virtual void traversePostorder(Iterator<Type>& It) = 0;
	/**
	 * Considering the root node at the zero level, the method maxLevel
	 * returns the maximum level possible in the tree.
	 * @return the maximum level or depth of the tree.
	 */
	virtual int maximumLevel() = 0;
	/**
	 * Function avgpathLength returns the average path length for the tree.
	 * @return the double value for the average path length for the binary tree.
	 */
	virtual double avgPathLength() = 0;
	/**
	* Default/argumentless Constructor for BinaryTree class
	*/
	BinaryTree(){}
	/**
	*virtual destructor for the BinaryTree class.
	*/
	virtual ~BinaryTree(){}
};
///////////////////////////////////////////////////////////////////////////
/**
*SearchTreeNode is a templated class, which creates a node to be added
*to a Binary Search Tree of either basic types or user defined types.
*/
template<typename Type>
class SearchTreeNode
{
public:
	/**
	 * contents is the object in the <code>SearchTreeNode</code>, which contains
	 * the data part of the node.
	 */
	Type contents;
	/**
	 * left is the self-referential reference pointing to the 
	 * left child of the node.
	 */
	SearchTreeNode * left;
	/**
	 * right is the self-referential reference pointing to the 
	 * right child of the node.
	 */
	SearchTreeNode * right;
	/**
	*Default/explicit constructor for class SearchTreeNode
	*/
	SearchTreeNode(Type init_data=Type(), SearchTreeNode * left1 = NULL,
		SearchTreeNode * right1 = NULL): contents(init_data),left(left1),
		right(right1)
	{
	
	}
	/**
	*Overloaded insertion operator << for class SearchTreeNode.
	*/
	friend ostream& operator << (ostream& out, const SearchTreeNode& IL)
	{
		out<<IL.contents<< "    ";
		return out;
	}
	/**
	*Overloaded extraction operator >> for class SearchTreeNode.
	*/
	friend istream& operator >>(istream& in, SearchTreeNode& IL)
	{
		in>>IL.contents;
		return in;
	}
	/**
	*Virtual destructor. No code needed.
	*/
	virtual ~SearchTreeNode() { }
	/**
	*Returns the type of the data field of SearchTreeNode as a string.
	*/
	string getType()
	{
		return typeid(contents).name();
	}
};
//////////////////////////////////////////////////////////
/**
*The concrete class BinarySearchTree derives from the 
*abstract class BinaryTree and adds the nodes to the tree
*structure as per criteria valid for a binary seatch tree.
*/
template<typename Type>
class BinarySearchTree:public BinaryTree<Type>
{
private:
	/**
	 * The field root is the pointer to the root node of 
	 *<code>BinarySearchTree</code>.
	 */
	SearchTreeNode<Type> * root;
	/**
	 * Gives the number of elements in the <code>BinarySearchTree</code>.
	 */
	int numberElements;
	/**
	 * Gives the maximum level for the <code>BinarySearchTree</code>.
	 */
	int maxLevel;
public:
	/**
	 * Argument-less  constructor for <code>BinarySearchTree</code>.
	 */
	BinarySearchTree();
	//Functions implemented from the base class
	//SearchTreeNode<Type> getRoot()
	//{
	//	return root;
	//}

	SearchTreeNode<Type>* get(Type obj)
	{
		SearchTreeNode<Type>* NumNode = root;
		if(!this->contains(obj))
		{
			return NULL;
		}

		bool found = false;
		while(!found && NumNode != NULL)
		{
			if(NumNode->contents == obj)
				found = true;
			else
			{
				if(NumNode->contents < obj)
					NumNode = NumNode->right;
				else
					NumNode = NumNode->left;
			}

		}

		return NumNode;
	}

	void makeEmpty();
	bool isEmpty() const;
	int size() const;
	int maximumLevel();
	void traverseInorder(Iterator<Type>& It);
	void traversePreorder(Iterator<Type>& It);
	void traversePostorder(Iterator<Type>& It);
	double avgPathLength();
	/**
	*Destructor for the BinarySearchTree class.
	*/
	virtual ~BinarySearchTree();
	/**
	 * Adds the object item to the <code>BinarySearchTree</code>.
	 * @param item is added to the tree. 
	 */
	void add(Type item);
	/**
	 * Finds whether the <code>BinarySearchTree</code> contains the
	 * Object obj.
	 * @param obj is the <code>Object</code> to be searched in the
	 * tree.
	 * @return true if the <code>Object</code> obj is in the tree, else
	 * returns false.
	 */
	bool contains(Type obj);
	/**
	 * Removes the node with key obj from the <code>BinarySearchTree</code>.
	 * @param obj is removed from the <code>BinarySearchTree</code>.
	 */
	void remove(Type obj);
	/**
	*Copy constructor.
	*/
	BinarySearchTree(const BinarySearchTree& Tree);
	/**
	*overloaded assignment operator.
	*/
	const BinarySearchTree & operator= (const BinarySearchTree& originalTree);
	/**
	*Prints Binary Search Tree in-order.
	*/
	void printInorder(ostream & out);
	/**
	*Prints Binary Search Tree post-order.
	*/
	void printPostorder(ostream & out);
	/**
	*Prints Binary Search Tree pre-order.
	*/
	void printPreorder(ostream & out);
};
////////////////////////////////////////////////////////////////////////
//proto-type of stand-alone functions
///////////////////////////////////////////////////////////////////
/**
*Deletes the binary search tree.
*/
template<typename Type>
void destroy(SearchTreeNode<Type>*& tree);
/**
*Returns the number of nodes in the tree
*/
template<typename Type>
int countNodes(SearchTreeNode<Type>* tree);
/**
*Copies the tree with root as originalTree into tree with root copy.
*/
template<typename Type>
void CopyTree(SearchTreeNode<Type>*& copy,const SearchTreeNode<Type>* originalTree);
/**
* Recursive internal method, inserts the item at its proper 
* location in the <code>BinarySearchTree</code>. Returns the root
* of the modified tree or sub-tree by reference.
* @param node is the pointer to the root of the tree or sub-tree 
* @param item is the template object to be inserted.
*/
template<typename Type>
void insertNode(SearchTreeNode<Type> * & node,  Type item);
/**
* Called internally by the method remove, to remove the node
* containing the key item, from the tree with  root node.
* Returns the root of the modified tree or sub-tree by reference.
* @param node is the pointer to the root of the sub-tree. 
* @param item is the template object to be deleted.
*/
template<typename Type>
void deleteNode(SearchTreeNode<Type>* & node, Type item);
/**
*Called internally by the method deleteNode to find the right most
* node for the tree or sub-tree with root node.
* @param node is the pointer to the root of the tree or sub-tree
* @return the right most object for the tree or sub-tree. 
*/
template<typename Type>
Type rightMost(SearchTreeNode<Type>* & node);
/**
* Internal method to delete the right most node of a tree or 
* sub-tree. Returns by reference the node of tree after deletion.
* @param node is the pointer to the root of the tree or sub-tree
*/
template<typename Type>
void deleteRightMost(SearchTreeNode<Type>* & node);
/**
*Takes the pointer to the tree or subtree and builds a 
*in-order iterator It for it. The iterator it is returned by
*reference.
*/
template<typename Type>
void buildInOrder(SearchTreeNode<Type>* & node, Iterator<Type>& It);
/**
*Takes the pointer to the tree or subtree and builds a 
*pre-order iterator It for it. The iterator it is returned by
*reference.
*/
template<typename Type>
void buildPreOrder(SearchTreeNode<Type>* & node, Iterator<Type>& It);
/**
*Takes the pointer to the tree or subtree and builds a 
*post-order iterator It for it. The iterator it is returned by
*reference.
*/
template<typename Type>
void buildPostOrder(SearchTreeNode<Type>* & node, Iterator<Type>& It);
/**
* Stand-alone method to compute the meximum level 
* @param node is the root of the tree or sub-tree
* @param level is the level of the node
*@param maxLevel is the final maximum level of the tree/sub-tree
*returned by reference.
*/
template<typename Type>
void computeMaxLevel(SearchTreeNode<Type>* & node, int level, int& maxLevel);
/**
* Stand-alone method to compute the path lengh of a tree or sub-tree.
* @param node is the root of tree or sub-tree
* @param pathLength is the distance from the root to the node
* @return the path length
*/
template<typename Type>
double computePathLength(SearchTreeNode<Type>* & node, double pathLength);
/////////////////////////////////////////////////////////////////////////////////
//Definition of memebr functions
//////////////////////////////////////////////////////////////////////////////
template<typename Type>
BinarySearchTree<Type>::BinarySearchTree()
{
	root = NULL;
	numberElements = 0;
	maxLevel = 0;
}
/////////////////////////////////////////////////////////////////////////
template<typename Type>
BinarySearchTree<Type>::BinarySearchTree(const BinarySearchTree<Type>& Tree)
{
	CopyTree(root, Tree.root);
	numberElements = Tree.numberElements;
	maxLevel = Tree.maxLevel;
}
/////////////////////////////////////////////////////////////////////////
template<typename Type>
const BinarySearchTree<Type> & BinarySearchTree<Type>::
operator= (const BinarySearchTree<Type>& originalTree)
{
	if(&originalTree == this)
		return *this;
	destroy(root);
	CopyTree(root, originalTree.root);
	numberElements = originalTree.numberElements;
	maxLevel = originalTree.maxLevel;

	return *this;
}
//////////////////////////////////////////////////////////////////////////
template<typename Type>
BinarySearchTree<Type>::~BinarySearchTree()
{
	destroy(root);
}
/////////////////////////////////////////////////////////////////
template<typename Type>
bool BinarySearchTree<Type>::isEmpty() const
{
	return numberElements==0;
}
////////////////////////////////////////////////////////////////
template<typename Type>
void BinarySearchTree<Type>::printInorder(ostream & out)
{
	Iterator<Type> it;
	traverseInorder(it);
	//int index = 0;

	while(it.hasNext())
	{
		out<<it.next()<<" ";
		//index++;
		//if(index%10 == 0)
		out<<endl;
	}
	out<<endl;
}
////////////////////////////////////////////////////////////////
template<typename Type>
void BinarySearchTree<Type>::printPreorder(ostream & out)
{
	Iterator<Type> it;
	traversePreorder(it);
	int index = 0;

	while(it.hasNext())
	{
		out<<it.next()<<" ";
		index++;
		if(index%10 == 0)
			out<<endl;
	}
	out<<endl;
}
////////////////////////////////////////////////////////////////
template<typename Type>
void BinarySearchTree<Type>::printPostorder(ostream & out)
{
	Iterator<Type> it;
	traversePostorder(it);
	int index = 0;

	while(it.hasNext())
	{
		out<<it.next()<<" ";
		index++;
		if(index%10 == 0)
			out<<endl;
	}
	out<<endl;
}
/////////////////////////////////////////////////////////////////
template<typename Type>
void BinarySearchTree<Type>::makeEmpty()
{
		destroy(root);
		root = NULL;
		numberElements=0;
}
//////////////////////////////////////////////////////////////////
template<typename Type>
int BinarySearchTree<Type>::size() const
{
	return countNodes(root);
}
///////////////////////////////////////////////////////////////////
template<typename Type>
void BinarySearchTree<Type>::add(Type item)
{
	if(!contains(item))
	{
		insertNode(root,item);
		numberElements++;
	}
	else
		cerr<<"The item "<<item<<" is slready in tree.\n";
}
////////////////////////////////////////////////////////////////////////
template<typename Type>
bool BinarySearchTree<Type>::contains(Type obj)
{
	if(numberElements == 0 )
		return false;
	SearchTreeNode<Type> * current = root;

	while(current != NULL)
	{
		if(obj < current->contents)
			current = current->left;
		else if(obj > current->contents)
			current = current->right;
		else
			break;
	}
	
	return current != NULL;
}
/////////////////////////////////////////////////////////////////////////
template<typename Type>
void BinarySearchTree<Type>::remove(Type obj)
{
	if(contains(obj))
	{
		deleteNode(root,obj);
		numberElements--;
		if(numberElements == 0)
			root = NULL;
	}
	else
		cerr<<"The item to be removed "<<obj<<" is not in tree.\n";
}
///////////////////////////////////////////////////////////////////////////
template<typename Type>
void BinarySearchTree<Type>::traverseInorder(Iterator<Type>& It)
{
	buildInOrder(root,It);
	It.Itr = It.List.retrieveHead();
}
//////////////////////////////////////////////////////////////////////////
template<typename Type>
void BinarySearchTree<Type>::traversePreorder(Iterator<Type>& It)
{
		buildPreOrder(root,It);
		It.Itr = It.List.retrieveHead();
}
////////////////////////////////////////////////////////////////////
template<typename Type>
void BinarySearchTree<Type>::traversePostorder(Iterator<Type>& It)
{
	buildPostOrder(root,It);
	It.Itr = It.List.retrieveHead();
}
/////////////////////////////////////////////////////////////////////
template<typename Type>
int BinarySearchTree<Type>::maximumLevel()
{
	maxLevel = 0;
	computeMaxLevel(root,0,maxLevel);
	return maxLevel;
}
///////////////////////////////////////////////////////////////
template<typename Type>
double BinarySearchTree<Type>::avgPathLength()
{
	double pathLength = 0;
	if(numberElements == 0)
		return 0;
	else
		return computePathLength(root, pathLength)/numberElements;
}
/////////////////////////////////////////////////////////////////////
//Full definitions of stand-alone functions
////////////////////////////////////////////////////////////////////
template<typename Type>
double computePathLength(SearchTreeNode<Type>* & node, double pathLength)
{
	if(node != NULL)
	{
		return pathLength + computePathLength(node->left, pathLength +1)
			+ computePathLength(node->right, pathLength +1);
	}
	else
		return 0;
}
////////////////////////////////////////////////////////////////////////////
template<typename Type>
void computeMaxLevel(SearchTreeNode<Type>* & node, int level, int& maxLevel)
{
	if(node != NULL)
	{
		computeMaxLevel(node->left, level+1,maxLevel);
		computeMaxLevel(node->right, level+1,maxLevel);

		if(node->right == NULL && node->left == NULL && level>maxLevel)
			maxLevel=level;
	}
}
////////////////////////////////////////////////////////////////////
template<typename Type>
void buildPostOrder(SearchTreeNode<Type>* & node, Iterator<Type>& It)
{
	if(node !=NULL)
	{
		buildPostOrder(node->left, It);
		buildPostOrder(node->right, It);
		It.List.addRear(node->contents);
	}
}
/////////////////////////////////////////////////////////////////////////
template<typename Type>
void buildPreOrder(SearchTreeNode<Type>* & node, Iterator<Type>& It)
{
	if(node !=NULL)
	{
		It.List.addRear(node->contents);
		buildPreOrder(node->left, It);
		buildPreOrder(node->right, It);
	}
}
/////////////////////////////////////////////////////////////////////////
template<typename Type>
void buildInOrder(SearchTreeNode<Type>* & node, Iterator<Type>& It)
{
	if(node !=NULL)
	{
		buildInOrder(node->left, It);
		It.List.addRear(node->contents);
		buildInOrder(node->right, It);
	}
}
/////////////////////////////////////////////////////////////////////
template<typename Type>
void deleteRightMost(SearchTreeNode<Type>* & node)
{
		if(node->right == NULL)
		{
			SearchTreeNode<Type>* Temp = node->left;
			if(Temp !=NULL)
			{
				*node = *Temp;
				delete Temp;
			}
			else
			{
				Temp = node;
				node = NULL;
				delete Temp;
			}
		}
		else
			deleteRightMost(node->right);
		
}
/////////////////////////////////////////////////////////////////
template<typename Type>
Type rightMost(SearchTreeNode<Type>* & node)
{
		if(node->right == NULL)
			return node->contents;
		else
			return rightMost(node->right);
}
///////////////////////////////////////////////////////////////////
template<typename Type>
void deleteNode(SearchTreeNode<Type>* & node, Type item)
{
		if(node == NULL)
		{
			cerr<<"The tree is null.\n";
			return;
		}

		if(item < node->contents)
			deleteNode(node->left,item);
		else if(item > node->contents)
			deleteNode(node->right,item);
		else if(item == node->contents)
		{
			SearchTreeNode<Type>* Temp;
			if(node->left == NULL && node->right == NULL)
			{
				Temp = node;
				node = NULL;
				delete Temp;
			}
			else if(node->left == NULL)
			{
				Temp = node->right;
				*node  = *Temp;
				delete Temp;
			}
			else if(node->right == NULL)
			{
				Temp = node->left;
				*node = *Temp;
				delete Temp;
			}
			else
			{
				Type replaceWithValue = rightMost(node->left);
				node->contents = replaceWithValue;
				deleteRightMost(node->left);
			}
		}
}

/////////////////////////////////////////////////////////////////////
template<typename Type>
void insertNode(SearchTreeNode<Type> * & node,  Type item)
{
	if(node == NULL)
	{
		 node = new SearchTreeNode<Type>();	
		 node->contents = item;
	}
	else if(item<node->contents)
	{
		insertNode(node->left,item);
	}
	else if(item>node->contents)
	{
		insertNode(node->right,item);
	}
}
///////////////////////////////////////////////////////////////////
template<typename Type>
void destroy(SearchTreeNode<Type>*& tree)
// Post: tree is empty; nodes have been deallocated.
{
  if (tree != NULL)
  {
    destroy(tree->left);
    destroy(tree->right);
    delete tree;
  }
}
/////////////////////////////////////////////////////////////
template<typename Type>
int countNodes(SearchTreeNode<Type>* tree)
{
  if (tree == NULL)
    return 0;
  else 
    return countNodes(tree->left) + countNodes(tree->right) + 1;
}
///////////////////////////////////////////////////////////////
template<typename Type>
void CopyTree(SearchTreeNode<Type>*& copy, 
const SearchTreeNode<Type>* originalTree)
{
  if (originalTree == NULL)
    copy = NULL;
  else
  {
    copy = new SearchTreeNode<Type>();
    copy->contents= originalTree->contents;
    CopyTree(copy->left, originalTree->left);
    CopyTree(copy->right, originalTree->right);
  }
}
///////////////////////////////////////////////////////////////
#endif