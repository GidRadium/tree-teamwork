# tree-teamwork

## Install
```
git clone https://github.com/GidRadium/tree-teamwork.git
```

## Build
```
cd tree-teamwork
cmake . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build
```

## Start
```
./build/main
```

## Run tests
```
ctest --test-dir build --output-on-failure
```
