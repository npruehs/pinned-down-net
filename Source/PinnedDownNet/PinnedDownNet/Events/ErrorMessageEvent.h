#pragma once

#include <string>

#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct ErrorMessageEvent : public PinnedDownCore::Event
		{
			static const HashedString ErrorMessageEventType;

			const HashedString & GetEventType() const
			{
				return ErrorMessageEventType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}

			std::string errorMessage;

			explicit ErrorMessageEvent() : ErrorMessageEvent("")
			{
			}

			explicit ErrorMessageEvent(std::string errorMessage)
			{
				this->errorMessage = errorMessage;
			}

			void Serialize(std::ostrstream& out);
			void Deserialize(std::istrstream& in);

			std::wstring ToString()
			{
				std::wstring errorMessageW(errorMessage.begin(), errorMessage.end());
				return std::wstring(L"Error: " + errorMessageW);
			}
		};
	}
}