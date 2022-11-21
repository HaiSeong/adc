// 세종대 수시모집 전형은 2단계로 구성되어 있고, 이 중 2단계 전형에서는 1단 계 점수 70%와 면접 점수 30%를 합산하여 총점이 높은 학생 순으로 신입생을 선발한다.
// 1단계 합격자는 N명이고, 최종 M명의 신입생을 선발하며, 각 지원자의 이름과 1단계 성적, 면접 점수가 아래 예시와 같이 주어질 때 최종 합격자의 이름과 총점을 출력

#pragma warning(disable : 4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct student {
	char *name; 
	int firstStage; 
	int interview; 
	double sum; 
} student;


void swap(student *a, student *b);


int main()
{
	int N, M; 
	char temp[11];
	scanf("%d%d", &N, &M); 

	student *s_array = (student *)malloc(sizeof(student) * N); 
	if (s_array == NULL)
		return -1; 

	for (int i= 0 ; i< N; i++) 
	{
		scanf("%s%d%d", temp, &(s_array[i].firstStage), &(s_array[i].interview)); 
		s_array[i].name = (char *)malloc(sizeof(char) * (strlen(temp) + 1)); 
		if (s_array[i].name  == NULL)
		{
			for (int j = i - 1; j >=0; j--) 
				free(s_array[i].name);
			free(s_array);
			return -1;
		}
		strcpy(s_array[i].name, temp); 

		s_array[i].sum = 0.7 * s_array[i].firstStage + 0.3 * s_array[i].interview; 
	}

	for (int i = N-1; i >0; i--) 
	{
		for (int j = 0; j < i; j++) 
		{
			if (s_array[j].sum < s_array[j+1].sum) 
			{
				swap(&(s_array[j]), &(s_array[j+1]));
			}
		}
	}

	for (int i = 0; i < M; i++) 
	{
		printf("%s %.1lf\n", s_array[i].name, s_array[i].sum);
	}
}

void swap(student *a, student *b)
{
	student temp;

	temp = *a;
	*a = *b;
	*b = temp;
}