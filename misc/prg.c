#include<stdio.h>
int main()
{

/*
 char *ptr = "void pointer";
 void *vptr;
 vptr = &ptr;
 printf("%s", *(char **)vptr);

*/
 //char *ptr = "void pointer";
  char str[] = "void pointer";
  char *ptr;
  ptr = str;  // ptr = &str[0];

 void *v1ptr;
 v1ptr = &ptr;

 void **v2ptr;
 v2ptr = &v1ptr;

 printf("%s\n" ,  ptr);
 //printf("%s\n" ,  *ptr);  //This statement causes a crash
 printf("%s\n" ,  *(char **)v1ptr);
 printf("%s\n" ,  **(char ***)v2ptr);

 return 0;
}
