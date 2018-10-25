#!/bin/bash

cp -n ../template.cpp $1.cpp
sh ./comp-tmux.sh $1
