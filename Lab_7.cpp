// Lab_7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

struct Deposit 
{
	char Name[64];
	char Currency[64];
	int Sum;
	int Percent;
};

int main()
{
	int n; 
	Deposit *pDep; 
	printf("n="); scanf_s("%d", &n); 
	pDep = new Deposit[n]; 

	for (int i = 0; i<n; ++i) 
	{
		printf("Deposit N=%d:\n", i + 1);
		fflush(stdin); gets_s(pDep[i].Name, 63);
		printf("Name: ");
		fflush(stdin); gets_s(pDep[i].Name, 63);
		printf("Currency: ");
		fflush(stdin); gets_s(pDep[i].Currency, 63);
		printf("Sum: "); scanf_s("%d", &pDep[i].Sum);
		printf("Percent: "); scanf_s("%d", &pDep[i].Percent);
	}

	FILE *pF;
	fopen_s(&pF, "BankDeposit.dat", "wb"); 
	fwrite(&n, sizeof(int), 1, pF); 
	fwrite(pDep, sizeof(Deposit), n, pF); 
	fclose(pF); 
	
	system("pause"); 
    return 0;
}

