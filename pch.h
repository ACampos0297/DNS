/*
	Abdul Campos
	325001471
	HW2
	CSCE 463 - 500
	Fall 2019
*/

// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#pragma once
#pragma comment(lib, "ws2_32.lib")

// flags
#define DNS_QUERY (0 << 15) 
#define DNS_RESPONSE (1 << 15)
#define DNS_STDQUERY (0 << 11) /* opcode - 4 bits */
#define DNS_AA (1 << 10) /* authoritative answer */
#define DNS_TC (1 << 9) /* truncated */
#define DNS_RD (1 << 8) /* recursion desired */
#define DNS_RA (1 << 7) /*recursion available */
#define DNS_A 1 /* name -> IP */
#define DNS_NS 2 /* name server */
#define DNS_CNAME 5 /* canonical name */ 
#define DNS_PTR 12 /* IP -> name */
#define DNS_HINFO 13 /* host info/SOA */
#define DNS_MX 15 /* mail exchange */
#define DNS_AXFR 252 /* request for zone transfer */
#define DNS_ANY 255 /* all records */ 
#define DNS_INET 1 /*DNS class*/

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here

#include <stdio.h>
#include <windows.h>
#include <string>
#include <iostream>
#include <ctime>
#include <stdio.h>

#include "DNS.h"

#endif //PCH_H