#!/bin/sh
set -e

REPO="https://github.com/goldstac/taskman"
INSTALL_DIR="$HOME/.local/bin"

command -v git >/dev/null 2>&1 || { echo "error: git is required"; exit 1; }
command -v g++ >/dev/null 2>&1 || { echo "error: g++ is required"; exit 1; }

TMP="$(mktemp -d)"
trap 'rm -rf "$TMP"' EXIT

echo "cloning taskman..."
git clone --depth 1 "$REPO" "$TMP/taskman"

echo "building..."
cd "$TMP/taskman"
g++ -std=c++17 -O2 -o taskman main.cpp

echo "installing to $INSTALL_DIR..."
mkdir -p "$INSTALL_DIR"
mv taskman "$INSTALL_DIR/taskman"

case ":$PATH:" in
    *":$INSTALL_DIR:"*) ;;
    *) echo "note: $INSTALL_DIR is not in your PATH"
       echo "add this to your shell rc (~/.bashrc or ~/.zshrc):"
       echo "    export PATH=\"\$HOME/.local/bin:\$PATH\"" ;;
esac

echo "taskman installed! run: taskman --version"
