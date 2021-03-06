/*
** EPITECH PROJECT, 2019
** Zia
** File description:
** LoadModules
*/

#pragma once

#include <vector>
#include <string>
#include <memory>
#include "pugixml.hpp"

#include "API.hpp"

namespace Zia
{

class LoadModules
{
  public:
    LoadModules();
    ~LoadModules();
    bool loadAllModules(
        std::vector<API::Module::pointer> &allModules,
        std::vector<std::string> allModulesPath,
        std::string configPath,
        API::ServerConfig &cfg);
    void closeAllModules(std::vector<API::Module::pointer> &allModules);

  protected:
  private:
    API::ServerConfig &_getModuleConfig(std::string modName, API::ServerConfig &cfg, std::string configPath);
    std::vector<void *> _loadmodule;
};

} // namespace Zia
