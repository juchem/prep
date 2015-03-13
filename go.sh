#!/bin/sh

clear
set -e

ename="`basename "$1"`"

if [ -z "$ename" ] || [ ! -d "$ename" ]; then
	echo "Exercise $ename not found"
	exit 1
fi

tmpdir="tmp/$ename"

if [ -d "$tmpdir" ]; then
	rm -rf "$tmpdir"
fi
mkdir -p "$tmpdir"

bname="$tmpdir/$ename.bin"
g++-4.7 -Wall -std=c++0x -O0 -g -o "$bname" $ename/*.cpp 2>&1 | more

set +e
if [ -x "$bname" ]; then
	shift
	echo "args = $@"
	echo

	# TODO: ugly hack, improve it
	if [ "`find "$ename" -name '*.input'`" ]; then
		for iname in $ename/*.input; do
			echo "Using $iname as stdin"
			"$bname" "$@" < "$iname"
			echo
		done
	else
		"$bname" "$@"
	fi
fi
