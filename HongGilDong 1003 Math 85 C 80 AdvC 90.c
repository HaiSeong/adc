// 총 N명 학생들의 과목별 점수를 관리하는 프로그램이다. n 번째 학 생에 대해 이름, 학번, 과목 1의 이름 및 점수, 과목 2의 이름 및 점수, ..., 과목 Mn의 이름 및 점 수를 입력 받아 메모리를 동적으로 할당한 구조체에 저장한다.
// Mn은 n 번째 학생이 수강한 과목 의 개수이다. 학생이 수강한 모든 과목 점수에 대한 평균을 구조체 멤버 변수 avg에 저장한다.
// 평균 점수가 가장 높은 학생부터 내림차순으로 정렬 한 후 K를 입력 받아 K 번째 학생의 이름, 학 번, 평균 점수를 출력하고 K 번째 학생의 과목 중 가장 점수가 높은 과목의 이름과 점수를 출력

#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct subject 
{
	char *name; 
	double score; 
}subject;

typedef struct student 
{
	char *name; 
	char id[5]; 
	int numSubject; 
	struct subject *psub; 
	double avg; 
}student;

void input_data(student *L) 
{
	int i, cnt = 0, len, tmpid;
	char input[101], *p, tmpsc, **word;
	double avg = 0;

	gets(input);

	len = strlen(input);
	for (i = 0; i < len; i++) 
	{
		if (input[i] == ' ') 
		{
			cnt++;
		}
	}
	L->numSubject = cnt / 2;
	word = (char **)malloc(sizeof(char *) * (cnt + 1));
	cnt = 0;
	word[cnt++] = input;
	for (i = 0; i < len; i++) 
	{
		if (input[i] == ' ') 
		{
			input[i] = '\0';
			word[cnt++] = &input[i + 1];
		}
	}

	L->name = (char *)malloc(sizeof(char) * (strlen(word[0]) + 1));
	strcpy(L->name, word[0]);
	strcpy(L->id, word[1]);

	L->psub = (subject *)malloc(sizeof(subject) * L->numSubject);

	for (i = 0; i < L->numSubject; i++) 
	{
		L->psub[i].name = (char *)malloc(sizeof(char) * (strlen(word[2 * i + 2]) + 1));
		strcpy(L->psub[i].name, word[2 * i + 2]);
		tmpsc = atoi(word[2 * i + 3]);
		L->psub[i].score = (double)tmpsc;
	}

	for (i = 0; i < L->numSubject; i++) 
	{
		avg += L->psub[i].score;
	}
	L->avg = avg / L->numSubject;
}


int main() 
{
	int n, k, i; 
	student *st, *p, *q, tmpst;
	subject *sp, *max;

	scanf("%d", &n);
	getchar();

	st = (student *)malloc(n * sizeof(student));

	for (i = 0; i < n; i++) 
	{ 
		input_data(&st[i]);
	}

	for (p = st + n; p >= st; p--)  
	{
		for (q = st; q < p - 1; q++) 
		{
			if (q->avg < (q + 1)->avg) 
			{
				tmpst = *q; 
				*q = *(q + 1);
				*(q + 1) = tmpst;
			}
			else if (q->avg == (q + 1)->avg && strcmp(q->id, (q + 1)->id) > 0) 
			{
				tmpst = *q;
				*q = *(q + 1);
				*(q + 1) = tmpst;
			}

		}
	}

	scanf("%d", &k); 
	p = st + k - 1;

	max = p->psub;
	for (sp = p->psub; sp < p->psub + p->numSubject; sp++) 
	{
		if (sp->score > max->score) 
		{
			max = sp;
		}
	}


	printf("%s %s %.2lf %s %.2lf", p->name, p->id, p->avg, max->name, max->score); 

	for (p = st; p < st + n; p++) 
	{
		for (sp = p->psub; sp < p->psub + p->numSubject; sp++) 
		{
			free(sp->name);
		}
		free(p->psub);
		free(p->name);
	}
	free(st);
}