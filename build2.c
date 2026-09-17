#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


  #include <stdio.h>

int main() {
    // a = kartu kesava, b = kartu devara, c = kartu shita
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);

    // urutin dulu biar gampang, dari kecil ke besar
    // pake variabel bantu x, y, z
    long long x, y, z, temp;
    x = a;
    y = b;
    z = c;

    // tuker2 manual kayak bubble sort gitu
    if (x > y) {
        temp = x;
        x = y;
        y = temp;
    }
    if (y > z) {
        temp = y;
        y = z;
        z = temp;
    }
    if (x > y) {
        temp = x;
        x = y;
        y = temp;
    }

    // sekarang x <= y <= z (paling kecil, tengah, paling besar)

    // jarak dari yang paling kecil ke tengah
    long long jarak1 = y - x;
    // jarak dari tengah ke yang paling besar
    long long jarak2 = z - y;

    // permainan berhenti pas salah satu jarak ini abis duluan
    long long hasil;
    if (jarak1 < jarak2) {
        hasil = jarak1;
    } else {
        hasil = jarak2;
    }

    printf("%lld\n", hasil);

    return 0;
}  