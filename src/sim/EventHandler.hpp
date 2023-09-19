// EventHandler.hpp

#pragma once

#include <map>
#include <vector>
#include <functional>
#include <memory>
#include <string>

class EventHandler {
public:
	using Event = std::function<void()>;
	using Callback = std::function<void()>;

	static std::map <Event, std::vector<Callback>> eventSubscribers;

	static void registerCallback(const Event&, const Callback&);
	static void unregisterCallback(const Event&, const Callback&);
	static void notify(const Event&);

	static void onNetworkInputReceived();
	static void onUserNotFoundLocally();

};