#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
//////////////////////////////////////////////////////////////////////////
char *get_string(char *alloc_str_length_1);
char* get_time(void);
void print_bin_8byte(const unsigned long long num, const int size_t);
void print_bin_4byte(const unsigned int num, const int size_t);
void print_bin(const unsigned long long num, const int size_t, const unsigned int size_group, const bool non_segmentation);
void insert_str(char *string_1, char *string_2, char ch);
int dec_com(int array_dec_3_3);
bool is_prime_num(long long int num);
bool is_letter(char ch);
bool is_num(char ch);
double *hash(const char *name, const double *base, int size, const char *hash_seed);
//////////////////////////////////////////////////////////////////////////
int get_string(char *str)				//stdlib.h
{
    int i = 0;
    char ch = 0;
    while((ch = getchar()) != '\n')
    {
        str[i] = ch;
        i++;
        str = realloc(str, (i + 1) * sizeof(char));
        if (str == NULL)
            return 0;
        str[i] = '\0';
    }
    return i;
}
//////////////////////////////////////////////////////////////////////////
void insert_str(char *s1, char *s2, char ch)	//string.h
{
	int i = 0, start = 0;
	char *p1 = NULL;
	char *p2 = NULL;
	p1 = s1;
	p2 = s2;
	while (*p1 != ch)
	{
		p1++;						/*定位到要插入的字符处*/
		start++;					/*将插入偏移量记为start*/
	}
	p1++;
	start++;
	for (i = strlen(s2);*p1 != '\0';i++, p1++)			/*将要插入的字符后的字符串复制到字符串s2后面*/
	{
		*(s2 + i) = *p1;
	}
	for (;*p2 != '\0';start++, p2++)		/*将字符串s2赋值到要插入的字符后面*/
	{
		*(s1 + start) = *p2;
	}
}
//////////////////////////////////////////////////////////////////////////
char* get_time(void)			//time.h
{
	time_t* ptm = ( time_t) malloc(sizeof(long long));
	time(ptm);
	struct tm* tmpt = localtime(ptm);
	free(ptm);
	ptm = NULL;
	return asctime(tmpt);
}
//////////////////////////////////////////////////////////////////////////
void print_bin_8byte(const unsigned long long num, const size_t size)
{
	unsigned long long flag = 1ULL << (size * 8 - 1);
	int count = 0;
	while(flag != 0)
	{
		printf("%d", 0 != (a & flag));
		flag >>= 1;
		++count;
		if(count % 8 == 0)
			printf(" ");
	}
	printf("\n");
}
void print_bin_4byte(const unsigned long long num, const size_t size)
{
	unsigned int flag = 1U << (size * 8 - 1);
	int count = 0;
	while(flag != 0)
	{
		printf("%d", 0 != (a & flag));
		flag >>= 1;
		++count;
		if(count % 8 == 0)
			printf(" ");
	}
	printf("\n");
}
void print_bin(const unsigned long long num, const size_t size, const unsigned int group, const bool nospace)
{//num为待转换为二进制数的十进制数原形，size为字节宽度，group为二进制分组大小,nospace为是否分组
	unsigned long long flag = 1ULL << (size * 8 - 1);		/*(size * 8)为二进制位数*/
	int count = 0, zero = 0,i = 0;
	while(0 == (num & flag))					/*记1前0的个数*/
	{
		flag >>= 1;
		++count;
	}
	if(nospace)
	{
		zero = count % group;						/*将每组中不足组数的用0补齐*/
		for(i = 0; i < zero; i++)
			printf("0");
	}
	while(flag != 0)
	{
		printf("%d", 0 != (num & flag));
		flag >>= 1;
		++count;
		if(nospace == 0)
			if(count % group == 0)
				printf(" ");
	}
	printf("\n");
}
//////////////////////////////////////////////////////////////////////////
int dec_com(int dec[3][3])
{
	//声明必要变量并初始化
	int i = 0, j = 0, tmp = 0, d = 0;

	//读取行列式
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			scanf(" %d", &det[i][j]);
	//计算行列式
	for (i = 0; i < 3; i++)
	{
		for (j = 0, tmp = 1; j < 3; j++)
		{
			if ((i + j) < 3)
				tmp *= det[j][j + i];
			else
				tmp *= det[j][j + i - 3];
		}
		d += tmp;
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 3 - 1, tmp = 1; j >= 0; j--)
		{
			if ((3 - 1 - j + i) < 3)
				tmp *= det[j][3 - 1 - j + i];
			else
				tmp *= det[j][i - j - 1];
		}
		d -= tmp;
	}
	return d;
}
//////////////////////////////////////////////////////////////////////////
bool is_prime_num(long long int num)	//math.h
{
    int i = 0;
    if (num == 1)
        return false;
    if ((num == 2) || (num == 3))
        return true;
    if ((num % 6 != 1) && (num % 6 != 5))
        return false;
    for (i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
        else
            continue;
    }
    return true;
}
//////////////////////////////////////////////////////////////////////////
bool is_letter(char ch)			//stdbool.h
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return true;
    else
        return false;
}
//////////////////////////////////////////////////////////////////////////
bool is_num(char ch)			//stdbool.h
{
    if (ch >= '0' && ch <= '9')
        return true;
    else
        return false;
}
//////////////////////////////////////////////////////////////////////////
double *hash(const char *name, const double *base, int size, const char *hash_seed)
{
    int i = 0;
    long long int tmp = 0, p3 = 0;
    char p1 = 0, p2 = 0;
    for (i = 0; i < strlen(name); i++)
    {
        p1 = (name[i] & 0xA5) | (hash_seed[i % strlen(hash_seed)] & 0x5A);
        p2 = (name[i] & 0x5A) | (hash_seed[i % strlen(hash_seed)] & 0xA5);
        tmp += ((p1 & 0xF0) | (p2 & 0x0F)) + ((p1 & 0x0F) | (p2 & 0xF0));
        p3 += hash_seed[i % strlen(hash_seed)];
    }
    return (base + (tmp*p3 % size));
}
//////////////////////////////////////////////////////////////////////////