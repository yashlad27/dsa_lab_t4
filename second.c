#include <stdio.h>
#include <string.h>
struct book{
	int id;
	char name[15];
	float cost;
};

void getdata(struct book b[10],int n);
void lessthan500(struct book b[10],int n);
void deletedup(struct book b[10],int n);
void morethan500(struct book b[10],int n);
void display(struct book b[10],int n);
int main()
{
	int i,j,n,k=1,ch;
	printf("Enter the number of books: ");
	scanf("%d",&n);
	struct book b1[10];
	getdata(b1,n);
	do
	{
		printf("1.Delete duplicate \n2.Less than 500 \n3.more than 500 \n4.display\n");
		printf("Enter Your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				deletedup(b1,n);
				printf("\nTo continue Enter 1: ");
				scanf("%d",&k);
				break;
			case 2:
                lessthan500(b1,n);
				printf("\nTo continue Enter 1: ");
				scanf("%d",&k);
				break;
			case 3:
				morethan500(b1,n);
				printf("\nTo continue Enter 1: ");
				scanf("%d",&k);
				break;
			case 4:
				display(b1,n);
				printf("\nTo continue Enter 1: ");
				scanf("%d",&k);
				break;
		}
	}
		while(k==1);
	return 0;

}


void getdata(struct book b[10],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
	printf("Enter the id of the book %d: ",i+1);
	scanf("%d",&b[i].id);
	printf("Enter the name of the book %d: ",i+1);
	scanf("%s",b[i].name);
	printf("Enter the price of the book %d: ",i+1);
	scanf("%f",&b[i].cost);
}
}
void lessthan500(struct book b[10],int n)
{
	int i,c=0;
	struct book b2[10];
	for(i=0;i<n;i++)
	{
		if(b[i].cost<=500.00)
		{
		b2[c].id=b[i].id;
		strcpy(b2[c].name,b[i].name);
		b2[c].cost=b[i].cost;
		c++;
	}
}
	if(c==0)
	printf("price of all books are less than 500");
	else
	{
	for(i=0;i<c;i++)
	printf("%d      %s      %f\n",b2[i].id,b2[i].name,b2[i].cost);
	}

}
void deletedup(struct book b[10],int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
		{
		for(j=i+1;j<n;j++)
		{
		if(b[i].id==b[j].id)
		{
			for(k=j;k<n;k++)
			b[k]=b[k+1];
			n--;
			j--;
			}
		}}
		for(i=0;i<n;i++)
	printf("%d     %s     %f\n",b[i].id,b[i].name,b[i].cost);
}
void morethan500(struct book b[10],int n)
{
	int i,count=0;
	for(i=0;i<n;i++)
	{
		if(b[i].cost>500)
		{
		count++;
		printf("%d       %s      %f\n",b[i].id,b[i].name,b[i].cost);
	    }
	}
	if(count==0)
	printf("price of all books are less than 500");
	else
	printf("%d",count);
}
void display(struct book b[10],int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d     %s     %f\n",b[i].id,b[i].name,b[i].cost);

}
