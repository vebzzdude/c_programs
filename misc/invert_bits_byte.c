#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	//code
	int T, x = 0, i, j, value;
	scanf("%d", &T);
	
	if (T < 1 || T > 100)
	  return EXIT_FAILURE;
	
	int a[T], b[T];
	
	for (i = 0; i < T; i++)
	{
	    scanf("%d",&a[i]);
	    if (a[i] < 1 || a[i] > 255)
	      return EXIT_FAILURE;
	}

        for (i = 0; i < T; i++)
        {
            b[i] = 0;
        }

	
	for (i = 0; i < T; i++)
	{
	   for (j = 0; j <= 6; j=j+2)
	    {
	       if (a[i] & (3 << j) == (1 << j))
	         b[i] = b[i] | (2 << j);
	       else if (a[i] & (3 << j) == (2 << j))
	         b[i] = b[i] | (1 << j);
	       else if (a[i] & (3 << j) == (3 << j))
	         b[i] = b[i] | (3 << j);
              printf("%d  %d\n", a[i], b[i]);
	    }
	}
	
	for (i = 0; i < T; i++)
	{
	    printf("%d\n", b[i]);
	}
	
	
	return 0;
}
