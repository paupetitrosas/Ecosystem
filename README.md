# Ecosystem

A C++ ecosystem simulation with predator-prey interactions, mutation-driven evolution, and live visualization.

The program renders the ecosystem with CImg and opens `gnuplot` windows at the end of a run to plot:

- population per species over time
- average maximum health per species
- average speed per species

## Features

- interactive setup for the initial number of each species
- real-time simulation window
- mutation of offspring traits
- quadtree-based spatial partitioning for collision checks
- end-of-run plotting with `gnuplot`

## Dependencies

- `g++` with C++17 support
- `gnuplot`
- Boost Iostreams development library
- X11 development libraries

The repository vendors these headers:

- `CImg.h`
- `gnuplot-iostream.h`

## Build

```bash
make
```

This produces the executable `ecosystem`.

## Run

```bash
./ecosystem
```

The program prompts for the initial number of:

1. plants
2. grasshoppers
3. mice
4. rabbits
5. frogs
6. birds
7. snakes
8. foxes
9. hawks
10. owls

## Controls

- `E`: remove half of the current population to recover from overpopulation
- `Esc`: stop the simulation and open the result plots

## Project Layout

- `main.cpp`: entry point
- `foodchain.h` / `foodchain.cpp`: creature and ecosystem model
- `utilities.h` / `utilities.cpp`: input handling, rendering helpers, and plotting
- `Makefile`: local build rules

## Third-Party Code

This repository includes third-party headers. See [THIRD_PARTY_NOTICES.md](/home/paupetitrosas/projects/Ecosystem/THIRD_PARTY_NOTICES.md) for attribution details.
