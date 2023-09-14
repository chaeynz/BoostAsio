#include <iostream>
#include <string>
#include <boost/asio.hpp>

class ConnectionHandler {
	static boost::asio::io_context io;
	static boost::asio::ip::tcp::endpoint endpoint;
	static void sendMessage();
	static void listenMessage();
};