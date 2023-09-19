#include "NetworkEngine.hpp"

std::unique_ptr<NetworkEngine>& NetworkEngine::getInstance() {
	if (instancePtr == nullptr) {
		instancePtr = std::make_unique<NetworkEngine>();
	}
	return instancePtr;
}

void NetworkEngine::start() {

}