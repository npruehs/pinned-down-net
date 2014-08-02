#pragma once

#define PINNED_DOWN_SERVER_PORT "27015"

enum ServerEventType
{
	LoginSuccess
};

enum ClientActionType
{
	SelectCard
};

struct ServerEvent
{
	ServerEvent() { }

	ServerEvent(ServerEventType eventType)
	{
		this->eventType = eventType;
	}

	ServerEventType eventType;
};

struct ClientAction
{
	ClientAction() { }

	ClientAction(ClientActionType actionType)
	{
		this->actionType = actionType;
	}

	ClientActionType actionType;
};