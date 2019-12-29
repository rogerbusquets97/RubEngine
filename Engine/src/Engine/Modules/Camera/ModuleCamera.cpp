#include "ModuleCamera.h"
#include "Window/ModuleWindow.h"
#include "Camera/PerspectiveCamera.h"

namespace Engine
{
	const float		CameraDeltaMovement = 2.f;

	std::shared_ptr<Camera> ModuleCamera::mCamera = std::make_shared<PerspectiveCamera>(); //TODO read params from config file

	ModuleCamera::ModuleCamera(Application* aApplication) :
		Module("Camera", aApplication)
	{
	}

	ModuleCamera::~ModuleCamera()
	{
	}

	bool ModuleCamera::Init()
	{
		mCamera->SetSize(ModuleWindow::GetWidth(), ModuleWindow::GetHeight());
		mCamera->SetPosition({0.f, 0.f, 2.f});
		return true;
	}

	bool ModuleCamera::Update(float aDeltaTime)
	{
		return true;
	}

	bool ModuleCamera::CleanUp()
	{
		return true;
	}

	bool ModuleCamera::Awake()
	{
		return true;
	}

	bool ModuleCamera::PreUpdate(float aDeltaTime)
	{
		return true;
	}

	bool ModuleCamera::PostUpdate(float aDeltaTime)
	{
		return true;
	}

	void ModuleCamera::OnMouseEvent(int aButton, int aAction)
	{

	}

	void ModuleCamera::OnKeyWindowEvent(KeyId aKeyId, KeyAction aKeyAction)
	{
		//TODO move this to update to apply delta time to speed
		float CameraSpeed = CameraDeltaMovement;
		if (aKeyAction == KeyAction::Pressed)
		{
			glm::vec3 CameraPosition = mCamera->GetPosition();
			glm::vec3 CameraViewDirection = mCamera->GetViewDirection();
			glm::vec3 CameraRightDirection = mCamera->GetRightDirection();

			switch (aKeyId)
			{
				case Engine::KeyId::W:
					CameraPosition += CameraSpeed * CameraViewDirection;
				break;
				case Engine::KeyId::S:
					CameraPosition -= CameraSpeed * CameraViewDirection;
				break;
				case Engine::KeyId::A:
					CameraPosition -= CameraSpeed * CameraRightDirection;
				break;
				case Engine::KeyId::D:
					CameraPosition += CameraSpeed * CameraRightDirection;
				break;
				default:
				break;
			}

			mCamera->SetPosition(CameraPosition);
		}
	}

	void ModuleCamera::OnResizeWindowEvent(unsigned int aWidth, unsigned int aHeight)
	{
		mCamera->SetSize(ModuleWindow::GetWidth(), ModuleWindow::GetHeight());
	}

	const std::shared_ptr<Camera> ModuleCamera::GetCamera()
	{
		return mCamera;
	}

}