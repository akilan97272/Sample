#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	scanf("%s",str);
	int l = strlen(str);
	int res = str[0] - '0';
	for(int i=0 ; i < l;i=i+2){
		if(str[i] == 'A')
			res = res & (str[i] - '0');
		else if(str[i] == 'B')
			res = res | (str[i] - '0');
		else
			res = !(res | (str[i] - '0'));
	}
	printf("%d",res);
	printf("\n")
	return 0;
}

// input : 1COC1C1A0B1