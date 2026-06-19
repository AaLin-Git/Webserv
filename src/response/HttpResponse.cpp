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

