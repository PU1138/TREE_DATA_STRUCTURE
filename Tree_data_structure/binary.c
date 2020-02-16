#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node* left;
 struct node* right;
};

struct node*root = NULL;

struct node*create(int value)
{

 struct node* newnode = (struct node*)malloc(sizeof(struct node));
 newnode->data = value;
 newnode->left = NULL;
 newnode->right= NULL;

 return newnode;
}


struct queue{
 int front,rear,size;
 struct node**arr;
};
 
struct queue* createqueue()
{
 struct queue* newqueue = (struct queue*)malloc(sizeof(struct queue));
 newqueue->front=-1;
 newqueue->rear=0;
 newqueue->size=0;

newqueue->arr = (struct node**) malloc(100 * sizeof( struct node* ));  
 return newqueue;
}

void enqueue(struct queue* queue,struct node* temp)
{
 queue->arr[queue->rear++]=temp;
 queue->size++;
}

struct node* dequeue(struct queue*queue)
{
 queue->size--;
 return queue->arr[++queue->front];
}

void insert(int value)
{
 struct node* newnode1 = create(value);
if(root==NULL)
{
 root = newnode1;
 return;
}

else
{
  struct queue* p = createqueue();
  enqueue(p,root);
 while(1)
{
 struct node *t= dequeue(p);
if(t->left!= NULL && t->right!=NULL)
{
 enqueue(p,t->left);
 enqueue(p,t->right);
}

else
{
 if(t->left==NULL)
{
 t->left = newnode1;
 enqueue(p,t->left);
}
else
{
 t->right = newnode1;
enqueue(p,t->right);
}

break;
}
}
}
}

void inorderTraversal(struct node *node) {  
    //Check whether tree is empty  
    if(root == NULL){  
        printf("Tree is empty\n");  
        return;  
    }  
    else {  
            
        if(node->left != NULL)  
            inorderTraversal(node->left);  
        printf("%d ", node->data);  
        if(node->right != NULL)  
            inorderTraversal(node->right);  
                
        }  
    }  
int main(){  
      int a[100],i,n;
   printf("Enter the no of nodes");
 scanf("%d ",&n);
for(i=0;i<n;i++)
{
 scanf("%d",&a[i]);
 insert(a[i]);
}

inorderTraversal(root);



    return 0;  
}  




