//大数据乘法运算
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BigDataMul(char *num01, char *num02)
{
	int res = 0, i = 0, j = 0;
	int length01 = 0, length02 = 0, totallength = 0;
	if(NULL == num01 || NULL == num02) {
		res = -1;
		return res;
	}
	length01 = strlen(num01);
	length02 = strlen(num02);
	totallength = length01 + length02;
	int *presult = (int *)malloc(sizeof(int) * totallength);
	memset(presult, 0, sizeof(int) * totallength);
	if(NULL == presult) {
		res = -2;
		return res;
	}
	//累乘
	for(i = 0; i < length01; i++)	{
		for(j = 0; j < length02; j++) {
			//将第一位空出来，以防产生进位,注意这个第0位置，表示最高位
			presult[i + j + 1] += (num01[i] - '0') * (num02[j] - '0');
		}
	}
	//累加 倒序
	for(i = totallength - 1; i >= 0; i--) {
		//大于10 表示产生进位
		if(presult[i] >= 10) {
			presult[i-1] += presult[i] / 10;//取出进位
			presult[i] %= 10;//取出个位数
		}
	}
	i = 0;
	//去除前面的0,因为可能没有产生进位，前面的可能是0
	while(0 == presult[i]) {
		i++;
	}
	//可能与0相乘的话，结果全为0
	if(i == totallength + 1) {
		printf("0\n");
		goto IsZero;
	}
	char *plastresult = (char *)malloc(sizeof(char) * totallength);
	memset(plastresult, 0, sizeof(char) * totallength);
	if(NULL == plastresult) {
		res = -2;
		return res;
	}
	for(j = 0; i < totallength; i++, j++) {
		plastresult[j]	= presult[i] + '0';
	}
	for(i = 0; i < totallength; i++) {
		printf("%c",plastresult[i]);
	}
	free(plastresult);
	plastresult = NULL;
IsZero:
	free(presult);
	presult = NULL;
	return res;
}

int main(int argc, char *argv[])
{
	BigDataMul("22222","9");
	return 0;
}
