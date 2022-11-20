
// 한 자리 양의 정수를 계속 입력 받아 배열 x에 저장하고, 정수 M을 입력받아, x[M]부터 값이 연속적으로 증가하는 원소들만 모아 하나의 정수를 만들어 출력

#pragma warning(disable : 4996)
#include <stdio.h>

int input(int *p);
int *sel_next(int *p, int N, int M);
int number(int *p, int *q);

int main()
{
    int array[100]; // 100개의 정수배열 생성

    int N = input(array); // 입력함수
    int M;
    scanf("%d", &M); // 입력

    int *q = sel_next(array, N, M); // sel_next 계산
    printf("%d\n", number(array + M, q)); // 출력
}


int input(int *p)
{
    int i = 0; // 원소의 갯수
    int temp; // 임시로 받을 공간

    while (1)
    {
        scanf("%d", &temp); // 입력
        *(p+i) = temp; // 위치에 저장
        if (*(p+i) == -1) // 종료조건
            break;
        i++; // 인덱스 증가
    }
    return i; // 갯수 리턴
}

int *sel_next(int *p, int N, int M) 
{
    int *temp = p + M; // 시작점

    while (*(temp) < *(temp + 1)) // 앞의 원소가 더 작을때 까지
    {
        temp++; // 증가
    }

    return temp; // 리턴
    
}

int number(int *p, int *q)
{
    int sum = 0; // 초기화
    for (int *temp = p; temp <= q; temp++) // 반복문
    {
        sum *= 10; // 자리수 올리기
        sum += *temp; // 1의자리에 더하기
    }
    return sum; // 리턴
}