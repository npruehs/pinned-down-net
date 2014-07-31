#pragma once

enum PinnedDownPacketType
{
	LoginSuccess
};

struct PinnedDownPacket
{
	PinnedDownPacketType packetType;
	unsigned int dataSize;
};