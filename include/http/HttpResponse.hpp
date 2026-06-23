#ifndef HTTPRESPONSE_HPP
# define HTTPRESPONSE_HPP


# include <string>
# include <map>

class HttpResponse {
public:
	int statusCode = 200;
	std::string statusText;
	std::map<std::string, std::string> headers;
	std::string body;
	HttpResponse();
	HttpResponse(const HttpResponse& other);
	HttpResponse& operator=(const HttpResponse& rhs);
	~HttpResponse();
	static HttpResponse make(int code, std::string body = "");
	static HttpResponse makeError(int code);
	static std::string reasonFor(int code);
	void setHeader(const std::string &name,const std::string &value);
	std::string getHeader(const std::string &name) const;
	bool hasHeader(const std::string &name) const;
};

#endif
