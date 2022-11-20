// K 전자는 필기시험 점수의 80%와 면접시험 점수의 20%를 합산한 총점이 높 은 순으로,
// N명의 지원자 중 M명의 신입직원을 선발 한다. 단, 총점이 같은 동점자는 없다고 가정 한다.
// 각 지원자의 이름과 필기시험, 면접시험 점수가 아래 예시와 같이 주어질 때 M명 합격자의 이름과 최종 점수를 출력하는 프로그램을 작성하시오.
#pragma warning(disable : 4996)
#include <stdio.h>

typedef struct person 
{
    char name[11];
    int test;
    int interview;
    double score; 
}person;

void swap(struct person *p, struct person *q);

int main()
{
    int N, M; 
    person p[100];
    scanf("%d%d", &N, &M); 
    for (int i = 0; i< N; i++) 
    {
        scanf("%s%d%d", p[i].name, &(p[i].test), &(p[i].interview)); 
        p[i].score = 0.8 * p[i].test + 0.2 * p[i].interview; 
    }

    for (int i = 0; i< N; i++) 
    {
        for (person *p2 = p; p2 < p + N - i -1; p2++) 
        {
            if (p2->score < (p2 + 1)->score) 
                swap(p2, p2+1);
        }

    }

    for (int i = 0; i < M; i++) 
    {
        printf("%s %.1lf\n", p[i].name, p[i].score); 
    }
}

void swap(struct person *p, struct person *q) 
{
    person temp;

    temp = *p; 
    *p = *q;
    *q = temp;
}