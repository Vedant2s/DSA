#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int key;
    struct node *left, *right;
};
 

struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 

void inorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    else if (root != NULL) {
        inorder(root->left);}
        printf("%d \n", root->key);
        inorder(root->right);
    
}
 void search(struct node*root,int key2)
 {
     if(root==NULL)
     {
         return;
     }
     else if(key2==root->key)
     {
         printf("found\n");
     }
     else if(key2 < root->key)
     {
         search(root->left,key2);
     }
     else{
         search(root->right,key2);
     }
 }
void preorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    else if (root != NULL) {
        printf("%d \n", root->key);
        inorder(root->left);}
        inorder(root->right);
    
}
void postorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    else if (root != NULL) {
		inorder(root->left);
        
        }
        inorder(root->right);
    printf("%d \n", root->key);
}
struct node* insert(struct node* node, int key)
{
   
 
    if (node == NULL)
        {return newNode(key);}
 

    else if (key < node->key)
        {node->left = insert(node->left, key);}
    else if (key > node->key)
        {node->right = insert(node->right, key);}
 

    return node;
}
 struct node* minValueNode(struct node* node)
{
    struct node* current = node;
 
   
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
 

struct node* deleteNode(struct node* root, int key)
{
    
    if (root == NULL)
        return root;
 
  
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
   
    else {
        
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        
        struct node* temp = minValueNode(root->right);
 
        
        root->key = temp->key;
 
        
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main()
{

    struct node* root = NULL;
    
    int ch,y,d;
    do{
        printf("\n1.insert\n2.traverse\n3.search\n4.delete element\n5.preorder\n6.postorder\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("enter the data\n");
            scanf("%d",&d);
            root=insert(root,d);
            break;
            case 2:       
            inorder(root);
            break;
            case 3:
            printf("enter the data\n");
            scanf("%d",&d);
            search(root,d);
            break;
				case 4:
				printf("enter the data\n");
            scanf("%d",&d);
            root=deleteNode(root,d);
				break;
				case 5:
				preorder(root);
				break;
				case 6:
				postorder(root);
				break;
        }
        printf("do you want to continue?[0/1]\n");
        scanf("%d",&y);
    }while(y!=0);

 
    return 0;
}
