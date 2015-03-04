#pragma once

#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct VerifyClientVersionAction : public PinnedDownCore::Event
		{
			static const HashedString VerifyClientVersionActionType;

			const HashedString & GetEventType() const
			{
				return VerifyClientVersionActionType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Server;
			}

			int major;
			int minor;
			int build;
			int revision;

			explicit VerifyClientVersionAction() : VerifyClientVersionAction(0, 0, 0, 0)
			{
			}

			explicit VerifyClientVersionAction(int major, int minor, int build, int revision)
				: major(major),
				minor(minor),
				build(build),
				revision(revision)
			{
			}

			void Serialize(std::ostrstream& out) const;
			void Deserialize(std::istrstream& in);

			std::string ToString() const
			{
				return std::string("Verify client version " +
					std::to_string(this->major) + "." +
					std::to_string(this->minor) + "." +
					std::to_string(this->build) + "." +
					std::to_string(this->revision));
			}
		};
	}
}