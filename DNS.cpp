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
	int pkt_size = strlen(lookup) + 2 + sizeof(FixedDNSheader) + sizeof(QueryHeader);
	buf = new char[pkt_size]; //declare buf size
	FixedDNSheader* fdh = (FixedDNSheader*)buf;
	QueryHeader* qh = (QueryHeader*) (buf + pkt_size - sizeof(QueryHeader));

	//create TXID
	srand(time(NULL));
	USHORT TXID = rand() % USHRT_MAX + 1;

	//fill DNS header
	fdh->ID = htons(TXID);
	fdh->flags = htons(DNS_QUERY | DNS_RD | DNS_STDQUERY);
	fdh->nQuestions = htons(1);
	fdh->nAnswers = htons(0);
	fdh->nAuthority = htons(0); //authority RR
	fdh->nAdditional = htons(0); //additional RR
	
	//fill query header
	qh->qClass = htons(DNS_INET);
	
	string host = string(lookup);
	if (type == 1)
	{
		qh->qType = htons(DNS_A); //fill in query type
		printf("Query\t: %s, type 1, TXID 0x%.4x\nServer\t: %s \n", lookup, TXID, server);
	}
	else
	{
		qh->qType = htons(DNS_PTR); //fill in query type
		host = host + ".in-addr.arpa";
		cout << "Query\t: " << lookup;
		printf(".in-addr.arpa, type 12, TXID 0x%.4x\nServer\t: %s \n", TXID,server);
	}
	cout << fdh << endl;
	//fill in query question
	int i = 0;
	while (host.length() != 0)
	{
		if (host.find_first_of(".") != string::npos) //still have dots in the host
		{

		}
	}
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