#include <stdio.h>
#include <string.h>

int Add(char a, char b);

int main(void)
{
	char A[10001] = "";
	char B[10001] = "";
	char C[10001] = "";
	int a_index, b_index;
	int result;
	int olim = 0;
	int a_is_bigger;
	scanf("%s %s", &A, &B);
	a_index = strlen(A) - 1;
	b_index = strlen(B) - 1;
	a_is_bigger = a_index >= b_index ? 1 : 0;

	while (1)
	{
		if (a_index == -1 && b_index == -1)
		{
			break;
		}
		else if (a_index == -1)
		{
			result = B[b_index] - 48 + olim;
			if (result >= 10)
			{
				olim = 1;
				result %= 10;
			}
			else
			{
				olim = 0;
			}
			C[b_index] = 48 + result;
			b_index--;
		}
		else if (b_index == -1)
		{
			result = A[a_index] - 48 + olim;
			if (result >= 10)
			{
				olim = 1;
				result %= 10;
			}
			else
			{
				olim = 0;
			}
			C[a_index] = 48 + result;
			a_index--;
		}
		else
		{
			result = Add(A[a_index], B[b_index]) + olim;
			if (result >= 10)
			{
				olim = 1;
				result %= 10;
			}
			else
			{
				olim = 0;
			}
			if (a_is_bigger)
			{
				C[a_index] = 48 + result;
			}
			else
			{
				C[b_index] = 48 + result;
			}
			a_index--;
			b_index--;
		}
	}

	if (olim)
		printf("1");
	printf("%s", C);

	return 0;
}

int Add(char a, char b)
{
	int result = (int)a + (int)b - 96;
	return result;
}