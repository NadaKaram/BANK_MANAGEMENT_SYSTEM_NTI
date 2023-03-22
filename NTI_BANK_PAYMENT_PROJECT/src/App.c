/*
 * App.c
 *
 *  Created on: Dec 28, 2022
 *      Author: Nada Karam Abdelmonem
 */
#include "PAYMENT.h"

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	//int condition=1;
	char operator[1];
	while(1)
	{
		MAIN_MENU();
		gets(operator);
		switch(operator[0])
		{
		case 'a':
			ADD_ACCOUNT();
			break;
		case 'd':
			delete_account();
			break;
		case 'p':
			printList();
			break;
		case 'e':
			CUSTOMER_EDIT();
			break;
		case 't':
			TRANSACT();
			break;
		case 'l':
			ACCOUNT_LIST();
			break;
		}

	}
	return 0;
}
