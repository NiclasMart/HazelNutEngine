#pragma once

#include "HazelNut/Layer.h"

namespace HazelNut {

	class HAZELNUT_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer()
			: Layer("ImGuiLayer") {}

		~ImGuiLayer() {};

		virtual void OnAttch() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnEvent(Event& event) override;
	private:
		float m_time;

		bool OnMouseButtonPressedEvent(class MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(class MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(class MouseMovedEvent& e);
		bool OnMouseScrolledEvent(class MouseScrollEvent& e);
		bool OnKeyPressedEvent(class KeyPressedEvent& e);
		bool OnKeyReleasedEvent(class KeyReleasedEvent& e);
		bool OnKeyTypedEvent(class KeyTypedEvent& e);
		bool OnWindowResizeEvent(class WindowResizeEvent& e);
	};
}

