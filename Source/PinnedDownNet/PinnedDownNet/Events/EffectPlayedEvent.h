#pragma once

#include "EntityManager.h"
#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct EffectPlayedEvent : public Event
		{
			static const HashedString EffectPlayedEventType;

			const HashedString & GetEventType() const
			{
				return EffectPlayedEventType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}

			Entity effectEntity;
			Entity targetEntity;

			explicit EffectPlayedEvent() : EffectPlayedEvent(INVALID_ENTITY_ID, INVALID_ENTITY_ID)
			{
			}

			explicit EffectPlayedEvent(Entity effectEntity, Entity targetEntity)
			{
				this->effectEntity = effectEntity;
				this->targetEntity = targetEntity;
			}
		};
	}
}