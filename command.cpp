
#include <command.h>

int parseHex(char *s)
{
	if(!*s)
		return 0;

	if(*s++ != '0')
		return 0;
			
	if(*s++ != 'x')
		return 0;

	int mult = 1;
	int sum = 0;

	char c;

	while(c=*s++)
	{
		if((c >= '0') && (c <='9'))
		{
			c -= '0';
		}
		else if((c >= 'a') && (c <= 'f'))
		{
			c += 10 - 'a';
		}
		else if((c >= 'A') && (c <= 'F'))
		{
			c += 10 - 'A';
		}
		else
		{
			return 0;
		}

		sum *= 0x10;
		sum += c;
	}

	return sum;
}
