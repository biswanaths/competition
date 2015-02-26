fswatch  a.cpp | xargs -I{} sh -c 'g++ a.cpp && ./a.out'
