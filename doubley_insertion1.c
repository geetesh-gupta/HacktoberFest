
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
struct Node *head;

void insert_beg(int x, int n)
{
    int i;
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;

        if(n==1)
        {
            if(head!=NULL){
            temp->next = head;
            head->prev = temp;
            }
            head = temp;
            return;
        }

        struct Node *temp1 = head;
        for(i=0;i<n-2;i++)
        temp1 = temp1->next; //n+1 node
         //nth node
        temp->prev = temp1;
        temp->next = temp1->next;
        temp1->next->prev = temp;
        temp1->next = temp;



}

void print()
{
    struct Node *temp = head;
    printf("\n FORWARD LIST IS  \n");
    while(temp!=NULL)
    {
        printf("%d", temp->data);
        temp =  temp->next;
    }
    printf("\n");
}
void reverse(){
    struct Node *temp = head;
    if(temp==NULL)
        return;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    printf("\n REVERSE LIST IS \n");
    while(temp!=NULL)
    {
        printf("%d", temp->data);
        temp = temp->prev;
    }
    printf("\n");

}
int main()
{
    int n,x,a;
    head = NULL;
    printf("enter the total number of elements");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf(" \n  enter the data  \n");
        scanf("%d",&x);
        printf("enter the position");
        scanf("%d",&a);
        insert_beg(x,a);

    }
    print();
    reverse();
    return 0;
}

