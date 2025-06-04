# Computer Recommender

A simple C++ console application to manage and recommend laptops based on use case and budget.

## Features

- Sellers can input multiple laptops with brand, model, use case, and price.
- Buyers can specify a use case and budget to get recommendations.

## Build and Run

### Prerequisites

- g++ compiler

### Build

```sh
make
```

### Run

```sh
./laptop_recommender
```

Or, to test with sample input:

```sh
./laptop_recommender < input.txt
```

## CI

This repository uses GitHub Actions to build and test the project automatically on every push and pull request to the `main` branch.
