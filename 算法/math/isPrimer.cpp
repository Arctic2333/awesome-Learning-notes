#include <stdio.h>
#include <math.h>

bool isPrimer(int n){
    if(n == 2) 
        return true;
    else if(n < 2 ) 
        return false;
    else
        for(register int i =2; i <= sqrt(n);i++)
            if(n % i == 0)
                return false;
    return true;
}

int main(){
    int n;
    scanf("%d",&n);
    if(isPrimer(n) == 1){
        printf("true");
    }
    else
    {
        printf("false");
    }
    
    return 0;
}