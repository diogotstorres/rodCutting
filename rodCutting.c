#include <stdio.h>

int maior(x,y){ //auxiliar
    if (x>=y) return x;
    return y;
}

int hasteMemoizada(int pre[], int n, int nArr){ //Tempo Quadrático
    int memo[n];
    memo[0] = 0;
    for(int i=1; i<=n; i++){

        int maximo = memo[0];

        if(i-1<nArr)
            memo[i] = maximo = pre[i-1];

        for(int j=i-1; j>=ceil(i/2); j--)
            maximo = maior(maximo, memo[j]+memo[i-j]);

        memo[i] = maximo;
    }
    return memo[n];
}

int main(){

    int precos[] = {1,5,8,9,10,17,17,20,24,30};
    int nArr = sizeof(precos)/sizeof(int);
    int n = 1500;

    for(int x=0; x<=n; x++)
        printf("n=%d: %d\n", x, hasteMemoizada(precos, x, nArr));

    return 0;
}
