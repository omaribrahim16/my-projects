/***********************************************************/
/***********************************************************/
/***********        Author:    OmarIbrahim     *************/
/***********        Layer:     HCAL            *************/
/***********        SWC:       CLCD            *************/
/***********        Version:   1.00            *************/
/***********************************************************/
/***********************************************************/

// THIS IS THE ONLY FILE THAT ANYONE CAN CHANGE WITHOUT RUINNING THE DRIVER

// first thing to do is preprocessor file guard
//PREPROCESSOR FILE GUARD
#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

#define CLCD_DATA_PORT		DIO_u8PORTA

#define CLCD_CTRL_PORT		DIO_u8PORTC
#define CLCD_RS_PIN			DIO_u8PIN0
#define CLCD_RW_PIN			DIO_u8PIN1
#define CLCD_E_PIN			DIO_u8PIN2







#endif
//END OF PREPROCESSOR FILE GUARD
