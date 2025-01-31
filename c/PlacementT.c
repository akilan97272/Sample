#include<stdio.h>
void main(){
	int i,j,m,n,res = 0;
	scanf("%d",&m);
	scanf("%d",&n);
	int arr[n][n];
	arr[0][0] = 1;
	printf("%d \n",arr[0][0] = 1);
	for(i = 1 ; i <= n ; i++){
		if(arr[i-1][0] > n)
			break;
		for(j = 0 ; j <= i ; j++){
			if(j == 0){
				arr[i][j] = arr[i-1][i-1];
				if( arr[i][j] > m && arr[i][j] < n && arr[i][j]%2 != 0){
					res = arr[i][j];
				}

			}
			else{
				arr[i][j]=arr[i][j-1]+arr[i-1][j-1];
				printf("%d \t",arr[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n%d\n",res);
}