#pragma once

#include "EntityManager.h"
#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct StructureChangedEvent : public PinnedDownCore::Event
		{
			static const HashedString StructureChangedEventType;

			const HashedString & GetEventType() const
			{
				return StructureChangedEventType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}

			Entity entity;
			int newStructure;

			explicit StructureChangedEvent() : StructureChangedEvent(INVALID_ENTITY_ID, 0)
			{
			}

			explicit StructureChangedEvent(Entity entity, int newStructure)
			{
				this->entity = entity;
				this->newStructure = newStructure;
			}

			void Serialize(std::ostrstream& out) const;
			void Deserialize(std::istrstream& in);

			std::string ToString() const
			{
				return std::string("Structure of entity " + std::to_string(this->entity) + " changed to " + std::to_string(this->newStructure));
			}
		};
	}
}