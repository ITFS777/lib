#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
//////////////////////////////////////////////////////////////////////////
char *get_string(char *alloc_str_length_1);
char *get_time(void);
void insert_str(char *string_1, char *string_2, char ch);
int dec_com(int array_dec_3_3);
bool is_prime_num(long long int num);
bool is_letter(char ch);
bool is_num(char ch);
void *hash(const char *name, const void *base, int size, const char *hash_salt);
//////////////////////////////////////////////////////////////////////////
int get_string(char *str)
{ /* 将读取的字符串保存在str中,并返回字符串长度,需包含strlib.h */
	int i = 0;
	char ch = 0;
	while ((ch = getchar()) != '\n')
	{
		str[i++] = ch;
		str = realloc(str, (i + 1) * sizeof(char));
		if (str == NULL)
			return 0;
		str[i] = '\0';
	}
	return i;
}
//////////////////////////////////////////////////////////////////////////
void insert_str(char *s1, char *s2, char ch)
{ /* 将字符串s2插入到字符串s1的第一个字符ch后 */
	int i = 0, start = 0, length = 0;
	while (s2[length++] != '\0')
		;
	length--;
	char *p1 = NULL, *p2 = NULL;
	p1 = s1;
	p2 = s2;
	while (*p1 != ch)
	{
		p1++;	 /*定位到要插入的字符处*/
		start++; /*将插入偏移量记为start*/
	}
	p1++;
	start++;
	for (i = length; *p1 != '\0'; i++, p1++) /*将要插入的字符后的字符串复制到字符串s2后面*/
		*(s2 + i) = *p1;
	for (; *p2 != '\0'; start++, p2++)       /*将字符串s2赋值到要插入的字符后面*/
		*(s1 + start) = *p2;
}
//////////////////////////////////////////////////////////////////////////
char *get_time(void)
{ /* 返回当前时间的GMT格式字符串,需包含time.h */
	time_t *ptm = (time_t)malloc(sizeof(long long));
	time(ptm);
	struct tm *tmpt = localtime(ptm);
	free(ptm);
	ptm = NULL;
	return asctime(tmpt);
}
//////////////////////////////////////////////////////////////////////////
int dec_com(int dec[3][3])
{ /* 计算3x3矩阵的行列式 */
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
bool is_prime_num(long long int num) 
{ /* 判断给定整数是否是素数,需包含math.h */
	int i = 0;
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
bool is_letter(char ch) 
{ /* 判断指定字符是否是字母,需包含stdbool.h */
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return true;
	else
		return false;
}
//////////////////////////////////////////////////////////////////////////
bool is_num(char ch)
{ /* 判断指定字符是否是数字,需包含stdbool.h */
	if (ch >= '0' && ch <= '9')
		return true;
	else
		return false;
}
//////////////////////////////////////////////////////////////////////////
void *hash(const char *name, const void *base, int size, const char *hash_salt)
{ /* 给定hash_salt、散列基址和散列空间大小后,将目的字符串name转换成void类型散列地址 */
	int i = 0;
	long long int tmp = 0, p3 = 0;
	char p1 = 0, p2 = 0;
	for (i = 0; i < strlen(name); i++)
	{
		p1 = (name[i] & 0xA5) | (hash_salt[i % strlen(hash_salt)] & 0x5A);
		p2 = (name[i] & 0x5A) | (hash_salt[i % strlen(hash_salt)] & 0xA5);
		tmp += ((p1 & 0xF0) | (p2 & 0x0F)) + ((p1 & 0x0F) | (p2 & 0xF0));
		p3 += hash_salt[i % strlen(hash_salt)];
	}
	return (base + (tmp * p3 % size));
}
//////////////////////////////////////////////////////////////////////////