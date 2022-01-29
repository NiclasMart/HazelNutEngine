#pragma once

#include "hzn_pch.h"
#include "HazelNut/Core.h"

namespace HazelNut {

	//Events in HazelNut are currently blocking, meaning when an event occurs it
	//immediately gets dispatched and must be dealt with right then an there.
	//For the future, a better strategy might be to buffer events in an event 
	//bus and process them during the "event" part of the update stage.

	//enum class is used, because EventCategory uses None as name too 
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	//the category can be used to filter certain event types
	//they are implemented as bit fields because an event can belong to different categories
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = SET_BITMAP(0),
		EventCategoryInput = SET_BITMAP(1),
		EventCategoryKeyboard = SET_BITMAP(2),
		EventCategoryMouse = SET_BITMAP(3),
		EventCategoryMouseButton = SET_BITMAP(4)
	};

/*
The following two macros help to implement all virtual functions into the derived classes of Event.
They allow to easily implement these functions without copy pasting a lot of code. The GetStaticType function
allows to get the type from the class without having an instance.
*/
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class HAZELNUT_API Event
	{
	public:
		bool Handled = false;
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		//can be overridden if further information then the name are needed only used for debugging
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			//uses bitwise AND to determine if there is an category match
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			:m_Event(event)
		{
		}

		// gets called with a specific event type and a corresponding function
		// if the event type matches the stored event type, the function gets executed
		// else return false and the function could potentially be called with every event type
		// until a type matches and the right function gets called
		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}
