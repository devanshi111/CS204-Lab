#include <bits/stdc++.h> 
using namespace std; 
 
struct tnode 
{ 
	int key, pr; 
	tnode *left, *right; 
}; 


tnode *rightRotate(tnode *y) 
{ 
	tnode *x = y->left, *T2 = x->right; 

	x->right = y; 
	y->left = T2; 

	return x; 
} 
 
tnode *leftRotate(tnode *x) 
{ 
	tnode *y = x->right, *T2 = y->left; 

	y->left = x; 
	x->right = T2; 

	return y; 
} 

tnode* newNode(int key) 
{ 
	tnode* temp = new tnode; 
	temp->key = key; 
	temp->pr = rand()%100; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

tnode* search(tnode* root, int key) 
{ 

	if (root == NULL || root->key == key) 
	return root; 

	if (root->key < key) 
	return search(root->right, key); 
 
	return search(root->left, key); 
} 

tnode* insert(tnode* root, int key) 
{  
	if (!root) 
		return newNode(key); 
 
	if (key <= root->key) 
	{ 
		root->left = insert(root->left, key); 

		if (root->left->pr > root->pr) 
			root = rightRotate(root); 
	} 
	else 
	{  
		root->right = insert(root->right, key); 

		if (root->right->pr > root->pr) 
			root = leftRotate(root); 
	} 
	return root; 
} 

tnode* deleteNode(tnode* root, int key) 
{ 
	if (root == NULL) 
		return root; 

	if (key < root->key) 
		root->left = deleteNode(root->left, key); 
	else if (key > root->key) 
		root->right = deleteNode(root->right, key); 

	else if (root->left == NULL) 
	{ 
		tnode *temp = root->right; 
		delete(root); 
		root = temp; 
	} 

	else if (root->right == NULL) 
	{ 
		tnode *temp = root->left; 
		delete(root); 
		root = temp; 
	} 

	else if (root->left->pr < root->right->pr) 
	{ 
		root = leftRotate(root); 
		root->left = deleteNode(root->left, key); 
	} 
	else
	{ 
		root = rightRotate(root); 
		root->right = deleteNode(root->right, key); 
	} 

	return root; 
} 

void inorder(tnode* root) 
{ 
	if (root) 
	{ 
		inorder(root->left); 
		cout << "key: "<< root->key << " | pr: %d "
			<< root->pr; 
		if (root->left) 
			cout << " | left child: " << root->left->key; 
		if (root->right) 
			cout << " | right child: " << root->right->key; 
		cout << endl; 
		inorder(root->right); 
	} 
} 

int main() 
{ 
	srand(time(NULL)); 

	struct tnode *root = NULL; 
	root = insert(root, 50); 
	root = insert(root, 30); 
	root = insert(root, 20); 
	root = insert(root, 40); 
	root = insert(root, 70); 
	root = insert(root, 60); 
	root = insert(root, 80); 

	cout << "Inorder traversal of the given tree \n"; 
	inorder(root); 

	cout << "\nDelete 20\n"; 
	root = deleteNode(root, 20); 
	cout << "Inorder traversal of the modified tree \n"; 
	inorder(root); 

	cout << "\nDelete 30\n"; 
	root = deleteNode(root, 30); 
	cout << "Inorder traversal of the modified tree \n"; 
	inorder(root); 

	cout << "\nDelete 50\n"; 
	root = deleteNode(root, 50); 
	cout << "Inorder traversal of the modified tree \n"; 
	inorder(root); 

	tnode *res = search(root, 50); 
	(res == NULL)? cout << "\n50 Not Found ": 
				cout << "\n50 found"; 

	return 0; 
} 
