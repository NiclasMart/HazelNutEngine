#pragma once
#include "HazelNut/Core.h"


namespace HazelNut {

	class HAZELNUT_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(class Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer * layer);
		void PopOverlay(Layer* overlay);

		void PassEventToLayers(class Event& event);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }
	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;
	};
}

