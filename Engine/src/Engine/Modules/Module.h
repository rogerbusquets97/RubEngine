#pragma once
#include <string>
#include "Core.h"
#include <Input/Inputs.h>
#include <vector>

namespace rubEngine
{
	class Application;

	class ENGINE_API Module
	{
	public:

		Module()
		{
		}

		virtual ~Module() {}
		virtual bool Awake() = 0;
		virtual bool Init() = 0;
		virtual bool CleanUp() = 0;
		virtual bool PreUpdate(float aDeltaTime) = 0;
		virtual bool Update(float aDeltaTime) = 0;
		virtual bool PostUpdate(float aDeltaTime) = 0;
		virtual void OnGUI() {};
	};
}

