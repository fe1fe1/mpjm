# MPJM (MiPrimerJuegoMal)

A simple 2d game, a personal project for an university assignment. 

## Introduction & explanation:

It's a vertical shooting game and consist of:

- 1 type of enemy
- 1 type of weapon
- 1 level
- 10 sublevels (each one containing more enemies of greater tier)

Killing enemies gives points, the amount of points gained increases with the enemy tier.

Once finished, each sublevel guarantees +1 life on the next sublevel. Also, when finished, the lifes counter on that sublevel gets multiplied and converted in bonus points (the +1 life reward it's not included in the sum).

### Build and run:

First install CMake.

Then in terminal, in the /build folder inside the project folder, run the `make` command in order to build it:

-Inside build:
```
cd ~/mpjm/build
```
-Make the build:
```
make
```
-Now run it:
```
./mpjm
```