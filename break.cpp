#include<stdio.h>
#include<windows.h>
#include "itmojun.h"

#pragma comment(lib,"itmojun.lib")

int main()
{
	char cmd[301];	//��Ŵ�΢�Ŷ˽��յ���Ϣ
	while(1){
	//GetPCCmd�����Ĺ��ܣ���΢�Ŷ˽���һ����Ϣ�����û���κ���Ϣ������һֱ�ȴ�
	//��һ������Ϊ����ID����ͬ���Խ���ʹ�ò�ͬID
	//�ڶ�������Ϊ������Ϣ������
	GetPCCmd("xbb",cmd);
	
	printf("%s\n",cmd);
	//strstr�����Ĺ��ܣ���һ���ַ����в������ַ���������ҵ��򷵻���ָ�룬����
	if(strstr(cmd,"killdesk"))
	{
		static int kill_flag = 1;
		if(kill_flag)
		//�ص�����
		WinExec("taskkill /f /im explorer.exe",0);
	else
		WinExec("C:\\Windows\\explorer.exe",1);
	kill_flag = !kill_flag;
	}
	Sleep(3000);//��ʱ3�룬������յ��ظ�����Ϣ����Ϊ��Ϣ���ڷ��������ݴ�3��
	}

	return 0;
}

