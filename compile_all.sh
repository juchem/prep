#!/bin/sh

for f in `ls | grep -P "[0-9]+\-.+"`; do
	if [ -d "$f" ]; then
		./go.sh "$f"
		echo
		echo "$f"
		sleep 1
	fi
done
