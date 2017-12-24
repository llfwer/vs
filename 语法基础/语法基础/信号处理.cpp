#include "stdafx.h"
#include "信号处理.h"

using namespace std;

void signalHandler(int signum)
{
	if (signum == SIGINT)
	{
		cout << "接收到交互注意信号 SIGINT = " << signum << ".\n";
	}
	else if (signum == SIGILL)
	{
		cout << "检测非法指令 SIGILL = " << signum << ".\n";
	}
	else if (signum == SIGFPE)
	{
		cout << "错误的算术运算，比如除以零或导致溢出的操作 SIGFPE = " << signum << ".\n";
	}
	else if (signum == SIGSEGV)
	{
		cout << "非法访问内存 SIGSEGV = " << signum << ".\n";
	}
	else if (signum == SIGTERM)
	{
		cout << "发送到程序的终止请求 SIGTERM = " << signum << ".\n";
	}
	else if (signum == SIGBREAK)
	{
		cout << "Ctrl-Break sequence SIGBREAK = " << signum << ".\n";
	}
	else if (signum == SIGABRT)
	{
		cout << "程序的异常终止 SIGABRT = " << signum << ".\n";
	}


	// 清理并关闭
	// 终止程序 

	//exit(signum);
}

void printSignal()
{
	// 注册信号 SIGINT 和信号处理程序
	signal(SIGINT, signalHandler);
	signal(SIGILL, signalHandler);
	signal(SIGFPE, signalHandler);
	signal(SIGSEGV, signalHandler);
	signal(SIGTERM, signalHandler);
	signal(SIGBREAK, signalHandler);
	signal(SIGABRT, signalHandler);

	int i = 0;
	while (++i) {
		cout << "Going to sleep...." << endl;
		if (i % 3 == 0) {
			raise(SIGSEGV);
		}
		Sleep(1000);
	}
}