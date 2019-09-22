#include "Can.h"

static Can_ControllerStateType Can_ControllerState[NUM_OF_CAN_CONTROLLERS]={CAN_CS_UNINIT};
static MsgConfType MsgConf[NUM_OF_HOH * MAX_HW_OBJ_COUNT_PER_HOH] = {CAN_MSG_NOT_CONF};
const CanType TivaCan = CAN_CONFIG;

Std_ReturnType Can_GetControllerMode(uint8 Controller,Can_ControllerStateType* ControllerModePtr)
{
	Std_ReturnType Loc_Can_GetControllerMode_Ret = E_OK;
	
	#if(CAN_DEV_ERROR_DETECT == STD_ON)
		if (Can_ControllerState[Controller]==CAN_CS_UNINIT)
		{
			Det_ReportError(CAN_MODULE_ID,CAN_INSTANCE_ID,Can_GetControllerMode_SID,CAN_E_UNINIT);
			Loc_Can_GetControllerMode_Ret = E_NOT_OK;
		}
		else
		{
			
		}
		
	#endif 

	if(Controller >= NUM_OF_CAN_CONTROLLERS)
	{
		Det_ReportError(CAN_MODULE_ID,CAN_INSTANCE_ID,Can_GetControllerMode_SID,CAN_E_PARAM_CONTROLLER);
		Loc_Can_GetControllerMode_Ret = E_NOT_OK;
	}
	else 
	{
		
	}
	if(ControllerModePtr==NULL)
	{
		Det_ReportError(CAN_MODULE_ID,CAN_INSTANCE_ID,Can_GetControllerMode_SID,CAN_E_PARAM_POINTER);	
		Loc_Can_GetControllerMode_Ret = E_NOT_OK;
	}
	else
	{
		
	}

	if(Loc_Can_GetControllerMode_Ret != E_NOT_OK)
	{

		
		*ControllerModePtr = Can_ControllerState[Controller];
	}
	else 
	{
		
	}
	return Loc_Can_GetControllerMode_Ret;
	
}

void Can_MainFunction_Write(void)
{
	
	#if ((CAN_TX_PROCESSING_0==POLLING_PROCESSING) || (CAN_TX_PROCESSING_1==POLLING_PROCESSING)\
	    || (CAN_TX_PROCESSING_0==MIXED_PROCESSING) || (CAN_TX_PROCESSING_1==MIXED_PROCESSING))
		
		uint8  index,index2;

		if(TivaCan.CanConfigSet.CanController[CONTROLLER_0_ID].CanControllerActivation == STD_ON )
		{
			CLR_BIT_PERPHBAND(CAN0_IF1CMSK_A,CAN_IF1CMSK_WRNRD);
		}
		else 
		{
			/*Do Nothing*/
		}
		
		if(TivaCan.CanConfigSet.CanController[CONTROLLER_1_ID].CanControllerActivation == STD_ON )
		{
		    CLR_BIT_PERPHBAND(CAN1_IF1CMSK_A,CAN_IF1CMSK_WRNRD);
		}
		else 
		{
			/*Do Nothing*/
		}

		for(index=0;index<NUM_OF_HOH;index++)
		{
			if(TivaCan.CanConfigSet.CanHardwareObject[index].CanObjectType == TRANSMIT_HOH )
			{
				if(TivaCan.CanConfigSet.CanHardwareObject[index].CanControllerRef == &TivaCan.CanConfigSet.CanController[CONTROLLER_0_ID])
				{
					#if (CAN_TX_PROCESSING_0==POLLING_PROCESSING)

						for(index2=0U;index2<TivaCan.CanConfigSet.CanHardwareObject[index].CanHwObjectCount;index2++)
	                    {
	                    	if(*(TivaCan.CanConfigSet.CanHardwareObject[index].MsgObj[index2].MsgConfPtr)==CAN_MSG_NOT_CONF)
	                        {
		                        CAN0_IF1CRQ_R=TivaCan.CanConfigSet.CanHardwareObject[index].MsgObj[index2].MsgId;
		                        
		                    	if(GET_BIT_PERPHBAND(CAN0_IF1MCTL_A,CAN_IF1MCTL_TXRQST) == (uint32)0)
		                      	{
		                    	    *(TivaCan.CanConfigSet.CanHardwareObject[index].MsgObj[index2].MsgConfPtr)=CAN_MSG_CONF;

		                            CanIf_TxConfirmation(TivaCan.CanConfigSet.CanHardwareObject[index].MsgObj[index2].PduId);

				                    /*The Can module shall call CanIf_TxConfirmation to indicate a
				                    successful transmission.It shall either called by the TX-interrupt service routine
				                    of the corresponding HW resource or inside the Can_MainFunction_Write in case of
				                    polling mode.*/
		                    	}

		                    	else 
		                    	{
		                    		/* Do Nothing */
		                    	}
		                    else 
		                    {
		                    	/*Do Nothing */
		                    }

	                     }

	                  }

					#elif(CAN_TX_PROCESSING_0==MIXED_PROCESSING)

						if(TivaCan.CanConfigSet.CanHardwareObject[index].CanHardwareObjectUsesPolling == STD_ON )
						{
							for(index2=0U;index2<TivaCan.CanConfigSet.CanHardwareObject[index].CanHwObjectCount;index2++)
	                    	{
		                    	if(*(TivaCan.CanConfigSet.CanHardwareObject[index].MsgObj[index2].MsgConfPtr)==CAN_MSG_NOT_CONF)
		                        {
			                        CAN0_IF1CRQ_R=TivaCan.CanConfigSet.CanHardwareObject[index].MsgObj[index2].MsgId;
			                        
			                        
			                    	if(GET_BIT_PERPHBAND(CAN0_IF1MCTL_A,CAN_IF1MCTL_TXRQST) == (uint32)0)
			                      	{
			                        	*(TivaCan.CanConfigSet.CanHardwareObject[index].MsgObj[index2].MsgConfPtr)=CAN_MSG_CONF;

			                            CanIf_TxConfirmation(TivaCan.CanConfigSet.CanHardwareObject[index].MsgObj[index2].PduId);

					                    /*The Can module shall call CanIf_TxConfirmation to indicate a
					                    successful transmission.It shall either called by the TX-interrupt service routine
					                    of the corresponding HW resource or inside the Can_MainFunction_Write in case of
					                    polling mode.*/
			                    	}

			                    	else 
			                    	{
			                    		/* Do Nothing */
			                    	}
		                        }
		                    	else 
		                    	{
		                    		/*Do Nothing */
		                    	}

							}
						}
				
					#else
						/*Do Nothing */ 		
					#endif	

				else if (TivaCan.CanConfigSet.CanHardwareObject[index].CanControllerRef == &TivaCan.CanConfigSet.CanController[CONTROLLER_1_ID])
				{
					#if (CAN_TX_PROCESSING_1==POLLING_PROCESSING)

						for(index2=0U;index2<TivaCan.CanConfigSet.CanHardwareObject[index].CanHwObjectCount;index2++)
	                    {
	                    	if(*(TivaCan.CanConfigSet.CanHardwareObject[index].MsgObj[index2].MsgConfPtr)==CAN_MSG_NOT_CONF)
	                        {
		                        CAN1_IF1CRQ_R=TivaCan.CanConfigSet.CanHardwareObject[index].MsgObj[index2].MsgId;
		                        
		                        
		                    	if(GET_BIT_PERPHBAND(CAN1_IF1MCTL_A,CAN_IF1MCTL_TXRQST) == (uint32)0)
		                      	{
		                    	    *(TivaCan.CanConfigSet.CanHardwareObject[index].MsgObj[index2].MsgConfPtr)=CAN_MSG_CONF;

		                            CanIf_TxConfirmation(TivaCan.CanConfigSet.CanHardwareObject[index].MsgObj[index2].PduId);

				                    /*The Can module shall call CanIf_TxConfirmation to indicate a
				                    successful transmission.It shall either called by the TX-interrupt service routine
				                    of the corresponding HW resource or inside the Can_MainFunction_Write in case of
				                    polling mode.*/
		                    	}

		                    	else 
		                    	{
		                    		/* Do Nothing */
		                    	}
		                    else 
		                    {
		                    	/*Do Nothing */
		                    }

	                     }
	                   }

					#elif(CAN_TX_PROCESSING_1==MIXED_PROCESSING)

						if(TivaCan.CanConfigSet.CanHardwareObject[index].CanHardwareObjectUsesPolling == STD_ON )
						{
							for(index2=0U;index2<TivaCan.CanConfigSet.CanHardwareObject[index].CanHwObjectCount;index2++)
	                    	{
		                    	if(*(TivaCan.CanConfigSet.CanHardwareObject[index].MsgObj[index2].MsgConfPtr)==CAN_MSG_NOT_CONF)
		                        {
			                        CAN1_IF1CRQ_R=TivaCan.CanConfigSet.CanHardwareObject[index].MsgObj[index2].MsgId;
			                        
			                        
			                    	if(GET_BIT_PERPHBAND(CAN1_IF1MCTL_A,CAN_IF1MCTL_TXRQST) == (uint32)0)
			                      	{
			                    	    *(TivaCan.CanConfigSet.CanHardwareObject[index].MsgObj[index2].MsgConfPtr)=CAN_MSG_CONF;

			                            CanIf_TxConfirmation(TivaCan.CanConfigSet.CanHardwareObject[index].MsgObj[index2].PduId);

					                    /*The Can module shall call CanIf_TxConfirmation to indicate a
					                    successful transmission.It shall either called by the TX-interrupt service routine
					                    of the corresponding HW resource or inside the Can_MainFunction_Write in case of
					                    polling mode.*/
			                    	}

			                    	else 
			                    	{
			                    		/* Do Nothing */
			                    	}
		                        }
		                    	else 
		                    	{
		                    		/*Do Nothing */
		                    	}

							}
						}
				
					#else
						/*Do Nothing */ 		
					#endif	

				}

				else 
				{
					/* Do Nothing */ 
				}
	        }

			else 
			{
				/* Do Nothing */ 
			}			
					
		}
	#else
		/* Do Nothing */ 
	#endif
	}
}
	

	
	
