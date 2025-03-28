export MY_NAME="app"

mkdir build
cd build
cmake ..
cmake --build .

# 复制构建好
cp $MY_NAME /home/ubuntu18/Desktop/mnt
cd ..
# rm -rf build



