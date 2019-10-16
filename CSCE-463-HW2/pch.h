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
#define DNS_QUERY (0 << 15)
#define DNS_RESPONSE (1 << 15)
#define DNS_STDQUERY (0 << 11)
#define DNS_AA (1 << 10) 
#define DNS_TC (1 << 9)
#define DNS_RD (1 << 8)
#define DNS_RA (1 << 7)

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