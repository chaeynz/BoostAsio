#pragma once

#include <iostream>

#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

class printer
{
public:
	printer(boost::asio::io_context& io) : timer_(io, boost::asio::chrono::seconds(1)), count_(0)
	{

	}
};