// 정수 N을 입력 받고, 공백을 포함하지 않은 N개의 문자열을 입력 받 아, 각 문자열에 포함된 자음의 수를 세어,
// 자음의 수가 가장 많은 문자열부터 내림차순으로 정렬 한 후 순서대로 문자열을 출력하고, 자음의 수가 같다면, 총 문자의 수가 많은 문자열부터 출력

#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct st{
	char *str; 
	int cnt1; 
	int cnt2; 
};

typedef struct st st;

void swap(st *a, st *b);

int main()
{
	int N;
	char temp[101]; 

	scanf("%d", &N); 
	getchar();

	st *st_array = (st *)malloc(sizeof(st) * N); 
	if (st_array == NULL) 
		return 1;

	for (int i = 0; i < N; i++)
	{
		scanf("%s", temp); 
		st_array[i].str = (char *)malloc(sizeof(char) * (strlen(temp) + 1)); 
		if (st_array[i].str == NULL) 
		{
			for (int j = i - 1; j >= 0; j--) 
				free(st_array[j].str);  
			free(st_array);
		}
		strcpy(st_array[i].str, temp); 
		st_array[i].cnt1 = 0;
		st_array[i].cnt2 = strlen(st_array[i].str); 
		
		for (int j = 0; j < st_array[i].cnt2; j++) 
		{
			char c = st_array[i].str[j];
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') 
				continue;
			else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') 
				continue;
			else
				st_array[i].cnt1 += 1; 
		}
	}

	for (int i = N - 1; i > 0 ; i--) 
	{
		for (int j = 0; j < i ; j++) 
		{
			if (st_array[j].cnt1 < st_array[j+1].cnt1) 
				swap(&(st_array[j]), &(st_array[j + 1])); 
			else if (st_array[j].cnt1 == st_array[j+1].cnt1) 
			{
				if (st_array[j].cnt2 < st_array[j+1].cnt2) 
					swap(&(st_array[j]), &(st_array[j + 1]));
			}
		}
	}

	for (int i = 0; i < N; i++) 
		printf("%s\n", st_array[i].str);


	for (int j = N - 1; j >= 0; j--) 
		free(st_array[j].str);  
	free(st_array);
}

void swap(st *a, st *b) 
{
	st temp;

	temp = *a; 
	*a = *b;
	*b = temp;
}