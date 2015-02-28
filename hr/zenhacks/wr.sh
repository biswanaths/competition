# If there is a change to file, compile and run
fswatch  $1.cpp | xargs -I{} sh -c 'g++ $1.cpp && ./a.out'
