#!/bin/sh

ls | grep -P "^[0-9]+-.+" | wc -l
