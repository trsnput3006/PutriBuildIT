#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// fungsi buat qsort, urutin dari kecil ke besar
int bandingin(const void *p, const void *q) {
    long long x = *(long long *)p;
    long long y = *(long long *)q;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    // pake malloc soalnya n bisa sampe sejuta, kalo array biasa takut kebesaran
    long long *arr = (long long *) malloc(n * sizeof(long long));

    int i;
    for (i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    // urutin dulu biar yang nilainya sama jadi ketemu bersebelahan
    qsort(arr, n, sizeof(long long), bandingin);

    // total semua pasangan yang mungkin = n*(n-1)/2
    long long total_pasangan = (long long) n * (n - 1) / 2;
    total_pasangan = total_pasangan % MOD;

    // sekarang cari pasangan yang nilainya SAMA, terus nanti dikurangin
    long long pasangan_sama = 0;
    i = 0;
    while (i < n) {
        int j = i;
        // hitung ada berapa banyak angka yang sama beruntun
        while (j < n && arr[j] == arr[i]) {
            j++;
        }
        long long jumlah_sama = j - i; // banyaknya yang sama di grup ini

        // kalo dalam 1 grup ada lebih dari 1 angka yang sama, hitung C(jumlah_sama, 2)
        if (jumlah_sama > 1) {
            long long c = jumlah_sama * (jumlah_sama - 1) / 2;
            c = c % MOD;
            pasangan_sama = (pasangan_sama + c) % MOD;
        }

        i = j; // lanjut ke grup berikutnya
    }

    // jawaban akhirnya = total pasangan - pasangan yang sama
    long long hasil = (total_pasangan - pasangan_sama + MOD) % MOD;

    printf("%lld\n", hasil);

    free(arr);
    return 0;
}