
// 문자열에 포함된 부분 문자열을 다른 문자열로 치환
#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>

int main()
{
    char str[101]; 
    char before[11], new[11]; 
    char result[251] = {0, }; 

    gets(str); 
    scanf("%s%s", before, new); 

    int len_str = strlen(str); 
    int len_before = strlen(before); 
    int len_new = strlen(new); 

    int i = 0; 
    
    while (i < len_str) 
    {
        if (i + len_before <= len_str && strncmp(str + i, before, len_before) == 0) 
        {
            strcat(result, new); 
            i += len_before; 
        }
        else 
        {
            strncat(result, str+i, 1); 
            i++; 
        }
    }
    printf("%s\n", result); 
}

