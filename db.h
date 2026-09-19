#pragma once

#include <map>
#include <optional>
#include <string>

class KeyValueDB
{
public:
    KeyValueDB() = default;

    void put(std::string key, std::string value);
    std::optional<std::string> get(std::string &key) const;
    void remove(std::string key);

    // TODO: Implement flush().

private:
    std::map<std::string, std::string> memTable;
};
