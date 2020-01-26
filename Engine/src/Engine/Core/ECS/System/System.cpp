#include "ECS/System/System.h"
#include "ECS/Entity/Entity.h"

namespace Engine
{
	namespace ECS
	{
		System::System() :
			mEntities(),
			mECSManager(nullptr)
		{

		}

		System::~System()
		{

		}

		void System::AddEntity(std::shared_ptr<Entity> aEntity)
		{
			mEntities.push_back(aEntity);
		}

		void System::RemoveEntity(std::shared_ptr<Entity> aEntity)
		{
			for (auto EntityIterator = mEntities.cbegin(); EntityIterator != mEntities.end(); ++EntityIterator)
			{
				if (*EntityIterator == aEntity)
				{
					mEntities.erase(EntityIterator);
					break;
				}
			}
		}

		void System::SetComponentsMask(const BitMask& aComponentsMask)
		{
			mComponentsMask = aComponentsMask;
		}
		
		const BitMask& System::GetComponentsMask() const
		{
			return mComponentsMask;
		}

		bool System::ComponentFits(tComponentFamilyId aComponentFamilyId) const
		{
			return mComponentsMask.IsBitSetted(aComponentFamilyId);
		}
	}
}