// EventHandler.cpp

#include "EventHandler.hpp"

void EventHandler::registerCallback(const Event& onEvent, const Callback& eventCallback) {
	if (eventSubscribers.find(onEvent) != eventSubscribers.end()) {
		auto& eventCallbacks = eventSubscribers[onEvent];
		if (std::find(eventCallbacks.begin(), eventCallbacks.end(), eventCallback) == eventCallbacks.end()) {
			eventCallbacks.push_back(eventCallback);
		}
		else {
			//ErrorHandler::handleNoEventSubscriberFoundError();
		}
	}
}

void EventHandler::notify(const Event& onEvent) {
	auto eventsIterator = eventSubscribers.find(onEvent);
	if (eventsIterator != eventSubscribers.end()) {
		for (const auto callback : eventSubscribers[onEvent]) {
			callback();
		}
	}
}