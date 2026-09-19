#pragma once

#include <cstddef>
#include <cstdint>
#include <fstream>
#include <string>
#include <vector>

enum class Operation : std::uint8_t
{
    CREATE = 1,
    UPDATE = 2,
    DELETE = 3
};

struct WALRecord {
    Operation operation;
    std::string key;
    std::string value;
};

class WAL
{
public:
    WAL(const std::string &fileName);

    void append(const WALRecord &record);
    bool readExact(std::ifstream &in, char *buffer, std::size_t size);

    template<typename T>
    bool readExact(std::ifstream &in, T &value)
    {
        return readExact(in, reinterpret_cast<char*>(&value), sizeof(value));
    }

    std::vector<WALRecord> recover();

private:
    std::ofstream writefile;
    std::ifstream readfile;
};
