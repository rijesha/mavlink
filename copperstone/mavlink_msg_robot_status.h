#pragma once
// MESSAGE ROBOT_STATUS PACKING

#define MAVLINK_MSG_ID_ROBOT_STATUS 502

MAVPACKED(
typedef struct __mavlink_robot_status_t {
 float motor_temp[4]; /*< [cdegC] Temperature measurement*/
 float motor_controller_current[2]; /*< [amps] Current measurement*/
 float motor_controller_voltage[2]; /*< [volts] Votlage measurement*/
 int16_t motor_spd[4]; /*<  Motor Speed*/
 uint8_t robot_state; /*<  State of robot*/
 uint8_t rc_state; /*<  State of RC*/
}) mavlink_robot_status_t;

#define MAVLINK_MSG_ID_ROBOT_STATUS_LEN 42
#define MAVLINK_MSG_ID_ROBOT_STATUS_MIN_LEN 42
#define MAVLINK_MSG_ID_502_LEN 42
#define MAVLINK_MSG_ID_502_MIN_LEN 42

#define MAVLINK_MSG_ID_ROBOT_STATUS_CRC 4
#define MAVLINK_MSG_ID_502_CRC 4

#define MAVLINK_MSG_ROBOT_STATUS_FIELD_MOTOR_TEMP_LEN 4
#define MAVLINK_MSG_ROBOT_STATUS_FIELD_MOTOR_CONTROLLER_CURRENT_LEN 2
#define MAVLINK_MSG_ROBOT_STATUS_FIELD_MOTOR_CONTROLLER_VOLTAGE_LEN 2
#define MAVLINK_MSG_ROBOT_STATUS_FIELD_MOTOR_SPD_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ROBOT_STATUS { \
    502, \
    "ROBOT_STATUS", \
    6, \
    {  { "robot_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_robot_status_t, robot_state) }, \
         { "rc_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 41, offsetof(mavlink_robot_status_t, rc_state) }, \
         { "motor_spd", NULL, MAVLINK_TYPE_INT16_T, 4, 32, offsetof(mavlink_robot_status_t, motor_spd) }, \
         { "motor_temp", NULL, MAVLINK_TYPE_FLOAT, 4, 0, offsetof(mavlink_robot_status_t, motor_temp) }, \
         { "motor_controller_current", NULL, MAVLINK_TYPE_FLOAT, 2, 16, offsetof(mavlink_robot_status_t, motor_controller_current) }, \
         { "motor_controller_voltage", NULL, MAVLINK_TYPE_FLOAT, 2, 24, offsetof(mavlink_robot_status_t, motor_controller_voltage) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ROBOT_STATUS { \
    "ROBOT_STATUS", \
    6, \
    {  { "robot_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_robot_status_t, robot_state) }, \
         { "rc_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 41, offsetof(mavlink_robot_status_t, rc_state) }, \
         { "motor_spd", NULL, MAVLINK_TYPE_INT16_T, 4, 32, offsetof(mavlink_robot_status_t, motor_spd) }, \
         { "motor_temp", NULL, MAVLINK_TYPE_FLOAT, 4, 0, offsetof(mavlink_robot_status_t, motor_temp) }, \
         { "motor_controller_current", NULL, MAVLINK_TYPE_FLOAT, 2, 16, offsetof(mavlink_robot_status_t, motor_controller_current) }, \
         { "motor_controller_voltage", NULL, MAVLINK_TYPE_FLOAT, 2, 24, offsetof(mavlink_robot_status_t, motor_controller_voltage) }, \
         } \
}
#endif

/**
 * @brief Pack a robot_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param robot_state  State of robot
 * @param rc_state  State of RC
 * @param motor_spd  Motor Speed
 * @param motor_temp [cdegC] Temperature measurement
 * @param motor_controller_current [amps] Current measurement
 * @param motor_controller_voltage [volts] Votlage measurement
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_robot_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t robot_state, uint8_t rc_state, const int16_t *motor_spd, const float *motor_temp, const float *motor_controller_current, const float *motor_controller_voltage)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ROBOT_STATUS_LEN];
    _mav_put_uint8_t(buf, 40, robot_state);
    _mav_put_uint8_t(buf, 41, rc_state);
    _mav_put_float_array(buf, 0, motor_temp, 4);
    _mav_put_float_array(buf, 16, motor_controller_current, 2);
    _mav_put_float_array(buf, 24, motor_controller_voltage, 2);
    _mav_put_int16_t_array(buf, 32, motor_spd, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ROBOT_STATUS_LEN);
#else
    mavlink_robot_status_t packet;
    packet.robot_state = robot_state;
    packet.rc_state = rc_state;
    mav_array_memcpy(packet.motor_temp, motor_temp, sizeof(float)*4);
    mav_array_memcpy(packet.motor_controller_current, motor_controller_current, sizeof(float)*2);
    mav_array_memcpy(packet.motor_controller_voltage, motor_controller_voltage, sizeof(float)*2);
    mav_array_memcpy(packet.motor_spd, motor_spd, sizeof(int16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ROBOT_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ROBOT_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ROBOT_STATUS_MIN_LEN, MAVLINK_MSG_ID_ROBOT_STATUS_LEN, MAVLINK_MSG_ID_ROBOT_STATUS_CRC);
}

/**
 * @brief Pack a robot_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param robot_state  State of robot
 * @param rc_state  State of RC
 * @param motor_spd  Motor Speed
 * @param motor_temp [cdegC] Temperature measurement
 * @param motor_controller_current [amps] Current measurement
 * @param motor_controller_voltage [volts] Votlage measurement
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_robot_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t robot_state,uint8_t rc_state,const int16_t *motor_spd,const float *motor_temp,const float *motor_controller_current,const float *motor_controller_voltage)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ROBOT_STATUS_LEN];
    _mav_put_uint8_t(buf, 40, robot_state);
    _mav_put_uint8_t(buf, 41, rc_state);
    _mav_put_float_array(buf, 0, motor_temp, 4);
    _mav_put_float_array(buf, 16, motor_controller_current, 2);
    _mav_put_float_array(buf, 24, motor_controller_voltage, 2);
    _mav_put_int16_t_array(buf, 32, motor_spd, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ROBOT_STATUS_LEN);
#else
    mavlink_robot_status_t packet;
    packet.robot_state = robot_state;
    packet.rc_state = rc_state;
    mav_array_memcpy(packet.motor_temp, motor_temp, sizeof(float)*4);
    mav_array_memcpy(packet.motor_controller_current, motor_controller_current, sizeof(float)*2);
    mav_array_memcpy(packet.motor_controller_voltage, motor_controller_voltage, sizeof(float)*2);
    mav_array_memcpy(packet.motor_spd, motor_spd, sizeof(int16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ROBOT_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ROBOT_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ROBOT_STATUS_MIN_LEN, MAVLINK_MSG_ID_ROBOT_STATUS_LEN, MAVLINK_MSG_ID_ROBOT_STATUS_CRC);
}

/**
 * @brief Encode a robot_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param robot_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_robot_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_robot_status_t* robot_status)
{
    return mavlink_msg_robot_status_pack(system_id, component_id, msg, robot_status->robot_state, robot_status->rc_state, robot_status->motor_spd, robot_status->motor_temp, robot_status->motor_controller_current, robot_status->motor_controller_voltage);
}

/**
 * @brief Encode a robot_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param robot_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_robot_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_robot_status_t* robot_status)
{
    return mavlink_msg_robot_status_pack_chan(system_id, component_id, chan, msg, robot_status->robot_state, robot_status->rc_state, robot_status->motor_spd, robot_status->motor_temp, robot_status->motor_controller_current, robot_status->motor_controller_voltage);
}

/**
 * @brief Send a robot_status message
 * @param chan MAVLink channel to send the message
 *
 * @param robot_state  State of robot
 * @param rc_state  State of RC
 * @param motor_spd  Motor Speed
 * @param motor_temp [cdegC] Temperature measurement
 * @param motor_controller_current [amps] Current measurement
 * @param motor_controller_voltage [volts] Votlage measurement
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_robot_status_send(mavlink_channel_t chan, uint8_t robot_state, uint8_t rc_state, const int16_t *motor_spd, const float *motor_temp, const float *motor_controller_current, const float *motor_controller_voltage)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ROBOT_STATUS_LEN];
    _mav_put_uint8_t(buf, 40, robot_state);
    _mav_put_uint8_t(buf, 41, rc_state);
    _mav_put_float_array(buf, 0, motor_temp, 4);
    _mav_put_float_array(buf, 16, motor_controller_current, 2);
    _mav_put_float_array(buf, 24, motor_controller_voltage, 2);
    _mav_put_int16_t_array(buf, 32, motor_spd, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ROBOT_STATUS, buf, MAVLINK_MSG_ID_ROBOT_STATUS_MIN_LEN, MAVLINK_MSG_ID_ROBOT_STATUS_LEN, MAVLINK_MSG_ID_ROBOT_STATUS_CRC);
#else
    mavlink_robot_status_t packet;
    packet.robot_state = robot_state;
    packet.rc_state = rc_state;
    mav_array_memcpy(packet.motor_temp, motor_temp, sizeof(float)*4);
    mav_array_memcpy(packet.motor_controller_current, motor_controller_current, sizeof(float)*2);
    mav_array_memcpy(packet.motor_controller_voltage, motor_controller_voltage, sizeof(float)*2);
    mav_array_memcpy(packet.motor_spd, motor_spd, sizeof(int16_t)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ROBOT_STATUS, (const char *)&packet, MAVLINK_MSG_ID_ROBOT_STATUS_MIN_LEN, MAVLINK_MSG_ID_ROBOT_STATUS_LEN, MAVLINK_MSG_ID_ROBOT_STATUS_CRC);
#endif
}

/**
 * @brief Send a robot_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_robot_status_send_struct(mavlink_channel_t chan, const mavlink_robot_status_t* robot_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_robot_status_send(chan, robot_status->robot_state, robot_status->rc_state, robot_status->motor_spd, robot_status->motor_temp, robot_status->motor_controller_current, robot_status->motor_controller_voltage);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ROBOT_STATUS, (const char *)robot_status, MAVLINK_MSG_ID_ROBOT_STATUS_MIN_LEN, MAVLINK_MSG_ID_ROBOT_STATUS_LEN, MAVLINK_MSG_ID_ROBOT_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_ROBOT_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_robot_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t robot_state, uint8_t rc_state, const int16_t *motor_spd, const float *motor_temp, const float *motor_controller_current, const float *motor_controller_voltage)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 40, robot_state);
    _mav_put_uint8_t(buf, 41, rc_state);
    _mav_put_float_array(buf, 0, motor_temp, 4);
    _mav_put_float_array(buf, 16, motor_controller_current, 2);
    _mav_put_float_array(buf, 24, motor_controller_voltage, 2);
    _mav_put_int16_t_array(buf, 32, motor_spd, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ROBOT_STATUS, buf, MAVLINK_MSG_ID_ROBOT_STATUS_MIN_LEN, MAVLINK_MSG_ID_ROBOT_STATUS_LEN, MAVLINK_MSG_ID_ROBOT_STATUS_CRC);
#else
    mavlink_robot_status_t *packet = (mavlink_robot_status_t *)msgbuf;
    packet->robot_state = robot_state;
    packet->rc_state = rc_state;
    mav_array_memcpy(packet->motor_temp, motor_temp, sizeof(float)*4);
    mav_array_memcpy(packet->motor_controller_current, motor_controller_current, sizeof(float)*2);
    mav_array_memcpy(packet->motor_controller_voltage, motor_controller_voltage, sizeof(float)*2);
    mav_array_memcpy(packet->motor_spd, motor_spd, sizeof(int16_t)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ROBOT_STATUS, (const char *)packet, MAVLINK_MSG_ID_ROBOT_STATUS_MIN_LEN, MAVLINK_MSG_ID_ROBOT_STATUS_LEN, MAVLINK_MSG_ID_ROBOT_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE ROBOT_STATUS UNPACKING


/**
 * @brief Get field robot_state from robot_status message
 *
 * @return  State of robot
 */
static inline uint8_t mavlink_msg_robot_status_get_robot_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  40);
}

/**
 * @brief Get field rc_state from robot_status message
 *
 * @return  State of RC
 */
static inline uint8_t mavlink_msg_robot_status_get_rc_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  41);
}

/**
 * @brief Get field motor_spd from robot_status message
 *
 * @return  Motor Speed
 */
static inline uint16_t mavlink_msg_robot_status_get_motor_spd(const mavlink_message_t* msg, int16_t *motor_spd)
{
    return _MAV_RETURN_int16_t_array(msg, motor_spd, 4,  32);
}

/**
 * @brief Get field motor_temp from robot_status message
 *
 * @return [cdegC] Temperature measurement
 */
static inline uint16_t mavlink_msg_robot_status_get_motor_temp(const mavlink_message_t* msg, float *motor_temp)
{
    return _MAV_RETURN_float_array(msg, motor_temp, 4,  0);
}

/**
 * @brief Get field motor_controller_current from robot_status message
 *
 * @return [amps] Current measurement
 */
static inline uint16_t mavlink_msg_robot_status_get_motor_controller_current(const mavlink_message_t* msg, float *motor_controller_current)
{
    return _MAV_RETURN_float_array(msg, motor_controller_current, 2,  16);
}

/**
 * @brief Get field motor_controller_voltage from robot_status message
 *
 * @return [volts] Votlage measurement
 */
static inline uint16_t mavlink_msg_robot_status_get_motor_controller_voltage(const mavlink_message_t* msg, float *motor_controller_voltage)
{
    return _MAV_RETURN_float_array(msg, motor_controller_voltage, 2,  24);
}

/**
 * @brief Decode a robot_status message into a struct
 *
 * @param msg The message to decode
 * @param robot_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_robot_status_decode(const mavlink_message_t* msg, mavlink_robot_status_t* robot_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_robot_status_get_motor_temp(msg, robot_status->motor_temp);
    mavlink_msg_robot_status_get_motor_controller_current(msg, robot_status->motor_controller_current);
    mavlink_msg_robot_status_get_motor_controller_voltage(msg, robot_status->motor_controller_voltage);
    mavlink_msg_robot_status_get_motor_spd(msg, robot_status->motor_spd);
    robot_status->robot_state = mavlink_msg_robot_status_get_robot_state(msg);
    robot_status->rc_state = mavlink_msg_robot_status_get_rc_state(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ROBOT_STATUS_LEN? msg->len : MAVLINK_MSG_ID_ROBOT_STATUS_LEN;
        memset(robot_status, 0, MAVLINK_MSG_ID_ROBOT_STATUS_LEN);
    memcpy(robot_status, _MAV_PAYLOAD(msg), len);
#endif
}
