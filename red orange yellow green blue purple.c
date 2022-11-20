//공백을 포함하는 두 개의 문자열, 문자열 A와 문자열 B를 입력받고, 입력받은 문자열을 단어로 나누어 동적으로 할당받은 두 개의 2차원 배열(포인터 배열에 연결된 문자 배열)에 각각 저장한 다.
// 단, 포인터 배열의 크기는 단어의 수와 같아야 하며, 포인터 배열에 연결되는 각 문자 배열은 단어의 길이+1의 크기여야 한다.
// 문자열 A에 포함된 두 개의 단어를 합성하여 만들어진 단어가 문자열 B에 포함되어있으면, 문 자열 B에 포함된 단어(합성하여 만들어지는 단어)를 출력한다.
// 출력 순서는 길이가 가장 긴 단어 부터 짧은 단어까지 정렬하여 출력하며, 길이가 같은 단어는 사전 순서상 빠른 단어부터 출력한 다.

#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char a[101], b[101], ** aa = NULL, ** bb = NULL;
	int cnta = 1, cntb = 1; 

	gets(a);
	gets(b); 
	
	for (char* p = a; *p; p++)
		if (*p == ' ') cnta++; 
	for (char* p = b; *p; p++)
		if (*p == ' ') cntb++; 

	aa = (char**)malloc(cnta * sizeof(char*));
	bb = (char**)malloc(cntb * sizeof(char*)); 
	if (aa == NULL || bb == NULL) return -1; 
	char* p = a;
	int len = strlen(a); 

	int index = 0;
	for (int i = 0; i <= len; i++) {
		if (a[i] == ' ' || a[i] == '\0') { 
			a[i] = '\0'; 
			aa[index] = (char*)malloc((strlen(p) + 1) * sizeof(char)); 
			if (aa[index] == NULL) return -1; 
			strcpy(aa[index], p);
			p = p + strlen(p) + 1;
			index++; 
		}
	}
	p = b; len = strlen(b);
	index = 0;
	for (int i = 0; i <= len; i++) {
		if (b[i] == ' ' || b[i] == '\0') {
			b[i] = '\0';
			bb[index] = (char*)malloc((strlen(p) + 1) * sizeof(char));
			if (bb[index] == NULL) return -1; 
			strcpy(bb[index], p);
			p = p + strlen(p) + 1; 
			index++; 
		}
	}

	for (int i = 0; i < cntb - 1; i++) {
		for (int j = 0; j < cntb - 1 - i; j++) {
			if (strlen(bb[j]) < strlen(bb[j + 1])) { 
				char* tmp = bb[j];
				bb[j] = bb[j + 1]; 
				bb[j + 1] = tmp;
			}
			else if (strlen(bb[j]) == strlen(bb[j + 1])) { 
				if (strcmp(bb[j], bb[j + 1]) > 0) { 
					char* tmp = bb[j];
					bb[j] = bb[j + 1]; 
					bb[j + 1] = tmp;
				}
			}
		}
	}
	int cnt = 0, arr[50]; 
	for (int i = 0, l = 0; i < cntb; i++)
	{
		int ck = 1; 
		for (int j = 0; j < cnta; j++)
		{
			if (strncmp(bb[i], aa[j], strlen(aa[j])) == 0)
			{ 
				for (int k = 0; k < cnta; k++)
				{
					if (strcmp(bb[i] + strlen(aa[j]), aa[k]) == 0)
					{ 
						if (j != k)
						{ 
							for (int m = 0; m < l; m++)
							{ 
								if (arr[m] == i)
									ck = 0;
							}
							if (ck) { 
								arr[l] = i; 
								printf("%s\n", bb[arr[l]]);
								l++;
								cnt++; 
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < cnta; i++)
		free(aa[i]); 
	free(aa);
	for (int i = 0; i < cntb; i++)
		free(bb[i]); 
	free(bb);
}
