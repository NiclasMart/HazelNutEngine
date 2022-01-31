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
	};
}

