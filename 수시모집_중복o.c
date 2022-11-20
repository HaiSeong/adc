// 세종대 수시모집 전형은 2단계로 구성되어 있고, 이 중 2단계 전형에서는 1 단계 점수 70%와 면접 점수 30%를 합산하여 총점이 높은 학생 순으로 신입생을 선발한다.
// 1단계 합격자는 N명이고, 최종 M명의 신입생을 선발하며, 각 지원자의 이름과 1단계 성적, 면접 점수가 아래 예시와 같이 주어질 때 최종 합격자의 이름과 1단계 점수, 면접 점수, 총점을 출력하고, 최종 합격자의 수도 출력
// 총점이 같은 동점자가 있으면, 1단계 점수가 더 높은 사람을 선발하고, 1단계 점수가 높은 사 람을 먼저 출력한다.
// M명 이내의 합격자와 총점 및 1단계 점수가 모두 같은 동점자도 합격자로 선발하고, 이름이 사전 순서상 빠른 사람을 먼저 출력한다. (이름까지 같은 동점자는 없으며, 대문자 Z가 소문자 a보다 먼저 나온다고 가정)

#pragma warning(disable : 4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct student
{
    char *name;
    int firstStage;
    int interview;
    double sum; //
} st; 
int main(void)
{
    int n, m;
    st *srr; 
    st swap; 
    char tmp[11]; 
    int ex;

    scanf("%d %d",&n,&m); 

    srr = (st *) malloc(sizeof(st) * n); 

    for(int i=0; i<n; i++)
    {
        scanf("%s %d %d",tmp, &srr[i].firstStage, &srr[i].interview);
        srr[i].name = (char *)malloc(sizeof(char) * (strlen(tmp)+1)); 
        strcpy(srr[i].name, tmp); 
        srr[i].sum = srr[i].firstStage * 7 + srr[i].interview * 3; 
    }

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++) 
        {
            if(srr[i].sum < srr[j].sum) 
            {
                swap = srr[i];
                srr[i] = srr[j]; 
                srr[j] = swap;
            }
            else if(srr[i].sum == srr[j].sum) 
            {
                if(srr[i].firstStage < srr[j].firstStage) 
                {
                    swap = srr[i];
                    srr[i] = srr[j]; 
                    srr[j] = swap;
                }
                else if(srr[i].firstStage == srr[j].firstStage) 
                {
                    if(strcmp(srr[i].name, srr[j].name) > 0) 
                    {
                        swap = srr[i];
                        srr[i] = srr[j]; 
                        srr[j] = swap;
                    }
                }
            }
        } 
    }
    
    ex = 0; 
    for(int i=m; i<n; i++) 
    {
        if(srr[m-1].sum == srr[i].sum && srr[m-1].firstStage == srr[i].firstStage) 
        {
            ex++; 
        }
    }
    m+=ex; 

    for(int i=0; i<m; i++) 
    {
        printf("%s %d %d %.1lf\n",srr[i].name, srr[i].firstStage, srr[i].interview, srr[i].sum/10.0); 
    }
    printf("%d",m);

    for(int i=0; i<n; i++)
    {
        free(srr[i].name); 
    }
    free(srr); 

    
    return 0;
}