#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	char name[100];
	int roll;
	struct student *link;
};
void create();
void display();
void beg();
void end();
void insert();
int getlen();
void del_beg();
void del_end();
void del_after();
void reverse();
void delete_range();
void del_specific();
struct student *head,*tail;
main()
{
	head=tail=NULL;
	int ch;
	while(1)
	{
		printf("Enter 1 to create\n 2 to display\n 3 to insert at the beginning\n 4 to insert at the end\n 5 to insert at a specific position\n 6 to delete from begin\n 7 to delete from the end\n 8 to del after a node\n 9 to reverse\n 10 to delete node in a specific range\n 11 to delete a specific node \n 12 to exit -");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				beg();
				break;
			case 4:
				end();
				break;
			case 5:
				insert();
				break;
			case 6:
				del_beg();
				break;
			case 7:
				del_end();
				break;
			case 8:
				del_after();
				break;
			case 9:
				reverse();
				break;
			case 10:
				delete_range();
				break;
			case 11:
				del_specific();
				break;
			case 12:
				exit(1);
		}
	}
}
void create()
{
	struct student *temp=(struct student*)malloc(sizeof(struct student));
	printf("Enter the name of the student is-");
	fflush(stdin);
	gets(temp->name);
	printf("\nEnter the roll no. of the student is:");
	scanf("%d",&temp->roll);
	temp->link=NULL;
	if(head==NULL)
	{
	head=tail=temp;
	tail->link=head;
}
	else
	{
		tail->link=temp;
		tail=temp;
		tail->link=head;
	}
}
void display()
{
	struct student *t=head;
	if(head==NULL)
	printf("Empty list\n");
	else
	{
	while(t->link!=head)
	{
		printf("The name of the student is-");
		puts(t->name);
		printf("\nThe roll no. of the student is:");
		printf("%d\n",t->roll);
		t=t->link;
	}
	printf("The name of the student is-");
	puts(t->name);
	printf("\nThe roll no. of the student is:");
	printf("%d\n",t->roll);
}
}
void beg()
{
	struct student *temp=(struct student*)malloc(sizeof(struct student));
	printf("Enter the name of the student is-");
	fflush(stdin);
	gets(temp->name);
	printf("\nEnter the roll no. of the student is:");
	scanf("%d",&temp->roll);
	temp->link=NULL;
	if(head==NULL)
	{
	head=tail=temp;
	tail->link=head;
}
	else
	{
	temp->link=head;
	head=temp;
	tail->link=head;
}
}
void end()
{
	struct student *temp=(struct student*)malloc(sizeof(struct student));
	printf("Enter the name of the student is-");
	fflush(stdin);
	gets(temp->name);
	printf("\nEnter the roll no. of the student is:");
	scanf("%d",&temp->roll);
	temp->link=NULL;
	if(head==NULL)
	{
	head=tail=temp;
	tail->link=head;
}
else
{
	tail->link=temp;
	tail=temp;
	tail->link=head;
}
	
}
void insert()
{
	int pos,c,l;
	c=1;
	printf("Enter the position of the node-");
	scanf("%d",&pos);
	l=getlen();
	if(pos<1 || pos>l)
	printf("Invalid position\n");
	else if(pos==1)
	beg();
	else
	{
	struct student *temp=(struct student*)malloc(sizeof(struct student));
	printf("Enter the name of the student is-");
	fflush(stdin);
	gets(temp->name);
	printf("\nEnter the roll no. of the student is:");
	scanf("%d",&temp->roll);
	temp->link=NULL;
	struct student *t=head;
	while(c<pos-1)
	t=t->link;
	temp->link=t->link;
	t->link=temp;	
	}
}
void del_beg()
{
	struct student *t=head;
	if(head==NULL)
	printf("List is empty\n");
	else  if(head==tail)
	{
		head=tail=NULL;
		free(t);
}
else
{
	head=head->link;
	tail->link=head;
	free(t);
}
}
void del_end()
{
	struct student *t=head;
	struct student *d;
	if(head==NULL)
	printf("List is empty\n");
	else if(head==tail)
	{
		head=tail=NULL;
		free(t);
	}
	else
	{
	while(t->link!=head)
	{
		d=t;
		t=t->link;
	}
	struct student *dl=d->link;
	d->link=head;
	tail=d;
	free(dl);
}
}
void del_after()
{
	struct student *t=head;
	int c,pos,l;
	c=1;
	l=getlen();
	printf("Enter the position:");
	scanf("%d",&pos);
	if(pos<=0 || pos>=l)
	printf("Invalid position\n");
	else if(pos==l-1)
	del_end();
	else
	{
		while(c<pos)
		t=t->link;
		struct student *d=t->link;
		t->link=d->link;
		free(d);
	}
	
}
void reverse()
{
	struct student *prev,*current,*next;
	current=tail->link;
	next=current->link;
	while(current->link!=head)
	{
		prev=current;
		current=next;
		next=current->link;
		current->link=prev;
	}
	next->link=tail;
	tail=next;
}
void del_specific()
{
	int c=1;
	int pos;
	int l=getlen();
	printf("Enter the position:");
	scanf("%d",&pos);
	if(pos==1)
	del_beg();
	else if(pos==l)
	del_end();
	else
	{
		struct student *t=head;
		while(c<pos-1)
		{
			t=t->link;
			c++;
		}
		struct student *d=t->link;
		t->link=d->link;
		free(d);
	}
}
void delete_range()
{
	int l=getlen();
	struct student *t=head;
	struct student *d;
	int pos1,pos2;
	int c=1;
	printf("Enter the starting and ending node-");
	scanf("%d %d",&pos1,&pos2);
	if(pos1==1 && pos2==l)
	{
		struct student *del;
		while(t->link!=head)
		{
			del=t;
			t=t->link;
			free(del);
		}
	    del=t;
	    free(del);
	    head=NULL;
	}
	else
	{
	while(c<pos1)
	{
		d=t;
		c++;
		t=t->link;
	}
	while(c<=pos2)
	{
		struct student *temp=t;
		t=temp->link;
		c++;
		free(temp);
	}
	if(pos1==1)
	{
	head=t;
	tail->link=head;
    }
    else if(pos2==l)
    {
    tail=d;
    d->link=head;
}
    else
	d->link=t;
}
}
int getlen()
{
	struct student *t=head;
	int count=1;
	while(t->link!=head)
	
{
	count++;
	t=t->link;
}
	return count;
}

