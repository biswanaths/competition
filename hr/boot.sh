echo " Creating directory $1"
mkdir $1

echo " Directory $1 created "

cp ../template.cpp $1/a.cpp
cp ../template.cpp $1/b.cpp
cp ../template.cpp $1/c.cpp

touch $1/test.in
touch $1/test.out


