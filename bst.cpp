#include "bst.h"


treenode * createTreeNode(int data){
	
	treenode * newnode = (treenode *)malloc(sizeof(treenode));
	newnode->data	 = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
	
}

void inserttree(treenode **root,int data){
	
	if(*root == NULL){
		*root = createTreeNode(data);
	}
	else{
		treenode *temp = *root ;
		if (data < (*root)->data){
				inserttree(&( (*root)->left),data);
		}
		else if (data >  (*root)->data){
			inserttree(&( (*root)->right),data);
		}
		*root = temp;
	}
}

void printInorder(treenode *root){
	if(root){
		printInorder(root->left);
		printf("%d",root->data);
		printInorder(root->right);	
	}	
}

int height(treenode *root){
	if(root){
		return max(height(root->left),height(root->right))+1;	
	}	
	return 0;
}

void printEachLevel(treenode* root, int depth){
	
if(root){
	if(depth ==0 ){
		printf("%d",root->data);
		}
	else{
		//recurse through root->left, root->right
		printEachLevel(root->left,depth-1);
		printEachLevel(root->right,depth-1);
		}
	}
	
	return;
}
void printLevelOrder(treenode *root){
	
	int depth = height(root);
	if(root){
		for(int i=0; i<depth; i++){
				printEachLevel(root,i);
			}
		}
	return;
	}


void iterativeTreeTraversal(treenode *root){
	//So the concept here is to make a threaded binary tree out of our tree for traversal
	//and then fix it back
	if(root){
		
		treenode * current = root, *temp = NULL;
		while(current){
			//if no left child, print root and move to right child	
			if(current->left == NULL){
					printf("%d",current->data);
					current = current->right;
			}	
			else{
				temp = current->left;
				//trying to find inorder predecessor here
				//temp will be the inorder predecssor of current now and link it to current node
				while(temp->right != NULL || temp->right !=current)
					temp = temp->right ;
					//if we reached to the end of right subtree...create a link to current
					if(temp->right == NULL){
						temp->right = current;
						current = current->left	;
					}else{
						printf("%d",current->data);
						current = current->right;
						
					}
			}	
		}	
	}
	
	
return;	
}