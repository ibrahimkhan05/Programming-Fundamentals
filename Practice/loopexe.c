#include<stdio.h>
int main(){
    int i,j,k;
    printf("Enter a number of rows: ");
    scanf("%d", &k);
    for(i=k;i>=1;i++){
        for(j=0;j<2*k;j++){
            if(j<=k-i+1 && j>=k+i-1){
                printf("*");
            }
            else(" ");
        }
        printf("\n");
    }
    return 0;



}