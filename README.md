# Data Structures and Algorithms

## How to install CMake

- Use apt-get

```bash
sudo apt-get -y install cmake
```

## How to install Catch2

- Update

```bash
sudo apt update
```

- Clone the Repo

```bash
git clone https://github.com/catchorg/Catch2.git
```

- Build Files

```bash
cd Catch2/
cmake -Bbuild -H. -DBUILD_TESTING=OFF
```

` Install Catch2

```bash
sudo cmake --build build/ --target install
```
