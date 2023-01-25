echo " Creating directory $1"
mkdir $1

echo " Directory $1 created "

cp ../template.cpp $1/a.cpp
cp ../template.cpp $1/b.cpp
cp ../template.cpp $1/c.cpp
cp ../template.cpp $1/d.cpp
cp ../template.cpp $1/e.cpp

ln -s ../wr.sh $1/wr.sh 
ln -s ../comp-tmux.sh $1/comp-tmux.sh

touch $1/test.in
touch $1/test.out

cd $1


