/************************************************************************************************************************************/
/** @file		system.c
 * 	@brief		System Initialization
 * 	@details	This file contains source code necessary to initialize the system
 *
 *  @target     dsPIC33EP512GM710
 *  @board      Explorer 16/32 Development Board
 *
 *  @author     Justin Reina, Firmware Engineer
 *  @created    2/27/18
 *  @last rev   2/28/18
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
#include "system.h"


//**********************************************************************************************************************************//
//													CONFIGURATION BITS																//
//**********************************************************************************************************************************//
// FICD
#pragma config ICS = PGD1               /* ICD Communication Channel Select bits (Communicate on PGEC1 and PGED1)					*/
#pragma config JTAGEN = OFF             /* JTAG Enable bit (JTAG is disabled) 														*/

// FPOR
#pragma config BOREN = ON               /* Brown-out Reset (BOR) Detection Enable bit (BOR is enabled) 								*/
#pragma config ALTI2C1 = OFF            /* Alternate I2C1 pins (I2C1 mapped to SDA1/SCL1 pins) 										*/
#pragma config ALTI2C2 = OFF            /* Alternate I2C2 pins (I2C2 mapped to SDA2/SCL2 pins) 										*/
#pragma config WDTWIN = WIN25           /* Watchdog Window Select bits (WDT Window is 25% of WDT period) 							*/

// FWDT
#pragma config WDTPOST = PS32768        /* Watchdog Timer Postscaler bits (1:32,768) 												*/
#pragma config WDTPRE = PR128           /* Watchdog Timer Prescaler bit (1:128) 													*/
#pragma config PLLKEN = ON              /* PLL Lock Enable bit (Clock switch to PLL src will wait until the PLL lock sig is valid.) */
#pragma config WINDIS = OFF             /* Watchdog Timer Window Enable bit (Watchdog Timer in Non-Window mode) 					*/
#pragma config FWDTEN = OFF             /* Watchdog Timer Enable bit (Watchdog timer enabled/disabled by user software) 			*/

// FOSC
#pragma config POSCMD = XT              /* Primary Oscillator Mode Select bits (XT Crystal Oscillator Mode) 						*/
#pragma config OSCIOFNC = ON            /* OSC2 Pin Function bit (OSC2 is general purpose digital I/O pin) 							*/
#pragma config IOL1WAY = ON             /* Peripheral pin select configuration (Allow only one reconfiguration) 					*/
#pragma config FCKSM = CSDCMD           /* Clock Switching Mode bits (Both Clock switching and Fail-safe Clock Monitor are disabled)*/

// FOSCSEL
#pragma config FNOSC = FRC              /* Oscillator Source Selection (Internal Fast RC (FRC)) 									*/
#pragma config PWMLOCK = ON             /* PWM Lock Enable bit (Certain PWM registers may only be written after key sequence) 		*/
#pragma config IESO = OFF               /* Two-speed Oscillator Start-up Enable bit (Start up with user-selected oscillator source) */

// FGS
#pragma config GWRP = OFF               /* General Segment Write-Protect bit (General Segment may be written) 						*/
#pragma config GCP = OFF                /* General Segment Code-Protect bit (General Segment Code protect is Disabled) 				*/


//Locals
void SOSC_Configuration ( void ) ;
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _OscillatorFail ( void ) ;
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _AddressError ( void ) ;
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _StackError ( void ) ;
void __attribute__ ( ( __interrupt__ , auto_psv ) ) _MathError ( void ) ;


/************************************************************************************************************************************/
/**	@fcn		void SYS_Initialize(void)
 *  @brief		Initializes the Explorer 16 board peripherals
 *  @details	This routine initializes the Explorer 16 board peripherals for the demo. In a bare-metal environment (where no OS
 *  			is supported), this routine should be called almost immediately after entering the "main" routine.
 *
 *  @pre		The C-language run-time environment and stack must have been initialized
 *
 *  @section	Opens
 *  	re-enable disabled ('//?') sections
 *
 *  @section    Basic System Initialization Sequence
 *    1.  Initialize minimal board services and processor-specific items (enough to use the board to initialize drivers and services)
 *    2.  Initialize all supported system services
 *    3.  Initialize all supported modules (libraries, drivers, middleware, and application-level modules)
 *    4.  Initialize the main (static) application, if present.
 *
 *    @note 	The order in which services and modules are initialized and started may be important.
 */
/************************************************************************************************************************************/
void SYS_Initialize(void) {
 	/* Enable LEDs*/
//X    LED_Enable ( LED_D9 ) ;
//X    LED_Enable ( LED_D10 ) ;

    /* Turn On LEDs*/
//X    LED_On ( LED_D9 ) ;
//X    LED_On ( LED_D10 ) ;

    /* Enable Switch S3*/
//X    BUTTON_Enable ( BUTTON_S3 ) ;

    /* Enable ADC to the Potentiometer channel */ 
     
//X    ADC_ChannelEnable ( ADC_CHANNEL_POTENTIOMETER ) ;


    /* Initialize LCD*/
//X    PRINT_SetConfiguration ( PRINT_CONFIGURATION_LCD ) ;

    /* Configure Secondary Oscillator for Timer 1 to work as RTC counter*/
    SOSC_Configuration();

    return;
}


/************************************************************************************************************************************/
/**	@fcn		void SOSC_Configuration(void)
 *  @brief		x
 *  @details	x
 *
 *  @section	Opens
 *  	re-enable disabled ('//?') sections
 */
/************************************************************************************************************************************/
void SOSC_Configuration(void) {
    
//? char a , b , c , *p ;

//? a = 2 ;
//? b = 0x46 ;
//? c = 0x57 ;
//? p = (char *) &OSCCON ;

//? asm volatile ("mov.b %1,[%0] \n"
//?            "mov.b %2,[%0] \n"
//?            "mov.b %3,[%0] \n" : /* no outputs */ : "r"( p ) , "r"( b ) , "r"( c ) ,
//?            "r"( a ) ) ;

	return;
}


/************************************************************************************************************************************/
/**	@fcn		void __attribute__ ((__interrupt__, auto_psv))_AD1Interrupt(void)
 *  @brief		ISR routine for the ADC1 Interrupt
 *  @details	This is the raw Interrupt Service Routine (ISR) for the ADC 1 interrupt. This routine calls the ADC's interrupt
 *  			routine to service the interrupt
 *
 *  @pre		The ADC peripheral must have been initialized for ADC 1
 *
 *  @section	Opens
 *  	re-enable disabled ('//?') sections
 *
 *  @note		This routine must not be "called" as a C-language function is called.  It is "vectored" to by the processor when the
 *  			interrupt occurs
 */
/************************************************************************************************************************************/
void __attribute__ ((__interrupt__, auto_psv))_AD1Interrupt(void) {
    static int count = 0 ;

    /* Simple "I am here" indicator */
    if ( count++ == 2000 )
    {
        count = 0 ;
    }

    /* reset ADC interrupt flag */
//? IFS0bits.AD1IF = 0 ;
    return;
}


/************************************************************************************************************************************/
/**	@fcn		void __attribute__ ((__interrupt__ , auto_psv))_T1Interrupt(void)
 *  @brief		ISR routine for the T1 Interrupt
 *  @details	This is the raw Interrupt Service Routine (ISR) for the Timer 3 interrupt. This routine calls the Timer1's interrupt
 *  			routine to service the interrupt.
 *
 *  @pre		The Timer peripheral must have been initialized for Timer 3.
 *
 *  @section	Opens
 *  	re-enable disabled ('//?') sections
 *
 *  @note		This routine must not be "called" as a C-language function is called.  It is "vectored" to by the processor when
 *  			the interrupt occurs.
 */
/************************************************************************************************************************************/
void __attribute__ ((__interrupt__ , auto_psv))_T1Interrupt(void) {
    /* reset Timer 1 interrupt flag */
//? IFS0bits.T1IF = 0 ;
	return;
}


/************************************************************************************************************************************/
/**	@fcn		void __attribute__ ((__interrupt__ , auto_psv)) _OscillatorFail(void)
 *  @brief		Provides the required exception vector handlers for Oscillator trap
 *  @details	This routine is used if INTCON2bits.ALTIVT = 0 and it handles the oscillator trap.
 *
 *  @section	Opens
 *  	re-enable disabled ('//?') sections
 *
 *  @note 		All trap service routines in this file simply ensure that device  continuously executes code within the trap service
 *  			routine. Users may modify the basic framework provided here to suit to the needs of their application.
 */
/************************************************************************************************************************************/
void __attribute__ ((__interrupt__ , auto_psv)) _OscillatorFail(void) {
//? INTCON1bits.OSCFAIL = 0 ;        //Clear the trap flag
    while(1);
}


/************************************************************************************************************************************/
/**	@fcn		void __attribute__ ((__interrupt__ , auto_psv))_AddressError(void)
 *  @brief		Provides the required exception vector handlers for Address Error trap
 *  @details	This routine is used if INTCON2bits.ALTIVT = 0 and it handles the address error trap.
 *
 *  @section	Opens
 *  	re-enable disabled ('//?') sections
 *
 *  @note		All trap service routines in this file simply ensure that device continuously executes code within the trap service
 *  			routine. Users may modify the basic framework provided here to suit to the needs of their application.
 */
/************************************************************************************************************************************/
void __attribute__ ((__interrupt__ , auto_psv))_AddressError(void) {
//? INTCON1bits.ADDRERR = 0 ;        //Clear the trap flag
    while(1);
}


/************************************************************************************************************************************/
/**	@fcn		void __attribute__ ((__interrupt__ , auto_psv))_StackError(void)
 *  @brief		Provides the required exception vector handlers for Stack Error trap
 *  @details	This routine is used if INTCON2bits.ALTIVT = 0 and it handles the stack error trap.
 *
 *  @section	Opens
 *  	re-enable disabled ('//?') sections
 *
 *  @note	    All trap service routines in this file simply ensure that device continuously executes code within the trap service
 *  			routine. Users may modify the basic framework provided here to suit to the needs of their application.
 */
/************************************************************************************************************************************/
void __attribute__ ((__interrupt__ , auto_psv))_StackError(void) {
//? INTCON1bits.STKERR = 0 ;         //Clear the trap flag
    while(1);
}


/************************************************************************************************************************************/
/**	@fcn		void __attribute__ ((__interrupt__ , auto_psv))_MathError(void)
 *  @brief		Provides the required exception vector handlers for Math Error trap
 *  @details	This routine is used if INTCON2bits.ALTIVT = 0 and it handles the math error trap.
 *
 *  @section	Opens
 *  	re-enable disabled ('//?') sections
 *
 *  @note	    All trap service routines in this file simply ensure that device continuously executes code within the trap service
 *  			routine. Users may modify the basic framework provided here to suit to the needs of their application.
 */
/************************************************************************************************************************************/
void __attribute__ ((__interrupt__ , auto_psv))_MathError(void) {
//? INTCON1bits.MATHERR = 0 ;        //Clear the trap flag
    while(1);
}

