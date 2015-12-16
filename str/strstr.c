/*模拟实现库函数strstr（查找第一次出现的子字符串）*/
char * strstr (const char * str1, const char * str2)
{
        char *cp = (char *) str1;
        char *s1, *s2;

        if ( !*str2 )
            return((char *)str1);

        while (*cp)
        {
                s1 = cp;//查找开始/查找失败源字符串回归
                s2 = (char *) str2;//查找开始/查找失败子字符串回归

                while ( *s1 && *s2 && !(*s1-*s2) )
                        s1++, s2++;

                if (!*s2)//查找成功
                        return(cp);

                cp++;
        }

        return(NULL);

}