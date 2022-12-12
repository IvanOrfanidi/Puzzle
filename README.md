## Puzzle

### Build for Windows
Run to script
```sh
sh genqt.sh
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

### Build for Linux
Run to script
```sh
genqt.sh
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

### Build for Linux from Docker
docker cp dummy:/Puzzle/build/puzzle .
```sh
docker build -t puzzle:latest .
docker create -it --name dummy puzzle:latest bash
docker cp dummy:/Puzzle/build/puzzle .
rm -rf build/
mkdir build/
mv puzzle build/
docker rm -f dummy
```
