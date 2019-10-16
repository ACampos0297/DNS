#pragma once
#include "pch.h"
using namespace std;

class DNS
{
	char* buf;//request buffer

public:
	void constructQuery(char* ip, char* serverIP, int type);
	void sendQuery();
	string reverseIP(char* ip);
};

