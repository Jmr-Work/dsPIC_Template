/*******************************************************************************
 System Initialization File

  File Name:
    sys_init.h

  Summary:
    System Initialization.

  Description:
    This file contains source code necessary to initialize the system.
 *******************************************************************************/

#ifdef __COMPILE_WITH_ECLIPSE__
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wattributes"
	#pragma GCC diagnostic ignored "-Wunknown-pragmas"
	#define __prog__
#endif

//Lib
#include <xc.h>

//Project
//?#include "app.h"

//Globals
extern void SYS_Initialize(void);

//Locals
void SOSC_Configuration(void);

