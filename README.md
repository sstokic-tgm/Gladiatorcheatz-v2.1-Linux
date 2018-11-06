## What is Gladiatorcheatz v2.1 Linux ?
---
A continued **Linux** port of [Gladiatorcheatz v2.1](https://github.com/sstokic-tgm/Gladiatorcheatz-v2.1).
Like the Windows version, is this version, a fully featured internal hack for CS:GO, aswell.

## Requirements
---
- CMake >= 3.0
- GCC >= 5.2

#### Ubuntu- / Debian-based distributions
Tested on Linux Mint 18 & Ubuntu 18.04.1
```
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt-get install gcc-6 g++-6 cmake gdb git libsdl2-dev zlib1g-dev libxdo-dev libv8-dev
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-6 60 --slave /usr/bin/g++ g++ /usr/bin/g++-6
```

## Building the cheat itself
---
**Note:** _Do NOT download or compile as the root user!_
#### Getting the source code
```
cd ~/
git clone -b master git://github.com/sstokic-tgm/Gladiatorcheatz-v2.1-Linux.git
```

## Compiling the source code
---
#### Creating the build-directory
To avoid issues with updates and colliding source builds, we create a specific build-directory, so we avoid any possible issues due to that (if any might occur):
```
cd Gladiatorcheatz-v2.1-Linux
mkdir build
cd build
```

#### Configuring for compiling
To configure the core, we use the configuration-tool cmake:
```
cmake ../
```

#### Building the core
After configuring and checking that everything is in order (read cmakes output), you can build **Gladiatorcheatz v2.1 Linux** (this will take some time unless you are on a rather fast machine)
```
make
```
If you have multiple CPU cores, you can enable the use of those during compile:
```
make -j <number of cores>
```
Alternatively:
```
make -j$(nproc)
```
After compiling, you will find your core binary in the build-directory. Now you can continue reading on and learn how how to update the source tree.

#### Keeping the code up to date
To update the core files, do the following:
```
cd ~/Gladiatorcheatz-v2.1-Linux/
# For master branch
git pull origin master
```
Now return to the build-directory and rebuild the cache:
```
cd build
make rebuild_cache
```
Afterwards you can build **Gladiatorcheatz v2.1 Linux**:
```
make
```
If you have multiple CPU cores, you can enable the use of those during compile:
```
make -j$(nproc)
```

## Running the cheat
---
**Note:** _You are running these commands from the build directory!_    

After you have compiled the source code, you can inject the cheat with the load script (run it as the super-user):
```
sudo ../load
```
To unload the cheat, run the unload script (run it as the super-user):
```
sudo ../uload
```

## Credits
---
- Aimtux/Fuzion makers for load/unload script
- Others can be looked up here: [Gladiatorcheatz v2.1 + Loader](https://www.unknowncheats.me/forum/cs-go-releases/279588-gladiatorcheatz-v2-1-loader.html) or here [Gladiatorcheatz v2](https://www.unknowncheats.me/forum/cs-go-releases/253335-gladiatorcheatz-v2.html)

_Credits may change with time..._

## TODO
---
- Finish the port to Linux from Windows

## Known issues
---
- If you inject nothing will happen, because the port is not finished ![Alt Text](https://media.giphy.com/media/EQ88Jp6w0yEu2II7uu/giphy.gif)

## Others
---
You may contribute to this project if you want to, but it is **clever to wait** till the port is **finished completely**!
