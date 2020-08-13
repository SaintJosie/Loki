#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <share.h>
#include "key.h"

#define MAX 5000
#define MIN 0
#define ALNUMSYM 93


extern const char pi[], alpha[], numsym[], capAl[], e[], sr2[], assKey[];

void encode(int* option1, int* option2, int* option3, const char* key);
void decode(int* option1, int* option2, int* option3, const char* key);
FILE* fpt;

char phrase[MAX];

const char test[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };



int main() {

	int flag, op1, op2, op3, key;	//op1 is a dialation, op2 is a translation, op3 is inversion

	printf("What do you wish to do?\n1. Encode a Text file's contents\n2. Decode a Text File's contents\n");

	flag = getchar();
	getchar();

	printf("\nOption 1: ");
	op1 = getchar();
	getchar();
	op1 = (op1 % 12) + 1;
	//printf("%d\n", op1);

	printf("\nOption 2: ");
	op2 = getchar();
	getchar();
	op2 = (op2 % 10) + 1;
	//printf("%d\n", op2);

	printf("\nOption 3: ");
	op3 = getchar() % 2;
	getchar();
	op3 = op3 % 2;
	//printf("%d\n", op3);

	printf("\nKey: ");
	key = getchar() % 3;
	getchar();
	//printf("%d\n", key);
	while (op2 > 25 || op2 < 0)
	{
		if (op2 > 25) op2 %= ALNUMSYM;
		else if (op2 < 0) op2 += ALNUMSYM;
	}
	if (!op3) op3 = -1;
	if (flag == 49)
	{
		switch (key)
		{
		case 0:
			encode(&op1, &op2, &op3, pi);
			break;
		case 1:
			encode(&op1, &op2, &op3, sr2);
			break;
		case 2:
			encode(&op1, &op2, &op3, e);
			break;
		case 3:
			encode(&op1, &op2, &op3, test);
			break;
		}
		getchar();
	}
	else if (flag == 50)
	{
		switch (key)
		{
		case 0:
			decode(&op1, &op2, &op3, pi);
			break;
		case 1:
			decode(&op1, &op2, &op3, sr2);
			break;
		case 2:
			decode(&op1, &op2, &op3, e);
			break;
		case 3:
			decode(&op1, &op2, &op3, test);
			break;
		}
		getchar();
	}
}

void encode(int* option1, int* option2, int * option3, const char* eKey)
{
	int c = 0, keyIndex = 0;
	if ((fpt = fopen("message.txt", "w+t")) != NULL) {
		printf("\nPlease Type in the message that you would like to encode\n");
		gets(phrase);
		for (int i = 0; c < MAX; i++)
		{
			if (keyIndex > 76) keyIndex = 0;
			switch (eKey[keyIndex])
			{
			case 48:	//0
				for (int j = 1; j < ALNUMSYM; j++)	//checks where in the alnbmkphabet phrase[i] is
				{

					if (phrase[i] == ' ')
					{
						phrase[i] = ' ';
					}
					else if (phrase[i] == assKey[j] && j < ALNUMSYM)	//once it finds out where in the alphabet phrase[i] is, it initiates a swap
					{
						int swap = j + 10 * (*option3) + (*option1 * *option3) + *option2;
						if (swap > ALNUMSYM) swap %= ALNUMSYM;
						if (swap < 0) swap += ALNUMSYM;
						phrase[i] = assKey[swap];
						break;
					}
				}
				break;
			case 49:	//1
				for (int j = 1; j < ALNUMSYM; j++)	//checks where in the alphabet phrase[i] is
				{

					if (phrase[i] == ' ')
					{
						phrase[i] = ' ';
					}
					else if (phrase[i] == assKey[j] && j < ALNUMSYM)	//once it finds out where in the alphabet phrase[i] is, it initiates a swap
					{
						int swap = j - 1 * (*option3) + (*option1 * *option3) + *option2;
						if (swap < 0) swap += ALNUMSYM;
						if (swap > ALNUMSYM) swap %= ALNUMSYM;
						phrase[i] = assKey[swap];
						break;
					}
				}
				break;
			case 50:	//2
				for (int j = 1; j < ALNUMSYM; j++)	//checks where in the alphabet phrase[i] is
				{

					if (phrase[i] == ' ')
					{
						phrase[i] = ' ';
					}
					else if (phrase[i] == assKey[j] && j < ALNUMSYM)	//once it finds out where in the alphabet phrase[i] is, it initiates a swap
					{
						int swap = j + 2 * (*option3) + (*option1 * *option3) + *option2;
						if (swap > ALNUMSYM) swap %= ALNUMSYM;
						if (swap < 0) swap += ALNUMSYM;
						phrase[i] = assKey[swap];
						break;
					}
				}
				break;
			case 51:	//3
				for (int j = 1; j < ALNUMSYM; j++)	//checks where in the alphabet phrase[i] is
				{

					if (phrase[i] == ' ')
					{
						phrase[i] = ' ';
					}
					else if (phrase[i] == assKey[j] && j < ALNUMSYM)	//once it finds out where in the alphabet phrase[i] is, it initiates a swap
					{
						int swap = j - 3 * (*option3) + (*option1 * *option3) + *option2;
						if (swap < 0) swap += ALNUMSYM;
						if (swap > ALNUMSYM) swap %= ALNUMSYM;
						phrase[i] = assKey[swap];
						break;
					}
				}
				break;
			case 52:	//4
				for (int j = 1; j < ALNUMSYM; j++)	//checks where in the alphabet phrase[i] is
				{

					if (phrase[i] == ' ')
					{
						phrase[i] = ' ';
					}
					else if (phrase[i] == assKey[j] && j < ALNUMSYM)	//once it finds out where in the alphabet phrase[i] is, it initiates a swap
					{
						int swap = j + 4 * (*option3) + (*option1 * *option3) + *option2;
						if (swap > ALNUMSYM) swap %= ALNUMSYM;
						if (swap < 0) swap += ALNUMSYM;
						phrase[i] = assKey[swap];

						break;
					}
				}
				break;
			case 53:	//5
				for (int j = 1; j < ALNUMSYM; j++)	//checks where in the alphabet phrase[i] is
				{
					if (phrase[i] == ' ')
					{
						phrase[i] = ' ';
					}
					else if (phrase[i] == assKey[j] && j < ALNUMSYM)	//once it finds out where in the alphabet phrase[i] is, it initiates a swap
					{
						int swap = j - 5 * (*option3) + (*option1 * *option3) + *option2;
						if (swap < 0) swap += ALNUMSYM;
						if (swap > ALNUMSYM) swap %= ALNUMSYM;
						phrase[i] = assKey[swap];
						break;
					}
				}
				break;
			case 54:	//6
				for (int j = 1; j < ALNUMSYM; j++)	//checks where in the alphabet phrase[i] is
				{

					if (phrase[i] == ' ')
					{
						phrase[i] = ' ';
					}
					else if (phrase[i] == assKey[j] && j < ALNUMSYM)	//once it finds out where in the alphabet phrase[i] is, it initiates a swap
					{
						int swap = j + 6 * (*option3) + (*option1 * *option3) + *option2;
						if (swap > ALNUMSYM) swap %= ALNUMSYM;
						if (swap < 0) swap += ALNUMSYM;
						phrase[i] = assKey[swap];
						break;
					}
				}
				break;
			case 55:	//7
				for (int j = 1; j < ALNUMSYM; j++)	//checks where in the alphabet phrase[i] is
				{

					if (phrase[i] == ' ')
					{
						phrase[i] = ' ';
					}
					else if (phrase[i] == assKey[j] && j < ALNUMSYM)	//once it finds out where in the alphabet phrase[i] is, it initiates a swap
					{
						int swap = j - 7 * (*option3) + (*option1 * *option3) + *option2;
						if (swap < 0) swap += ALNUMSYM;
						if (swap > ALNUMSYM) swap %= ALNUMSYM;
						phrase[i] = assKey[swap];
						break;
					}
				}
				break;
			case 56:	//8
				for (int j = 1; j < ALNUMSYM; j++)	//checks where in the alphabet phrase[i] is
				{

					if (phrase[i] == ' ')
					{
						phrase[i] = ' ';
					}
					else if (phrase[i] == assKey[j] && j < ALNUMSYM)	//once it finds out where in the alphabet phrase[i] is, it initiates a swap
					{
						int swap = j + 8 * (*option3) + (*option1 * *option3) + *option2;
						if (swap > ALNUMSYM) swap %= ALNUMSYM;
						if (swap < 0) swap += ALNUMSYM;
						phrase[i] = assKey[swap];
						break;
					}
				}
				break;
			case 57:	//9
				for (int j = 1; j < ALNUMSYM; j++)	//checks where in the alphabet phrase[i] is
				{

					if (phrase[i] == ' ')
					{
						phrase[i] = ' ';
					}
					else if (phrase[i] == assKey[j] && j < ALNUMSYM)	//once it finds out where in the alphabet phrase[i] is, it initiates a swap
					{
						int swap = j - 9 * (*option3) + (*option1 * *option3) + *option2;
						if (swap < 0) swap += ALNUMSYM;
						if (swap > ALNUMSYM) swap %= ALNUMSYM;
						phrase[i] = assKey[swap];
						break;
					}
				}
				break;
			}
			c++;
			keyIndex++;
		}
		fputs(phrase, fpt);
	}
	fclose(fpt);
	printf("%s", phrase);
	getchar();
}




void decode(int* option1, int* option2, int* option3, const char* eKey)
{
	int c = 0, key = 0;

	printf("Would you like to : 1.Decode a file or 2. Type in the message?");
    if (!(getchar() % 2))
    {
        scanf("%s ", phrase);
    }
	else if ((fpt = fopen("message.txt", "a+t")) != NULL) {
		fgets(phrase, MAX, fpt);
		fclose(fpt);
		}
		for (int i = 0; c < MAX; i++)
		{
			if (key > 76) key = 0;

			switch (eKey[key])
			{
			case 48:	//0
				for (int j = 1; j < ALNUMSYM; j++)	//checks where in the alnbmkphabet phrase[i] is
				{

					if (phrase[i] == ' ')
					{
						phrase[i] = ' ';
						break;
					}
					else if (phrase[i] == assKey[j] && j < ALNUMSYM)	//once it finds out where in the alphabet phrase[i] is, it initiates a swap
					{
						int swap = j - 10 * (*option3) - (*option1 * *option3) - *option2;
						if (swap < 0) swap += ALNUMSYM;
						if (swap > ALNUMSYM) swap %= ALNUMSYM;
						phrase[i] = assKey[swap];
						break;
					}

				}
				break;
			case 49:	//1
				for (int j = 1; j < ALNUMSYM; j++)	//checks where in the alphabet phrase[i] is
				{

					if (phrase[i] == ' ')
					{
						phrase[i] = ' ';
						break;
					}
					else if (phrase[i] == assKey[j] && j < ALNUMSYM)	//once it finds out where in the alphabet phrase[i] is, it initiates a swap
					{
						int swap = j + 1 * (*option3) - (*option1 * *option3) - *option2;
						if (swap > ALNUMSYM) swap %= ALNUMSYM;
						if (swap < 0) swap += ALNUMSYM;
						phrase[i] = assKey[swap];
						break;
					}
				}
				break;
			case 50:	//2
				for (int j = 1; j < ALNUMSYM; j++)	//checks where in the alphabet phrase[i] is
				{

					if (phrase[i] == ' ')
					{
						phrase[i] = ' ';
						break;
					}
					else if (phrase[i] == assKey[j] && j < ALNUMSYM)	//once it finds out where in the alphabet phrase[i] is, it initiates a swap
					{
						int swap = j - 2 * (*option3) - (*option1 * *option3) - *option2;
						if (swap < 0) swap += ALNUMSYM;
						if (swap > ALNUMSYM) swap %= ALNUMSYM;
						phrase[i] = assKey[swap];
						break;
					}
				}
				break;
			case 51:	//3
				for (int j = 1; j < ALNUMSYM; j++)	//checks where in the alphabet phrase[i] is
				{

					if (phrase[i] == ' ')
					{
						phrase[i] = ' ';
						break;
					}
					else if (phrase[i] == assKey[j] && j < ALNUMSYM)	//once it finds out where in the alphabet phrase[i] is, it initiates a swap
					{
						int swap = j + 3 * (*option3) - (*option1 * *option3) - *option2;
						if (swap > ALNUMSYM) swap = swap % ALNUMSYM;
						if (swap < 0) swap += ALNUMSYM;
						phrase[i] = assKey[swap];
						break;
					}
				}
				break;
			case 52:	//4
				for (int j = 1; j < ALNUMSYM; j++)	//checks where in the alphabet phrase[i] is
				{

					if (phrase[i] == ' ')
					{
						phrase[i] = ' ';
						break;
					}
					else if (phrase[i] == assKey[j] && j < ALNUMSYM)	//once it finds out where in the alphabet phrase[i] is, it initiates a swap
					{
						int swap = j - 4 * (*option3) - (*option1 * *option3) - *option2;
						if (swap < 0) swap += ALNUMSYM;
						if (swap > ALNUMSYM) swap %= ALNUMSYM;
						phrase[i] = assKey[swap];
						break;
					}
				}
				break;
			case 53:	//5
				for (int j = 1; j < ALNUMSYM; j++)	//checks where in the alphabet phrase[i] is
				{
					if (phrase[i] == ' ')
					{
						phrase[i] = ' ';
						break;
					}
					else if (phrase[i] == assKey[j] && j < ALNUMSYM)	//once it finds out where in the alphabet phrase[i] is, it initiates a swap
					{
						int swap = j + 5 * (*option3) - (*option1 * *option3) - *option2;
						if (swap > ALNUMSYM) swap %= ALNUMSYM;
						if (swap < 0) swap += ALNUMSYM;
						phrase[i] = assKey[swap];
						break;
					}
				}
				break;
			case 54:	//6
				for (int j = 1; j < ALNUMSYM; j++)	//checks where in the alphabet phrase[i] is
				{

					if (phrase[i] == ' ')
					{
						phrase[i] = ' ';
						break;
					}
					else if (phrase[i] == assKey[j] && j < ALNUMSYM)	//once it finds out where in the alphabet phrase[i] is, it initiates a swap
					{
						int swap = j - 6 * (*option3) - (*option1 * *option3) - *option2;
						if (swap < 0) swap += ALNUMSYM;
						if (swap > ALNUMSYM) swap %= ALNUMSYM;
						phrase[i] = assKey[swap];
						break;
					}
				}
				break;
			case 55:	//7
				for (int j = 1; j < ALNUMSYM; j++)	//checks where in the alphabet phrase[i] is
				{

					if (phrase[i] == ' ')
					{
						phrase[i] = ' ';
						break;
					}
					else if (phrase[i] == assKey[j] && j < ALNUMSYM)	//once it finds out where in the alphabet phrase[i] is, it initiates a swap
					{
						int swap = j + 7 * (*option3) - (*option1 * *option3) - *option2;
						if (swap > ALNUMSYM) swap %= ALNUMSYM;
						if (swap < 0) swap += ALNUMSYM;
						phrase[i] = assKey[swap];
						break;
					}
				}
				break;
			case 56:	//8
				for (int j = 1; j < ALNUMSYM; j++)	//checks where in the alphabet phrase[i] is
				{

					if (phrase[i] == ' ')
					{
						phrase[i] = ' ';
						break;
					}
					else if (phrase[i] == assKey[j] && j < ALNUMSYM)	//once it finds out where in the alphabet phrase[i] is, it initiates a swap
					{
						int swap = j - 8 * (*option3) - (*option1 * *option3) - *option2;
						if (swap < 0) swap += ALNUMSYM;
						if (swap > ALNUMSYM) swap %= ALNUMSYM;
						phrase[i] = assKey[swap];
						break;
					}
				}
				break;
			case 57:	//9
				for (int j = 1; j < ALNUMSYM; j++)	//checks where in the alphabet phrase[i] is
				{

					if (phrase[i] == ' ')
					{
						phrase[i] = ' ';
						break;
					}
					else if (phrase[i] == assKey[j] && j < ALNUMSYM)	//once it finds out where in the alphabet phrase[i] is, it initiates a swap
					{
						int swap = j + 9 * (*option3) - (*option1 * *option3) - *option2;
						if (swap > ALNUMSYM) swap %= ALNUMSYM;
						if (swap < 0) swap += ALNUMSYM;
						phrase[i] = assKey[swap];
						break;
					}
				}
				break;
			}
			c++;
			key++;
		}

	//fclose(fpt);
	printf("%s", phrase);
	if ((fpt = fopen("output.txt", "w+t")) != NULL) {
		fputs(phrase, fpt);
		fclose(fpt);
	}
	getchar();
}

