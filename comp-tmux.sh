#!/bin/sh 
tmux new-session -d 
tmux split-window -h 
tmux split-window -v 
tmux select-pane -t 0
tmux send-keys 'vim '"$1"'.cpp' Enter
tmux select-pane -t 1
tmux send-keys 'vim test.in' Enter
tmux select-pane -t 2
tmux send-keys 'sh wr.sh '"$1"'' Enter
tmux select-pane -t 0
tmux -2 attach-session -d 

