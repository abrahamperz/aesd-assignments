#!/bin/sh
# writer.sh - AESD Assignment 1
# Writes a string to a file, creating the path if needed and overwriting it.
#
# Usage: writer.sh <writefile> <writestr>
#   writefile : full path (including filename) of the file to write
#   writestr  : text string written into writefile

# Require both arguments.
if [ $# -lt 2 ]; then
    echo "Error: two arguments are required: writefile and writestr" >&2
    exit 1
fi

writefile=$1
writestr=$2

# Create the containing directory path if it does not already exist.
mkdir -p "$(dirname "$writefile")"

# Write the content, overwriting any existing file.
echo "$writestr" > "$writefile"

# Fail if the file could not be created.
if [ ! -f "$writefile" ]; then
    echo "Error: could not create file '$writefile'" >&2
    exit 1
fi
