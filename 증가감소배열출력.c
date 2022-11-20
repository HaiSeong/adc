// 한 자리 양의 정수를 입력 받아 배열 x에 저장한 후, 배열의 원소가 연속적으로 증가하는 구간과 연속적으 로 감소하는 구간으로 나누어,
// 연속적으로 증가하는 구간의 원소들을 모아 하나의 정수로 만들고, 연속적으로 감소하는 구간의 원소들을 모아 하나의 정수로 만들어 출력

#pragma warning(disable : 4996)
#include <stdio.h>

int input(int *p);
int *sel_next(int *p);
int number(int *p, int *q);

int main()
{
    int array[100];

    int N = input(array); 
    int M = 0;

    int *p = array; 
    int *q = 0;

    while (1)
    {
        int *q = sel_next(p); 
        
        printf("%d\n", number(p, q)); 
        p = q; 
        if (*(p + 1) == -1) 
            break;
    }
    

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

int *sel_next(int *p) 
{
    int *temp = p; 

    if (*(temp) < *(temp + 1))
    {
        while (*(temp) < *(temp + 1)) 
        {
            temp++; 
        }
    }
    else if (*(temp) > *(temp + 1))
    {
        while (*(temp) > *(temp + 1)) 
        {
            if (*(temp + 1) == -1) 
                return temp;
            temp++; 
        }
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