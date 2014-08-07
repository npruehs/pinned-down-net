#pragma once

namespace PinnedDownNet
{
	namespace Data
	{
		enum Affiliation
		{
			InvalidAffiliation,
			BlueWing,
			Enemy
		};

		inline std::string AffiliationToString(Affiliation affiliation)
		{
			switch (affiliation)
			{
			case Affiliation::BlueWing:
				return "Blue Wing";
				break;

			case Affiliation::Enemy:
				return "Enemy";
				break;

			default:
				return "Invalid";
				break;
			}
		}
	}
}