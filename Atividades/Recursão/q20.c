#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double exponencialN(double n);

int main(void){

    double n;

    printf("Informe um valor");
    scanf("%lf", &n);

    printf("Fatorial de %.0lf = %0.lf\n", n, exponencialN(n));

    return 0;
}

double exponencialN(double n){

    if(n == 1)
        return 1;

    return pow(n, exponencialN(n - 1));
}