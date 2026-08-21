# taskman

A minimal, no-nonsense task manager for your terminal. Written in a single C++ file with zero dependencies — just you, your tasks, and plain text storage.

## Features

- Add tasks from the command line
- List all your tasks
- Tasks are stored in a simple local file (`blob/storage/taskman.storage`)
- No dependencies, no config files, no bloat

## Building

Requires a C++ compiler (e.g. `g++`) with C++17 support.

```sh
./quick.sh
```

Or manually:

```sh
g++ -o main main.cpp
```

## Usage

```sh
./main add Buy groceries     # add a task
./main list                  # show all tasks
./main --version             # print version
```

Running `taskman` without arguments prints usage help.

## Storage

Tasks live in `blob/storage/taskman.storage`. The file is created automatically on first run if it doesn't exist. It's plain text, so you can read, edit, or back it up however you like.

## Project Structure

```
├── main.cpp                  # the entire program
├── quick.sh                  # build script
├── blob/storage/             # task storage
└── extra/                    # experimental code
```

## License

This project is licensed under the [GPL-3.0](LICENSE).
