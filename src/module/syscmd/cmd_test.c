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

#include "hal/can/can.h"

// void can1_test(void);

int cmd_test(int argc, char** argv)
{
    /* add your test code here */

    // can1_test();

    rt_device_t dev = rt_device_find("can1");

    rt_device_open(dev, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX);

    can_msg msg, recv_msg;

    //     can1_data.tx_header.StdId              = 0x13;
    //     can1_data.tx_header.RTR                = CAN_RTR_DATA;
    //     can1_data.tx_header.IDE                = CAN_ID_STD;
    //     can1_data.tx_header.DLC                = 2;
    //     can1_data.tx_header.TransmitGlobalTime = DISABLE;
    //     can1_data.tx_data[0]                   = 0xCA;
    //     can1_data.tx_data[1]                   = 0xFE;

    msg.std_id  = 0x16;
    msg.RTR     = CAN_RTR_DATA;
    msg.IDE     = CAN_ID_STD;
    msg.DLC     = 8;
    msg.data[0] = 0x12;
    msg.data[1] = 0x34;
    msg.data[2] = 0x56;
    msg.data[3] = 0x44;
    msg.data[4] = 0x55;
    msg.data[5] = 0x66;
    msg.data[6] = 0x77;
    msg.data[7] = 0x88;

    rt_size_t ss;

    for (int i = 0; i < 1000; i++) {
        ss = rt_device_write(dev, RT_WAITING_FOREVER, &msg, 1);
        systime_mdelay(10);
    }
    printf("write size:%d\n", ss);

    ss = rt_device_read(dev, 100, &recv_msg, 1);
    printf("read size:%d\n", ss);

    printf("id:%x DLC:%d\n", recv_msg.std_id, recv_msg.DLC);
    printf("%x %x %x %x %x %x %x %x\n", recv_msg.data[0], recv_msg.data[1], recv_msg.data[2], recv_msg.data[3], recv_msg.data[4], recv_msg.data[5], recv_msg.data[6], recv_msg.data[7]);

    // can1_test();

    return 0;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_test, __cmd_test, user test command);