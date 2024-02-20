#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void indata();
void outdata();
void screen1();
void customer();
void admin();
void deldata();

struct prod
{

	char name[20];
	int quant;
	int price;
};

int k = 0;
int h = 0;
struct prod p[50];

int main()
{
	system("cls");

	printf("================================");
	printf("\n    STOCK MANAGEMENT SYSTEM");
	printf("\n================================\n");

	screen1();

	getch();
	return 0;
}
void indata()
{
	int n = k + h;
	if (k > 0)
	{
		printf("\n!!WARNING!!\n\nIf you add new products old products will be delete!!\n");
		printf("Press 1 for Add & Press 2 for back to menu :");
		scanf("%d", &n);
		if (n == 2)
		{
			admin();
		}
	}
	printf("\n\nHow Many Products do You want to Register : ");
	scanf("%d", &k);
	// struct prod p[k];
	for (int i = 0; i < k + h; i++)
	{
		printf("\nEnter Product Name        : ");
		scanf("%s", &p[i].name);
		printf("\nEnter Price of Product    : ");
		scanf("%d", &p[i].price);
		printf("\nEnter Quantity of Product : ");
		scanf("%d", &p[i].quant);
		printf("\n--------------------------------------------------");
	}
	printf("\n!!Your Product Has Been Successfully Registered!!\n");
	printf("--------------------------------------------------\n");
	screen1();
}

void outdata()
{
	if (k > 0)
		for (int j = 0; j < k + h; j++)
		{
			printf("\nProduct Number : %d", j + 1);
			printf("\nProduct Name   : %s", p[j].name);
			printf("\nProduct price  : %d", p[j].price);
			printf("\nQuantity Left  : %d", p[j].quant);
			if (j < (k + h) - 1)
			{
				printf("\n--------------------------------------------------");
			}
			else
				printf("\n\n");
		}
	else
		printf("\nThere are 0 products!!\nFirst you have to Add Products \n");
	screen1();
}

void screen1()
{
	int c;
	printf("\n\tMain Menu\n");
	printf("\n1. Customer");
	printf("\n2. Administrator");
	printf("\n3. Exit");
	printf("\n\nChoose between (1-3) : ");
gourav:
	scanf("%d", &c);

	switch (c)
	{
	case 1:
		customer();
		break;
	case 2:
		admin();
		break;
	case 3:
		system("cls");
		break;
	default:
		printf("\nPlease choose between (1-3) : ");
		goto gourav;
		break;
	}
}

void customer()
{
	printf("\n1. Show Product List");
	printf("\n2. Return to main menu");
	int l;
	printf("\nchoose between (1-2) : ");
gilhare:
	scanf("%d", &l);
	switch (l)
	{
	case 1:
		outdata();
		break;
	case 2:
		screen1();
		break;
	default:
		printf("Please choose between (1-2) : ");
		goto gilhare;
		break;
	}
}

void admin()
{
	printf("\n1. Add Products ");
	printf("\n2. Show Product List");
	printf("\n3. Delete Product");
	printf("\n4. Return to main menu");
	printf("\nPlease choose between (1-4) : ");
	int f;
goldi:
	scanf("%d", &f);

	switch (f)
	{
	case 1:
		indata();
		break;
	case 2:
		outdata();
		break;
	case 3:
		deldata();
		break;
	case 4:
		screen1();
		break;
	default:
		printf("\nPlease choose between (1-2) : ");
		goto goldi;
		break;
	}
}

void deldata()
{
	int s, d;
	for (d = 0; d < k; d++)
	{
		printf("\n%d. Product Name   : %s", d + 1, p[d].name);
	}
	printf("\nEnter product number which you to delete : ");
	scanf("%d", &s);
	int g;
	for (g = s; g < k; g++)
	{
		p[g - 1] = p[g];
	}
	h = -1;
	printf("\n\nProduct number %d is deleted!!\n\n", s);
	screen1();
}
