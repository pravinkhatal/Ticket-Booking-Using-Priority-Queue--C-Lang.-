#include <stdlib.h>
#include<stdio.h>
#include<string.h>



struct queue_node
{
	char name[100],sname[100];
	long int mileage;
	int year,sequence;
	float priority;
	struct queue_node* link;
};


void queue_display (struct queue_node*);
void enqueue (struct queue_node **pQF, struct queue_node **pQR ,char s[],char r[],long int m,int y,int se,float p);
void dequeue (struct queue_node **, struct queue_node **);


void queue_display(struct queue_node *pQF)
{
	struct queue_node *p;
	p=pQF;
	printf ("\n********************************************************:\n");
	printf("Name\t\tMilage\tYear\tSequence Priority\n");
	if(pQF==NULL)
	{
	 printf("Queue Empty");
	}
	while (p!= NULL)
	{
		printf("\n");
		printf("%s",p->name);
		printf(" %s",p->sname);
		printf("\t%ld\t%d\t%d\t%f ",p->mileage,p->year,p->sequence,p->priority);
		p=p->link;
	}
	printf("\n********************************************************:\n");
}



void enqueue (struct queue_node **pQF, struct queue_node **pQR ,char s[],char r[],long int m,int y,int se,float p)
{
	struct queue_node* pNew,*q;
	q=*pQF;
	pNew= (struct queue_node*) malloc (sizeof(struct queue_node));


	strcpy(pNew->name ,s);
	strcpy(pNew->sname,r);
	pNew->mileage=m;
	pNew->year=y;
	pNew->sequence=se;
	pNew->priority=p;
	if (!pNew)
		{
		}

	else
	{

		pNew->link = NULL;
		if (*pQF == NULL)
		{
			*pQF=pNew;
			*pQR=pNew;
		}
		else if(p > (*pQF)->priority)
		{
		  pNew->link=*pQF;
		  *pQF=pNew;
		}
		else if(p<(*pQR)->priority)
		{
		  (*pQR)->link=pNew;
		  *pQR=pNew;
		}
		else
		{
		q=*pQF;
  			while(p <= q->link->priority)
			{
			  q=q->link;
			}
		pNew->link = q->link;
		q->link=pNew;

		}
	}
}



void dequeue (struct queue_node **pQF, struct queue_node ** pQR)
{
	struct queue_node* pDlt;

	if (*pQF == NULL)
	{
		printf ("\nQueue is Empty");

	}
	else
	{
		pDlt = *pQF;
		*pQF = pDlt->link;
		free(pDlt);
	}

}

int main()
{
	struct queue_node *front, *rear;
	char n[100],b[100];
	long int m;
	int y,se,num;
	float p;
	 FILE *fp;

	front = rear = NULL;
	fp=fopen("pjdata.txt","r");
	if(fp==0)
	 {
		printf("Unable to allocate buffer");
	 }



	//Reading Total no of employee

	while(fgetc(fp) != EOF)
	{
		fscanf(fp,"%s",n);		
	    	fscanf(fp,"%s",b);
		fscanf(fp,"%ld",&m);
		fscanf(fp,"%d",&y);
		fscanf(fp,"%d",&se);
		p=(m/1000)+y-se;
		enqueue (&front, &rear,n,b,m,y,se,p);
	}

     queue_display(front);

     return 0;
}




