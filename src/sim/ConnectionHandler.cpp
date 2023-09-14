#include "ConnectionHandler.hpp"

boost::asio::io_context ConnectionHandler::io;
boost::asio::ip::tcp::endpoint ConnectionHandler::endpoint;

void ConnectionHandler::sendMessage() {
	boost::asio::ip::tcp::socket socket(io);

	socket.connect(endpoint);

	std::string message;

	//boost::asio::write(message);

}

void ConnectionHandler::listenMessage() {
	boost::asio::ip::tcp::acceptor acceptor(io, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 8000));
	boost::asio::ip::tcp::socket socket(io);

	boost::system::error_code ec;
	std::array<char, 128> buffer;

	for (;;) {
		acceptor.accept(socket, ec);

		size_t length = socket.read_some(boost::asio::buffer(buffer), ec);
		if (ec) {
			std::cout << "Error\n";
		}
		else {
			std::cout << std::string(buffer.data(), length) << std::endl;
		}
	}

}