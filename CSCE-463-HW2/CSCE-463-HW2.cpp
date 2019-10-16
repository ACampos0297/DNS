// CSCE-463-HW2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
using namespace std;

int main(int argc, char *argv[])
{
	//verify you have 2 inputs
	if (argc != 3)
	{
		printf("Usage %s [IP or Hostname] [DNS Server IP]\n",argv[0]);
		return 0;
	}
	printf("Lookup\t: %s\n",argv[1]);

	DNS dnsLookup;

	//check if host name or IP
	DWORD IP = inet_addr(argv[1]);
	if (IP==INADDR_NONE)	//type A or 1
	{
		printf("Query\t: %s, type 1, TXID \nServer\t: %s", argv[1], argv[2]);
	}
	else //type PTR or 12
	{
		string queryIP = dnsLookup.reverseIP(argv[1]);	//reverse IP
		cout << "Query\t: "<<queryIP;
		printf(".in-addr.arpa, type 12, TXID \nServer\t: %s \n",argv[2]);
	}
}