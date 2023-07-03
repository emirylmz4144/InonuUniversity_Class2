#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Bilgilendirmeler

Ad: Muhammed Emir Yýlmaz
Bölüm : Yazýlým Mühendisliði
No: 02220224570

Program sanal derleyiciler ve yerel ideler ile test edilmiþtir lütfen bir sorunla karþýlaþýrsanýz
kopyalama hatasý yaptýðýn mý diye kontrol ediniz yada online compilerda deneyiniz..
*/

int main() {
    char input[100];
    char type[10];
    int size;

    // Kullanýcýdan dizi tipi ve boyutu isteniyor.
    
    
    printf("Dizi tipi ve boyutunu girin (ornek: double y[10]): ");
    fgets(input, 100, stdin);

    // Verilen girdi parse ediliyor.
    sscanf(input, "%s %*c %*c %d", type, &size);

    // Kabul edilen veri tiplerini kontrol ediyoruz.
    if (strcmp(type, "int") != 0 && strcmp(type, "double") != 0 && strcmp(type, "char") != 0 && strcmp(type, "long") && strcmp(type, "float") != 0) {
        printf("Hata: Geçersiz veri tipi girdiniz lütfen kabul edilen veri tiplerinden giriniz\n");
        return 0;
    }

    // Bellekte dizi için yer ayrýlýyor.
    void* arr = malloc(size * sizeof(type));

    // Dizi veri yapýsý için gerekli bilgiler yazdýrýlýyor.
    printf("Dizi:\nEleman Tipi: %s\nIndeks Tipi: int\nIndeks Alt Siniri: 0\nIndeks Ust Siniri: %d\n", type, size - 1);

    // Dizinin bellek adresi yazdýrýlýyor.
    printf("Bellek Adresi: %p\n\n", arr);

    // Dizinin elemanlarýna deðer atanýyor.
    int i;
    for (i = 0; i < size; i++) {
        printf("Dizinin %d. elemani: ", i);
        if (strcmp(type, "char") == 0) {
            scanf(" %c", (char*)arr + i * sizeof(char));
        } else if (strcmp(type, "int") == 0) {
            scanf("%d", (int*)((char*)arr + i * sizeof(int)));
        } else if (strcmp(type, "float") == 0) {
            scanf("%f", (float*)((char*)arr + i * sizeof(float)));
        } else if (strcmp(type, "double") == 0) {
            scanf("%lf", (double*)((char*)arr + i * sizeof(double)));
        }
    }

    int index;

    // Kullanýcýdan dizinin hangi elemanýna eriþmek istediði isteniyor.
    printf("Dizinin hangi elemanina erismek istersiniz? (0-%d arasinda bir tam sayi giriniz): ", size - 1);
    scanf("%d", &index);

    // Ofset deðeri hesaplanýyor ve yazdýrýlýyor.
    printf("Dizideki ofset degeri: %ld\n", (long)((char*)arr + index * sizeof(type)) - (long)arr);

    free(arr);  // Bellek iade ediliyor.

    return 0;
}
