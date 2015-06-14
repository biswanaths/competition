#!/bin/sh 
y=${1%.cpp}
tmux new-session -d 
tmux split-window -h -p 30 
tmux split-window -v 
tmux select-pane -t 0
tmux send-keys 'vim +47 '"$y"'.cpp' Enter
tmux select-pane -t 1
tmux send-keys 'vim test.in' Enter
tmux select-pane -t 2
tmux send-keys 'sh wr.sh '"$y"'' Enter
tmux select-pane -t 0
tmux -2 attach-session -d 

