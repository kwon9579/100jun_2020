#include<stdio.h>
#include<stdlib.h>

int result[40] = { 0 };

void fibonacci(int n)
{
	int current = 1;
	int last = 0;
	result[0] = 0;

	for (int i = 0; i < n; i++)
	{
		last = current;
		current = result[i-1];

		result[i] = current + last;
	}
}


int main(void)
{
	fibonacci(40);
	int T,temp;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &temp);
		if (temp == 0)
		{
			printf("1 0\n");
		}
		else if (temp == 1)
		{
			printf("0 1\n");
		}
		else
		{
			printf("%d %d\n", result[temp - 2], result[temp - 1]);
		}
	}
	return 0;
}