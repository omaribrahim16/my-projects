/***********************************************************/
/***********************************************************/
/***********        Author:    OmarIbrahim     *************/
/***********        Layer:     HCAL            *************/
/***********        SWC:       CLCD            *************/
/***********        Version:   1.00            *************/
/***********************************************************/
/***********************************************************/


//preprocessor file guard
#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

void CLCD_voidSendCommand(u8 Copy_u8Command);

void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidSendNumber(u8 Copy_u8Data);

void CLCD_voidInit(void);

void CLCD_voidSendString(const char* Copy_pcString);

void CLCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos);

void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos);


#endif
