#pragma once

#include "Event.h"

namespace Kami {

	class KAMI_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
	};
}