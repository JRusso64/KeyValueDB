#include "db.h"

#include <utility>

void KeyValueDB::put(std::string key, std::string value)
{
    memTable.insert_or_assign(std::move(key), std::move(value));
}

std::optional<std::string> KeyValueDB::get(std::string &key) const
{
    auto it = memTable.find(key);
    if (it != memTable.end())
    {
        return it->second;
    }

    return std::nullopt;
}

void KeyValueDB::remove(std::string key)
{
    memTable.erase(key);
}
