#include "Input.h"



CInput::CInput()
{
	memset(m_KeyCur, 0, sizeof(m_KeyCur));
	memset(m_KeyOld, 0, sizeof(m_KeyOld));
	memset(m_KeyMap, 0, sizeof(m_KeyMap));

	memset(m_BtnCur, 0, sizeof(m_BtnCur));
	memset(m_BtnOld, 0, sizeof(m_BtnOld));
	memset(m_BtnMap, 0, sizeof(m_BtnMap));
}


CInput::~CInput()
{

}

void CInput::Update()
{
	memcpy(m_KeyOld, m_KeyCur, sizeof(m_KeyOld));

	memset(m_KeyCur, 0, sizeof(m_KeyCur));
	memset(m_KeyMap, 0, sizeof(m_KeyMap));

	GetKeyboardState(m_KeyCur);

	for (int i = 0; i < MAX_INPUT_KEY; ++i)
	{
		BYTE vKey = m_KeyCur[i] & 0x80;
		m_KeyCur[i] = (vKey) ? 1 : 0;

		INT nOld = m_KeyOld[i];
		INT nCur = m_KeyCur[i];

		if (0 == nOld && 1 == nCur) m_KeyMap[i] = KS_DOWN;
		else if (1 == nOld && 0 == nCur) m_KeyMap[i] = KS_UP;
		else if (1 == nOld && 1 == nCur) m_KeyMap[i] = KS_PRESS;
		else							 m_KeyMap[i] = KS_NONE;
	}
}
BOOL CInput::KeyDown(int key)
{
	return m_KeyMap[key] == KS_DOWN;
}
BOOL CInput::KeyPress(int key)
{
	return m_KeyMap[key] == KS_PRESS;
}
BOOL CInput::KeyUp(int key)
{
	return m_KeyMap[key] == KS_UP;
}