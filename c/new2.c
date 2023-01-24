#include<stdio.h>
#include<string.h>
void strreplace(char string[], char search[], char replace[]) {
    char buffer[100];
    char *p = string;

    while ((p = strstr(p, search))) {
        printf("%s\n",p);
        strncpy(buffer, string, p-string);
        printf("%s\n",buffer);
        buffer[p-string] = '\0'; //EDIT: THIS WAS MISSING
        strcat(buffer, replace);
        printf("%s\n",buffer);
        strcat(buffer, p+strlen(search));
        printf("%s\n",buffer);
        strcpy(string, buffer);
        printf("%s\n",buffer);
        p++;
    }
} 
int main(){
char str[100]="Ram is a good boy. Ram is a bad boy";
char str2[100]="Ram";
char str3[100]="Shyam";
strreplace(str,str2,str3);
printf(str);
return 0; }