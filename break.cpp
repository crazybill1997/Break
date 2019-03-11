#include<stdio.h>
#include<windows.h>
#include "itmojun.h"

#pragma comment(lib,"itmojun.lib")

int main()
{
	char cmd[301];	//存放从微信端接收的消息
	while(1){
	//GetPCCmd函数的功能：从微信端接收一条消息，如果没有任何消息，它会一直等待
	//第一个参数为电脑ID，不同电脑建议使用不同ID
	//第二个参数为接收消息的数组
	GetPCCmd("xbb",cmd);
	
	printf("%s\n",cmd);
	//strstr函数的功能，在一个字符串中查找子字符串，如果找到则返回其指针，否则
	if(strstr(cmd,"killdesk"))
	{
		static int kill_flag = 1;
		if(kill_flag)
		//关掉桌面
		WinExec("taskkill /f /im explorer.exe",0);
	else
		WinExec("C:\\Windows\\explorer.exe",1);
	kill_flag = !kill_flag;
	}
	Sleep(3000);//延时3秒，避免接收到重复的消息，因为消息会在服务器上暂存3秒
	}

	return 0;
}

