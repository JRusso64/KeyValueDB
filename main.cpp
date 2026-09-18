#include<iostream>
#include<map>
#include<vector>
#include<utility>
#include<string>
#include<optional>
#include<iostream>
#include<fstream>
#include<cstdint>


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
    WAL(const std::string &fileName)
        : writefile(fileName, std::ios::binary | std::ios::app),
          readfile(fileName, std::ios::binary | std::ios::app)
    {
    }

    void append(const WALRecord &record)
    {
        std::uint32_t keySize = static_cast<std::uint32_t>(record.key.size());
        std::uint32_t valueSize = static_cast<std::uint32_t>(record.value.size());
        writefile.write(reinterpret_cast<const char*>(&record.operation), sizeof(record.operation));
        writefile.write(reinterpret_cast<const char*>(&keySize), sizeof(keySize));
        writefile.write(reinterpret_cast<const char*>(&valueSize), sizeof(valueSize));
        writefile.write(record.key.data(), keySize);
        writefile.write(record.value.data(), valueSize);
    }

    bool readExact(std::ifstream& in, char* buffer, std::size_t size){
        in.read(buffer, static_cast<std::streamsize>(size));
        return in.gcount() == static_cast<std::streamsize>(size);
    };

    template<typename T>
    bool readExact(std::ifstream& in, T& value){
        return readExact(in, reinterpret_cast<char*>(&value), sizeof(value));
    };

    std::vector<WALRecord> recover(){
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

private:
    std::ofstream writefile;
    std::ifstream readfile;
};

class KeyValueDB
{
private:
    std::map<std::string, std::string> memTable;

public:
    KeyValueDB() = default;

    void put(std::string key, std::string value)
    {
        memTable.insert_or_assign(std::move(key), std::move(value));
    }

    std::optional<std::string> get(std::string &key) const
    {
        auto it = memTable.find(key);
        if (it != memTable.end())
        {
            return it->second;
        }

        return std::nullopt;
    }

    void remove(std::string key)
    {
        memTable.erase(key);
    }

    // TODO: IMPLEMENT
    // void flush(){
    // }
};

int main(){
    KeyValueDB db = KeyValueDB(); 
    WAL wal = WAL("TestWAL");
    // WALRecord walRecord = WALRecord{Operation::CREATE, "hello", "John"};
    // wal.append(walRecord);
    wal.recover();
    return 0;
}
