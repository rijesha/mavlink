#pragma once
// MESSAGE PING_TEST PACKING

#define MAVLINK_MSG_ID_PING_TEST 187

MAVPACKED(
typedef struct __mavlink_ping_test_t {
 uint64_t time; /*<  Timestamp*/
 uint8_t ping_src; /*<  Ping Source*/
 uint8_t ping_dest; /*<  Ping Destination*/
 char message[50]; /*<  Ping Message*/
}) mavlink_ping_test_t;

#define MAVLINK_MSG_ID_PING_TEST_LEN 60
#define MAVLINK_MSG_ID_PING_TEST_MIN_LEN 60
#define MAVLINK_MSG_ID_187_LEN 60
#define MAVLINK_MSG_ID_187_MIN_LEN 60

#define MAVLINK_MSG_ID_PING_TEST_CRC 101
#define MAVLINK_MSG_ID_187_CRC 101

#define MAVLINK_MSG_PING_TEST_FIELD_MESSAGE_LEN 50

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PING_TEST { \
    187, \
    "PING_TEST", \
    4, \
    {  { "ping_src", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_ping_test_t, ping_src) }, \
         { "ping_dest", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_ping_test_t, ping_dest) }, \
         { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_ping_test_t, time) }, \
         { "message", NULL, MAVLINK_TYPE_CHAR, 50, 10, offsetof(mavlink_ping_test_t, message) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PING_TEST { \
    "PING_TEST", \
    4, \
    {  { "ping_src", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_ping_test_t, ping_src) }, \
         { "ping_dest", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_ping_test_t, ping_dest) }, \
         { "time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_ping_test_t, time) }, \
         { "message", NULL, MAVLINK_TYPE_CHAR, 50, 10, offsetof(mavlink_ping_test_t, message) }, \
         } \
}
#endif

/**
 * @brief Pack a ping_test message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ping_src  Ping Source
 * @param ping_dest  Ping Destination
 * @param time  Timestamp
 * @param message  Ping Message
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ping_test_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t ping_src, uint8_t ping_dest, uint64_t time, const char *message)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PING_TEST_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_uint8_t(buf, 8, ping_src);
    _mav_put_uint8_t(buf, 9, ping_dest);
    _mav_put_char_array(buf, 10, message, 50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PING_TEST_LEN);
#else
    mavlink_ping_test_t packet;
    packet.time = time;
    packet.ping_src = ping_src;
    packet.ping_dest = ping_dest;
    mav_array_memcpy(packet.message, message, sizeof(char)*50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PING_TEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PING_TEST;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PING_TEST_MIN_LEN, MAVLINK_MSG_ID_PING_TEST_LEN, MAVLINK_MSG_ID_PING_TEST_CRC);
}

/**
 * @brief Pack a ping_test message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ping_src  Ping Source
 * @param ping_dest  Ping Destination
 * @param time  Timestamp
 * @param message  Ping Message
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ping_test_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t ping_src,uint8_t ping_dest,uint64_t time,const char *message)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PING_TEST_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_uint8_t(buf, 8, ping_src);
    _mav_put_uint8_t(buf, 9, ping_dest);
    _mav_put_char_array(buf, 10, message, 50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PING_TEST_LEN);
#else
    mavlink_ping_test_t packet;
    packet.time = time;
    packet.ping_src = ping_src;
    packet.ping_dest = ping_dest;
    mav_array_memcpy(packet.message, message, sizeof(char)*50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PING_TEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PING_TEST;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PING_TEST_MIN_LEN, MAVLINK_MSG_ID_PING_TEST_LEN, MAVLINK_MSG_ID_PING_TEST_CRC);
}

/**
 * @brief Encode a ping_test struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ping_test C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ping_test_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ping_test_t* ping_test)
{
    return mavlink_msg_ping_test_pack(system_id, component_id, msg, ping_test->ping_src, ping_test->ping_dest, ping_test->time, ping_test->message);
}

/**
 * @brief Encode a ping_test struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ping_test C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ping_test_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ping_test_t* ping_test)
{
    return mavlink_msg_ping_test_pack_chan(system_id, component_id, chan, msg, ping_test->ping_src, ping_test->ping_dest, ping_test->time, ping_test->message);
}

/**
 * @brief Send a ping_test message
 * @param chan MAVLink channel to send the message
 *
 * @param ping_src  Ping Source
 * @param ping_dest  Ping Destination
 * @param time  Timestamp
 * @param message  Ping Message
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ping_test_send(mavlink_channel_t chan, uint8_t ping_src, uint8_t ping_dest, uint64_t time, const char *message)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PING_TEST_LEN];
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_uint8_t(buf, 8, ping_src);
    _mav_put_uint8_t(buf, 9, ping_dest);
    _mav_put_char_array(buf, 10, message, 50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PING_TEST, buf, MAVLINK_MSG_ID_PING_TEST_MIN_LEN, MAVLINK_MSG_ID_PING_TEST_LEN, MAVLINK_MSG_ID_PING_TEST_CRC);
#else
    mavlink_ping_test_t packet;
    packet.time = time;
    packet.ping_src = ping_src;
    packet.ping_dest = ping_dest;
    mav_array_memcpy(packet.message, message, sizeof(char)*50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PING_TEST, (const char *)&packet, MAVLINK_MSG_ID_PING_TEST_MIN_LEN, MAVLINK_MSG_ID_PING_TEST_LEN, MAVLINK_MSG_ID_PING_TEST_CRC);
#endif
}

/**
 * @brief Send a ping_test message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ping_test_send_struct(mavlink_channel_t chan, const mavlink_ping_test_t* ping_test)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ping_test_send(chan, ping_test->ping_src, ping_test->ping_dest, ping_test->time, ping_test->message);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PING_TEST, (const char *)ping_test, MAVLINK_MSG_ID_PING_TEST_MIN_LEN, MAVLINK_MSG_ID_PING_TEST_LEN, MAVLINK_MSG_ID_PING_TEST_CRC);
#endif
}

#if MAVLINK_MSG_ID_PING_TEST_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ping_test_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t ping_src, uint8_t ping_dest, uint64_t time, const char *message)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time);
    _mav_put_uint8_t(buf, 8, ping_src);
    _mav_put_uint8_t(buf, 9, ping_dest);
    _mav_put_char_array(buf, 10, message, 50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PING_TEST, buf, MAVLINK_MSG_ID_PING_TEST_MIN_LEN, MAVLINK_MSG_ID_PING_TEST_LEN, MAVLINK_MSG_ID_PING_TEST_CRC);
#else
    mavlink_ping_test_t *packet = (mavlink_ping_test_t *)msgbuf;
    packet->time = time;
    packet->ping_src = ping_src;
    packet->ping_dest = ping_dest;
    mav_array_memcpy(packet->message, message, sizeof(char)*50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PING_TEST, (const char *)packet, MAVLINK_MSG_ID_PING_TEST_MIN_LEN, MAVLINK_MSG_ID_PING_TEST_LEN, MAVLINK_MSG_ID_PING_TEST_CRC);
#endif
}
#endif

#endif

// MESSAGE PING_TEST UNPACKING


/**
 * @brief Get field ping_src from ping_test message
 *
 * @return  Ping Source
 */
static inline uint8_t mavlink_msg_ping_test_get_ping_src(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field ping_dest from ping_test message
 *
 * @return  Ping Destination
 */
static inline uint8_t mavlink_msg_ping_test_get_ping_dest(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field time from ping_test message
 *
 * @return  Timestamp
 */
static inline uint64_t mavlink_msg_ping_test_get_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field message from ping_test message
 *
 * @return  Ping Message
 */
static inline uint16_t mavlink_msg_ping_test_get_message(const mavlink_message_t* msg, char *message)
{
    return _MAV_RETURN_char_array(msg, message, 50,  10);
}

/**
 * @brief Decode a ping_test message into a struct
 *
 * @param msg The message to decode
 * @param ping_test C-struct to decode the message contents into
 */
static inline void mavlink_msg_ping_test_decode(const mavlink_message_t* msg, mavlink_ping_test_t* ping_test)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ping_test->time = mavlink_msg_ping_test_get_time(msg);
    ping_test->ping_src = mavlink_msg_ping_test_get_ping_src(msg);
    ping_test->ping_dest = mavlink_msg_ping_test_get_ping_dest(msg);
    mavlink_msg_ping_test_get_message(msg, ping_test->message);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PING_TEST_LEN? msg->len : MAVLINK_MSG_ID_PING_TEST_LEN;
        memset(ping_test, 0, MAVLINK_MSG_ID_PING_TEST_LEN);
    memcpy(ping_test, _MAV_PAYLOAD(msg), len);
#endif
}
