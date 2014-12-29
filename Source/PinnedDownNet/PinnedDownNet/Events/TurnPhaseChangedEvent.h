#pragma once

#include "Event.h"
#include "..\Data\TurnPhase.h"

using namespace PinnedDownCore;
using namespace PinnedDownNet::Data;

namespace PinnedDownNet
{
	namespace Events
	{
		struct TurnPhaseChangedEvent : public PinnedDownCore::Event
		{
			static const HashedString TurnPhaseChangedEventType;

			const HashedString & GetEventType() const
			{
				return TurnPhaseChangedEventType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}

			TurnPhase newTurnPhase;

			explicit TurnPhaseChangedEvent() : TurnPhaseChangedEvent(TurnPhase::InvalidTurnPhase)
			{
			}

			explicit TurnPhaseChangedEvent(TurnPhase newTurnPhase)
			{
				this->newTurnPhase = newTurnPhase;
			}

			void Serialize(std::ostrstream& out);
			void Deserialize(std::istrstream& in);

			std::wstring ToString()
			{
				std::string turnPhase = TurnPhaseToString(this->newTurnPhase);
				std::wstring turnPhaseW(turnPhase.begin(), turnPhase.end());

				return std::wstring(L"Turn phase changed: " + turnPhaseW);
			}
		};
	}
}