#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

void Create(node *head)
{
    int num, ch; node *temp, *curr;
            temp=head;
            do{
                curr=(node*)malloc(sizeof(node));
                printf("Enter the data\n: ");
                scanf("%d", &curr->data);
                curr->next=NULL;
                temp->next=curr;
                temp=curr;
                printf("do you want to add more nodes(1/0)");
                scanf("%d", &ch);
            }while(ch!=0);
}

void Display(node* head)
{
    node* temp;
    temp=head->next;
    printf("\n\nList:");
    while(temp != NULL)
        {
            printf("%d --> ", temp->data);
            temp = temp->next;
        }
    printf("NULL\n");
}

int len(node *head)
{
    int i=0;
    node *curr;
    curr=head->next;
    while(curr!=NULL)
    {
        i++;
        curr=curr->next;
    }
    return i;
}

void InsertPos(node* head)
    {
        int i=1, pos, k;
        node *curr, *nnode;
        curr=head;
        nnode=(node*)malloc(sizeof(node));
        printf("\nEnter data: ");
        scanf("%d", &nnode->data);
        printf("\nEnter position to insert data: ");
        scanf("%d", &pos);

        k=len(head);
        if(pos>k+1)
            printf("Data cant be inserted");
        else
        {
            while(curr!=NULL  && i<pos)
            {
                i++;
                curr=curr->next;
            }
        nnode->next=curr->next;
        curr->next=nnode;
        }
    }
void DeletePos(node* head)
{
node *temp;
int pos, i=1, k;
    node* prev=head,*curr;
    curr=head->next;
    printf("\nEnter the position to delete data: ");
    scanf("%d", &pos);
    k = len(head);
    if(k<pos)
        printf("Data can't be deleted");
    else
    {
        while(i<pos && curr!=NULL)
        {
            i++;
                prev=curr;
                curr=curr->data;
        }
                temp=curr;
                prev->next=curr->next;
                curr->next=NULL;
                free(temp);
    }
}
void Reverse(node *head)
{
node *prev, *curr, *future;
prev=NULL;
    curr=head->next;
    while(curr!=NULL)
    {
        future=curr->next;
        curr->next=prev;
        prev=curr;
        curr=future;
    }
    head->next=prev;
}

void Sort(node *head)  //bubble sort
{
int i,k,j;
node *temp, *curr, *prev;

    Display(head);
    //printf("len:%d", k);
    k=len(head);

    for(i=1;i<=k-1;i++)
    {
        prev=head;
        curr=head->next;
        for(j=0;j<k-i;j++)
        {
            temp=curr->next;
            if(curr->data > temp->data)
            {
                prev->next=temp;
                curr->next=temp->next;
                temp->next=curr;
                prev=temp;
            }
            else
            {
                prev=curr;
                curr=curr->next;
            }
        }
    }
}


int main()
{
    int ch, w=1;
    node *head, *head2;
    head=(node*)malloc(sizeof(node));
    head->next=NULL;
    head2=(node*)malloc(sizeof(node));
    head->next=NULL;
    int n,m; 
    while(w!=0)
    {
        printf("\nChoose an Option: \n1.Create \n2.Insert \n3.Delete \n4.Display \n5.Reverse \n6.Sort \n7.Merge \n Enter your choice: ");
        scanf("%d", &n);
        switch(n)
        {
            case 1: Create(head);
                    break;
            case 2: InsertPos(head);
                        break;
            case 3: DeletePos(head);
                            break;
            case 4: Display(head);
                    break;
            case 5: Reverse(head);
                    printf("\n After Reversing");
                    Display(head);
                    break;
            case 6: Sort(head);
                    printf("\n After Sorting");
                    Display(head);
                    break;
        }
        printf("Press 0 to exit");
        scanf("%d",&w);
    }
return 0;       
}