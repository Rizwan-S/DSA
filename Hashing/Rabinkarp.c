
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char text[100], pattern[100];
	scanf("%s %s", text, pattern);
	int mul = 10, textlength = strlen(text), patternlength = strlen(pattern), pc = (pattern[0] - '0'), tc = (text[0] - '0'), i, j, p = 14821;
	for(i = 1; i < patternlength; i++)
	{
		pc = (10 * pc) + (pattern[i] - '0') % p;
		tc = (10 * tc) + (text[i] - '0') % p;
		mul *= 10;
	}
	if(pc == tc)
	{
		for(j = 0; j < patternlength; j++)
		{
			if(pattern[i] != text[i + j])
			{
				break;
			}
		}
		if(i == patternlength)
		{
			printf("They match at 0\n");
		}
	}

	for(i = 1; i <= textlength - patternlength; i++)
	{
		tc = (tc * 10 + (text[i + patternlength - 1] - '0') - mul * (text[i - 1] - '0')) % p;
		if ( tc < 0)
       	{
       	    tc = tc + p;
       	}
       	if (tc == pc)
	    {
	        for (j = 0; j < patternlength; j++)
	        {
	            if (pattern[j] != text[i + j])
	            {
	                break;
	            }
	        }
	        if (j == patternlength)
	        {
                printf("They match at %d\n", i);
            }
	    }
	}
	return 0;
}
