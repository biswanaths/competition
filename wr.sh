# If there is a change to file, compile and run
fswatch  a.cpp | xargs -I{} sh -c 'g++ a.cpp && ./a.out'
