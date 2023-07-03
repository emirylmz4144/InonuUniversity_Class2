#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//                  --------------ÖNEMLİ-------------
/*
Lütfen programı çalıştırmadan önce visual studio'da gcc varlığı ve lounch.json entagrasyonunu
doğru şekilde yaptığınıza emin olunuz çünki hata alırsanız programdan değil entagrasyon veya extansion 
eksikliğinden hata alabilirsiniz aksi takdirde program birçok online compiler ve ide'de başarılı şekilde çalışmıştır.
*/

/*
                          ÖĞRENCİ BİLGİLERİ
                Ad: Muhammed Emir 
                Soyad : Yılmaz
                Numara: 02220224570
                Bölüm/ Sınıf:  Yazılım mühendisliği/ 2.Sınıf
*/


// Oluşaacak yığını tanımlıyoruz
typedef struct 
{
    int top;
    int capacity;
    int *array;
} stack;

//Yığına özellik ataması yapıyoruz
void initialize(stack *s, int capacity) 
{
    s->capacity = capacity;
    s->top = -1;
    s->array = (int *) malloc(s->capacity * sizeof(int));
}

//Yığın dolumu diye kontol ediyoruz
int is_full(stack *s) 
{
    return s->top == s->capacity - 1;
}

//Yığın boşmu diye kontrol ediyoruz
int is_empty(stack *s)
{
    return s->top == -1;
}

//Yığına eleman gönderiyoruz
void push(stack *s, int data)
{
    if (is_full(s))
    {
        printf("Yigin dolu\n");
        return;
    }
    s->array[++s->top] = data;
}

//Yığındaki son elemanı alıp yığından çıkarıyoruz
int pop(stack *s)
{
    if (is_empty(s)) 
    {
        printf("Yigin bos\n");
        return -1;
    }
    return s->array[s->top--];
}

//Token işlemlerini yapıyoruz
int evaluate(char *expression)
{
    stack s;
    initialize(&s, 100);

    char *token = strtok(expression, " ");
    while (token != NULL)
    {
        if (isdigit(token[0])) // Gelen token boşluk karakterimi
        
        {
            int num = atoi(token);
            push(&s, num);
        } 
        else if (strchr("+-*/", token[0]) != NULL)//Gelen kısım operatör mü
        {
            int op1 = pop(&s);
            int op2 = pop(&s);
            switch (token[0]) {
                case '+':
                    push(&s, op2 + op1);
                    break;
                case '-':
                    push(&s, op2 - op1);
                    break;
                case '*':
                    push(&s, op2 * op1);
                    break;
                case '/':
                    push(&s, op2 / op1);
                    break;
            }
        } else if (token[0] == '(') //Gelen kısım parantez mi
        {
            push(&s, -1);
        } 
        else if (token[0] == ')')//Parantez bitiminde işlemleri yapıyoruz
        {
            int result = 0;
            while (!is_empty(&s) && s.array[s.top] != -1)
            {
                result += pop(&s);
            }
            pop(&s); // discard -1
            push(&s, result);
        }
        token = strtok(NULL, " ");
    }
    int result = 0;
    while (!is_empty(&s)) 
    {
        result += pop(&s);
    }
    return result;
}

int main() {
    char expression[100];
    printf("--------------------UYARILAR----------------------------\n");
    printf("Lutfen kurallara gore islem yapiniz\n");
    printf("Birden cok deneme yapabilmeniz icin program sonsuz dongudedir\n");
    printf("Her tokendan sonra dogru islem icin bir bosluk birakiniz (orn : ( 9 8 - ) 10 + veya 7 ( 4 1 - ) + )\n");
    printf("-------------------------------------------------------------\n");
    while (1)
    {
        printf("----------------------------------\n");
        printf("Lutfen aritmetik bir islem giriniz: ");
        fgets(expression, 100, stdin);
        printf("Dizi adresi: %p\n", expression);
        printf("Dizi: ");
        
        int i;
        for (i= 0; i < strlen(expression); i++) 
        {
            if (expression[i] != '\n') 
            {
                printf("%c ", expression[i]);
            }
        }
        printf("\nSonuc: %d\n", evaluate(expression));
        printf("----------------------------------\n");
    }
    return 0;
}
