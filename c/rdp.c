#include <stdio.h>
#include<string.h>
char string[10];
int ind = 0;
void A()
{
	if(string[ind]== &#39;a&#39;){
 		ind++;
		if(string[ind]== &#39;b&#39;)
			ind++;
		else{
			printf("Not matched.");
			exit(0);
		}
	}
	else{
		if(string[ind] == &#39;e&#39;)
			ind++;
		else{
			printf("Notmatched.");
			exit(0);
 		}
	}
}
void S(){
	if(string[ind]== &#39;c&#39;)
 		ind++;
	else{
 		printf("Not matched.");
		exit(0);
	}
	A();

	if(string[ind]== &#39;d&#39;)
		ind++;
	else{
		printf("Not matched.");
		exit(0);
	}
}
void main()
{
	printf("Production:\nS-&gt;cAd\nA-&gt;ab|e\n");
	printf("Enter string to parse: ");
	scanf("%s",string);
	S();
	if(strlen(string)== ind)	printf("String matched.");
	else	 printf("String not matched.");
}
