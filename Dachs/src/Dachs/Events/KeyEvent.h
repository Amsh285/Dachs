#pragma once

#include "dspch.h"

#include "Event.h"

namespace Dachs
{
	class DACHS_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(const int& keyCode)
			: m_KeyCode(keyCode) {}

		int m_KeyCode;
	};

	class DACHS_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(const int& keyCode, const int& repeatCount)
			: KeyEvent(keyCode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class DACHS_API KeyReleasedEvent : public KeyEvent
	{
		KeyReleasedEvent(const int& keyCode)
			: KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}
