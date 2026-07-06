#!/bin/bash

if [ -z "$1" ]; then
    echo "error: no file specified."
    echo "usage: ./scripts/push.sh <path/to/file.cpp>"
    exit 1
fi

FILE=$1

if [ ! -f "$FILE" ]; then
    echo "error: file '$FILE' does not exist."
    exit 1
fi

DIR_NAME=$(dirname "$FILE")

# 1. grab the real folder name, even if neovim just passes "."
if [ "$DIR_NAME" == "." ]; then
    RAW_DIR=$(basename "$PWD")
else
    RAW_DIR=$(basename "$DIR_NAME")
fi

# 2. strip the prefix and format it
PATTERN=$(echo "$RAW_DIR" | sed 's/^[0-9]*_//' | tr '_' ' ' | tr '[:upper:]' '[:lower:]')

# 3. only default to general if you are pushing from the absolute root of the repo
if [ "$RAW_DIR" == "!corporateMajdoori" ]; then
    PATTERN="general"
fi

git add "$FILE"
echo "staged: $FILE"
echo "detected pattern: $PATTERN"
echo "----------------------------------------"

read -p "enter time/space complexity & core concept (e.g. O(N) hashmap complement): " CONCEPT

COMMIT_MSG="feat($PATTERN): $CONCEPT"

echo "----------------------------------------"
echo "commit message: \"$COMMIT_MSG\""
read -p "push to github? (y/n): " CONFIRM

if [[ "$CONFIRM" == "y" || "$CONFIRM" == "Y" ]]; then
    git commit -m "$COMMIT_MSG"
    git push
    echo "successfully pushed to accountability matrix."
else
    echo "push aborted. file remains staged."
fi
