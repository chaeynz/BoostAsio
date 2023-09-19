#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;

class ConnectionHandler {
public:
    ConnectionHandler(boost::asio::io_context& io_context, const std::string& server, const std::string& port);

    void receiveData(boost::asio::ip::tcp::endpoint sender);

private:
    boost::asio::ip::address_v4 eaddress;
    boost::asio::ip::tcp::endpoint eendpoint;

    void do_connect(const std::string& server, const std::string& port);

    tcp::resolver resolver_;
    tcp::socket socket_;
};

