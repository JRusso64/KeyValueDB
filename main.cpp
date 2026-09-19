#include "db.h"
#include "wal.h"

int main(){
    KeyValueDB db = KeyValueDB(); 
    WAL wal = WAL("TestWAL");
    // WALRecord walRecord = WALRecord{Operation::CREATE, "hello", "John"};
    // wal.append(walRecord);
    wal.recover();
    return 0;
}
