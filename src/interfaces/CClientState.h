#pragma once

#include <cstdint>

class INetChannel
{
public:

	char pad_0000[20]; //0x0000
	bool m_bProcessingMessages; //0x0014
	bool m_bShouldDelete; //0x0015
	char pad_0016[2]; //0x0016
	int32_t m_nOutSequenceNr;    //0x0018 last send outgoing sequence number
	int32_t m_nInSequenceNr;     //0x001C last received incoming sequnec number
	int32_t m_nOutSequenceNrAck; //0x0020 last received acknowledge outgoing sequnce number
	int32_t m_nOutReliableState; //0x0024 state of outgoing reliable data (0/1) flip flop used for loss detection
	int32_t m_nInReliableState;  //0x0028 state of incoming reliable data
	int32_t m_nChokedPackets;    //0x002C number of choked packets
	char pad_0030[1044]; //0x0030
}; //Size: 0x0444

class CEventInfo
{
public:

	uint16_t classID; //0x0000 0 implies not in use
	char pad_0002[2]; //0x0002
	float fire_delay; //0x0004 If non-zero, the delay time when the event should be fired ( fixed up on the client )
	char pad_0008[4]; //0x0008
	ClientClass *pClientClass; //0x000C
	void *pData; //0x0010 Raw event data
	char pad_0014[48]; //0x0014
}; //Size: 0x0044

class CClientState
{

public:

    void ForceFullUpdate()
    {
		m_nDeltaTick = -1;
    }

	char _pad0[0x20C];
	int m_nDeltaTick;
	bool m_bPaused;
	char _pad1[0x3];
	int m_nViewEntity;
	char _pad2[0x8];
	char m_szLevelName[260];
	char m_szLevelNameShort[40];
}; //Size: 0x4E1C
