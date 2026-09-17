#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    
    int n;
    scanf("%d", &n);

    long long total = 0;
    long long a;

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a);
        total = total + a;
    }

    long long hasil;

    if (total < 0)
    {
        hasil = -total;
    } else {
        hasil = total;
    }

    printf("%lld\n", hasil);
    
    return 0;
}
    