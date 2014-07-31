#pragma once

enum PinnedDownPacketType
{
	LoginSuccess
};

struct PinnedDownPacket
{
	PinnedDownPacketType packetType;
	int dataSize;
};