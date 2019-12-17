#pragma once
#include <string>
#include "../Core/Core.h"
#include "../Core/Events/Event.h"
#include "../Core/Events/EventTypes.h"

namespace Engine
{
	class Application;

	class ENGINE_API Module
	{
	public:

		Module(const std::string& aName, Application* aApplication)
		{
			mName = aName;
			mApplication = aApplication;
		}

		virtual ~Module() {}
		virtual bool Awake() = 0;
		virtual bool Init() = 0;
		virtual bool CleanUp() = 0;
		virtual bool PreUpdate() = 0;
		virtual bool Update() = 0;
		virtual bool PostUpdate() = 0;

		virtual void OnMouseEvent(int aButton, int aAction) {}
		virtual void OnResizeWindowEvent(unsigned int aWidth, unsigned int aHeight) {}

		inline const std::string& GetName() const { return mName; }

	protected:
		std::string mName;
		Application* mApplication;
	};
}

