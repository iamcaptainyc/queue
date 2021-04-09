#include <conio.h>
#include <stdio.h>
int main(void)
{
char buffer[83];
char *p;
/* There's space for 80 characters plus the NULL terminator */
buffer[0] = 81;
printf("Input some chars:");
p=_cgets(buffer);
printf("\ncgets read %d characters: \"%s\"\n", buffer[1], p);
printf("The returned pointer is %p, buffer[0] is at %p\n", p, &buffer);
printf("%s\n",p);
/* Leave room for 5 characters plus the NULL terminator */
buffer[0] = 6;
printf("Input some chars:");
p = _cgets(buffer);
printf("\ncgets read %d characters: \"%s\"\n", buffer[1], p);
printf("The returned pointer is %p, buffer[0] is at %p\n", p, &buffer);
return 0;
}
