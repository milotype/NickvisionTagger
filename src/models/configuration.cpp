#include "configuration.hpp"
#include <filesystem>
#include <fstream>
#include <adwaita.h>
#include <json/json.h>

using namespace NickvisionTagger::Models;

Configuration::Configuration() : m_configDir{ std::string(g_get_user_config_dir()) + "/Nickvision/NickvisionTagger/" }, m_theme{ Theme::System }, m_includeSubfolders{ true }, m_rememberLastOpenedFolder{ true }, m_lastOpenedFolder{ "" }, m_preserveModificationTimeStamp{ false }, m_overwriteTagWithMusicBrainz{ true }, m_acoustIdUserAPIKey{ "" }
{
    if(!std::filesystem::exists(m_configDir))
    {
        std::filesystem::create_directories(m_configDir);
    }
    std::ifstream configFile{ m_configDir + "config.json" };
    if(configFile.is_open())
    {
        Json::Value json;
        configFile >> json;
        m_theme = static_cast<Theme>(json.get("Theme", 0).asInt());
        m_includeSubfolders = json.get("IncludeSubfolders", true).asBool();
        m_rememberLastOpenedFolder = json.get("RememberLastOpenedFolder", true).asBool();
        m_lastOpenedFolder = json.get("LastOpenedFolder", "").asString();
        m_preserveModificationTimeStamp = json.get("PreserveModificationTimeStamp", false).asBool();
        m_overwriteTagWithMusicBrainz = json.get("OverwriteTagWithMusicBrainz", true).asBool();
        m_acoustIdUserAPIKey = json.get("AcoustIdUserAPIKey", "").asString();
    }
}

Theme Configuration::getTheme() const
{
    return m_theme;
}

void Configuration::setTheme(Theme theme)
{
    m_theme = theme;
}

bool Configuration::getIncludeSubfolders() const
{
    return m_includeSubfolders;
}

void Configuration::setIncludeSubfolders(bool includeSubfolders)
{
    m_includeSubfolders = includeSubfolders;
}

bool Configuration::getRememberLastOpenedFolder() const
{
    return m_rememberLastOpenedFolder;
}

void Configuration::setRememberLastOpenedFolder(bool rememberLastOpenedFolder)
{
    m_rememberLastOpenedFolder = rememberLastOpenedFolder;
}

const std::string& Configuration::getLastOpenedFolder() const
{
    return m_lastOpenedFolder;
}

void Configuration::setLastOpenedFolder(const std::string& lastOpenedFolder)
{
    m_lastOpenedFolder = lastOpenedFolder;
}


bool Configuration::getPreserveModificationTimeStamp() const
{
    return m_preserveModificationTimeStamp;
}

void Configuration::setPreserveModificationTimeStamp(bool preserveModificationTimeStamp)
{
    m_preserveModificationTimeStamp = preserveModificationTimeStamp;
}

bool Configuration::getOverwriteTagWithMusicBrainz() const
{
    return m_overwriteTagWithMusicBrainz;
}

void Configuration::setOverwriteTagWithMusicBrainz(bool overwriteTagWithMusicBrainz)
{
    m_overwriteTagWithMusicBrainz = overwriteTagWithMusicBrainz;
}

const std::string& Configuration::getAcoustIdUserAPIKey() const
{
    return m_acoustIdUserAPIKey;
}

void Configuration::setAcoustIdUserAPIKey(const std::string& acoustIdUserAPIKey)
{
    m_acoustIdUserAPIKey = acoustIdUserAPIKey;
}

void Configuration::save() const
{
    std::ofstream configFile{ m_configDir + "config.json" };
    if(configFile.is_open())
    {
        Json::Value json;
        json["Theme"] = static_cast<int>(m_theme);
        json["IncludeSubfolders"] = m_includeSubfolders;
        json["RememberLastOpenedFolder"] = m_rememberLastOpenedFolder;
        json["LastOpenedFolder"] = m_lastOpenedFolder;
        json["PreserveModificationTimeStamp"] = m_preserveModificationTimeStamp;
        json["OverwriteTagWithMusicBrainz"] = m_overwriteTagWithMusicBrainz;
        json["AcoustIdUserAPIKey"] = m_acoustIdUserAPIKey;
        configFile << json;
    }
}
