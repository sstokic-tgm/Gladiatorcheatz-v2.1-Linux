#pragma once

#include "../misc/CUserCmd.h"

#define MULTIPLAYER_BACKUP 150

class bf_write;
class bf_read;
class CVerifiedUserCmd;

class CInput
{
public:
	bool                m_fTrackIRAvailable;
	bool                m_fMouseInitialized;
	bool                m_fMouseActive;
	bool                m_fJoystickAdvancedInit;
	char                pad_0x08[0x2C];
	void*               m_pKeys;
	char                pad_0x38[0x64];
	int                 pad_0x41;
	int                 pad_0x42;
	bool                m_fCameraInterceptingMouse;
	bool                m_fCameraInThirdPerson;
	bool                m_fCameraMovingWithMouse;
	Vector              m_vecCameraOffset;
	bool                m_fCameraDistanceMove;
	int                 m_nCameraOldX;
	int                 m_nCameraOldY;
	int                 m_nCameraX;
	int                 m_nCameraY;
	bool                m_CameraIsOrthographic;
	Vector              m_angPreviousViewAngles;
	Vector              m_angPreviousViewAnglesTilt;
	float               m_flLastForwardMove;
	int                 m_nClearInputState;
	char                pad_0xE4[0x8];
	CUserCmd*           m_pCommands;
	CVerifiedUserCmd*   m_pVerifiedCommands;
};
