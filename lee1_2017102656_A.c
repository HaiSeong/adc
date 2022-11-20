
// 5명 학생의 이름과 각 학생의 학번 및 지난학기 평균학점을 입력받는다. 그다 음 찾고자 하는 학생의 이름을 입력하면, 이 학생의 학번과 지난학기 평균학점을 출력

#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>

typedef struct student
{
	char name[10];
	char id[11];
	char grade;
}student;


int main()
{
	student s[5];
	char finding[10];

	for (int i=0; i < 5; i++) 
	{
		scanf("%s", s[i].name); 
		scanf("%s", s[i].id); 
		getchar();
		scanf("%c", &(s[i].grade)); 
	}

	scanf("%s", finding); 

	for (int i=0; i < 5; i++) 
	{
		if (strcmp(finding, s[i].name) == 0) 
		{
			printf(" %s %c\n", s[i].id, s[i].grade); 
			break;
		}
	}
}
