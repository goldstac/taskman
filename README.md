# taskman

A minimal, no-nonsense task manager for your terminal. Written in a single C++ file with zero dependencies — just you, your tasks, and plain text storage.

## Install

One-line install (clones, builds, and installs to `~/.local/bin`):

```sh
curl -fsSL https://raw.githubusercontent.com/goldstac/taskman/main/install.sh | bash
```

After installing, run it from anywhere:

```sh
taskman --version
```

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
g++ -o taskman main.cpp
```

## Usage

If installed via `install.sh`:

```sh
taskman add Buy groceries     # add a task
taskman list                  # show all tasks
taskman --version             # print version
```

Or straight from the repo after building:

```sh
./taskman add Buy groceries
./taskman list
```

Running `taskman` without arguments prints usage help.

## Storage

Tasks live in `blob/storage/taskman.storage`. The file is created automatically on first run if it doesn't exist. It's plain text, so you can read, edit, or back it up however you like.

> **Note:** the storage path is currently relative to the folder you run `taskman` from — running it from a different directory will use a different storage file. This will move to a fixed location (e.g. `~/.local/share/taskman/`) in a future version.

## Project Structure

```
├── main.cpp                  # the entire program
├── quick.sh                  # build script
├── install.sh                # curl | bash installer
├── blob/storage/             # task storage
└── extra/                    # experimental code
```

## License

This project is licensed under the [GPL-3.0](LICENSE).
