# include <stdio.h>
# include <stdlib.h>
struct treenode {
	int data;
	treenode *left;
	treenode *right;
	
};
struct treenode *createNode(int data){
	struct treenode *newNode=(struct treenode*)malloc(sizeof(struct treenode));
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}
struct treenode *insert_data(struct treenode *root,int dat){
	if (root==NULL){
		return createNode(dat);
	}
	else if (dat < root->data){
        root->left = insert_data(root->left, dat);
	}
	else if (dat>root->data){
		root->right=insert_data(root->right,dat);
	}
	return  root;
}

void inorder_traversal(treenode *root){
	if (root==NULL){
		return ;
	}
	inorder_traversal(root->left);
	printf("%d ",root->data);
	inorder_traversal(root->right);
}
void postorder_traversal(treenode *root){
	if (root==NULL){
		return ;
	}
	postorder_traversal(root->left);
	postorder_traversal(root->right);
	printf("%d ",root->data);
}
void preorder_traversal(treenode *root){
	if (root==NULL){
		return;
	}
	printf("%d ",root->data);
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}
int main (){
	struct treenode *root=NULL;
	int n;
	printf("enter the number of nodes :\n");
	scanf("%d",&n);
	for (int i =0;i<n;i++){
		int x;
		printf("enter element you want to insert : ");
		scanf("%d",&x);
		root=insert_data(root,x);	
	}
	printf("inorder Traversal : \n");
	inorder_traversal(root);
	printf("\npostorder Traversal : \n");
	
	postorder_traversal(root);
	printf("\npreorder Traversal : \n");
	
	preorder_traversal(root);
	
	
}
