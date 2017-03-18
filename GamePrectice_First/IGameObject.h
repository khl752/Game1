#pragma once
#include "stdafx.h"

class GameObject;

class IGameObject
{
public:
	IGameObject();
	virtual ~IGameObject();

	virtual INT Init()					   = 0;
	virtual INT Render()				   = 0;
	virtual INT Update()				   = 0;
	virtual void Destroy()				   = 0;

	virtual void ThrowMessage() {};
};

enum MessageState
{


} typedef MSGSTATE;

template<typename Type_From>
struct Message
{
private:
	//---------- Owner
	const IGameObject* m_From;
	//----------  listener?
	const IGameObject* m_To;

	const MSGSTATE	  m_MsgState;
	const Type_From*  m_vpData;
public:

	const IGameObject* GetOwner()
	{
		return m_From;
	}
	const IGameObject* GetListener()
	{
		return m_To;
	}
	const MSGSTATE	   GetMsgState()
	{
		return m_vpData;
	}

	//if your MessageState == Data MessageState ? return data : fail
	Type_From* GetData(MessageState Ms_State)
	{
		if (Ms_State == m_MsgState)
			return m_vpData;
		else
			return nullptr;
	}

	Message(IGameObject* From_Obj,IGameObject* To_Obj, MSGSTATE state, void* data)
		: m_From(From_Obj),m_To(To_Obj), m_MsgState(state), m_vpData(data)
	{
	}

};