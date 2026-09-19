#include "wal.h"

#include <iostream>

WAL::WAL(const std::string &fileName)
    : writefile(fileName, std::ios::binary | std::ios::app),
      readfile(fileName, std::ios::binary | std::ios::app)
{
}

void WAL::append(const WALRecord &record)
{
    std::uint32_t keySize = static_cast<std::uint32_t>(record.key.size());
    std::uint32_t valueSize = static_cast<std::uint32_t>(record.value.size());
    writefile.write(reinterpret_cast<const char*>(&record.operation), sizeof(record.operation));
    writefile.write(reinterpret_cast<const char*>(&keySize), sizeof(keySize));
    writefile.write(reinterpret_cast<const char*>(&valueSize), sizeof(valueSize));
    writefile.write(record.key.data(), keySize);
    writefile.write(record.value.data(), valueSize);
}

bool WAL::readExact(std::ifstream& in, char* buffer, std::size_t size){
    in.read(buffer, static_cast<std::streamsize>(size));
    return in.gcount() == static_cast<std::streamsize>(size);
}

std::vector<WALRecord> WAL::recover(){
    std::vector<WALRecord> output;
    Operation op;
    std::uint32_t keySize;
    std::uint32_t valueSize;


    
    if(!readExact(readfile, op)){
        
    }

    if(!readExact(readfile, keySize)){
        
    }

    if(!readExact(readfile, valueSize)){
        
    }

    std::string key;
    std::string value;
    key.resize(keySize);
    value.resize(valueSize);

    if(!readExact(readfile, key.data(), keySize)){
        
    }

    if(!readExact(readfile, value.data(), valueSize)){
        
    }

    std::cout << "op: " << static_cast<int>(op) << "\n"
      << "keySize: " << keySize << "\n"
      << "valueSize: " << valueSize << "\n"
      << "key: [" << key << "]\n"
      << "value: [" << value << "]\n"
      << "-------------------\n";

    return output;
}

