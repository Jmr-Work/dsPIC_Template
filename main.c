/*
 * File:   main.c
 * Author: Justin
 *
 * @section   Opens
 *		ref/stdComments.h
 *		file headers
 *		fcn headers
 *		proper commenting
 *		mcu docs (doc/)
 *		sys_init()
 *		pkg & complete
 *
 * Created on February 27, 2018, 4:22 PM
 */

//Lib
#include <stdlib.h>

//Tool
#include <xc.h>

//Project
#include "bsp/system.h"

volatile int i = 0;
int main(void) {
    
    //Init
    SYS_Initialize();
    
    for(;;) {
        i++;
    }
    
    return EXIT_SUCCESS;
}

