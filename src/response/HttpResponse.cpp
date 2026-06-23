#include "http/HttpResponse.hpp"
#include <iostream>

HttpResponse::HttpResponse()
{
	std::cout << "HttpResponse Default constructor called" << std::endl;
}

HttpResponse::HttpResponse(const HttpResponse& other)
{
	std::cout << "HttpResponse Copy constructor called" << std::endl;
	*this = other;
}

HttpResponse& HttpResponse::operator=(const HttpResponse& rhs)
{
	std::cout << "HttpResponse Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		
	}
	return (*this);
}

HttpResponse::~HttpResponse()
{
	std::cout << "HttpResponse Destructor called" << std::endl;
}

std::string HttpResponse::reasonFor(int code)
{
	//I need to filter it out into make, makeError and invalid code
}

HttpResponse HttpResponse::make(int code, std::string body)
{

}

HttpResponse HttpResponse::makeError(int code)
{

}

void HttpResponse::setHeader(const std::string &name,const std::string &value)
{

}

std::string HttpResponse::getHeader(const std::string &name) const
{

}

bool HttpResponse::hasHeader(const std::string &name) const
{

}
