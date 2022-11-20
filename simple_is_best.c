

// 공백을 포함하는 알파벳 소문자로된 하나의 문장을 입력받고, 이를 단어 단위로 분리한 후 이를 다시 영어 사전순으로 정렬

#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>

int main()
{
	char strs[20][200];
	char temp[201]; 

	gets(temp); 
	int index = 0; 
	int i = 0; 
	while (temp[index] != '\0')
	{
		int j = 0; 
		while (temp[index] != ' ' && temp[index] != '\0')
		{
			strs[i][j] = temp[index]; 
			j++; 
			index++; 
		}
		if (j > 0) 
		{
			strs[i][j] = '\0'; 
			i++; 
		}
		else
			index++;
	}
	int cnt = i; 
	for (i = 0; i < cnt; i++)
	{
		printf("%s\n", strs[i]); 
	}

	for (i = cnt - 1; i >= 0; i--) 
	{
		for (int j = 0; j < i; j++) 
		{
			if (strcmp(strs[j], strs[j+1]) > 0)
			{
				strcpy(temp, strs[j]); 
				strcpy(strs[j], strs[j+1]);
				strcpy(strs[j+1], temp);
			}
		}
	}

	for (i = 0; i < cnt; i++)
	{
		printf("%s ", strs[i]); 
	}

}