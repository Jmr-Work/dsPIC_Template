/************************************************************************************************************************************/
/** @file		main.c
 * 	@brief		x
 * 	@details	x
 *
 *  @target     dsPIC33EP512GM710
 *  @board      dsPIC33EP512GM710 Module, Explorer 16/32 Board
 *
 *  @author     Justin Reina, Firmware Engineer, Misc. Company
 *  @created    2/28/18
 *  @last rev   2/28/18
 *
 *
 * 	@notes		x
 *
 * 	@section	Opens
 *		fcn headers
 *		proper commenting
 *		mcu docs (doc/)
 *		sys_init()
 *		pkg & complete
 *		depr opens ('//?')
 *
 * 	@section	Legal Disclaimer
 * 			All contents of this source file and/or any other related source files are the explicit property of
 * 			Justin Reina. Do not distribute. Do not copy.
 */
/************************************************************************************************************************************/

//Lib
#include <stdlib.h>

//Tool
#include <xc.h>

//Project
#include "bsp/system.h"


/************************************************************************************************************************************/
/**	@fcn		int main(void)
 *  @brief		x
 *  @details	x
 */
/************************************************************************************************************************************/
int main(void) {
    
    //Init
    SYS_Initialize();
    
    return EXIT_SUCCESS;
}

