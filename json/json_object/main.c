#include <stdio.h>
#include <stdlib.h>
#include"cJSON.h"
int main() {
	/*************
	    json�Ľ���
	***************************/
	char data[] = "{\"name\":\"���ں�\",\"age\":20}";
	//json��json����ָ��,json_name�� name�����ָ��,json_age��age�����ָ��
	cJSON *json=0, *json_name=0, *json_age=0;
	//�������ݰ�
	json = cJSON_Parse(data);
	//�������ʧ��
	if (!json) {
		printf("Error Before:", cJSON_GetErrorPtr());
	} else {
		json_age = cJSON_GetObjectItem(json, "age");
		//��������� ����
		if(json_age->type==cJSON_Number) {
			
			printf("����:%d\n", json_age->valueint);
		}
		json_name = cJSON_GetObjectItem(json, "name");
		//��������� �ַ���
		if (json_name->type == cJSON_String) {
			printf("������%s\n", json_name->valuestring);
		}
		//�ͷ��ڴ�
		cJSON_Delete(json);
	}
	/**************************
	    json������
	**********************************/
	cJSON * jsonroot=0;
	char * jsonout=0;
	//�������ڵ����
	jsonroot = cJSON_CreateObject();
	//����ڵ�������ֶ���
	cJSON_AddNumberToObject(jsonroot, "age", 19);
	//����ڵ�����ַ�������
	cJSON_AddStringToObject(jsonroot, "name", "ɽ�");
	//�������ַ���
	jsonout=cJSON_Print(jsonroot);
	printf("%s", jsonout);
	//�ͷ�json����Ŀռ�
	cJSON_Delete(jsonroot);
	//�ͷ�jsonout�Ŀռ�
	free(jsonout);
	system("pause");
	return 0;
}

