
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

enum state{ VALID, INVALID };

int g_state = VALID;
int strint(const char* str)
{
	long long num = 0;
	g_state = INVALID;

	if (str != NULL && *str != '\0')
	{
		int flag = 1;
		while (isspace(*str))
		{
			str++;
		}
		if (*str == '+')
			str++;
		else if (*str == '-')
		{
			str++;
			flag = -1;
		}
		while (*str)
		{
			if (*str >= '0' && *str <= '9')
			{
				num = num * 10 + flag*(*str - '0');
				if (((flag == 1) && (num> 0x7fffffff)) ||
					((flag == -1) && (num <(signed int)0x80000000)))
				{
					num = 0;
					break;
				}
				str++;
			}
			else
			{
				num = 0;
				break;
			}
		}
		if (*str == '\0')
		{
			g_state = VALID;
		}
	}
	return (int)num;
}
int main()
{
	char *p = "-1212212121212";
	printf("%d\n", strint(p));
	printf("%d\n", g_state);
	printf("%d\n", sizeof(long long));
	system("pause");
	return 0;
}