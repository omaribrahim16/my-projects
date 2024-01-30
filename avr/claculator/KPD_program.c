/***********************************************************/
/***********************************************************/
/***********        Author:    OmarIbrahim     *************/
/***********        Layer:     HAL             *************/
/***********        SWC:       KEYPAD          *************/
/***********        Version:   1.00            *************/
/***********************************************************/
/***********************************************************/

#include "STD_TYPES.h"
#include "DIO_interface.h"

#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"

u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey = KPD_NO_PRESSED_KEY , Local_u8PinState ;
	u8 Local_u8ColumnIndex, Local_u8RowIndex;

	/*2D Array with keypad values of buttons*/
	static u8 Local_u8KPDArr[ROW_NUM][COLUMN_NUM]=KPD_ARR_VAL;
	/*Array with 4 column pins*/
	static u8 Local_u8KPDColumnArr[COLUMN_NUM] = {KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
	/*Array with 4 row pins*/
	static u8 Local_u8KPDRowArr[ROW_NUM] = {KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};

	for(Local_u8ColumnIndex= 0; Local_u8ColumnIndex < COLUMN_NUM ;Local_u8ColumnIndex++ )
	{
		/*Activate current column*/
		DIO_u8SetPinValue(KPD_PORT, Local_u8KPDColumnArr[Local_u8ColumnIndex], DIO_u8PIN_LOW);

		for(Local_u8RowIndex = 0; Local_u8RowIndex < ROW_NUM ; Local_u8RowIndex++)
		{
			/*Read the current row*/
			DIO_u8GetPinValue(KPD_PORT,Local_u8KPDRowArr[Local_u8RowIndex], &Local_u8PinState);

			/*check if switch is pressed*/
			// the way of writing the condition is a fail safe if we forgot we are equaling not assigning
			if( DIO_u8PIN_LOW == Local_u8PinState)
			{
				Local_u8PressedKey = Local_u8KPDArr[Local_u8RowIndex][Local_u8ColumnIndex];
				/*polling (busy waiting ) until the key is released*/
				while(DIO_u8PIN_LOW == Local_u8PinState)
				{
					DIO_u8GetPinValue(KPD_PORT,Local_u8KPDRowArr[Local_u8RowIndex], &Local_u8PinState);
				}
				/*end of polling*/

				return Local_u8PressedKey;
			}

		}
		/*Deactivate the current column*/
		DIO_u8SetPinValue(KPD_PORT, Local_u8KPDColumnArr[Local_u8ColumnIndex], DIO_u8PIN_HIGH);

	}


	return Local_u8PressedKey;

}
