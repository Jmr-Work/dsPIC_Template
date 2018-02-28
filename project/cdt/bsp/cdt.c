/************************************************************************************************************************************/
/** @file		cdt.c
 * 	@brief		eclipse compilation configuration support
 * 	@details	replacement of register map from mcu to enable gcc dev compilation
 *
 *  @target     PIC24FJ256GA705
 *  @board      all
 *
 *  @author     Justin Reina, Firmware Engineer
 *  @created    2/24/18
 *  @last rev   2/24/18
 *
 *
 * 	@notes		x
 *
 * 	@section	Opens
 * 			none current
 *
 * 	@section	Legal Disclaimer
 * 			All contents of this source file and/or any other Misc. Product related source files are the explicit property of
 * 			Misc. Company. Do not distribute. Do not copy.
 */
/************************************************************************************************************************************/
#ifdef _COMPILE_WITH_ECLIPSE_

#include <stdint.h>

//Register Map Support
volatile uint16_t  LATA = 0;
volatile uint16_t  LATB = 0;
volatile uint16_t  LATC = 0;
volatile uint16_t  TRISA = 0;
volatile uint16_t  TRISB = 0;
volatile uint16_t  TRISC = 0;
volatile uint16_t  IOCPDA = 0;
volatile uint16_t  IOCPDB = 0;
volatile uint16_t  IOCPDC = 0;
volatile uint16_t  IOCPUA = 0;
volatile uint16_t  IOCPUB = 0;
volatile uint16_t  IOCPUC = 0;
volatile uint16_t  ODCA = 0;
volatile uint16_t  ODCB = 0;
volatile uint16_t  ODCC = 0;
volatile uint16_t  ANSA = 0;
volatile uint16_t  ANSB = 0;
volatile uint16_t  ANSC = 0;
volatile uint16_t  CLKDIV    = 0;
volatile uint16_t  OSCTUN    = 0;
volatile uint16_t  REFOCONL  = 0;
volatile uint16_t  REFOCONH  = 0;
volatile uint16_t  REFOTRIML = 0;
volatile uint16_t  DCOTUN   = 0;
volatile uint16_t  DCOCON   = 0;
volatile uint16_t  OSCDIV   = 0;
volatile uint16_t  OSCFDIV  = 0;


/************************************************************************************************************************************/
/**	@fcn		void __builtin_write_OSCCONL(uint8_t val)
 *  @brief		placeholder for mplab built-in
 *  @details
 *
 *  @section	Purpose
 *  	mplab's methodology for OSCCONL writes
 *
 *  @param		[in] (uint8_t) val - value to apply
 *
 *  @section	Operation
 *		CF      - no clock failure
 *		NOSC    - FRC
 *		SOSCEN  - disabled
 *		POSCEN  - disabled
 *		CLKLOCK - unlocked
 *		OSWEN   - Switch is Complete
 *		IOLOCK  - not-active
 *
 *  @section	Assembly
 *  	CLR W2
 *		MOV #0x46, W0
 *		MOV #0x57, W1
 *		MOV #0x100, W3
 *		MOV.B W0, [W3]
 *		MOV.B W1, [W3]
 *		MOV.B W2, [W3]
 */
/************************************************************************************************************************************/
void __builtin_write_OSCCONL(uint8_t val) {
	return;
}


#endif /* _COMPILER_USES_ECLIPSE_ */

