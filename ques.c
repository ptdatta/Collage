#include <stdio.h>     //2 5

int main()
{
int a[5] = {1,2,3,4,5};
int *ptr = (int*)(&a+1);
printf("%d %d", *(a+1), *(ptr-1));
return 0;
}

// #include <stdio.h>    //  TEST sQuiz Z CQ
// char *c[] = {"PtrsQuiz", "MCQ", "TEST", "QUIZ"};
// char **cp[] = {c+3, c+2, c+1, c};
// char ***cpp = cp;
// int main()
// {
// printf("%s ", **++cpp);
// printf("%s ", *--*++cpp+3);
// printf("%s ", *cpp[-2]+3);
// printf("%s ", cpp[-1][-1]+1);
// return 0;
// }

// #include <stdio.h>        //gh
// #include<stdlib.h>
// void f(char**);
// int main()
// {
// char *argv[] = { "ab", "cd", "ef", "gh", "ij", "kl" };
// f(argv);
// return 0;
// }
// void f(char **p)
// {
// char *t;
// t = (p += sizeof(int))[-1];
// printf("%s\n", t);

// int i;         //0 1 2 2 3
// int *ptr = (int *) malloc(5 * sizeof(int));
// for (i=0; i<5; i++)
// *(ptr + i) = i;
// printf("%d ", *ptr++);
// printf("%d ", (*ptr)++);
// printf("%d ", *ptr);
// printf("%d ", *++ptr);
// printf("%d ", ++*ptr);
// }

// #include <stdio.h>        //19
// int f(int x, int *py, int **ppz) {
// int y, z;
// **ppz += 1;
// z = **ppz;
// *py += 2;
// y = *py;
// x += 3;
// return x + y + z;
// }
// void main(){
// int c, *b, **a;
// c = 4;
// b = &c;
// a = &b;
// printf( "%d", f(c,b,a)); 
// }