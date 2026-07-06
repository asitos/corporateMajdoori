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
PATTERN=$(basename "$DIR_NAME" | sed 's/^[0-9]*_//' | tr '_' ' ' | tr '[:upper:]' '[:lower:]')

if [ "$DIR_NAME" == "." ]; then
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
