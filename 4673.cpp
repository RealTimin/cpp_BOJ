#include <stdio.h>

bool CheckConstructor(int n, int dn);

int main(void)
{
	int dn, i, n; 
	bool isSelf;
	for(dn = 1; dn <= 10000; dn++)
	{
		isSelf = true;
		for(i = 1; i <= 36; i++)
		{
			n = dn - i;
			if(n >= 1 && CheckConstructor(n, dn))
			{
				isSelf = false;
				break;
			}
		}
		
		if(isSelf)
			printf("%d \n", dn);
	}
}

bool CheckConstructor(int n, int dn)
{
	int result = n; 
	int prev_n; 
	while(n != 0)
	{
		prev_n = n;
		n = n / 10;
		result += prev_n - n * 10; 
	}
	return result == dn ? true : false;	
}
