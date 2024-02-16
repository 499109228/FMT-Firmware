/******************************************************************************
 * Copyright 2020-2023 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include <firmament.h>
#include "stm32f7xx_hal_can.h"

// CAN_HandleTypeDef     CanHandle;
// CAN_TxHeaderTypeDef   TxHeader;
// CAN_RxHeaderTypeDef   RxHeader;
// uint8_t               TxData[8];
// uint8_t               RxData[8] = {0};
// uint32_t              TxMailbox;

void can1_test(void);

int cmd_test(int argc, char** argv)
{
    /* add your test code here */

  // CAN_FilterTypeDef  sFilterConfig;

  // /*##-1- Configure the CAN peripheral #######################################*/
  // CanHandle.Instance = CAN1;
  // CanHandle.Init.Prescaler = 6;
  // CanHandle.Init.Mode = CAN_MODE_LOOPBACK;
  // CanHandle.Init.SyncJumpWidth = CAN_SJW_1TQ;
  // CanHandle.Init.TimeSeg1 = CAN_BS1_5TQ;
  // CanHandle.Init.TimeSeg2 = CAN_BS2_3TQ;
  // CanHandle.Init.TimeTriggeredMode = DISABLE;
  // CanHandle.Init.AutoBusOff = DISABLE;
  // CanHandle.Init.AutoWakeUp = DISABLE;
  // CanHandle.Init.AutoRetransmission = DISABLE;
  // CanHandle.Init.ReceiveFifoLocked = DISABLE;
  // CanHandle.Init.TransmitFifoPriority = DISABLE;
  // if (HAL_CAN_Init(&CanHandle) != HAL_OK)
  // {
  //   printf("fail 0\n");
  //   return 0;
  // }

  // // SET_BIT(CanHandle.Instance->IER, 1 | 2);
  // // uint32_t ier_reg = READ_REG(CanHandle.Instance->IER);
  // // printf("IER:0x%x\n", ier_reg);

  // /*##-2- Configure the CAN Filter ###########################################*/
  // sFilterConfig.FilterBank = 0;
  // sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
  // sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
  // sFilterConfig.FilterIdHigh = 0x0000;
  // sFilterConfig.FilterIdLow = 0x0000;
  // sFilterConfig.FilterMaskIdHigh = 0x0000;
  // sFilterConfig.FilterMaskIdLow = 0x0000;
  // sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
  // sFilterConfig.FilterActivation = ENABLE;
  // sFilterConfig.SlaveStartFilterBank = 14;
  
  // if(HAL_CAN_ConfigFilter(&CanHandle, &sFilterConfig) != HAL_OK)
  // {
  //   printf("fail 1\n");
  //   return 0;
  // }

  // if(HAL_CAN_ActivateNotification(&CanHandle, CAN_IT_TX_MAILBOX_EMPTY | CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK)
  // {
  //   printf("fail notify\n");
  //   return 0;
  // }

  // uint32_t ier_reg = READ_REG(CanHandle.Instance->IER);
  // printf("IER:0x%x\n", ier_reg);

  // /*##-3- Start the CAN peripheral ###########################################*/
  // if (HAL_CAN_Start(&CanHandle) != HAL_OK)
  // {
  //   printf("fail 2\n");
  //   return 0;
  // }

  // /*##-4- Start the Transmission process #####################################*/
  // TxHeader.StdId = 0x17;
  // TxHeader.RTR = CAN_RTR_DATA;
  // TxHeader.IDE = CAN_ID_STD;
  // TxHeader.DLC = 2;
  // TxHeader.TransmitGlobalTime = DISABLE;
  // TxData[0] = 0xCA;
  // TxData[1] = 0xFE;
  
  // /* Request transmission */
  // if(HAL_CAN_AddTxMessage(&CanHandle, &TxHeader, TxData, &TxMailbox) != HAL_OK)
  // {
  //   printf("fail 3\n");
  //   return 0;
  // }
  
  // /* Wait transmission complete */
  // while(HAL_CAN_GetTxMailboxesFreeLevel(&CanHandle) != 3) {}

  // /*##-5- Start the Reception process ########################################*/
  // if(HAL_CAN_GetRxFifoFillLevel(&CanHandle, CAN_RX_FIFO0) != 1)
  // {
  //   printf("fail 4\n");
  //   return 0;
  // }

  // if(HAL_CAN_GetRxMessage(&CanHandle, CAN_RX_FIFO0, &RxHeader, RxData) != HAL_OK)
  // {
  //   printf("fail 5\n");
  //   return 0;
  // }

  // if((RxHeader.StdId != 0x17)                     ||
  //    (RxHeader.RTR != CAN_RTR_DATA)               ||
  //    (RxHeader.IDE != CAN_ID_STD)                 ||
  //    (RxHeader.DLC != 2)                          ||
  //    ((RxData[0]<<8 | RxData[1]) != 0xCAFE))
  // {
  //   printf("rx message error\n");
  //   return 0;
  // }

  // printf("can test pass! id:%x\n", RxHeader.StdId);

  can1_test();

    return 0;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_test, __cmd_test, user test command);