/***********************************************************/
/***********        Author:    OmarIbrahim     *************/
/***********        Layer:     MCAL            *************/
/***********        SWC:       PORT            *************/
/***********        Version:   1.00            *************/
/***********************************************************/
/***********************************************************/

#include "STD_TYPES.h"

#include "PORT_config.h"
#include "PORT_private.h"
#include "PORT_interface.h"
#include "PORT_register.h"

void PORT_voidInit(void)
{
    DDRA=PORTA_DIR;
    DDRB=PORTB_DIR;
    DDRC=PORTC_DIR;
    DDRD=PORTD_DIR;

    PORTA=PORTA_INITAIL_VALUE;
    PORTB=PORTB_INITAIL_VALUE;
    PORTC=PORTC_INITAIL_VALUE;
    PORTD=PORTD_INITAIL_VALUE;
    

}