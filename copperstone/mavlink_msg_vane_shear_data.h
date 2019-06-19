#pragma once
// MESSAGE VANE_SHEAR_DATA PACKING

#define MAVLINK_MSG_ID_VANE_SHEAR_DATA 500

MAVPACKED(
typedef struct __mavlink_vane_shear_data_t {
 uint32_t torque; /*< [Nm] Torque*/
 float motor_spd; /*< [rpm] Motor Speed*/
 int16_t temperature; /*< [cdegC] Temperature measurement*/
}) mavlink_vane_shear_data_t;

#define MAVLINK_MSG_ID_VANE_SHEAR_DATA_LEN 10
#define MAVLINK_MSG_ID_VANE_SHEAR_DATA_MIN_LEN 10
#define MAVLINK_MSG_ID_500_LEN 10
#define MAVLINK_MSG_ID_500_MIN_LEN 10

#define MAVLINK_MSG_ID_VANE_SHEAR_DATA_CRC 169
#define MAVLINK_MSG_ID_500_CRC 169



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VANE_SHEAR_DATA { \
    500, \
    "VANE_SHEAR_DATA", \
    3, \
    {  { "torque", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_vane_shear_data_t, torque) }, \
         { "motor_spd", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_vane_shear_data_t, motor_spd) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_vane_shear_data_t, temperature) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VANE_SHEAR_DATA { \
    "VANE_SHEAR_DATA", \
    3, \
    {  { "torque", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_vane_shear_data_t, torque) }, \
         { "motor_spd", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_vane_shear_data_t, motor_spd) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_vane_shear_data_t, temperature) }, \
         } \
}
#endif

/**
 * @brief Pack a vane_shear_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param torque [Nm] Torque
 * @param motor_spd [rpm] Motor Speed
 * @param temperature [cdegC] Temperature measurement
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vane_shear_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t torque, float motor_spd, int16_t temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VANE_SHEAR_DATA_LEN];
    _mav_put_uint32_t(buf, 0, torque);
    _mav_put_float(buf, 4, motor_spd);
    _mav_put_int16_t(buf, 8, temperature);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VANE_SHEAR_DATA_LEN);
#else
    mavlink_vane_shear_data_t packet;
    packet.torque = torque;
    packet.motor_spd = motor_spd;
    packet.temperature = temperature;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VANE_SHEAR_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VANE_SHEAR_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VANE_SHEAR_DATA_MIN_LEN, MAVLINK_MSG_ID_VANE_SHEAR_DATA_LEN, MAVLINK_MSG_ID_VANE_SHEAR_DATA_CRC);
}

/**
 * @brief Pack a vane_shear_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param torque [Nm] Torque
 * @param motor_spd [rpm] Motor Speed
 * @param temperature [cdegC] Temperature measurement
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vane_shear_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t torque,float motor_spd,int16_t temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VANE_SHEAR_DATA_LEN];
    _mav_put_uint32_t(buf, 0, torque);
    _mav_put_float(buf, 4, motor_spd);
    _mav_put_int16_t(buf, 8, temperature);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VANE_SHEAR_DATA_LEN);
#else
    mavlink_vane_shear_data_t packet;
    packet.torque = torque;
    packet.motor_spd = motor_spd;
    packet.temperature = temperature;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VANE_SHEAR_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VANE_SHEAR_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VANE_SHEAR_DATA_MIN_LEN, MAVLINK_MSG_ID_VANE_SHEAR_DATA_LEN, MAVLINK_MSG_ID_VANE_SHEAR_DATA_CRC);
}

/**
 * @brief Encode a vane_shear_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vane_shear_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vane_shear_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vane_shear_data_t* vane_shear_data)
{
    return mavlink_msg_vane_shear_data_pack(system_id, component_id, msg, vane_shear_data->torque, vane_shear_data->motor_spd, vane_shear_data->temperature);
}

/**
 * @brief Encode a vane_shear_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vane_shear_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vane_shear_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_vane_shear_data_t* vane_shear_data)
{
    return mavlink_msg_vane_shear_data_pack_chan(system_id, component_id, chan, msg, vane_shear_data->torque, vane_shear_data->motor_spd, vane_shear_data->temperature);
}

/**
 * @brief Send a vane_shear_data message
 * @param chan MAVLink channel to send the message
 *
 * @param torque [Nm] Torque
 * @param motor_spd [rpm] Motor Speed
 * @param temperature [cdegC] Temperature measurement
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_vane_shear_data_send(mavlink_channel_t chan, uint32_t torque, float motor_spd, int16_t temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VANE_SHEAR_DATA_LEN];
    _mav_put_uint32_t(buf, 0, torque);
    _mav_put_float(buf, 4, motor_spd);
    _mav_put_int16_t(buf, 8, temperature);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VANE_SHEAR_DATA, buf, MAVLINK_MSG_ID_VANE_SHEAR_DATA_MIN_LEN, MAVLINK_MSG_ID_VANE_SHEAR_DATA_LEN, MAVLINK_MSG_ID_VANE_SHEAR_DATA_CRC);
#else
    mavlink_vane_shear_data_t packet;
    packet.torque = torque;
    packet.motor_spd = motor_spd;
    packet.temperature = temperature;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VANE_SHEAR_DATA, (const char *)&packet, MAVLINK_MSG_ID_VANE_SHEAR_DATA_MIN_LEN, MAVLINK_MSG_ID_VANE_SHEAR_DATA_LEN, MAVLINK_MSG_ID_VANE_SHEAR_DATA_CRC);
#endif
}

/**
 * @brief Send a vane_shear_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_vane_shear_data_send_struct(mavlink_channel_t chan, const mavlink_vane_shear_data_t* vane_shear_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_vane_shear_data_send(chan, vane_shear_data->torque, vane_shear_data->motor_spd, vane_shear_data->temperature);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VANE_SHEAR_DATA, (const char *)vane_shear_data, MAVLINK_MSG_ID_VANE_SHEAR_DATA_MIN_LEN, MAVLINK_MSG_ID_VANE_SHEAR_DATA_LEN, MAVLINK_MSG_ID_VANE_SHEAR_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_VANE_SHEAR_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_vane_shear_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t torque, float motor_spd, int16_t temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, torque);
    _mav_put_float(buf, 4, motor_spd);
    _mav_put_int16_t(buf, 8, temperature);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VANE_SHEAR_DATA, buf, MAVLINK_MSG_ID_VANE_SHEAR_DATA_MIN_LEN, MAVLINK_MSG_ID_VANE_SHEAR_DATA_LEN, MAVLINK_MSG_ID_VANE_SHEAR_DATA_CRC);
#else
    mavlink_vane_shear_data_t *packet = (mavlink_vane_shear_data_t *)msgbuf;
    packet->torque = torque;
    packet->motor_spd = motor_spd;
    packet->temperature = temperature;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VANE_SHEAR_DATA, (const char *)packet, MAVLINK_MSG_ID_VANE_SHEAR_DATA_MIN_LEN, MAVLINK_MSG_ID_VANE_SHEAR_DATA_LEN, MAVLINK_MSG_ID_VANE_SHEAR_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE VANE_SHEAR_DATA UNPACKING


/**
 * @brief Get field torque from vane_shear_data message
 *
 * @return [Nm] Torque
 */
static inline uint32_t mavlink_msg_vane_shear_data_get_torque(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field motor_spd from vane_shear_data message
 *
 * @return [rpm] Motor Speed
 */
static inline float mavlink_msg_vane_shear_data_get_motor_spd(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field temperature from vane_shear_data message
 *
 * @return [cdegC] Temperature measurement
 */
static inline int16_t mavlink_msg_vane_shear_data_get_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Decode a vane_shear_data message into a struct
 *
 * @param msg The message to decode
 * @param vane_shear_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_vane_shear_data_decode(const mavlink_message_t* msg, mavlink_vane_shear_data_t* vane_shear_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    vane_shear_data->torque = mavlink_msg_vane_shear_data_get_torque(msg);
    vane_shear_data->motor_spd = mavlink_msg_vane_shear_data_get_motor_spd(msg);
    vane_shear_data->temperature = mavlink_msg_vane_shear_data_get_temperature(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_VANE_SHEAR_DATA_LEN? msg->len : MAVLINK_MSG_ID_VANE_SHEAR_DATA_LEN;
        memset(vane_shear_data, 0, MAVLINK_MSG_ID_VANE_SHEAR_DATA_LEN);
    memcpy(vane_shear_data, _MAV_PAYLOAD(msg), len);
#endif
}
