# If there is a change to file, compile and run
source=$1.cpp
cmd='g++ '"$source"' && ./a.out'
fswatch  $source test.in | xargs -I{} sh -c "$cmd"
