/*
 ============================================================================
 Name        :BANK MANAGEMENT SYSTEM
 Author      :Nada Karam Abdelmonem
 Date        : 25/12/2022
 ============================================================================
 */

#include"PAYMENT.H"
struct node *head = NULL;


//Create Linked List
void ADD_ACCOUNT(void)
{
	char temp[8];
	struct node *last;
	NODE *new=(NODE *)malloc(sizeof (NODE));
	if(head==NULL)
	{
		head=new;
	}
	else
	{

		last=head;
		while(last->next)
		{
			last=last->next;
		}

		last->next=new;
	}
	// Allocate memory for new node

	printf("enter the name : ");
	gets(new->data.name);
	// insert the data to the new node and make the next point to null
	//strcpy(,data2);
	printf("enter the address : ");
	gets(new->data.address);
	printf("enter the id : ");
	gets(new->data.id);
	printf("enter the phone : ");
	gets(new->data.phone);
	printf("enter the date of birth in form (MM/YY) : ");
	gets(new->data.date_of_birth);
	printf("enter the balance : ");
	gets(temp);
	new->data.balance=atof(temp);
	// printf("\n");

	new->next=NULL;

	// If head is empty, create new list

}

//display the list
void printList(void)
{
	NODE *ptr = head;
	int count=0;
	//start looping from the head until the last node
	if(head == NULL)
	{
		printf("empty list\n");
	}
	else
	{
		while(ptr)
		{
			printf("account num.%d: \n",count+1);
			printf("the name is:%s",ptr->data.name);
			printf("\n");
			printf("the address is : %s",ptr->data.address);
			printf("\n");
			printf("the id is : %s",ptr->data.id);
			printf("\n");
			printf("the phone is : %s",ptr->data.phone);
			printf("\n");
			printf("the birth date is : %s",ptr->data.date_of_birth);
			printf("\n");
			printf("the balance is: %0.2f",ptr->data.balance);
			printf("\n");
			ptr = ptr->next;
			count++;
		}
	}


}
int delete_account(void)
{
	printf("enter the id of the account you want to delete");
	char temp[40];
	gets(temp);
	if(head)
	{
		NODE *p_select=head;
		NODE *p_previous=NULL;
		while(p_select)
		{
			if(strcmp(p_select->data.id,temp)==0)
			{
				if(p_previous)
				{
					p_previous->next=p_select->next;

				}else
				{
					head = p_select->next;
				}
				free(p_select);
				return 1;
			}
			p_previous=p_select;
			p_select=p_select->next;
		}
		//	return 0;
	}
	printf("id not found");
	return 0;
}
void MAIN_MENU()
{
	printf("*************welcome to our system***************\n");
	printf("PRESS\n");
	printf("a)-ADD A NEW ACCOUNT\n");
	printf("d)-DELETE AN ACCOUNT\n");
	printf("p)-PRINT ALL ACCOUNTS\n");
	printf("e)-EDIT AN ACCOUNT\n");
	printf("t)-DO A TRANSACT\n");
	printf("l)-PRINT ACCOUNT LIST\n");
	printf("**************************************************\n");
}

void CUSTOMER_EDIT(void)
{
	int flag=0;
	printf("enter the id of the account you want to edit");
	char temp[40],operator[2];
	gets(temp);
	NODE *P_current=head;
	while(P_current)
	{
		if(strcmp(P_current->data.id,temp)==0)
		{
			flag=1;
			printf("press n for name\n press p for phone\n press a for address\n press i for id\n press b for birth");
			gets(operator);
			switch(operator[0])
			{
			case 'n':
				printf("insert the new name");
				scanf("%s",temp);
				strcpy(P_current->data.name,temp);
				break;
			case 'a':
				printf("insert the new address");
				gets(temp);
				strcpy(P_current->data.address,temp);
				break;
			case 'p':
				printf("insert the new phone number");
				gets(temp);
				strcpy(P_current->data.phone,temp);
				break;
			case 'i':
				printf("insert the new id");
				gets(temp);
				strcpy(P_current->data.id,temp);
				break;
			case'b':
				printf("insert the new birth date in form (MM/YY)");
				gets(temp);
				strcpy(P_current->data.date_of_birth,temp);
				break;
			default:
				printf("entered wrong character please try again");
				break;
			}
			//
		}
		P_current=P_current->next;

	}
	if(flag==0)
	{
		printf("id not found\n");
	}
	//
}
void TRANSACT()
{
	printf("enter the id of the account you want to edit its balance ");
	char temp[40], operator[2];
	int new_balance,flag=0;
	gets(temp);
	NODE*P_current=head;
	while (P_current)
	{
		if(strcmp(P_current->data.id,temp)==0)
		{
			flag=1;
			printf("to withdraw press w : \nto deposit press d : ");
			gets(operator);
			switch(operator[0])
			{
			case 'w':
				printf("enter the money you want to withdraw : ");
				gets(temp);
				new_balance =atof(temp);
				if(new_balance > P_current->data.balance)
				{
					printf("balance limited.");
				}
				else
				{

					P_current->data.balance -=new_balance;
					P_current->data.nums[P_current->data.m_for_all][0]=new_balance;
					P_current->data.nums[P_current->data.m_for_all][1]=0;
					P_current->data.m_for_all++;
				}
				break;
			case 'd':
				printf("enter the money you want to deposit : ");
				gets(temp);
				new_balance = atof(temp);
				P_current->data.balance +=new_balance;
				P_current->data.nums[P_current->data.m_for_all][0]=new_balance;
				P_current->data.nums[P_current->data.m_for_all][1]=1;
				P_current->data.m_for_all++;
				break;
			}
		}
		P_current=P_current->next;
	}
	if(flag==0)
	{
		printf("ID NOT FOUND \n");
	}

}
void ACCOUNT_LIST(void)
{
	struct node*P_current=head;
	char temp[40];
	printf("enter the id of the account you want to check its balancies \n");

	gets(temp);
	while(P_current)
	{
		if(strcmp(P_current->data.id,temp)==0)
		{
			for(int i=0;i<P_current->data.m_for_all;i++)
			{
				if(P_current->data.nums[i][1]==0)
				{
					printf("process num :%d and the withdrawed money is :%0.2f\n",i+1,P_current->data.nums[i][0]);
				}
				else if(P_current->data.nums[i][1]==1)
				{
					printf("process num :%d and the deposited money is :%0.2f\n",i+1,P_current->data.nums[i][0]);
				}
			}
		}


		P_current = P_current->next;
	}

}
