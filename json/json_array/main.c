#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cJSON.h"
#define MAX_LINE 1024*5 


int main() {

	char buf[MAX_LINE];  /*������*/
	FILE *fp;            /*�ļ�ָ��*/
	int len;             /*���ַ�����*/
	if((fp = fopen("test.json","r")) == NULL) {
		perror("fail to read");
		exit (1) ;
	}
	while(fgets(buf,MAX_LINE,fp) != NULL) {
		len = strlen(buf);
		buf[len-1] = '\0';  /*ȥ�����з�*/
		printf("%s %d \n",buf,len - 1);
	}

	//��char* ģ��һ��JSON�ַ���
	char* json_string;
	strcpy(json_string,buf);


	//��һ�����JSON�ַ���
	cJSON * cjson = cJSON_Parse(json_string);

	//�ж��Ƿ����ɹ�
	if (cjson == NULL) {
		printf("cjson error��");
	} else { //����ɹ�����cJSON_Print��ӡ���
		cJSON_Print(cjson);
	}

	//��ȡ�������
	cJSON* test_arr = (cJSON*)cJSON_GetObjectItemCaseSensitive(cjson, "test_arr");

	//��ȡ��������������ѭ��
	int arr_size = cJSON_GetArraySize(test_arr);//return arr_size 2

	//��ȡtest_arr��������ӽڵ�
	cJSON* arr_item = test_arr->child;//�Ӷ���

	//ѭ����ȡ������ÿ���ֶε�ֵ��ʹ��cJSON_Print��ӡ
	int i;
	for ( i = 0; i <= (arr_size - 1); ++i) {
		cJSON_Print(cJSON_GetObjectItem(arr_item, "test_1"));
		cJSON_Print(cJSON_GetObjectItem(arr_item, "test_2"));
		cJSON_Print(cJSON_GetObjectItem(arr_item, "test_3"));
		arr_item = arr_item->next;//��һ���Ӷ���
	}

	//delete cjson ����ֻ��Ҫ�ͷ�cjson���ɣ���Ϊ�����Ķ�ָ����
	cJSON_Delete(cjson);
}
