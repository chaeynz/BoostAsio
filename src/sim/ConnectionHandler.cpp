#include "ConnectionHandler.hpp"
void execute() {
    boost::asio::io_context io_context;
    ConnectionHandler conn(io_context, "localhost", "8080");
    io_context.run();
}

ConnectionHandler::ConnectionHandler(boost::asio::io_context& io_context, const std::string& server, const std::string& port)
    : resolver_(io_context), socket_(io_context) {
    do_connect(server, port);
}
void ConnectionHandler::do_connect(const std::string& server, const std::string& port) {
    // Asynchronously resolve the server name
    resolver_.async_resolve(server, port,
        [this](boost::system::error_code ec, tcp::resolver::results_type endpoints) {
            if (!ec) {
                // Asynchronously connect to the first endpoint
                boost::asio::async_connect(socket_, endpoints, 
                    [this](boost::system::error_code ec, tcp::endpoint) {
                        if (!ec) { 
                            std::cout << "Connected successfully." << std::endl; 
                        }
                    }
                );
            }
        }
    );
}
