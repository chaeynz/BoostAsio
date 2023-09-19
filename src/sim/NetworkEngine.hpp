#pragma once
#include <memory>

#include "ConnectionHandler.hpp"

class NetworkEngine
{
	std::unique_ptr<ConnectionHandler> conn;

private:
	NetworkEngine() {

	}

	static std::unique_ptr<NetworkEngine> instancePtr;
public:
	NetworkEngine(const NetworkEngine& obj) = delete;
	static std::unique_ptr<NetworkEngine>& getInstance();
	void start();
};

