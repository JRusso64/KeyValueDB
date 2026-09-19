# keyValueDB

Requires CMake 3.16 or newer and a C++17 compiler.

## Build

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug
```

The executable is `build/keyValueDB` with a single-configuration generator,
or `build/Debug/keyValueDB` with a multi-configuration generator (plus `.exe`
on Windows).

## Test scaffold

- `tests/CMakeLists.txt` contains commented-out test target and CTest registration.
- `tests/key_value_db_tests.cpp` is a placeholder for your future tests.

No test framework is required or downloaded. When you add tests, provide a
`main()` that returns zero on success and nonzero on failure, then uncomment
the target and registration in `tests/CMakeLists.txt`.

`db.h` and `db.cpp` contain `KeyValueDB`; `wal.h` and `wal.cpp` contain the
write-ahead log. Both implementations build into `keyValueDB_core`, while
`main.cpp` starts the application. Tests can include the headers and link
`keyValueDB_core` without linking the application's `main()`.

Configure, build, and run tests with:

```sh
cmake -S . -B build -DBUILD_TESTING=ON
cmake --build build --config Debug
ctest --test-dir build -C Debug --output-on-failure
```

Until you implement and enable the test runner, CTest will report no tests.
To exclude the test directory, configure with `-DBUILD_TESTING=OFF`.
