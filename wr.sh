# If there is a change to file, compile and run
source=$1.cpp
cmd='clear && g++ '"$source"' && ./a.out'
if hash fswatch 2> /dev/null; then 
    fswatch  $source test.in | xargs -I{} sh -c "$cmd"
else 
    ls $source test.in | entr sh -c "$cmd"
fi


