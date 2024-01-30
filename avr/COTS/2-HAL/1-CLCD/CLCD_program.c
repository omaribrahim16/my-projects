/***********************************************************/
/***********************************************************/
/***********        Author:    OmarIbrahim     *************/
/***********        Layer:     HCAL            *************/
/***********        SWC:       CLCD            *************/
/***********        Version:   1.00            *************/
/***********************************************************/
/***********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
//we only include DIO interface file from all DIO files
#include "DIO_interface.h"

#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*set RS pin to low for command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_LOW);

	/*set RW pin to low for write */
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);

	/*set command to data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Command);

	/*Send enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);

}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*set RS pin to high for data*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_HIGH);

	/*set RW pin to low for write */
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);

	/*set data to data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Data);

	/*Send enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);



}

void CLCD_voidInit(void)
{
	/*wait for more than 30 ms */
	_delay_ms(40);

	/*function set command: 2 lines, 5*8 font size*/
	CLCD_voidSendCommand(0b00111000);

	/*display on off control : display enable disable cursor no blink cursor*/
	CLCD_voidSendCommand(0b00001100);

	/*clear display */
	CLCD_voidSendCommand(1);

	/* delay needed before the first character is sent for it to appear*/
	_delay_ms(3);		//musb be more than 2ms


}

void CLCD_voidSendString(const char* Copy_pcString)
{
	u8 Local_u8Counter = 0;
	while(Copy_pcString[Local_u8Counter] != '\0')
	{
		CLCD_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void CLCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8Address;
	if(Copy_u8XPos == 0)
	{
		/*Location is at first line */
		Local_u8Address = Copy_u8YPos;
	}
	else if(Copy_u8XPos == 1)
	{
		/*Location is at second line*/
		Local_u8Address = Copy_u8YPos + 0x40;
	}

	/* set bit number 7 for set DDRAM address command then send command*/
	CLCD_voidSendCommand(Local_u8Address + 128);

}

void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8CGRAMAdress = 0 , Local_u8Iterator;

	/* calculate the CGRam address whose each block is 8 bytes*/
	Local_u8CGRAMAdress = Copy_u8PatternNumber * 8 ;

	/*Send CGRam address command to LCD , with setting bit 6, clearing bit 7*/
	CLCD_voidSendCommand(Local_u8CGRAMAdress + 64);

	for(Local_u8Iterator=0; Local_u8Iterator < 8; Local_u8Iterator++)
	{
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8Iterator]);
	}
	/*go back to the DDRAM to display pattern*/
	CLCD_voidGoToXY(Copy_u8XPos, Copy_u8YPos);
	/*Display the pattern written in the CGRAM*/
	CLCD_voidSendData(Copy_u8PatternNumber);

}
