#pragma once

#include "Event.h"

namespace Kami {

	class KAMI_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(uint32_t width, uint32_t height) : m_Width(width), m_Height(height) {}

		std::string ToString() const override {
			return fmt::format("WindowResizeEvent: [ {} x {} ]", m_Width, m_Height);
		}

		EVENT_CLASS_TYPE(WindowResize)
	private:
		uint32_t m_Width, m_Height;
	};

	class KAMI_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
	};
}