/*
 * AWS IoT Device SDK for Embedded C 202103.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef MQTT_DEMO_HELPERS_H_
#define MQTT_DEMO_HELPERS_H_

#define AWS_IOT_ENDPOINT        CONFIG_MQTT_BROKER_ENDPOINT
#define AWS_MQTT_PORT         ( CONFIG_MQTT_BROKER_PORT )
#define CLIENT_IDENTIFIER       CONFIG_MQTT_CLIENT_IDENTIFIER
#define NETWORK_BUFFER_SIZE   ( CONFIG_MQTT_NETWORK_BUFFER_SIZE )
#define OS_NAME                 "FreeRTOS"
#define OS_VERSION                tskKERNEL_VERSION_NUMBER
#define HARDWARE_PLATFORM_NAME  CONFIG_HARDWARE_PLATFORM_NAME

/* MQTT API header. */
#include "core_mqtt.h"
#define MQTT_LIB    "core-mqtt@" MQTT_LIBRARY_VERSION

#define THING_NAME              CONFIG_MQTT_CLIENT_IDENTIFIER
#define THING_NAME_LENGTH    ( ( uint16_t ) ( sizeof( THING_NAME ) - 1 ) )
#define SHADOW_NAME             SHADOW_NAME_CLASSIC
#define SHADOW_NAME_LENGTH   ( ( uint16_t ) ( sizeof( SHADOW_NAME ) - 1 ) )

/**
 * @brief Establish a MQTT connection.
 *
 * @param[in] appCallback The callback function used to receive incoming
 * publishes and incoming acks from MQTT library.
 *
 * @return EXIT_SUCCESS if an MQTT session is established;
 * EXIT_FAILURE otherwise.
 */
int32_t EstablishMqttSession( MQTTEventCallback_t eventCallback );

/**
 * @brief Handle the incoming packet if it's not related to the device shadow.
 *
 * @param[in] pPacketInfo Packet Info pointer for the incoming packet.
 * @param[in] packetIdentifier Packet identifier of the incoming packet.
 */
void HandleOtherIncomingPacket( MQTTPacketInfo_t * pPacketInfo,
                                uint16_t packetIdentifier );

/**
 * @brief Close the MQTT connection.
 *
 * @return EXIT_SUCCESS if DISCONNECT was successfully sent;
 * EXIT_FAILURE otherwise.
 */
int32_t DisconnectMqttSession( void );

/**
 * @brief Subscribe to a MQTT topic filter.
 *
 * @param[in] pTopicFilter Pointer to the shadow topic buffer.
 * @param[in] topicFilterLength Indicates the length of the shadow
 * topic buffer.
 *
 * @return EXIT_SUCCESS if SUBSCRIBE was successfully sent;
 * EXIT_FAILURE otherwise.
 */
int32_t SubscribeToTopic( const char * pTopicFilter,
                          uint16_t topicFilterLength );

/**
 * @brief Sends an MQTT UNSUBSCRIBE to unsubscribe from the shadow
 * topic.
 *
 * @param[in] pTopicFilter Pointer to the shadow topic buffer.
 * @param[in] topicFilterLength Indicates the length of the shadow
 * topic buffer.
 *
 * @return EXIT_SUCCESS if UNSUBSCRIBE was successfully sent;
 * EXIT_FAILURE otherwise.
 */
int32_t UnsubscribeFromTopic( const char * pTopicFilter,
                              uint16_t topicFilterLength );

/**
 * @brief Publish a message to a MQTT topic.
 *
 * @param[in] pTopicFilter Points to the topic.
 * @param[in] topicFilterLength The length of the topic.
 * @param[in] pPayload Points to the payload.
 * @param[in] payloadLength The length of the payload.
 *
 * @return EXIT_SUCCESS if PUBLISH was successfully sent;
 * EXIT_FAILURE otherwise.
 */
int32_t PublishToTopic( const char * pTopicFilter,
                        int32_t topicFilterLength,
                        const char * pPayload,
                        size_t payloadLength );

#endif /* ifndef MQTT_HELPERS_H_ */
