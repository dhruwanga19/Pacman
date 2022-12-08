We evalate our program in an Ubuntu system.

The first step is to compile the dependent libraries.
1. install relevent packages
sudo apt install build-essential git
sudo apt install libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev

git clone https://github.com/raysan5/raylib.git
cd raylib/src/
make PLATFORM=PLATFORM_DESKTOP

The second step in to compile our program.
2. unzip the zip file in the folder of raylib
cd to the folder “group20”
run “make” command
run “./game”enjoy the game!

Any issues, feel free to contact qzeng53@uwo.ca