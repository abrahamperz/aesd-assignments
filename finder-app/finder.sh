#!/bin/sh
# finder.sh - AESD Assignment 1
# Counts the files in a directory tree and the lines that contain a string.
#
# Usage: finder.sh <filesdir> <searchstr>
#   filesdir  : path to a directory on the filesystem
#   searchstr : text string searched for within the files

# Require both arguments.
if [ $# -lt 2 ]; then
    echo "Error: two arguments are required: filesdir and searchstr" >&2
    exit 1
fi

filesdir=$1
searchstr=$2

# filesdir must be an existing directory.
if [ ! -d "$filesdir" ]; then
    echo "Error: '$filesdir' is not a directory on the filesystem" >&2
    exit 1
fi

# X = number of regular files in the directory and all subdirectories.
numfiles=$(find "$filesdir" -type f | wc -l)

# Y = number of lines across those files that contain searchstr.
nummatching=$(grep -r "$searchstr" "$filesdir" 2>/dev/null | wc -l)

echo "The number of files are ${numfiles} and the number of matching lines are ${nummatching}"
