/*
Programmer =   Shivam Mohite 
Topic=         Linked List

Problem statement:- Department of computer engineering has a students club named "Pinnacle Club".
                    Student of second year , third year and final year of department can be granted membership on request.
                    Similarly one may cancle the membership on request . first node is reserved for President of the club 
                    And last node is reserved for Secretary. Write a C/C++ code to maintain club member's information
                         1]Add and Delete the members as well as as president
                         2]Compute total number of members of club
                         3]display members
                         4]Display list in reverse order
                         5]Concatenate two list

Algorithm:-
     1]Start
     2]Creat a list
     3]while creating a list check whether it is president ,a secrtary or a member
     4]display
     5]delete
     6]count
     7]display in reverse
     8]concatenate
     9]End
*/

#include<iostream>
#include<string.h>
using namespace std;
#define TRUE 1                                    //initialising true to 1
#define FALSE 0                                   //initialising false to 0
#define size 20                                   //initialising size to 20

struct node                                       //creating structure for node of link list
{
	int PRN;                                     //Data part of list
	char name[size];                             //Data part of list
	struct node *next;                           //Link part of list
}*head;                                           //creating node for link list

class sll                                         //Class
{
     public:
	sll();                                       //Function declaration
	struct node*create();                        //Function declaration
	void display(struct node*);                  //Function declaration
	void count();                                //Function declaration
	void reverse(struct node*);                  //Function declaration
	struct node*insert_President();              //Function declaration
	void insert_member();                        //Function declaration
	void insert_Secretary();                     //Function declaration
	node*remove();                               //Function declaration
	node *concat(struct node*,struct node *);    //Function declaration
	~sll();                                      //Function declaration
};

sll::sll()                                        //Constructor
{
	head=NULL;                                   //initialising head to NULL
}

sll::~sll()                                       //Distructor
{
	node *temp,*temp1;                           //creating node for link list
	temp=head->next;                             //initialising temp to head's next node    
	delete head;                                 //delete head
	while(temp!=NULL)                            //loop till temp is not = NULL
	{
		temp1=temp->next;                       //initialising temp1 to temp's next node
		delete temp;                            //delete temp
		temp=temp1;                             //initialising temp1 to temp
	}
}

node *sll::create()                               //Function to creat 
{
	node *temp=NULL,*New;                        //creating node for link list
	int val,flag;
	char n[size];                      
	char ans='y';                                //initialising ans to y
	flag=TRUE;                                   //initialising flag to TRUE 
	do                                           //loop
	{
		cout<<"\n Enter the PRN of student: ";  //Data entry of Student's PRN
		cin>>val;
		cout<<"\n Enter name: ";                //Data entry of Student's Name
		cin>>n;
		New = new node;                         //creating node for link list
		if(New==NULL)                           //if new not created or it is equal to NULL
		{
			cout<<"\n Memory not allocated";
		}
		New->PRN=val;                           //Data entry of Student's PRN in list
		strcpy(New->name,n);                    //Data entry of Student's Name in list
		New->next=NULL;                         //initialising next node od New to NULL
		if(flag==TRUE)                          //if flag is equal to TRUE
		{
			head=New;                          //initialise New to head
			temp=head;                         //initialise head to temp
			flag=FALSE;                        //initialise flag to FALSE
		}
		else
		{
			temp->next=New;                    //initialising temp to New's next node
			temp=New;                          //initialise temp to New
		}
		cout<<"\n Do you want to enter more elements(y/n): ";  //loop condition
		cin>>ans;
	}while(ans=='y'||ans=='Y');                  //loop condition statement

	return head;                                 //return head after th function ends
}

void sll::display(node *head)                     //function for display
{
	struct node*temp;                            //creating node for link list
	temp=head;                                   //initialise head to temp
	if(temp==NULL)                               //if temp equal NULL
	{
		cout<<"\n List is empty";               //if yes print
		return;
	}
	while(temp!=NULL)                            //loop till temp not equal NULL
	{
		cout<<" "<<temp->PRN<<"  "<<temp->name<<"\n";     //print
		temp=temp->next;                        //initialising temp to temp's next node
	}
}
void sll::count()                                 //function count
{
	struct node*temp;                            //creating node for link list
	int count=0;                                 //initialise count = 0
	temp=head;                                   //initialise head to temp
	if(temp==NULL)                               //if temp equal NULL
	{
		cout<<"\n List is empty";               //if yes print
		return;
	}
	while(temp!=NULL)                            //if temp not equal NULL
	{
		count++;                                //count increment
		temp=temp->next;                        //initialising temp to temp's next node
	}
	cout<<"\n Total number of members are "<<count;   //print
}

void sll::reverse(node *head)                     //function reverse
{
	if(head!=NULL)                               //if head not equal NULL
		reverse(head->next);                    //recursion function
	else
		return;
	cout<<" "<<head->PRN<<"  "<<head->name<<"\n";     //print
}

node *sll::remove()                               //function remove
{
	node *temp,*prev;                            //creating node for link list
	int key;
	prev=new node;                               //creating node for link list
	temp=head;                                   //initialise head to temp
	cout<<"\n Enter the PRN of the node you want to delete: ";  //data entry for prn to be deleted
	cin>>key;
	while(temp!=NULL)                            //if temp not equal NULL
	{
		if(temp->PRN==key)                      //if temp's PRN is equal to key
			break;
		prev=temp;                              //initialise temp to prev
		temp=temp->next;                        //initialise temp's next to temp
	}
	if(temp==NULL)                               //if temp is NULL
		cout<<"\n Node not found";              //print
	else
	{
		if(temp==head)                          //if head is equal to temp
			head=temp->next;                   //initialise temp's next to head
		else
			prev->next=temp->next;             //else initialise temp's next to prev's next
		delete temp;                            //delete temp
		cout<<"\n The member is deleted";       //print
	}
	return head;
}

void sll::insert_Secretary()                      //function secretary
{
	node *New,*temp;                             //creating node for link list
	New=new node;
	cout<<"\n Enter the PRN of the student: ";   //Data Entery of PRN of the student
	cin>>New->PRN;
	cout<<"\n Enter the name of the student: ";  //Data Entery of Name of the student
	cin>>New->name;
	New->next=NULL;                              //initialise New's next to NULL
	if(head==NULL)                               //if head is equal to NULL
		head=New;                               //initialise new to head
	else
	{
		temp=head;                              //initialise head to temp
		while(temp->next!=NULL)                 //loop till temp's next is not equal to NULL
			temp=temp->next;                   //initialise temp's next to temp
		temp->next=New;                         //initialise New to temp's next
		New->next=NULL;                         //initialise NULL to New's next
	}
	cout<<"\n The member is inserted";           //print
}

void sll::insert_member()                         //function insert member
{
	int key;
	node *temp,*New;                             //creating node for link list
	New=new node;                                //creating node for link list
	cout<<"\n Enter the PRN of the student ";    //Data Entery of PRN of the student
	cin>>New->PRN;
	cout<<"\n Enter the name of the student: ";  //Data Entery of Name of the student
	cin>>New->name;
	if(head==NULL)                               //if head is equal to NULL
		head=New;                               //initialise new to head
	else
	{
		cout<<"\n Enter the PRN after which you want to insert the node: ";   //Enter the PRN after which you want to insert the node
		cin>>key;
		temp=head;                              //initialise head to temp
		do
		{
			if(temp->PRN==key)                 //if temp's PRN is equal to key
			{
				New->next=temp->next;         //initialise temp's next to new's next
				temp->next=New;               //initialise new to temp's next
				break;
			}
			else
				temp=temp->next;              //initialise temp's next to temp
		}while(temp!=NULL);                     //loop condition statement
	}
	cout<<"\n The member is inserted";           //print
}

node *sll::insert_President()                     //insert president
{
	node *New,*temp;                             //creating node for link list
	New=new node;                                //creating node for link list
	cout<<"\n Enter the PRN of the student ";    //Data Entery of PRN of the student
	cin>>New->PRN;
	cout<<"\n Enter the name of the student: ";  //Data Entery of Name of the student
	cin>>New->name;
	if(head==NULL)                               //if head is equal to NULL
		head=New;                               //initialise new to head
	else
	{
		temp=head;                              //initialise head to temp
		New->next=temp;                         //initialise temp to new's next
		head=New;                               //initialise new to head
	}
	cout<<"\n The member is inserted";           //print
	return head;
}

node *sll::concat(node *head1,node *head2)        //concatination
{
	node *temp;                                  //creating node for link list
	temp=head1;                                  //initialise head1 to temp
	while(temp->next!=NULL)                      //if temp's next equal to NULL
		temp=temp->next;                        //initialise temp's next to temp
	temp->next=head2;                            //initialise head to temp's next
	cout<<"\n The lists are concatenated";       //print
	return head1;
}

int main()
{
	sll s;                                       //Object of class ssl
	int ch,ch1;
	char ans='y';                                //initialisation of ans to y
	node *start=NULL;
	node *start1,*start2,*start3;                //creating of node
	start1=NULL;                                 //initialise start1=NULL
	start2=NULL;                                 //initialise start2=NULL
	start3=NULL;                                 //initialise start3=NULL
	//loop of menu
	do
	{
		cout<<"\n 1. Create.";
	     cout<<"\n 2. Display members";
	     cout<<"\n 3. Insert member";
	     cout<<"\n 4. Delete member";
	     cout<<"\n 5. Total number of members of club";
	     cout<<"\n 6. Display list in reverse using recursion";
	     cout<<"\n 7. Concatenate two lists";
	     cout<<"\n 8. Exit";
		cout<<"\n Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
		     case 1:
			     start=s.create();                       //creation of list
			     break;
		     case 2:
			     s.display(start);                       //display of list
			     break;
		     case 3:
			     cout<<"\n The members are ";            //insertion
			     s.display(start);
			     cout<<"\n Menu";
			     cout<<"\n 1. Insert President";    
			     cout<<"\n 2. Insert Member";       
			     cout<<"\n 3. Insert Secretary";    
			     cout<<"\n Enter your choice: ";
			     cin>>ch1;
			     switch(ch1)                             //switch case
			     {
			          //menu
			          case 1:
				          start=s.insert_President();   //insert president
				          break;
			          case 2:
				          s.insert_member();            //insert member
				          break;
			          case 3:
				          s.insert_Secretary();         //insert secretary
				          break;
			     }
			     break;		
		     case 4:
			     start=s.remove();                       //delete member
			     break;
		     case 5:
			     s.count();                              //count member
			     break;
		     case 6:
			     s.reverse(start);                       //reverse list
			     break;
		     case 7:                                      //concatination
			     cout<<"\n Enter the data for first division";
			     start1=s.create();
			     cout<<"\n Enter the data for second division";
			     start2=s.create();
			     start3=s.concat(start1,start2);
			     s.display(start3);
			     break;
		}
		cout<<"\n Want to continue to Menu(y/n): ";       //loop conditon 
		cin>>ans;
	}while(ans=='y'||ans=='Y');                            //loop conditon statement
	return 0;
}

