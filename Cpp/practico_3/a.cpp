#include <stdio.h>
int mcd(int a, int b){
    int min = (a < b)? a: b;
    int max = (a >= b)? a: b;
    if (max % min == 0){
        return min;
    }
    int r = max % min;
    return mcd(r, min);
   
}
int rayuela(int n){
    int i = 0;
    if (n-2 < 0 || n-1 < 0){
        return 1;
    }
    return rayuela(n-2) + rayuela(n-1);
}
int main(){

    int h = 1;
    printf("%d\n", rayuela(h));
    printf("%d\n", mcd(45,50));

    return 0;
}