/*
 * PAYMENT.h
 *
 *  Created on: Dec 28, 2022
 *      Author: Nada Karam Abdelmonem
 */

#ifndef PAYMENT_H_
#define PAYMENT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account
{
	float balance;
	int m_for_all;
	char date_of_birth[8];
	char address[10];
	char name[12];
	char id[13];
	char phone[13];
	float nums[6][2];
};
typedef struct node
{
	struct account data;
	struct node *next;
}NODE;

void ADD_ACCOUNT(void);
void printList(void);
int delete_account(void);
void MAIN_MENU();
void CUSTOMER_EDIT(void);
void TRANSACT();
void ACCOUNT_LIST(void);

#endif /* PAYMENT_H_ */
