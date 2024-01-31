# SeniorDesign

This project uses Cmake to generate Make files and a build for the project.
To build and execute this project do the following:

```
mkdir build/
cd build
```

To build this project in the build/ folder:

```
cmake ..
make dungeon_crawler
```

Finally to execute the project:

```
cd bin
./dungeon_crawler
```

Be sure to add any new files to the CMakeLists.txt so they are included in the  build

Basic Implementation for player and monster movement
![Hex Set Up](https://github.com/ECE477-Senior-Design/SeniorDesign/assets/89484474/59cd3fac-0d13-4525-be87-8246b729e261)
Above is a hex grid shown with axial coordinates and with a point top, top row left-aligned. This is the way the code is implemented. Do not implement it any other way.
