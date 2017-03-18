#pragma once
#include "stdafx.h"

#define MAX_INPUT_KEY	256

enum KeyState
{
	KS_NONE,
	KS_DOWN,
	KS_UP,
	KS_PRESS
};

class CInput
{
public:
	CInput();
	virtual ~CInput();

	BYTE m_KeyCur[MAX_INPUT_KEY];
	BYTE m_KeyOld[MAX_INPUT_KEY];
	BYTE m_KeyMap[MAX_INPUT_KEY];

	BYTE m_BtnCur[MAX_INPUT_KEY];
	BYTE m_BtnOld[MAX_INPUT_KEY];
	BYTE m_BtnMap[MAX_INPUT_KEY];

	void Update();

	BOOL KeyDown(int key);
	BOOL KeyPress(int key);
	BOOL KeyUp(int key);
};

