#include <thread>
#include <iostream>
#include <vector>

#include "Cmd.hpp"
#include "Server.hpp"
#include "Zia.hpp"

Zia::Zia::Zia()
{
    _run = (bool *)malloc(sizeof(bool));
}

Zia::Zia::~Zia()
{
    if (*_run == true) {
        std::cout << "A server is running !" << std::endl;
        _server->join();
    }
    free(_run);
}

void Zia::Zia::runCli()
{
    std::string str;
    Cmd cmd(this);

    this->startServer();
    std::cout << "Cli start" << std::endl;
    while (1) {
        std::cout << ">";
        std::getline(std::cin, str);
        cmd.runCmd(str);
    }
}

void Zia::Zia::startServer()
{
    bool *test = _run;

    if (*_run == true) {
        std::cout << "A server is already running !" << std::endl;
        return;
    }
    *_run = true;
    std::cout << "Start server !" << std::endl;
    _server = new std::thread([test]() {
        Server *server = new Server();
        while (1) {
            if (*test == false) {
                delete server;
                return (0);
            }
            sleep(1);
        }
    });
}

void Zia::Zia::forceStopServer()
{
    std::cout << "Force stop server !" << std::endl;
    if (_server != NULL)
        _server->detach();
    *_run = false;
}

void Zia::Zia::stopServer()
{
    std::cout << "Stop server !" << std::endl;
    *_run = false;
    _server->join();
    delete _server;
}

bool Zia::Zia::getRun()
{
    return *_run;
}