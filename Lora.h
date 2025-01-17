/**   __  ___     ____  _    ______        __     ____         __                  ____
 *   /  |/  /_ __/ / /_(_)__/_  __/__ ____/ /    / __/_ _____ / /____ __ _  ___   /  _/__  ____
 *  / /|_/ / // / / __/ /___// / / -_) __/ _ \  _\ \/ // (_-</ __/ -_)  ' \(_-<  _/ // _ \/ __/  __
 * /_/  /_/\_,_/_/\__/_/    /_/  \__/\__/_//_/ /___/\_, /___/\__/\__/_/_/_/___/ /___/_//_/\__/  /_/
 * Copyright (C) 2015 by Multi-Tech Systems        /___/
 *
 *
 * @author Jason Reiss
 * @date   10-31-2015
 * @brief  lora namespace defines global settings, structures and enums for the lora library
 *
 * @details
 *
 *
 *
 */

#ifndef __LORA_H__
#define __LORA_H__

#include "mbed.h"
#include <assert.h>
#include "MTSLog.h"
//#include <cstring>
#include <inttypes.h>

namespace lora {

    /**
     * Frequency bandwidth of a Datarate, higher bandwidth gives higher datarate
     */
    enum Bandwidth {
        BW_125,
        BW_250,
        BW_500,
        BW_FSK = 50
    };

    /**
     * Spreading factor of a Datarate, lower spreading factor gives higher datarate
     */
    enum SpreadingFactors {
        SF_6 = 6,
        SF_7,
        SF_8,
        SF_9,
        SF_10,
        SF_11,
        SF_12,
        SF_FSK,
        SF_INVALID
    };

    /**
     * Datarates for use with ChannelPlan
     */
    enum Datarates {
        DR_0 = 0,
        DR_1,
        DR_2,
        DR_3,
        DR_4,
        DR_5,
        DR_6,
        DR_7,
        DR_8,
        DR_9,
        DR_10,
        DR_11,
        DR_12,
        DR_13,
        DR_14,
        DR_15
    };

    const uint8_t MIN_DATARATE = (uint8_t) DR_0;             //!< Minimum datarate


    const uint8_t MAX_PHY_PACKET_SIZE = 255;                    //!< Maximum size for a packet
    const uint8_t MAX_APPS = 8;                                 //!< Maximum number of apps sessions to save
    const uint8_t MAX_MULTICAST_SESSIONS = 8;                   //!< Maximum number of multicast sessions to save
    const uint8_t EUI_SIZE = 8;                                 //!< Number of bytes in an EUI
    const uint8_t KEY_SIZE = 16;                                //!< Number of bytes in an AES key

    const uint8_t DEFAULT_NUM_CHANNELS = 16;                    //!< Default number of channels in a plan
    const uint8_t DEFAULT_RX1_DR_OFFSET = 0;                    //!< Default datarate offset for first rx window
    const uint8_t DEFAULT_RX2_DATARATE = 0;                     //!< Default datarate for second rx window
    const uint8_t DEFAULT_TX_POWER = 14;                        //!< Default transmit power
    const uint8_t DEFAULT_CODE_RATE = 1;                        //!< Default coding rate 1:4/5, 2:4/6, 3:4/7, 4:4/8
    const uint8_t DEFAULT_PREAMBLE_LEN = 8;                     //!< Default preamble length

    const int32_t MAX_FCNT_GAP = 16384;                         //!< Maximum allowed gap in sequence numbers before roll-over

    const uint16_t PRIVATE_JOIN_DELAY = 1000;                   //!< Default join delay used for private network
    const uint16_t PUBLIC_JOIN_DELAY = 5000;                    //!< Default join delay used for public network
    const uint16_t DEFAULT_JOIN_DELAY = PRIVATE_JOIN_DELAY;     //!< Default join delay1
    const uint16_t DEFAULT_RX_DELAY = 1000;                     //!< Default delay for first receive window
    const uint16_t DEFAULT_RX_TIMEOUT = 3000;                   //!< Default timeout for receive windows

    const uint8_t HI_DR_SYMBOL_TIMEOUT = 12;                    //!< Symbol timeout for receive at datarate with SF < 11
    const uint8_t LO_DR_SYMBOL_TIMEOUT = 8;                     //!< Symbol timeout for receive at datarate with SF > 10

    const uint16_t RX2_DELAY_OFFSET = 1000;                     //!< Delay between first and second window
    const uint16_t RXC_OFFSET = 50;                             //!< Time between end of RXC after TX and RX1

    const uint8_t US915_125K_NUM_CHANS = 64;                    //!< Number of 125k channels in US915 channel plan
    const uint8_t US915_500K_NUM_CHANS = 8;                     //!< Number of 500k channels in US915 channel plan

    const uint32_t US915_125K_FREQ_BASE = 902300000;            //!< Frequency base for 125k US915 uplink channels
    const uint32_t US915_125K_FREQ_STEP = 200000;               //!< Frequency step for 125k US915 uplink channels

    const uint32_t US915_500K_FREQ_BASE = 903000000;            //!< Frequency base for 500k US915 uplink channels
    const uint32_t US915_500K_FREQ_STEP = 1600000;              //!< Frequency step for 500k US915 uplink channels

    const uint32_t US915_500K_DBASE = 923300000;                //!< Frequency base for 500k US915 downlink channels
    const uint32_t US915_500K_DSTEP = 600000;                   //!< Frequency step for 500k US915 downlink channels

    const uint32_t US915_FREQ_MIN = 902000000;
    const uint32_t US915_FREQ_MAX = 928000000;

    const uint8_t US915_MIN_DATARATE = (uint8_t) DR_0;       //!< Minimum transmit datarate for US915
    const uint8_t US915_MAX_DATARATE = (uint8_t) DR_4;       //!< Maximum transmit datarate for US915

    const uint8_t US915_MIN_DATARATE_OFFSET = (uint8_t) 0;       //!< Minimum transmit datarate for US915
    const uint8_t US915_MAX_DATARATE_OFFSET = (uint8_t) 3;       //!< Maximum transmit datarate for US915

    const uint8_t AU915_125K_NUM_CHANS = 64;                    //!< Number of 125k channels in AU915 channel plan
    const uint8_t AU915_500K_NUM_CHANS = 8;                     //!< Number of 500k channels in AU915 channel plan

    const uint32_t AU915_125K_FREQ_BASE = 915200000;            //!< Frequency base for 125k AU915 uplink channels
    const uint32_t AU915_125K_FREQ_STEP = 200000;               //!< Frequency step for 125k AU915 uplink channels

    const uint32_t AU915_500K_FREQ_BASE = 915900000;            //!< Frequency base for 500k AU915 uplink channels
    const uint32_t AU915_500K_FREQ_STEP = 1600000;              //!< Frequency step for 500k AU915 uplink channels

    const uint32_t AU915_500K_DBASE = 923300000;                //!< Frequency base for 500k AU915 downlink channels
    const uint32_t AU915_500K_DSTEP = 600000;                   //!< Frequency step for 500k AU915 downlink channels

    const uint32_t AU915_FREQ_MIN = 915000000;
    const uint32_t AU915_FREQ_MAX = 928000000;

    const uint8_t AU915_MIN_DATARATE = (uint8_t) DR_0;       //!< Minimum transmit datarate for AU915
    const uint8_t AU915_MAX_DATARATE = (uint8_t) DR_4;       //!< Maximum transmit datarate for AU915

    const uint8_t AU915_MIN_DATARATE_OFFSET = (uint8_t) 0;       //!< Minimum transmit datarate for AU915
    const uint8_t AU915_MAX_DATARATE_OFFSET = (uint8_t) 3;       //!< Maximum transmit datarate for AU915

    const uint8_t EU868_125K_NUM_CHANS = 16;                    //!< Number of 125k channels in EU868 channel plan
    const uint8_t EU868_DEFAULT_NUM_CHANS = 3;                  //!< Number of defualt channels in EU868 channel plan
    const uint32_t EU868_125K_FREQ_BASE = 868100000;            //!< Frequency base for 125k EU868 uplink channels
    const uint32_t EU868_125K_FREQ_STEP = 200000;               //!< Frequency step for 125k EU868 uplink channels
    const uint32_t EU868_RX2_FREQ = 869525000;                  //!< Frequency default for second rx window in EU868

    const uint8_t EU868_TX_POWER_MAX = 14;                      //!< Max power for EU868 channel plan

    // 0.1% duty cycle 863-868
    // Limiting to 865-868 allows for 1% duty cycle
    const uint32_t EU868_MILLI_FREQ_MIN = 865000000;
    const uint32_t EU868_MILLI_FREQ_MAX = 868000000;

    const uint32_t EU868_MILLI_1_FREQ_MIN = 868700000;
    const uint32_t EU868_MILLI_1_FREQ_MAX = 869200000;

    // 1% duty cycle
    const uint32_t EU868_CENTI_FREQ_MIN = 868000000;
    const uint32_t EU868_CENTI_FREQ_MAX = 868600000;

    // 10% duty cycle
    const uint32_t EU868_DECI_FREQ_MIN = 869400000;
    const uint32_t EU868_DECI_FREQ_MAX = 869650000;

    // Below 7dBm there is no duty cycle for these frequencies
    // Up to 14dBm there is 1% duty cycle
    const uint32_t EU868_VAR_FREQ_MIN = 869700000;
    const uint32_t EU868_VAR_FREQ_MAX = 870000000;

    const uint32_t EU868_FREQ_MIN = 863000000;
    const uint32_t EU868_FREQ_MAX = 870000000;

    const uint8_t EU868_MIN_DATARATE = (uint8_t) DR_0;       //!< Minimum transmit datarate for EU868
    const uint8_t EU868_MAX_DATARATE = (uint8_t) DR_7;       //!< Maximum transmit datarate for EU868

    const uint8_t EU868_MIN_DATARATE_OFFSET = (uint8_t) 0;       //!< Minimum transmit datarate for US915
    const uint8_t EU868_MAX_DATARATE_OFFSET = (uint8_t) 5;       //!< Maximum transmit datarate for US915

    const int16_t DEFAULT_FREE_CHAN_RSSI_THRESHOLD = -90;       //!< Threshold for channel activity detection (CAD) dBm

    const uint8_t CHAN_MASK_SIZE = 16;                          //!< Number of bits in a channel mask
    const uint8_t COMMANDS_BUFFER_SIZE = 15;                    //!< Size of Mac Command buffer

    const uint8_t PKT_HEADER = 0;                               //!< Index to packet mHdr field
    const uint8_t PKT_ADDRESS = 1;                              //!< Index to first byte of packet address field
    const uint8_t PKT_FRAME_CONTROL = PKT_ADDRESS + 4;          //!< Index to packet fCtrl field @see UplinkControl
    const uint8_t PKT_FRAME_COUNTER = PKT_FRAME_CONTROL + 1;    //!< Index to packet frame counter field
    const uint8_t PKT_OPTIONS_START = PKT_FRAME_COUNTER + 2;    //!< Index to start of optional mac commands

    const uint8_t PKT_JOIN_APP_NONCE = 1;                       //!< Index to application nonce in Join Accept message
    const uint8_t PKT_JOIN_NETWORK_ID = 4;                      //!< Index to network id in Join Accept message
    const uint8_t PKT_JOIN_NETWORK_ADDRESS = 7;                 //!< Index to network address in Join Accept message
    const uint8_t PKT_JOIN_DL_SETTINGS = 11;                    //!< Index to downlink settings in Join Accept message
    const uint8_t PKT_JOIN_RX_DELAY = 12;                       //!< Index to rx delay in Join Accept message

    const uint8_t ADR_ACK_LIMIT = 64;                           //!< Number of packets without ADR ACK Request
    const uint8_t ADR_ACK_DELAY = 32;                           //!< Number of packets to expect ADR ACK Response within

    const uint16_t ACK_TIMEOUT = 2000;                          //!< Base millisecond timeout to resend after missed ACK
    const uint16_t ACK_TIMEOUT_RND = 1000;                      //!< Random millisecond adjustment to resend after missed ACK

    const uint8_t FRAME_OVERHEAD = 13;                          //!< Bytes of network info overhead in a frame

    /**
     * Settings to choose ChannelPlan
     */
    enum FrequencyBand {
        EU868,      //!< EU 863-870 16 channel uplink
        US915,      //!< US 902-928 64-125k/8-500k uplink and 8-500k downlink channels
        AU915,      //!< US 915-928 64-125k/8-500k uplink and 8-500k downlink channels
        CN779,      //!<
        CN470,      //!<
        EU433,      //!<
    };

    /**
     * Settings for type of network
     * PUBLIC - defaults to 5/6 second join windows and 0x34 sync word
     * PRIVATE - defaults to 1/2 second join windows and 0x12 sync word
     */
    enum NetworkType {
        PRIVATE = 0,
        PUBLIC = 1,
        PEER_TO_PEER = 4
    };

    /**
     * Enum for on/off settings
     */
    enum Enabled {
        OFF = 0,
        ON = 1
    };

    /**
     * Return status of mac functions
     */
    enum MacStatus {
        LORA_OK = 0,
        LORA_ERROR = 1,
        LORA_JOIN_ERROR = 2,
        LORA_SEND_ERROR = 3,
        LORA_MIC_ERROR = 4,
        LORA_ADDRESS_ERROR = 5,
        LORA_NO_CHANS_ENABLED = 6,
        LORA_COMMAND_BUFFER_FULL = 7,
        LORA_UNKNOWN_MAC_COMMAND = 8,
        LORA_ADR_OFF = 9,
        LORA_BUSY = 10,
        LORA_LINK_BUSY = 11,
        LORA_RADIO_BUSY = 12,
        LORA_BUFFER_FULL = 13,
        LORA_JOIN_BACKOFF = 14,
        LORA_NO_FREE_CHAN = 15,
        LORA_AGGREGATED_DUTY_CYCLE = 16,
        LORA_MAC_COMMAND_ERROR = 17,
        LORA_MAX_PAYLOAD_EXCEEDED = 18
    };

    /**
     * State for Link
     */
    enum LinkState {
        LINK_IDLE = 0,  //!< Link ready to send or receive
        LINK_TX,        //!< Link is busy sending
        LINK_ACK_TX,    //!< Link is busy resending after missed ACK
        LINK_REP_TX,    //!< Link is busy repeating
        LINK_RX,        //!< Link has receive window open
        LINK_RX1,       //!< Link has first received window open
        LINK_RX2,       //!< Link has second received window open
        LINK_RXC,       //!< Link has class C received window open
        LINK_P2P,       //!< Link is busy sending
    };

    /**
     * State for MAC
     */
    enum MacState {
        MAC_IDLE,
        MAC_RX1,
        MAC_RX2,
        MAC_RXC,
        MAC_TX,
        MAC_JOIN
    };

    /**
     * Operation class for device
     */
    enum MoteClass {
        CLASS_A = 0x00, //!< Device can only receive in windows opened after a transmit
        CLASS_B = 0x01, //!< Device can receive in windows sychronized with gateway beacon
        CLASS_C = 0x02  //!< Device can receive any time when not transmitting
    };

    /**
     * Direction of a packet
     */
    enum Direction {
        DIR_UP = 0,     //!< Packet is sent from mote to gateway
        DIR_DOWN = 1,   //!< Packet was received from gateway
        DIR_PEER = 2    //!< Packet was received from peer
    };


    /**
     * Received window used by Link
     */
    enum ReceiveWindows {
        RX_1 = 1,           //!< First receive window
        RX_2,               //!< Second receive window
        RX_BEACON,          //!< Beacon receive window
        RX_SLOT,             //!< Beacon Slot receive window
        RX_TEST
    };

    /**
     * Datarate range for a Channel
     */
    typedef union {
            int8_t Value;
            struct {
                    int8_t Min :4;
                    int8_t Max :4;
            } Fields;
    } DatarateRange;

    /**
     * Datarate used for transmitting and receiving
     */
    typedef struct Datarate {
            uint8_t Index;
            uint8_t Bandwidth;
            uint8_t Coderate;
            uint8_t PreambleLength;
            uint8_t SpreadingFactor;
            uint8_t Crc;
            uint8_t TxIQ;
            uint8_t RxIQ;
            uint8_t SymbolTimeout();
            Datarate();
    } Datarate;

    /**
     * Channel used for transmitting
     */
    typedef struct {
            uint8_t Index;
            uint32_t Frequency;
            DatarateRange DrRange;
    } Channel;

    /**
     * Receive window
     */
    typedef struct {
            uint8_t Index;
            uint32_t Frequency;
            uint8_t DatarateIndex;
    } RxWindow;

    /**
     * Duty band for limiting time-on-air for regional regulations
     */
    typedef struct {
            uint8_t Index;
            uint32_t FrequencyMin;
            uint32_t FrequencyMax;
            uint8_t PowerMax;
            uint16_t DutyCycle;          //!< Multiplier of time on air, 0:100%, 1:50%, 2:33%, 10:10%, 100:1%, 1000,0.1%
            uint32_t TimeOffEnd;         //!< Timestamp when this band will be available
    } DutyBand;

    /**
     * Device configuration
     */
    typedef struct {
            uint8_t FrequencyBand;      //!< Used to choose ChannelPlan
            uint8_t EUI[8];             //!< Unique identifier assigned to device
    } DeviceConfig;

    /**
     * Network configuration
     */
    typedef struct {
            uint8_t Mode;               //!< PUBLIC, PRIVATE or PEER_TO_PEER network mode
            uint8_t Class;              //!< Operating class of device
            uint8_t EUI[8];             //!< Network ID or AppEUI
            uint8_t Key[16];            //!< Network Key or AppKey
            uint8_t JoinDelay;          //!< Number of seconds to wait before 1st RX Window
            uint8_t RxDelay;            //!< Number of seconds to wait before 1st RX Window
            uint8_t ChannelGroup;       //!< ChannelGroup used for US915 hybrid operation 0:72 channels, 1:1-8 channels ...
            uint8_t AckAttempts;        //!< Number of attempts to send packet and receive an ACK from server
            uint8_t Retries;            //!< Number of times to resend a packet without receiving an ACK, redundancy
            uint8_t ADREnabled;         //!< Enable adaptive datarate
            uint8_t CADEnabled;         //!< Enable listen before talk/channel activity detection
            uint8_t RepeaterMode;       //!< Limit payloads to repeater compatible sizes
            uint8_t TxPower;            //!< Default radio output power in dBm
            uint8_t TxPowerMax;         //!< Max transmit power
            uint8_t TxDatarate;         //!< Datarate for P2P transmit
            uint32_t TxFrequency;       //!< Frequency for P2P transmit
            int8_t AntennaGain;         //!< Antenna Gain
            uint8_t DisableEncryption;  //!< Disable Encryption
            uint8_t DisableCRC;        //!< Disable CRC on uplink packets
            uint16_t P2PACKTimeout;
            uint16_t P2PACKBackoff;
            uint8_t JoinRx1DatarateOffset;  //!< Offset for datarate for first window
            uint32_t JoinRx2Frequency;      //!< Frequency used in second window
            uint8_t JoinRx2DatarateIndex;   //!< Datarate for second window
    } NetworkConfig;

    /**
     * Network session info
     * Some settings are acquired in join message and others may be changed through Mac Commands from server
     */
    typedef struct {
            uint8_t Joined;                     //!< State of session
            uint8_t Rx1DatarateOffset;          //!< Offset for datarate for first window
            uint32_t Rx2Frequency;              //!< Frequency used in second window
            uint8_t Rx2DatarateIndex;           //!< Datarate for second window
            uint8_t TxPower;                    //!< Current total radiated output power in dBm
            uint8_t TxDatarate;                 //!< Current datarate can be changed when ADR is enabled
            uint32_t Address;                   //!< Network address
            uint32_t NetworkID;                 //!< Network ID 24-bits
            uint8_t NetworkSessionKey[16];      //!< Network session key
            uint8_t ApplicationSessionKey[16];  //!< Data session key
            uint16_t ChannelMask[4];            //!< Current channel mask
            uint16_t ChannelMask500k;           //!< Current channel mask for 500k channels
            uint32_t DownlinkCounter;           //!< Downlink counter of last packet received from server
            uint32_t UplinkCounter;             //!< Uplink counter of last packet received from server
            uint8_t Redundancy;                 //!< Number of time to repeat an uplink
            uint8_t MaxDutyCycle;               //!< Current Max Duty Cycle value
            uint32_t JoinTimeOnAir;              //!< Balance of time on air used during join attempts
            uint32_t JoinTimeOffEnd;            //!< RTC time of next join attempt
            uint32_t JoinFirstAttempt;          //!< RTC time of first failed join attempt
            uint32_t AggregatedTimeOffEnd;      //!< Time off air expiration for aggregate duty cycle
            uint16_t AggregateDutyCycle;        //!< Used for enforcing time-on-air
            uint8_t AckCounter;                 //!< Current number of packets sent without ACK from server
            uint8_t AdrCounter;                 //!< Current number of packets received without downlink from server
            uint8_t RxDelay;                    //!< Number of seconds to wait before 1st RX Window
            uint8_t CommandBuffer[COMMANDS_BUFFER_SIZE]; //!< Buffer to hold Mac Commands and parameters to be sent in next packet
            uint8_t CommandBufferIndex;         //!< Index to place next Mac Command, also current size of Command Buffer
            bool SrvRequestedAck;               //!< Indicator of ACK requested by server in last packet received
            bool DataPending;                   //!< Indicator of data pending at server
            uint8_t RxTimingSetupReqReceived;   //!< Indicator that RxTimingSetupAns should be included in uplink
            uint8_t RxParamSetupReqAnswer;      //!< Indicator that RxParamSetupAns should be included in uplink
    } NetworkSession;

    /**
     * Multicast session info
     */
    typedef struct {
            uint32_t Address;               //!< Network address
            uint8_t NetworkSessionKey[16];  //!< Network session key
            uint8_t DataSessionKey[16];     //!< Data session key
            uint32_t DownlinkCounter;       //!< Downlink counter of last packet received from server
    } MulticastSession;

    /**
     * Application configuration
     */
    typedef struct {
            uint8_t Port;                   //!< Port used by application
            uint8_t AppEUI;                 //!< Application ID
            uint8_t AppKey[16];             //!< Application Key
    } ApplicationConfig;

    /**
     * Statistics of current network session
     */
    typedef struct Statistics {
            uint32_t Up;                    //!< Number of uplink packets sent
            uint32_t Down;                  //!< Number of downlink packets received
            uint32_t Joins;                 //!< Number of join requests sent
            uint32_t JoinFails;             //!< Number of join requests without response or invalid response
            uint32_t MissedAcks;            //!< Number of missed acknowledgement attempts of confirmed packets
            uint32_t CRCErrors;             //!< Number of CRC errors in received packets
            int32_t AvgCount;              //!< Number of packets used to compute rolling average of RSSI and SNR
            int16_t Rssi;                   //!< RSSI of last packet received
            int16_t RssiMin;                //!< Minimum RSSI of last AvgCount packets
            int16_t RssiMax;                //!< Maximum RSSI of last AvgCount packets
            int16_t RssiAvg;                //!< Rolling average RSSI of last AvgCount packets
            int16_t Snr;                     //!< SNR of last packet received
            int16_t SnrMin;                  //!< Minimum SNR of last AvgCount packets
            int16_t SnrMax;                  //!< Maximum SNR of last AvgCount packets
            int16_t SnrAvg;                  //!< Rolling average SNR of last AvgCount packets
    } Statistics;

    /**
     *  Testing settings
     */
    typedef struct {
            uint8_t TestMode;
            uint8_t SkipMICCheck;
            uint8_t DisableDutyCycle;
            uint8_t DisableRx1;
            uint8_t DisableRx2;
            uint8_t FixedUplinkCounter;
            uint8_t DisableRandomJoinDatarate;
    } Testing;

    /**
     * Combination of device, network, testing settings and statistics
     */
    typedef struct {
            DeviceConfig Device;
            NetworkConfig Network;
            NetworkSession Session;
            ApplicationConfig Applications[MAX_APPS];
            MulticastSession Multicast[MAX_MULTICAST_SESSIONS];
            Statistics Stats;
            Testing Test;
    } Settings;

    /**
     * Downlink settings sent in Join Accept message
     */
    typedef union {
            uint8_t Value;
            struct {
                    uint8_t Rx2Datarate :4;
                    uint8_t Rx1Offset :3;
                    uint8_t RFU :1;
            };
    } DownlinkSettings;

    /**
     * Frame structure for Join Request
     */
    typedef struct {
            uint8_t Type;
            uint8_t AppEUI[8];
            uint8_t DevEUI[8];
            uint8_t Nonce[2];
            uint8_t MIC[4];
    } JoinRequestFrame;

    /**
     * Mac header of uplink and downlink packets
     */
    typedef union {
            uint8_t Value;
            struct {
                    uint8_t Major :2;
                    uint8_t RFU :3;
                    uint8_t MType :3;
            } Bits;
    } MacHeader;

    /**
     * Frame control field of uplink packets
     */
    typedef union {
            uint8_t Value;
            struct {
                    uint8_t OptionsLength :4;
                    uint8_t ClassB :1;
                    uint8_t Ack :1;
                    uint8_t AdrAckReq :1;
                    uint8_t Adr :1;
            } Bits;
    } UplinkControl;

    /**
     * Frame control field of downlink packets
     */
    typedef union {
            uint8_t Value;
            struct {
                    uint8_t OptionsLength :4;
                    uint8_t FPending :1;
                    uint8_t Ack :1;
                    uint8_t RFU :1;
                    uint8_t Adr :1;
            } Bits;
    } DownlinkControl;

    /**
     * Frame type of packet
     */
    typedef enum {
        FRAME_TYPE_JOIN_REQ = 0x00,
        FRAME_TYPE_JOIN_ACCEPT = 0x01,
        FRAME_TYPE_DATA_UNCONFIRMED_UP = 0x02,
        FRAME_TYPE_DATA_UNCONFIRMED_DOWN = 0x03,
        FRAME_TYPE_DATA_CONFIRMED_UP = 0x04,
        FRAME_TYPE_DATA_CONFIRMED_DOWN = 0x05,
        FRAME_TYPE_RFU = 0x06,
        FRAME_TYPE_PROPRIETARY = 0x07,
    } FrameType;

    /**
     * LoRaWAN mote MAC commands
     */
    typedef enum {
        /* Class A */
        MOTE_MAC_LINK_CHECK_REQ = 0x02,
        MOTE_MAC_LINK_ADR_ANS = 0x03,
        MOTE_MAC_DUTY_CYCLE_ANS = 0x04,
        MOTE_MAC_RX_PARAM_SETUP_ANS = 0x05,
        MOTE_MAC_DEV_STATUS_ANS = 0x06,
        MOTE_MAC_NEW_CHANNEL_ANS = 0x07,
        MOTE_MAC_RX_TIMING_SETUP_ANS = 0x08,

        /* Class B */
        MOTE_MAC_PING_SLOT_INFO_REQ = 0x09,
        MOTE_MAC_PING_SLOT_FREQ_ANS = 0x0a,
        MOTE_MAC_PING_SLOT_CHANNEL_ANS = 0x0a,
        MOTE_MAC_BEACON_TIMING_REQ = 0x0b,
        MOTE_MAC_BEACON_FREQ_ANS = 0x0c,

        /* Multitech */
        MOTE_MAC_PING_REQ = 0x80,
        MOTE_MAC_CHANGE_CLASS = 0x81,
        MOTE_MAC_MULTIPART_START_REQ = 0x82,
        MOTE_MAC_MULTIPART_START_ANS = 0x83,
        MOTE_MAC_MULTIPART_CHUNK = 0x84,
        MOTE_MAC_MULTIPART_END_REQ = 0x85,
        MOTE_MAC_MULTIPART_END_ANS = 0x86
    } MoteCommand;

    /*!
     * LoRaWAN server MAC commands
     */
    typedef enum {
        /* Class A */
        SRV_MAC_LINK_CHECK_ANS = 0x02,
        SRV_MAC_LINK_ADR_REQ = 0x03,
        SRV_MAC_DUTY_CYCLE_REQ = 0x04,
        SRV_MAC_RX_PARAM_SETUP_REQ = 0x05,
        SRV_MAC_DEV_STATUS_REQ = 0x06,
        SRV_MAC_NEW_CHANNEL_REQ = 0x07,
        SRV_MAC_RX_TIMING_SETUP_REQ = 0x08,

        /* Class B */
        SRV_MAC_PING_SLOT_INFO_ANS = 0x09,
        SRV_MAC_PING_SLOT_FREQ_REQ = 0x0a,
        SRV_MAC_PING_SLOT_CHANNEL_REQ = 0x0a,
        SRV_MAC_BEACON_TIMING_ANS = 0x0b,
        SRV_MAC_BEACON_FREQ_REQ = 0x0c,

        /* Multitech */
        SRV_MAC_PING_ANS = 0x80,
        SRV_MAC_CHANGE_CLASS = 0x81,
        SRV_MAC_MULTIPART_START_REQ = 0x82,
        SRV_MAC_MULTIPART_START_ANS = 0x83,
        SRV_MAC_MULTIPART_CHUNK = 0x84,
        SRV_MAC_MULTIPART_END_REQ = 0x85,
        SRV_MAC_MULTIPART_END_ANS = 0x86
    } ServerCommand;

    /**
     * Random seed for software RNG
     */
    void srand(uint32_t seed);

    /**
     * Software RNG for consistent results across differing hardware
     */
    int rand(void);

    /**
     * Generate random number bounded by min and max
     */
    int32_t rand_r(int32_t min, int32_t max);

    uint8_t CountBits(uint16_t mask);

    /**
     * Copy 3-bytes network order from array into LSB of integer value
     */
    void CopyNetIDtoInt(const uint8_t* arr, uint32_t& val);

    /**
     * Copy LSB 3-bytes from integer value into array network order
     */
    void CopyNetIDtoArray(uint32_t val, uint8_t* arr);

    /**
     * Copy 4-bytes network order from array in to integer value
     */
    void CopyAddrtoInt(const uint8_t* arr, uint32_t& val);

    /**
     * Copy 4-bytes from integer in to array network order
     */
    void CopyAddrtoArray(uint32_t val, uint8_t* arr);

    /**
     * Copy 3-bytes network order from array into integer value and multiply by 100
     */
    void CopyFreqtoInt(const uint8_t* arr, uint32_t& freq);

    /**
     * Reverse memory copy
     */
    void memcpy_r(uint8_t *dst, const uint8_t *src, size_t n);

}

#endif

