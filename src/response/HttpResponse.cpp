#include "http/HttpResponse.hpp"
#include <iostream>

HttpResponse::HttpResponse()
{}

HttpResponse::HttpResponse(const HttpResponse& other)
{
	*this = other;
}

HttpResponse& HttpResponse::operator=(const HttpResponse& rhs)
{
	if (this != &rhs)
	{
		
	}
	return (*this);
}

HttpResponse::~HttpResponse()
{}

std::string HttpResponse::reasonFor(int code)
{
	//I need to filter it out into make, makeError and invalid code
	static const std::map<int, std::string> lookupTable{
		{200, "OK"},
		{201, "Created"},
		{204, "No Content"},
		{301, "Moved Permanently"},
		{302, "Found"},
		{400, "Bad Request"},
		{403, "Forbidden"},
		{404, "Not Found"},
		{405, "Method Not Allowed"},
		{408, "Request Timeout"},
		{409, "Conflict"},
		{413, "Payload Too Large"},
		{414, "URI Too Long"},
		{500, "Internal Server Error"},
		{501, "Not Implemented"},
		{505, "HTTP Version Not Supported"}};
	auto it = lookupTable.find(code);
	if (it != lookupTable.end())
		return (it->second);
	else
		return ("Missing code");
}

HttpResponse HttpResponse::make(int code, std::string body)
{
	HttpResponse response;
	response.body = body;
	response.statusCode = code;
	response.statusText = reasonFor(code);
	return response;
}

static	std::string errorPage(int code)
{
	std::string defaultPage = R"(<html><body><h1>)" + std::to_string(code) + " "
		+ HttpResponse::reasonFor(code) + R"(</h1></body></html>)";
	return defaultPage;
}

HttpResponse HttpResponse::makeError(int code)
{
	HttpResponse response;
	response.statusCode = code;
	response.statusText = reasonFor(code);
	response.body = errorPage(code);
	response.setHeader("Content-Type", "text/html");
	return response;
}

void HttpResponse::setHeader(const std::string &name,const std::string &value)
{
	headers[name] = value;
}

std::string HttpResponse::getHeader(const std::string &name) const
{

}

bool HttpResponse::hasHeader(const std::string &name) const
{

}
