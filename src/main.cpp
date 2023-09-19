#include "sim/ConnectionHandler.hpp"
#include <memory>
#include <string>

void (*a)() = []() {};


int main() {
	std::shared_ptr<int> test = std::make_shared<int>(1);
	auto var = [&](int i) {
		std::cout << "Hello " << i << " " << test << " has " << *test;
		};

	std::shared_ptr<int> a = std::make_shared<int>(11);

	var(1);
	(*a)();

	boost::asio::io_context io;
	ConnectionHandler handlerx(io, "127.0.0.1", "4444");
}