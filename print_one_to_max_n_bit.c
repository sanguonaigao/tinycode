
//非递归实现

#include<stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool increment(char *num)
{
    bool isoverflow = false;
    int len = strlen(num);
    int take = 0;
    int i = 0;

    for(i = len-1;i>=0;i--)
    {
        int cur_num = num[i] - '0' + take;
        if(i == len-1)
       {
           cur_num++;
       }

        if(cur_num >= 10)
       {
            if(i == 0)
           {
               isoverflow = true;
           }
            else
           {
               cur_num -= 10;
               take = 1;
               num[i] = cur_num + '0';
           }
       }
        else
       {
           num[i] = cur_num+ '0';
            break;
       }
    }
    return isoverflow;
}

void print(const char *num)
{
    bool isbegin0 = false;
    int i = 0;
    int len = strlen(num);
    for( i = 0; i<len; i++ )
    {
        if(!isbegin0 && num[i] != '0' )
           isbegin0 = true;
        if(isbegin0 == true )
       {
           printf( "%c",num[i]);
       }
    }
    printf("\n");
}


int main()
{
    int n = 0;
    scanf("%d",&n);
    char *pnum = malloc(n+1);
    memset(pnum, '0', n);
    pnum[n] = '\0';
    
    if(pnum == NULL)
    {
       printf( "out of memory\n");
       exit(1);
    }
    
    while(!increment(pnum))
    {
       print(pnum);
    }
    return 0;
}


//递归实现

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void print(const char *num)
{
    bool isbegin0 = false;
    int len = strlen(num);
    int i = 0;
    for(i = 0;i<len;i++)
    {
        if(!isbegin0 && num[i] != '0' )
           isbegin0 = true;
        if(isbegin0)
           printf( "%c",num[i]);
    }
    printf("\n");
}

void print1tomaxofn(char *num, int n, int index)
{
    int i = 0;
    if(index == n-1)
    {
       print(num);
        return;
    }

    for(i = 0;i<10;i++)
    {
       num[index+1] = i+ '0';
       print1tomaxofn(num, n, index+1);
    }
}
int main()
{
    int n = 10;
    char *pnum = NULL;
    scanf("%d", &n);
    pnum = malloc(n+1);
    memset(pnum, 0, n);
    pnum[n] = '\0';
    int i = 0;
    for(i = 0; i<10; i++)
    {
       pnum[0] = i + '0';
       print1tomaxofn(pnum, n, 0);
    }

    return 0;
}
  


