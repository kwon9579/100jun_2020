#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct building
{
	int prev_num[1000];
	int cur_num;
	int time;
	struct building* next;
};

struct building *head = 0;

void addbuilding(int build_num, int build_time)
{
	struct building *new_one = (struct building *)malloc(sizeof(struct building));
	new_one->cur_num = build_num;
	for (int i = 0; i < 1000; i++)
	{
		new_one->prev_num[i] = 0;
	}
	new_one->time = build_time;
	new_one->next = 0;

	struct building* temp = head;
	if (head == 0)
	{
		head = new_one;
	}
	else
	{
		while (temp->next != 0)
		{
			temp = temp->next;
		}
		temp->next = new_one;
	}
}

void addrule(int prev, int cur)
{
	struct building* temp = head;
	
	for (int i = 1; i <= cur; i++)
	{
		temp = temp->next;
	}
	for (int j = 0; j < 1000; j++)
	{
		if (temp->prev_num[j] == 0)
		{
			temp->prev_num[j] = prev;
			break;
		}
	}
}
void showtime(int result_num)
{
	int time=0;

	printf("%d", time);
}

int main(void)
{
	int T;
	int b_sum, bur_num;
	int build_time;
	int prev_num, cur_num;
	int result;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &b_sum, &bur_num);
		for (int k = 1; k <= bur_num; k++)
		{
			scanf("%d", &build_time);
			addbuilding(k, build_time);
		}
		for (int j = 0; j < b_sum; j++)
		{
			scanf("%d %d",&prev_num,&cur_num);
			addrule(prev_num, cur_num);
		}
		scanf("%d", &result);
		showtime(result);
	}
}