#include "ModuleCamera.h"
#include "Window/ModuleWindow.h"
#include "Camera/PerspectiveCamera.h"

namespace Engine
{
	const float		CameraDeltaMovement = 2.f;
	const float		CameraRotationSensibility = 0.5f;

	std::shared_ptr<Camera> ModuleCamera::mCamera = std::make_shared<PerspectiveCamera>(); //TODO read params from config file

	ModuleCamera::ModuleCamera(Application* aApplication) :
		Module("Camera", aApplication),
		mRotateCamera(false),
		mPreviousCursorX(0.0f),
		mPreviousCursorY(0.0f)
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

	void ModuleCamera::OnCursorMovedEvent(float aXPos, float aYPos)
	{
		if (mRotateCamera)
		{
			float XIncr = aXPos - mPreviousCursorX;
			if (XIncr != 0.f)
			{
				float Yaw = mCamera->GetYaw() + CameraRotationSensibility * XIncr;
				mCamera->SetYaw(Yaw);
			}

			float YIncr = -(aYPos - mPreviousCursorY);
			if (YIncr != 0.f)
			{
				float Pitch = mCamera->GetPitch() + CameraRotationSensibility * YIncr;
				mCamera->SetPitch(Pitch);
			}
		}

		mPreviousCursorX = aXPos;
		mPreviousCursorY = aYPos;
	}

	void ModuleCamera::OnMouseButtonEvent(MouseButton aMouseButton, InputAction aInputAction)
	{
		if (aMouseButton == MouseButton::Left)
		{
			switch (aInputAction)
			{
				case InputAction::Pressed:
					mRotateCamera = true;
				break;
				case InputAction::Released:
					mRotateCamera = false;
				break;
			}
		}
	}

	void ModuleCamera::OnKeyWindowEvent(KeyId aKeyId, InputAction aInputAction)
	{
		//TODO move this to update to apply delta time to speed
		float CameraSpeed = CameraDeltaMovement;
		if (aInputAction == InputAction::Pressed)
		{
			glm::vec3 CameraPosition = mCamera->GetPosition();
			glm::vec3 CameraViewDirection = mCamera->GetViewDirection();
			glm::vec3 CameraRightDirection = mCamera->GetRightDirection();
			glm::vec3 CameraUpDirection = mCamera->GetUpDirection();

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
				case Engine::KeyId::Q:
					CameraPosition += CameraSpeed * CameraUpDirection;
				break;
				case Engine::KeyId::E:
					CameraPosition -= CameraSpeed * CameraUpDirection;
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