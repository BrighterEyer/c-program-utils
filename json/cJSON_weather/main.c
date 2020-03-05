#include<stdio.h>
#include<stdlib.h>
#include"cJSON.h"

void Parse_Str1(void);
void Parse_Str2(void);
void Parse_BJ_Time(void);
void Parse_Weather(void);
void parse_seniverse_weather(void);
void parse_heweather(void);

int main()
{
//    Parse_Str1();
//    Parse_Str2();
//    Parse_BJ_Time();
//    parse_seniverse_weather();
    parse_heweather();
}
//�����ͷ���������ʽ����֪�����ǳ���
void parse_heweather(void)
{
    char heweather_str[] = "{\"HeWeather6\":[{\"basic\":{\"cid\":\"CN101010700\",\"location\":\"��ƽ\",\"parent_city\":\"����\",\"admin_area\":\"����\",\"cnty\":\"�й�\",\"lat\":\"40.21808624\",\"lon\":\"116.23590851\",\"tz\":\"+8.00\"},\"update\":{\"loc\":\"2018-11-21 21:45\",\"utc\":\"2018-11-21 13:45\"},\"status\":\"ok\",\"daily_forecast\":[{\"cond_code_d\":\"100\",\"cond_code_n\":\"100\",\"cond_txt_d\":\"��\",\"cond_txt_n\":\"��\",\"date\":\"2018-11-21\",\"hum\":\"21\",\"mr\":\"16:02\",\"ms\":\"04:27\",\"pcpn\":\"0.0\",\"pop\":\"0\",\"pres\":\"1030\",\"sr\":\"07:08\",\"ss\":\"16:53\",\"tmp_max\":\"9\",\"tmp_min\":\"-3\",\"uv_index\":\"5\",\"vis\":\"10\",\"wind_deg\":\"323\",\"wind_dir\":\"������\",\"wind_sc\":\"1-2\",\"wind_spd\":\"4\"},{\"cond_code_d\":\"100\",\"cond_code_n\":\"101\",\"cond_txt_d\":\"��\",\"cond_txt_n\":\"����\",\"date\":\"2018-11-22\",\"hum\":\"21\",\"mr\":\"16:36\",\"ms\":\"05:33\",\"pcpn\":\"0.0\",\"pop\":\"0\",\"pres\":\"1030\",\"sr\":\"07:09\",\"ss\":\"16:52\",\"tmp_max\":\"8\",\"tmp_min\":\"-4\",\"uv_index\":\"3\",\"vis\":\"20\",\"wind_deg\":\"35\",\"wind_dir\":\"������\",\"wind_sc\":\"1-2\",\"wind_spd\":\"5\"},{\"cond_code_d\":\"101\",\"cond_code_n\":\"100\",\"cond_txt_d\":\"����\",\"cond_txt_n\":\"��\",\"date\":\"2018-11-23\",\"hum\":\"23\",\"mr\":\"17:15\",\"ms\":\"06:41\",\"pcpn\":\"0.0\",\"pop\":\"16\",\"pres\":\"1024\",\"sr\":\"07:10\",\"ss\":\"16:52\",\"tmp_max\":\"7\",\"tmp_min\":\"-2\",\"uv_index\":\"2\",\"vis\":\"20\",\"wind_deg\":\"305\",\"wind_dir\":\"������\",\"wind_sc\":\"1-2\",\"wind_spd\":\"3\"}]}]}";

    cJSON *root;
    cJSON *results;
    cJSON *basic_json, *update_json, *forecast_json;
    cJSON *daily_json;

    int i = 0;
    char *basic_tmp, *update_tmp, *status_tmp, *weather_tmp;
    root = cJSON_Parse(heweather_str);
    if(root)
    {
        results = cJSON_GetObjectItem(root, "HeWeather6");      //HeWeather����Ӧ��ֵ����һ������
        results = cJSON_GetArrayItem(results,0);
        if(results)
        {
            basic_json = cJSON_GetObjectItem(results, "basic");
            if(basic_json)
            {
                basic_tmp = cJSON_GetObjectItem(basic_json, "cid") -> valuestring;
                printf("����ID:%s\n",basic_tmp);
                basic_tmp = cJSON_GetObjectItem(basic_json, "location") -> valuestring;
                printf("�ؼ���:%s\n",basic_tmp);
                basic_tmp = cJSON_GetObjectItem(basic_json, "parent_city") -> valuestring;
                printf("�ؼ���:%s\n",basic_tmp);
                basic_tmp = cJSON_GetObjectItem(basic_json, "admin_area") -> valuestring;
                printf("����ʡ:%s\n",basic_tmp);
                basic_tmp = cJSON_GetObjectItem(basic_json, "lat") -> valuestring;
                printf("γ��:%s\n",basic_tmp);
                basic_tmp = cJSON_GetObjectItem(basic_json, "lon") -> valuestring;
                printf("����:%s\n\n",basic_tmp);
            }
            update_json = cJSON_GetObjectItem(results, "update");
            if(update_json)
            {
                update_tmp = cJSON_GetObjectItem(update_json, "loc") -> valuestring;
                printf("����ʱ��:%s(���ڵ�ʱ��)\n", update_tmp);
                update_tmp = cJSON_GetObjectItem(update_json, "utc") -> valuestring;
                printf("����ʱ��:%s(����ʱ��)\n\n", update_tmp);
            }
            status_tmp = cJSON_GetObjectItem(results, "status") -> valuestring;
            printf("����״̬:%s\n\n", status_tmp);
            daily_json = cJSON_GetObjectItem(results, "daily_forecast");
            if(daily_json)
            {
                for(i = 0; i < 3; i++)
                {
                    forecast_json = cJSON_GetArrayItem(daily_json, i);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "date") -> valuestring;
                    printf("����:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "cond_txt_d") -> valuestring;
                    printf("��������:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "cond_txt_n") -> valuestring;
                    printf("��������:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "tmp_max") -> valuestring;
                    printf("����¶�:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "tmp_min") -> valuestring;
                    printf("����¶�:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "wind_deg") -> valuestring;
                    printf("����Ƕ�:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "wind_dir") -> valuestring;
                    printf("����:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "wind_sc") -> valuestring;
                    printf("����:%s\r\n\n", weather_tmp);
                }
            }
        }
    }
    cJSON_Delete(root);
    cJSON_Delete(results);
    cJSON_Delete(basic_json);
    cJSON_Delete(update_json);
    cJSON_Delete(forecast_json);
    cJSON_Delete(daily_json);
}

//������֪��������
void parse_seniverse_weather(void)
{
    char weather_str[] =
        "{\"results\":[{\"location\":{\"id\":\"WS10730EM8EV\",\"name\":\"����\",\"country\":\"CN\",\"path\":\"����,����,�㶫,�й�\",\"timezone\":\"Asia/Shanghai\",\"timezone_offset\":\"+08:00\"},\"daily\":[{\"date\":\"2018-11-18\",\"text_day\":\"����\",\"code_day\":\"4\",\"text_night\":\"����\",\"code_night\":\"4\",\"high\":\"26\",\"low\":\"20\",\"precip\":\"\",\"wind_direction\":\"�޳�������\",\"wind_direction_degree\":\"\",\"wind_speed\":\"10\",\"wind_scale\":\"2\"},{\"date\":\"2018-11-19\",\"text_day\":\"С��\",\"code_day\":\"13\",\"text_night\":\"С��\",\"code_night\":\"13\",\"high\":\"25\",\"low\":\"20\",\"precip\":\"\",\"wind_direction\":\"�޳�������\",\"wind_direction_degree\":\"\",\"wind_speed\":\"10\",\"wind_scale\":\"2\"},{\"date\":\"2018-11-20\",\"text_day\":\"С��\",\"code_day\":\"13\",\"text_night\":\"С��\",\"code_night\":\"13\",\"high\":\"25\",\"low\":\"21\",\"precip\":\"\",\"wind_direction\":\"�޳�������\",\"wind_direction_degree\":\"\",\"wind_speed\":\"10\",\"wind_scale\":\"2\"}],\"last_update\":\"2018-11-18T11:00:00+08:00\"}]}";
    cJSON *root;
    cJSON *results;
    cJSON *last_update;
    cJSON *loc_json, *daily_json;
    cJSON *forecast_json;
    char *loc_tmp, *weather_tmp, *update_tmp;
    int i = 0;

    root = cJSON_Parse((const char*)weather_str);
    if(root)
    {
//        printf("JSON��ʽ��ȷ:\n%s\n\n",cJSON_Print(root));    //���json�ַ���
        results = cJSON_GetObjectItem(root, "results");
        results = cJSON_GetArrayItem(results,0);
        if(results)
        {
            loc_json = cJSON_GetObjectItem(results, "location");   //�õ�location����Ӧ��ֵ����һ������

            loc_tmp = cJSON_GetObjectItem(loc_json, "id") -> valuestring;
            printf("����ID:%s\n",loc_tmp);
            loc_tmp = cJSON_GetObjectItem(loc_json, "name") -> valuestring;
            printf("��������:%s\n",loc_tmp);
            loc_tmp = cJSON_GetObjectItem(loc_json, "timezone") -> valuestring;
            printf("����ʱ��:%s\n\n",loc_tmp);

            daily_json = cJSON_GetObjectItem(results, "daily");
            if(daily_json)
            {
                for(i = 0; i < 3; i++)
                {
                    forecast_json = cJSON_GetArrayItem(daily_json, i);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "date") -> valuestring;
                    printf("����:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "code_day") -> valuestring;
                    printf("������������:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "code_night") -> valuestring;
                    printf("������������:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "high") -> valuestring;
                    printf("����¶�:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "low") -> valuestring;
                    printf("����¶�:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "wind_direction_degree") -> valuestring;
                    printf("����Ƕ�:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "wind_scale") -> valuestring;
                    printf("����:%s\r\n\n", weather_tmp);
                }
            }
            else
                printf("daily json��ʽ����\r\n");
            last_update = cJSON_GetObjectItem(results, "last_update");
            update_tmp = last_update->valuestring;
            if(last_update)
            {
                printf("����ʱ��:%s\r\n", update_tmp);
            }
        }
        else
        {
            printf("results��ʽ����:%s\r\n", cJSON_GetErrorPtr());
        }
    }
    else
    {
        printf("JSON��ʽ����\r\n");
    }
    cJSON_Delete(root);
    cJSON_Delete(results);
}
void Parse_Weather(void)
{
    /*��֪����json����*/
    char weather_str[] =
        "{\"results\":[{\"location\":{\"id\":\"WX4FBXXFKE4F\",\"name\":\"����\",\"country\":\"CN\",\"path\":\"����,����,�й�\",\"timezone\":\"Asia/Shanghai\",\"timezone_offset\":\"+08:00\"},\"daily\":[{\"date\":\"2018-11-18\",\"text_day\":\"��\",\"code_day\":\"0\",\"text_night\":\"��\",\"code_night\":\"1\",\"high\":\"11\",\"low\":\"-3\",\"precip\":\"\",\"wind_direction\":\"����\",\"wind_direction_degree\":\"315\",\"wind_speed\":\"15\",\"wind_scale\":\"3\"},{\"date\":\"2018-11-19\",\"text_day\":\"��\",\"code_day\":\"0\",\"text_night\":\"��\",\"code_night\":\"1\",\"high\":\"10\",\"low\":\"-3\",\"precip\":\"\",\"wind_direction\":\"��\",\"wind_direction_degree\":\"180\",\"wind_speed\":\"10\",\"wind_scale\":\"2\"},{\"date\":\"2018-11-20\",\"text_day\":\"����\",\"code_day\":\"4\",\"text_night\":\"����\",\"code_night\":\"4\",\"high\":\"10\",\"low\":\"-2\",\"precip\":\"\",\"wind_direction\":\"��\",\"wind_direction_degree\":\"0\",\"wind_speed\":\"10\",\"wind_scale\":\"2\"}],\"last_update\":\"2018-11-18T11:00:00+08:00\"}]}";
    cJSON *root;

    cJSON *results;
    cJSON *last_update;
    cJSON *loc_json, *daily_json;
//    cJSON *today_json, *tomorrow_json, *after_json;
    cJSON *forecast_json;
    int i = 0;
    char *loc_tmp;
    char *weather_tmp;       //ֻʹ��һ�������������ڴ�ʹ��
    char *update_tmp;

    root = cJSON_Parse(weather_str);
    if(root)
    {
        results = cJSON_GetObjectItem(root, "results");
        results = cJSON_GetArrayItem(results,0);
        results = cJSON_Parse(cJSON_Print(results));      //loc_json�ַ���������������
        if(results)
        {
            loc_json = cJSON_GetObjectItem(results, "location");   //�õ�location����Ӧ��ֵ����һ������
            loc_tmp = cJSON_GetObjectItem(loc_json, "id") -> valuestring;
            printf("����ID:%s\r\n",loc_tmp);
            loc_tmp = cJSON_GetObjectItem(loc_json, "name") -> valuestring;
            printf("��������:%s\r\n",loc_tmp);
            loc_tmp = cJSON_GetObjectItem(loc_json, "timezone") -> valuestring;
            printf("����ʱ��:%s\r\n\n",loc_tmp);
            daily_json = cJSON_GetObjectItem(results, "daily");
            if(daily_json)
            {
                for(i = 0; i < 3; i++)
                {
                    forecast_json = cJSON_GetArrayItem(daily_json, i);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "date") -> valuestring;
                    printf("����:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "code_day") -> valuestring;
                    printf("������������:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "code_night") -> valuestring;
                    printf("������������:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "high") -> valuestring;
                    printf("����¶�:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "low") -> valuestring;
                    printf("����¶�:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "wind_direction_degree") -> valuestring;
                    printf("����Ƕ�:%s\r\n", weather_tmp);
                    weather_tmp = cJSON_GetObjectItem(forecast_json, "wind_scale") -> valuestring;
                    printf("����:%s\r\n\n\n", weather_tmp);
                }

                /*
                            today_json = cJSON_GetArrayItem(daily_json, 0);
                            tomorrow_json = cJSON_GetArrayItem(daily_json, 1);
                            after_json = cJSON_GetArrayItem(daily_json, 2);

                            printf("����������json�ַ���:\n%s\r\n",cJSON_Print(today_json));
                            weather_tmp = cJSON_GetObjectItem(today_json, "date") -> valuestring;
                            printf("��������:%s\r\n", weather_tmp);
                            weather_tmp = cJSON_GetObjectItem(today_json, "code_day") -> valuestring;
                            printf("���������������:%s\r\n", weather_tmp);
                            weather_tmp = cJSON_GetObjectItem(today_json, "code_night") -> valuestring;
                            printf("����������������:%s\r\n", weather_tmp);
                            weather_tmp = cJSON_GetObjectItem(today_json, "high") -> valuestring;
                            printf("��������¶�:%s\r\n", weather_tmp);
                            weather_tmp = cJSON_GetObjectItem(today_json, "low") -> valuestring;
                            printf("��������¶�:%s\r\n", weather_tmp);
                            weather_tmp = cJSON_GetObjectItem(today_json, "wind_direction_degree") -> valuestring;
                            printf("�������Ƕ�:%s\r\n", weather_tmp);
                            weather_tmp = cJSON_GetObjectItem(today_json, "wind_scale") -> valuestring;
                            printf("�������:%s\r\n", weather_tmp);

                            printf("����������json�ַ���:\n%s\r\n",cJSON_Print(tomorrow_json));
                            printf("����������json�ַ���:\n%s\r\n",cJSON_Print(after_json));
                */
            }
            last_update = cJSON_GetObjectItem(results, "last_update");
            update_tmp = last_update->valuestring;
            if(last_update)
            {
                printf("������ʱ��:%s\r\n", update_tmp);
            }
        }
    }
    cJSON_Delete(root);
    cJSON_Delete(results);
    printf("�������ݽ����ɹ�\r\n\n");

}


/*
http://api.k780.com:88/?app=life.time&appkey=10003&sign=b59bc3ef6191eb9f747dd4e83c99f2a4&format=json
*/
void Parse_BJ_Time(void)
{
    /*
    {
    	"success": "1",
    	"result": {
    		"timestamp": "1542456793",
    		"datetime_1": "2018-11-17 20:13:13",
    		"datetime_2": "2018��11��17�� 20ʱ13��13��",
    		"week_1": "6",
    		"week_2": "������",
    		"week_3": "����",
    		"week_4": "Saturday"
    	}
    }
    */
    char bj_time_str[] = "{\"success\":\"1\",\"result\":{\"timestamp\":\"1542456793\",\"datetime_1\":\"2018-11-17 20:13:13\",\"datetime_2\":\"2018��11��17�� 20ʱ13��13��\",\"week_1\":\"6\",\"week_2\":\"������\",\"week_3\":\"����\",\"week_4\":\"Saturday\"}}";

    cJSON *root;
    cJSON *result_json;
    char *datetime, *week;

    root = cJSON_Parse(bj_time_str);
    if(root)
    {
        printf("json��ʽ��ȷ:\n%s\n\n", cJSON_Print(root));
        result_json =  cJSON_GetObjectItem(root, "result");  //��ȡresult����Ӧ��ֵ
        if(result_json)
        {
            datetime = cJSON_GetObjectItem(result_json, "datetime_2")->valuestring;
            printf("����ʱ��: %s \r\n", datetime);
            week = cJSON_GetObjectItem(result_json, "week_2")->valuestring;
            printf("����: %s \r\n", week);
        }
    }
    cJSON_Delete(root);
    cJSON_Delete(result_json);
}


void Parse_Str2(void)
{
    /*
    {
    	"location": [{
    			"name": "Faye",
    			"address": "����"
    		},
    		{
    			"name": "Andy",
    			"address": "���"
    		}
    	],
    	"time": "2018-11-17"
    }
    */
    char str2[] = "{\"location\":[{\"name\":\"Faye\",\"address\":\"����\"},{\"name\":\"Andy\",\"address\":\"���\"}],\"time\":\"2018-11-17\"}";

    cJSON *root = 0;
    cJSON *loc_json = 0;
    cJSON *name1_json,*name2_json;
    char *time_str, *str_tmp;

    root = cJSON_Parse(str2);
    if(!root)
        printf("str2 JSON��ʽ����:%s \r\n", cJSON_GetErrorPtr());
    else
    {
        printf("str2 JSON��ʽ��ȷ:\n%s\n",cJSON_Print(root));
        time_str = cJSON_GetObjectItem(root,"time")->valuestring;//time��ֵ��
        printf("time:%s\n", time_str);

        loc_json = cJSON_GetObjectItem(root,"location");
        if(loc_json)
        {
            name1_json = cJSON_GetArrayItem(loc_json,0);        //�����0��Ԫ��
            str_tmp = cJSON_GetObjectItem(name1_json, "name")->valuestring;//name����Ӧ��ֵ
            printf("name1 is : %s \r\n", str_tmp);
            str_tmp = cJSON_GetObjectItem(name1_json, "address")->valuestring;//addr1����Ӧ��ֵ
            printf("addr1 is : %s \r\n", str_tmp);

            name2_json = cJSON_GetArrayItem(loc_json,1);       //�����1��Ԫ��
            str_tmp = cJSON_GetObjectItem(name2_json, "name")->valuestring;
            printf("name2 is : %s \r\n", str_tmp);
            str_tmp = cJSON_GetObjectItem(name2_json, "address")->valuestring;
            printf("addr2 is : %s \r\n", str_tmp);
        }
    }
    cJSON_Delete(loc_json);
}


void Parse_Str1(void)
{
    /*
    {
    	"name": "Andy",      //��ֵ��1
    	"age": 20              //��ֵ��2
    }
    */
    char str1[] = "{\"name\":\"Andy\",\"age\":20}";
    cJSON *str1_json, *str1_name, *str1_age;
    printf("str1:%s\n\n",str1);
    str1_json = cJSON_Parse(str1);   //�ж�json��ʽ�Ƿ���ȷ
    if (!str1_json)
    {
        printf("JSON��ʽ����:%s\n\n", cJSON_GetErrorPtr()); //���json��ʽ������Ϣ
    }
    else
    {
        printf("JSON��ʽ��ȷ:\n%s\n\n",cJSON_Print(str1_json) );
        str1_name = cJSON_GetObjectItem(str1_json, "name"); //��ȡname����Ӧ��ֵ����Ϣ
        if (str1_name->type == cJSON_String)
        {
            printf("����:%s\r\n", str1_name->valuestring);
        }
        str1_age = cJSON_GetObjectItem(str1_json, "age");   //��ȡage����Ӧ��ֵ����Ϣ
        if(str1_age->type==cJSON_Number)
        {
            printf("����:%d\r\n", str1_age->valueint);
        }
        cJSON_Delete(str1_json);//�ͷ��ڴ�
    }

}
