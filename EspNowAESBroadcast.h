#ifndef ESP_NOBRADCAST_H
#define ESP_NOBRADCAST_H
#ifdef ESP32
#include <esp_now.h>
#else
#include <espnow.h>
#endif

//#define DISABLE_CRYPTING //send messages as plain text
//#define DEBUG_PRINTS
#define MAX_ALLOWED_TIME_DIFFERENCE_IN_MESSAGES 3 //if message time differens more than this from RTC, reject message

    void espNowAESBroadcast_begin(int channel);
    void espNowAESBroadcast_end();

    void espNowAESBroadcast_setChannel(int channel);

    void espNowAESBroadcast_setToMasterRole(bool master=true, unsigned char ttl=0 /*ttl for sync messages*/);
    void espNowAESBroadcast_setToBatteryNode(bool isBatteryNode=true);

    void espNowAESBroadcast_RecvCB(void (*callback)(const uint8_t *, int, uint32_t));
    void espNowAESBroadcast_send(uint8_t* msg, int size, int ttl=0); //Max message length is 236byte
    void espNowAESBroadcast_secredkey(const unsigned char key[16]);
    void espNowAESBroadcast_setAesInitializationVector(const unsigned char iv[16]);

    void espNowAESBroadcast_ErrorDebugCB(void (*callback)(int,const char *));

    uint32_t espNowAESBroadcast_sendAndHandleReply(uint8_t* msg, int size, int ttl, void (*f)(const uint8_t *, int)); //Max message length is 236byte

    //Run this only in Mainloop!!!
    bool espNowAESBroadcast_sendAndWaitReply(uint8_t* msg, int size, int ttl, int tryCount=1, void (*f)(const uint8_t *, int)=NULL, int timeoutMs=3000, int expectedCountOfReplies=1); //Max message length is 236byte
    bool espNowAESBroadcast_syncWithMasterAndWait(int timeoutMs=3000, int tryCount=3);

    void espNowAESBroadcast_sendReply(uint8_t* msg, int size, int ttl, uint32_t replyIdentifier);

    void espNowAESBroadcast_loop();

    void espNowAESBroadcast_delay(unsigned long tm);
    int espNowAESBroadcast_getTTL();

    void espNowAESBroadcast_setRTCTime(time_t time);
    time_t espNowAESBroadcast_getRTCTime();
#endif
