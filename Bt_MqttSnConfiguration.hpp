//*************************************************************************************************
//
//  BITTAILOR.CH - BtMqttSn, an Arduino library for MQTT-SN over nRF24L01+
//
//-------------------------------------------------------------------------------------------------
//
//  Bt::MqttSnConfiguration
//  
//*************************************************************************************************

#ifndef INC__Bt_MqttSnConfiguration__hpp
#define INC__Bt_MqttSnConfiguration__hpp

#include <avr/pgmspace.h>
#include "Arduino.h"

#define BT_MQTTSN_MAX_NUMBER_OF_REGISTERED_TOPICS 20

#define BT_LOGGING 1

#define BT_PROGMEM __attribute__(( section(".progmem.data") ))
#define BT_PROGMEM_STR(s) (__extension__({static char __c[] BT_PROGMEM = (s); &__c[0];}))
#define BT_LOG_STR(string_literal) (reinterpret_cast<const __FlashStringHelper *>(BT_PROGMEM_STR(string_literal)))

#if BT_LOGGING > 0

#define BT_LOG_MESSAGE(message) Serial.println(BT_LOG_STR(message)) ;
#define BT_LOG_MESSAGE_AND_PARAMETER(message,parameter) Serial.print(BT_LOG_STR(message)); Serial.println(parameter) ;

#else

#define BT_LOG_MESSAGE(message)
#define BT_LOG_MESSAGE_AND_PARAMETER(message,parameter)

#endif


inline void* operator new(size_t size, void* ptr )
{
   return ptr;
}


#endif // INC__Bt_MqttSnConfiguration__hpp
