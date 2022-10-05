#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int coeff;
	int pow;
	struct Node *next;
};

typedef struct Node *NODE;

void readPolynomial(NODE *poly)
{
	int coeff, pow, cont, terms;
	NODE temp = (NODE)malloc(sizeof(struct Node));
	*poly = temp;
	printf("Number of terms: ");
	scanf("%d", &terms);
	while (terms)
	{
		printf("Coefficient and Power: ");
		scanf("%d %d", &coeff, &pow);
		temp->coeff = coeff;
		temp->pow = pow;

		if(terms>1){
			temp->next = (NODE)malloc(sizeof(struct Node));
			temp = temp->next;
		}
		terms--;
	}
}

void displayPolynomial(NODE poly)
{
	printf("\nPolynomial expression is: ");
	while (poly != NULL)
	{
		printf("%dX^%d", poly->coeff, poly->pow);
		poly = poly->next;
		if (poly != NULL)
			printf("+");
	}
}

void addPolynomials(NODE *result, NODE first, NODE second)
{
	NODE temp = (NODE)malloc(sizeof(struct Node));
	temp->next = NULL;
	*result = temp;
	while (first && second)
	{
		if (first->pow > second->pow)
		{
			temp->coeff = first->coeff;
			temp->pow = first->pow;
			first = first->next;
		}
		else if (first->pow < second->pow)
		{
			temp->coeff = second->coeff;
			temp->pow = second->pow;
			second = second->next;
		}
		else
		{
			temp->coeff = first->coeff + second->coeff;
			temp->pow = first->pow;
			first = first->next;
			second = second->next;
		}

		if (first && second)
		{
			temp->next = (NODE)malloc(sizeof(struct Node));
			temp = temp->next;
			temp->next = NULL;
		}
	}
	while (first || second)
	{
		temp->next = (NODE)malloc(sizeof(struct Node));
		temp = temp->next;
		temp->next = NULL;

		if (first)
		{
			temp->coeff = first->coeff;
			temp->pow = first->pow;
			first = first->next;
		}

		else if (second)
		{
			temp->coeff = second->coeff;
			temp->pow = second->pow;
			second = second->next;
		}
	}
}

int main()
{
	NODE first = NULL;
	NODE second = NULL;
	NODE result = NULL;
	printf("\nFirst polynomial:\n");
	readPolynomial(&first);
	displayPolynomial(first);
	printf("\nSecond polynomial:\n");
	readPolynomial(&second);
	displayPolynomial(second);
	addPolynomials(&result, first, second);
	printf("\nResult:\n");
	displayPolynomial(result);
	return 0;
}