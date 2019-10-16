#include "DNS.h"

#pragma pack(push,1) //sets struct padding/alignment to 1 byte
class QueryHeader {
public:
	USHORT qType;
	USHORT qClass;
};
class FixedDNSheader {
public:
	USHORT ID;
	USHORT flags;
	USHORT nQuestions;
	USHORT nAnswers;
	USHORT nAuthority;
	USHORT nAdditional;
};
#pragma pack(pop) //restores old packing

void DNS::constructQuery(char* lookup, char* server, int type)
{
}

void DNS::sendQuery()
{
}

string DNS::reverseIP(char* ip)
{
	int a, b, c, d;
	char ip2[16];
	sscanf_s(ip, "%d.%d.%d.%d", &a, &b, &c, &d);
	sprintf_s(ip2, "%d.%d.%d.%d", d, c, b, a);
	return string(ip2);
}
