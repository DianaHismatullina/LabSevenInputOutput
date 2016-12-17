// Lab_7.0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>


struct Deposit 
{
	char Name[64];
	char Currency[64];
	int Sum;
	int Percent;
};

struct List
{
	Deposit Deposit;
	List *pNext;
};

void addFirst(List *& pF, List* p)
{
	p->pNext = pF;
	pF = p;
}


int main()
{
	List *pF = 0;
	List *p;

	int n;
	FILE *pFi;
	fopen_s(&pFi, "BankDeposit.dat", "rb");
	
	if (pFi == 0) 
	{
		printf("Error!!!");
		system("pause");
		return 1;
	}

	fread(&n, sizeof(int), 1, pFi);

	for (int i = 0; i < n; i++) 
	{
		p = (List *)malloc(sizeof(List));
		fread(p, sizeof(Deposit), 1, pFi);
		addFirst(pF, p);
	}
	fclose(pFi);

	printf("\nn = %d", n);
	for (List *pi = pF; pi; pi = pi->pNext)
		printf("\nName: %s \nCurrency: %s \nSum = %4d \nPersent = %4d \n", pi->Deposit.Name, pi->Deposit.Currency, pi->Deposit.Sum, pi->Deposit.Percent);


	system("pause");
	return 0;
}

