

#include <stdio.h>
#include <stdlib.h>

//Queue creation
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct Node **)malloc(q->size*sizeof(struct
    Node *));
}

void enqueue(struct Queue *q,struct Node *x)
{
    if((q->rear+1)%q->size==q->front)
    printf("Queue is Full");
    else
    {
    q->rear=(q->rear+1)%q->size;
    q->Q[q->rear]=x;
    }
}
struct Node * dequeue(struct Queue *q)
{
    struct Node* x=NULL;

    if(q->front==q->rear)
    printf("Queue is Empty\n");
    else
    {
    q->front=(q->front+1)%q->size;
    x=q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q)
{
    return q.front==q.rear;
}

//Stack creation

struct Stack
{
  int size;
  int top;
  int *S;
};

void StackCreate(struct Stack *st)
{
    printf("Enter Size");
    scanf("%d",&st->size);
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));
}

void Display(struct Stack st)
{
   int i;
   for(i=st.top;i>=0;i--)
   printf("%d ",st.S[i]);
   printf("\n");
}

void push(struct Stack *st,int x)
{
   if(st->top==st->size-1)
   printf("Stack overflow\n");
   else
   {
     st->top++;
     st->S[st->top]=x;
   }

}

int pop(struct Stack *st)
{
   int x=-1;

   if(st->top==-1)
   printf("Stack Underflow\n");
   else
   {
     x=st->S[st->top--];
   }
  return x;
}

int peek(struct Stack st,int index)
{
   int x=-1;
   if(st.top-index+1<0)
   printf("Invalid Index \n");
   x=st.S[st.top-index+1];

   return x;
}

int isEmptyStack(struct Stack st)
{
   if(st.top==-1)
   return 1;
   return 0;
}

int isFull(struct Stack st)
{
   return st.top==st.size-1;
}

//int stackTop(struct Stack st)
//{
  //if(!isEmpty(st))
   //return st.S[st.top];
   //return -1;
//}




//tree
struct Node *root=NULL;
void Treecreate()
{
    struct Node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);

    printf("Eneter root value ");
    scanf("%d",&x);
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

 while(!isEmpty(q))
 {
    p=dequeue(&q);
    printf("eneter left child of %d ",p->data);
    scanf("%d",&x);
    if(x!=-1)
    {
    t=(struct Node *)malloc(sizeof(struct
    Node));
    t->data=x;
    t->lchild=t->rchild=NULL;
    p->lchild=t;
    enqueue(&q,t);
 }

 printf("enter right child of %d ",p->data);
 scanf("%d",&x);
 if(x!=-1)
 {
    t=(struct Node *)malloc(sizeof(struct
    Node));
    t->data=x;
    t->lchild=t->rchild=NULL;
    p->rchild=t;
    enqueue(&q,t);
}
 }
}
void Preorder(struct Node *p)
{
    if(p)
    {
    printf("%d ",p->data);
    Preorder(p->lchild);
    Preorder(p->rchild);
    }
}

void Inorder(struct Node *p)
{
 if(p)
 {
 Inorder(p->lchild);
 printf("%d ",p->data);
 Inorder(p->rchild);
 }
}
void Postorder(struct Node *p)
{
 if(p)
 {
 Postorder(p->lchild);
 Postorder(p->rchild);
 printf("%d ",p->data);
 }
}

void IPreorder(struct Node *p){
    struct Stack stk;
    StackCreate(&stk);

    while(p || !isEmptyStack(stk)){
        if(p){
            printf("%d ",p->data);
            push(&stk,p);       //pushing into the stack since we need the address later
            p=p->lchild;
        }
        else{
            p=pop(&stk);
            p=p->rchild;
        }
    }
    }

void IInorder(struct Node *p){
    struct Stack stk;
    StackCreate(&stk);

    while(p || !isEmptyStack(stk)){
        if(p){

            push(&stk,p);       //pushing into the stack since we need the address later
            p=p->lchild;
        }
        else{
            p=pop(&stk);
            printf("%d ",p->data);
            p=p->rchild;
        }
    }
    }

void LevelOrder(struct Node *root){     //root node
    struct Queue q;
    create(&q,100);
    printf("%d ",root->data);
    enqueue(&q,root);

    while(!isEmpty(q)){
        root=dequeue(&q);
        if(root->lchild){
            printf("%d ",root->lchild->data);
            enqueue(&q,root->lchild);
        }
        if(root->rchild){
            printf("%d ",root->rchild->data);
            enqueue(&q,root->rchild);
        }
    }

}

int count(struct Node *root){
if(root){
    return count(root->lchild)+count(root->rchild)+1;
}
return 0;
}

int height(struct Node *root){
    int x=0,y=0;
    if(root==0){
        return 0;
    }
    x=height(root->lchild);
    y=height(root->rchild);
    if(x>y){
        return x+1;
    }
    else{
        return y+1;
    }
}



int main()
{
 Treecreate();
 printf("count %d ",count(root));
 printf("height %d ",height(root));

 return 0;
}
