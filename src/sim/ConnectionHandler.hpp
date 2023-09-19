#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <memory>
#include <vector>

class ConnectionHandler {

public:
    ConnectionHandler(boost::asio::io_context& io_context, const std::string& server, const std::string& port);

    void receiveData(boost::asio::ip::tcp::endpoint sender);

private:
    boost::asio::io_context io;
    boost::asio::ip::address_v4 eaddress;
    boost::asio::ip::tcp::endpoint eendpoint;

    void do_connect(const std::string& server, const std::string& port);

    boost::asio::ip::tcp::resolver resolver_;
    boost::asio::ip::tcp::socket socket_;

    enum { maxLength = 1024 };
    char data_[maxLength];

    std::vector<boost::asio::ip::tcp::endpoint> endpoints;
};

