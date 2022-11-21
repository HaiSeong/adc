
// 한 자리 양의 정수를 계속 입력 받아 배열 x에 저장하고, 정수 M을 입력받아, x[M]부터 값이 연속적으로 증가하는 원소들만 모아 하나의 정수를 만들어 출력

#pragma warning(disable : 4996)
#include <stdio.h>

int input(int *p);
int *sel_next(int *p, int N, int M);
int number(int *p, int *q);

int main()
{
    int array[100];

    int N = input(array); 
    int M;
    scanf("%d", &M); 

    int *q = sel_next(array, N, M); 
    printf("%d\n", number(array + M, q)); 
}


int input(int *p)
{
    int i = 0; 
    int temp; 

    while (1)
    {
        scanf("%d", &temp); 
        *(p+i) = temp; 
        if (*(p+i) == -1) 
            break;
        i++; 
    }
    return i; 
}

int *sel_next(int *p, int N, int M) 
{
    int *temp = p + M; 

    while (*(temp) < *(temp + 1)) 
    {
        temp++; 
    }

    return temp; 
    
}

int number(int *p, int *q)
{
    int sum = 0; 
    for (int *temp = p; temp <= q; temp++) 
    {
        sum *= 10; 
        sum += *temp; 
    }
    return sum; 
}