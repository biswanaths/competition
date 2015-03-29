#!/bin/sh 
tmux new-session -d 'vim a.cpp'
tmux split-window -h 'vim test.in'
tmux split-window -v 'sh wr.sh a'
tmux -2 attach-session -d 

