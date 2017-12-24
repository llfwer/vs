#include "stdafx.h"
#include "�źŴ���.h"

using namespace std;

void signalHandler(int signum)
{
	if (signum == SIGINT)
	{
		cout << "���յ�����ע���ź� SIGINT = " << signum << ".\n";
	}
	else if (signum == SIGILL)
	{
		cout << "���Ƿ�ָ�� SIGILL = " << signum << ".\n";
	}
	else if (signum == SIGFPE)
	{
		cout << "������������㣬����������������Ĳ��� SIGFPE = " << signum << ".\n";
	}
	else if (signum == SIGSEGV)
	{
		cout << "�Ƿ������ڴ� SIGSEGV = " << signum << ".\n";
	}
	else if (signum == SIGTERM)
	{
		cout << "���͵��������ֹ���� SIGTERM = " << signum << ".\n";
	}
	else if (signum == SIGBREAK)
	{
		cout << "Ctrl-Break sequence SIGBREAK = " << signum << ".\n";
	}
	else if (signum == SIGABRT)
	{
		cout << "������쳣��ֹ SIGABRT = " << signum << ".\n";
	}


	// �����ر�
	// ��ֹ���� 

	//exit(signum);
}

void printSignal()
{
	// ע���ź� SIGINT ���źŴ������
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