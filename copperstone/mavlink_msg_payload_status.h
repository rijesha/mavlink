#pragma once
// MESSAGE PAYLOAD_STATUS PACKING

#define MAVLINK_MSG_ID_PAYLOAD_STATUS 503

MAVPACKED(
typedef struct __mavlink_payload_status_t {
 uint8_t payload_ids[8]; /*<  Payload ID*/
 uint8_t payload_status[8]; /*<  Payload STATUS*/
}) mavlink_payload_status_t;

#define MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN 16
#define MAVLINK_MSG_ID_PAYLOAD_STATUS_MIN_LEN 16
#define MAVLINK_MSG_ID_503_LEN 16
#define MAVLINK_MSG_ID_503_MIN_LEN 16

#define MAVLINK_MSG_ID_PAYLOAD_STATUS_CRC 122
#define MAVLINK_MSG_ID_503_CRC 122

#define MAVLINK_MSG_PAYLOAD_STATUS_FIELD_PAYLOAD_IDS_LEN 8
#define MAVLINK_MSG_PAYLOAD_STATUS_FIELD_PAYLOAD_STATUS_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PAYLOAD_STATUS { \
    503, \
    "PAYLOAD_STATUS", \
    2, \
    {  { "payload_ids", NULL, MAVLINK_TYPE_UINT8_T, 8, 0, offsetof(mavlink_payload_status_t, payload_ids) }, \
         { "payload_status", NULL, MAVLINK_TYPE_UINT8_T, 8, 8, offsetof(mavlink_payload_status_t, payload_status) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PAYLOAD_STATUS { \
    "PAYLOAD_STATUS", \
    2, \
    {  { "payload_ids", NULL, MAVLINK_TYPE_UINT8_T, 8, 0, offsetof(mavlink_payload_status_t, payload_ids) }, \
         { "payload_status", NULL, MAVLINK_TYPE_UINT8_T, 8, 8, offsetof(mavlink_payload_status_t, payload_status) }, \
         } \
}
#endif

/**
 * @brief Pack a payload_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param payload_ids  Payload ID
 * @param payload_status  Payload STATUS
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_payload_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const uint8_t *payload_ids, const uint8_t *payload_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN];

    _mav_put_uint8_t_array(buf, 0, payload_ids, 8);
    _mav_put_uint8_t_array(buf, 8, payload_status, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN);
#else
    mavlink_payload_status_t packet;

    mav_array_memcpy(packet.payload_ids, payload_ids, sizeof(uint8_t)*8);
    mav_array_memcpy(packet.payload_status, payload_status, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PAYLOAD_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PAYLOAD_STATUS_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_CRC);
}

/**
 * @brief Pack a payload_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param payload_ids  Payload ID
 * @param payload_status  Payload STATUS
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_payload_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const uint8_t *payload_ids,const uint8_t *payload_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN];

    _mav_put_uint8_t_array(buf, 0, payload_ids, 8);
    _mav_put_uint8_t_array(buf, 8, payload_status, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN);
#else
    mavlink_payload_status_t packet;

    mav_array_memcpy(packet.payload_ids, payload_ids, sizeof(uint8_t)*8);
    mav_array_memcpy(packet.payload_status, payload_status, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PAYLOAD_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PAYLOAD_STATUS_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_CRC);
}

/**
 * @brief Encode a payload_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param payload_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_payload_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_payload_status_t* payload_status)
{
    return mavlink_msg_payload_status_pack(system_id, component_id, msg, payload_status->payload_ids, payload_status->payload_status);
}

/**
 * @brief Encode a payload_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param payload_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_payload_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_payload_status_t* payload_status)
{
    return mavlink_msg_payload_status_pack_chan(system_id, component_id, chan, msg, payload_status->payload_ids, payload_status->payload_status);
}

/**
 * @brief Send a payload_status message
 * @param chan MAVLink channel to send the message
 *
 * @param payload_ids  Payload ID
 * @param payload_status  Payload STATUS
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_payload_status_send(mavlink_channel_t chan, const uint8_t *payload_ids, const uint8_t *payload_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN];

    _mav_put_uint8_t_array(buf, 0, payload_ids, 8);
    _mav_put_uint8_t_array(buf, 8, payload_status, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PAYLOAD_STATUS, buf, MAVLINK_MSG_ID_PAYLOAD_STATUS_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_CRC);
#else
    mavlink_payload_status_t packet;

    mav_array_memcpy(packet.payload_ids, payload_ids, sizeof(uint8_t)*8);
    mav_array_memcpy(packet.payload_status, payload_status, sizeof(uint8_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PAYLOAD_STATUS, (const char *)&packet, MAVLINK_MSG_ID_PAYLOAD_STATUS_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_CRC);
#endif
}

/**
 * @brief Send a payload_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_payload_status_send_struct(mavlink_channel_t chan, const mavlink_payload_status_t* payload_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_payload_status_send(chan, payload_status->payload_ids, payload_status->payload_status);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PAYLOAD_STATUS, (const char *)payload_status, MAVLINK_MSG_ID_PAYLOAD_STATUS_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_payload_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const uint8_t *payload_ids, const uint8_t *payload_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;

    _mav_put_uint8_t_array(buf, 0, payload_ids, 8);
    _mav_put_uint8_t_array(buf, 8, payload_status, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PAYLOAD_STATUS, buf, MAVLINK_MSG_ID_PAYLOAD_STATUS_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_CRC);
#else
    mavlink_payload_status_t *packet = (mavlink_payload_status_t *)msgbuf;

    mav_array_memcpy(packet->payload_ids, payload_ids, sizeof(uint8_t)*8);
    mav_array_memcpy(packet->payload_status, payload_status, sizeof(uint8_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PAYLOAD_STATUS, (const char *)packet, MAVLINK_MSG_ID_PAYLOAD_STATUS_MIN_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN, MAVLINK_MSG_ID_PAYLOAD_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE PAYLOAD_STATUS UNPACKING


/**
 * @brief Get field payload_ids from payload_status message
 *
 * @return  Payload ID
 */
static inline uint16_t mavlink_msg_payload_status_get_payload_ids(const mavlink_message_t* msg, uint8_t *payload_ids)
{
    return _MAV_RETURN_uint8_t_array(msg, payload_ids, 8,  0);
}

/**
 * @brief Get field payload_status from payload_status message
 *
 * @return  Payload STATUS
 */
static inline uint16_t mavlink_msg_payload_status_get_payload_status(const mavlink_message_t* msg, uint8_t *payload_status)
{
    return _MAV_RETURN_uint8_t_array(msg, payload_status, 8,  8);
}

/**
 * @brief Decode a payload_status message into a struct
 *
 * @param msg The message to decode
 * @param payload_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_payload_status_decode(const mavlink_message_t* msg, mavlink_payload_status_t* payload_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_payload_status_get_payload_ids(msg, payload_status->payload_ids);
    mavlink_msg_payload_status_get_payload_status(msg, payload_status->payload_status);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN? msg->len : MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN;
        memset(payload_status, 0, MAVLINK_MSG_ID_PAYLOAD_STATUS_LEN);
    memcpy(payload_status, _MAV_PAYLOAD(msg), len);
#endif
}
