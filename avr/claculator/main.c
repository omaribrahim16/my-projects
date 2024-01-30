#include "STD_TYPES.h"

#include "PORT_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"

void main(void)
{
	u8 Local_u8Key;
	u8 Local_u8FirstNum = 0 , Local_u8SecondNum = 0 , Local_u8Operator = 0, Local_u8ResultOperator = 0, Local_u8Result = 0;
	u8 Local_u8NumberWritten = 0;	//flag to know which field is being written (0 is first number field)
	PORT_voidInit();
	CLCD_voidInit();
	//	CLCD_voidSendNumber();
	//	CLCD_voidSendData(Local_u8Key+ 48 );
	while(1)
	{
		do
		{
			Local_u8Key= KPD_u8GetPressedKey();
		}while(Local_u8Key == 0xff);

		switch(Local_u8NumberWritten)
		{
		case 0:
			if(Local_u8Key >= 10)
			{
				Local_u8NumberWritten = 2;
				Local_u8Operator = Local_u8Key;
				switch(Local_u8Operator)
				{
				case 10: CLCD_voidSendData('+'); break;
				case 11: CLCD_voidSendData('-'); break;
				case 12: CLCD_voidSendData('*'); break;
				case 13: CLCD_voidSendData('/'); break;
				}
			}
			else
			{
				Local_u8FirstNum =  (Local_u8FirstNum * 10) + Local_u8Key;
				CLCD_voidSendNumber(Local_u8Key);
				Local_u8NumberWritten++;
			}

			break;
		case 1:
			if(Local_u8Key < 10)
			{
				Local_u8FirstNum = (Local_u8FirstNum * 10) + Local_u8Key;
				CLCD_voidSendNumber(Local_u8Key);
				Local_u8NumberWritten = 0;
			}
			else
			{
				Local_u8NumberWritten = 2;
				Local_u8Operator = Local_u8Key;
				switch(Local_u8Operator)
				{
				case 10: CLCD_voidSendData('+'); break;
				case 11: CLCD_voidSendData('-'); break;
				case 12: CLCD_voidSendData('*'); break;
				case 13: CLCD_voidSendData('/'); break;
				}

			}
			break;
		case 2:
			if(Local_u8Key < 10)
			{
				Local_u8SecondNum = (Local_u8SecondNum * 10) + Local_u8Key;
				CLCD_voidSendNumber(Local_u8Key);
			}
			else if(Local_u8Key == 14)
			{
				CLCD_voidSendData('=');
				switch(Local_u8Operator)
				{
				case 10:
					Local_u8Result = Local_u8FirstNum + Local_u8SecondNum;
					CLCD_voidSendNumber(Local_u8Result); break;
				case 11:
					Local_u8Result = Local_u8FirstNum - Local_u8SecondNum;
					CLCD_voidSendNumber(Local_u8Result); break;
				case 12:
					Local_u8Result = Local_u8FirstNum * Local_u8SecondNum;
					CLCD_voidSendNumber(Local_u8Result); break;
				case 13:
					Local_u8Result = Local_u8FirstNum / Local_u8SecondNum;
					CLCD_voidSendNumber(Local_u8Result); break;
				}

			}

		}





		//		if(Local_u8Key != 0xff && Local_u8FirstNum == 0)
		//		{
		//			Local_u8FirstNum = Local_u8Key;
		//			CLCD_voidSendNumber(Local_u8FirstNum);
		//		}
		//
		//		/*this sends the ascii so we add 0 to it and get only numbers from 0 to 9 (we made sendNumber instead sendData for this)*/
		//		else if (Local_u8Key != 0xff && Local_u8FirstNum != 0 && Local_u8Operator == 0)
		//		{
		//			Local_u8Operator = Local_u8Key;
		//			switch(Local_u8Operator)
		//			{
		//				case 11: CLCD_voidSendData('+'); break;
		//				case 12: CLCD_voidSendData('-'); break;
		//				case 13: CLCD_voidSendData('*'); break;
		//				case 14: CLCD_voidSendData('/'); break;
		//			}
		//
		//		}
		//		else if (Local_u8Key != 0xff && Local_u8FirstNum != 0 && Local_u8Operator != 0 && Local_u8SecondNum ==0)
		//		{
		//			Local_u8SecondNum = Local_u8Key;
		//			CLCD_voidSendNumber(Local_u8SecondNum);
		//		}
		//		else if (Local_u8Key == 15 && Local_u8ResultOperator == 0)
		//		{
		//			Local_u8ResultOperator = '=';
		//			CLCD_voidSendData(Local_u8ResultOperator);
		//		}

	}

}


