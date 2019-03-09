/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** ParseRequest
*/

#pragma once

#include <string>
#include "API.hpp"

namespace Zia
{

class ParseRequest
{
  public:
    ParseRequest(boost::asio::ip::tcp::socket& socket);
    ~ParseRequest();
    API::Request& getRequest();
    void parsRequest();

  protected:
  private:
    API::Request _request;
    boost::asio::ip::tcp::socket _socket;
    std::string _bufferToString(const boost::asio::streambuf &buffer);
    void _getMethod(std::string &req);
    void _getUri(std::string &req);
    void _getProtocol(std::string &req);
    void _getHeaders(std::string &req);
    void _getBody(std::string &req);
};

} // namespace Zia