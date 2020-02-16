#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* left;
struct node* right;
};

struct node* createnode(int value)
{
 struct node* newnode = (struct node*)malloc(sizeof(struct node));

 newnode->data = value;
 newnode->left = NULL;
 newnode->right = NULL;

return newnode;

}

struct node* insert(struct node* node,int value)
{
 if(node==NULL)
{
 return createnode(value);
}

else if(node->data > value)
{

 node->left = insert(node->left,value);
}

else if(node->data < value)
{
 node->right = insert(node->right,value);
}
return node;
}

void inorder(struct node* root)
{
 if(root!=NULL)
{
 inorder(root->left);
 printf("%d ",root->data);
 inorder(root->right);
}
}

struct node* check(struct node* root,int value)
{
 if(root==NULL||root->data == value)
 {
  return root;
}
else if(value>root->data)
 {
  return check(root->right,value);
}

else if(value<root->data)
{
  return check(root->left,value);
}
}
int main()
{int n,i,p,a[50],search;
 struct node *root = NULL; 
   printf("ENTER THE ROOT");
  scanf("%d",&n);
root = insert(root,n);
printf("ENTER THE NUMBER OF LEFT NODES");
scanf("%d",&p);
for(i=0;i<p;i++)
{
 scanf("%d",&a[i]);
 insert(root,a[i]);
}
inorder(root);


   
    return 0; 
}
