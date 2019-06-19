/** @file
 *    @brief MAVLink comm protocol testsuite generated from copperstone.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef COPPERSTONE_TESTSUITE_H
#define COPPERSTONE_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_ardupilotmega(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_copperstone(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_ardupilotmega(system_id, component_id, last_msg);
    mavlink_test_copperstone(system_id, component_id, last_msg);
}
#endif

#include "../ardupilotmega/testsuite.h"


static void mavlink_test_vane_shear_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_VANE_SHEAR_DATA >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_vane_shear_data_t packet_in = {
        963497464,45.0,17651
    };
    mavlink_vane_shear_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.torque = packet_in.torque;
        packet1.motor_spd = packet_in.motor_spd;
        packet1.temperature = packet_in.temperature;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_VANE_SHEAR_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_VANE_SHEAR_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vane_shear_data_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_vane_shear_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vane_shear_data_pack(system_id, component_id, &msg , packet1.torque , packet1.motor_spd , packet1.temperature );
    mavlink_msg_vane_shear_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vane_shear_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.torque , packet1.motor_spd , packet1.temperature );
    mavlink_msg_vane_shear_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_vane_shear_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vane_shear_data_send(MAVLINK_COMM_1 , packet1.torque , packet1.motor_spd , packet1.temperature );
    mavlink_msg_vane_shear_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_robot_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_ROBOT_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_robot_status_t packet_in = {
        { 17.0, 18.0, 19.0, 20.0 },{ 129.0, 130.0 },{ 185.0, 186.0 },{ 18899, 18900, 18901, 18902 },125,192
    };
    mavlink_robot_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.robot_state = packet_in.robot_state;
        packet1.rc_state = packet_in.rc_state;
        
        mav_array_memcpy(packet1.motor_temp, packet_in.motor_temp, sizeof(float)*4);
        mav_array_memcpy(packet1.motor_controller_current, packet_in.motor_controller_current, sizeof(float)*2);
        mav_array_memcpy(packet1.motor_controller_voltage, packet_in.motor_controller_voltage, sizeof(float)*2);
        mav_array_memcpy(packet1.motor_spd, packet_in.motor_spd, sizeof(int16_t)*4);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_ROBOT_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_ROBOT_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_robot_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_robot_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_robot_status_pack(system_id, component_id, &msg , packet1.robot_state , packet1.rc_state , packet1.motor_spd , packet1.motor_temp , packet1.motor_controller_current , packet1.motor_controller_voltage );
    mavlink_msg_robot_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_robot_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.robot_state , packet1.rc_state , packet1.motor_spd , packet1.motor_temp , packet1.motor_controller_current , packet1.motor_controller_voltage );
    mavlink_msg_robot_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_robot_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_robot_status_send(MAVLINK_COMM_1 , packet1.robot_state , packet1.rc_state , packet1.motor_spd , packet1.motor_temp , packet1.motor_controller_current , packet1.motor_controller_voltage );
    mavlink_msg_robot_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_payload_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_PAYLOAD_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_payload_status_t packet_in = {
        { 5, 6, 7, 8, 9, 10, 11, 12 },{ 29, 30, 31, 32, 33, 34, 35, 36 }
    };
    mavlink_payload_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        
        mav_array_memcpy(packet1.payload_ids, packet_in.payload_ids, sizeof(uint8_t)*8);
        mav_array_memcpy(packet1.payload_status, packet_in.payload_status, sizeof(uint8_t)*8);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_PAYLOAD_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_PAYLOAD_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_payload_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_payload_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_payload_status_pack(system_id, component_id, &msg , packet1.payload_ids , packet1.payload_status );
    mavlink_msg_payload_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_payload_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.payload_ids , packet1.payload_status );
    mavlink_msg_payload_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_payload_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_payload_status_send(MAVLINK_COMM_1 , packet1.payload_ids , packet1.payload_status );
    mavlink_msg_payload_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_copperstone(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_vane_shear_data(system_id, component_id, last_msg);
    mavlink_test_robot_status(system_id, component_id, last_msg);
    mavlink_test_payload_status(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // COPPERSTONE_TESTSUITE_H
