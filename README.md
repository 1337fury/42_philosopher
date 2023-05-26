# 42 Philosopher Project

![Philosophers](philosophers.jpg)

## Table of Contents
1. [Introduction](#introduction)
2. [Project Overview](#project-overview)
3. [Project Requirements](#project-requirements)
4. [Project Architecture](#project-architecture)
5. [Installation](#installation)
6. [Usage](#usage)
7. [Design Decisions](#design-decisions)
8. [Troubleshooting](#troubleshooting)

## Introduction

Welcome to the 42 Philosopher Project! This project aims to simulate the classic dining philosophers problem using a concurrent programming approach. The dining philosophers problem is an illustration of a synchronization issue in computer science, where multiple processes compete for shared resources and must avoid deadlock or starvation.

This README provides a detailed overview of the project, including its requirements, architecture, installation instructions, usage guidelines, design decisions, troubleshooting tips, and information on how to contribute.

## Project Overview

The 42 Philosopher Project is implemented in the C programming language and utilizes multi-threading to simulate the dining philosophers problem. The goal is to model a scenario where a fixed number of philosophers sit at a round table with bowls of spaghetti and forks. The philosophers alternate between thinking and eating, using the forks placed on either side of their position.

The challenge lies in preventing deadlocks, where philosophers end up waiting indefinitely for the forks they need, and in avoiding starvation, where a philosopher never gets a chance to eat. This project aims to tackle these issues through the implementation of a solution that employs proper synchronization techniques.

## Project Requirements

To run the 42 Philosopher Project, you will need:

- C Compiler (e.g., gcc)
- POSIX Threads (pthreads) library

Ensure that these requirements are installed and properly configured on your system before proceeding with the installation.

## Project Architecture

The project follows a multi-threaded architecture to simulate the dining philosophers problem. It consists of the following key components:

1. **Philosopher**: Represents an individual philosopher. Each philosopher is implemented as a separate thread/process and performs actions such as thinking and eating.

2. **Fork**: Represents a fork placed between two philosophers. Forks are shared resources that philosophers must acquire to eat. They are implemented using mutex locks to ensure proper synchronization.

3. **Table**: Represents the dining table where philosophers and forks are located. The table initializes the philosophers and forks, starts the simulation, and handles resource allocation and deallocation.

4. **Main Program**: The entry point of the program. It creates the table, philosophers, and forks, and orchestrates the simulation.

## Installation

Follow these steps to install and run the 42 Philosopher Project:

1. Clone the project repository:

   ```
   git clone https://github.com/your_username/42-philosopher-project.git](https://github.com/1337fury/42_philosopher.git
   ```

2. Navigate to the project directory:

   ```
   cd 42_philosopher && cd PHILO
   ```

3. Compile the source code using your preferred C compiler:

   ```
   make 
   ```

4. The project is now ready to be executed.

## Usage

To execute the 42 Philosopher Project, follow these steps:

1. Open a terminal or command prompt.

2. Navigate to the project directory:

   ```
   cd 42_philosopher
   ```

3. Run the compiled executable:

   ```
   ./philo
   ```

4. The simulation will start, and you will see the philosophers performing their actions (thinking and eating and sleeping) in the output.

5. To terminate the program, press `Ctrl + C` in

 the terminal.

## Design Decisions

The 42 Philosopher Project makes several design decisions to address the dining philosophers problem effectively. These decisions include:

- Implementing a mutex lock for each fork to allow only one philosopher to hold a fork at a time.
- Introducing a maximum number of allowed philosophers to prevent resource exhaustion.
- Applying the "Resource Hierarchy Solution" to avoid deadlock by enforcing a strict ordering of resource acquisition.
- Utilizing a semaphore to limit the number of philosophers allowed to eat simultaneously, thus avoiding starvation.

These design decisions are based on established synchronization techniques and aim to strike a balance between preventing deadlocks and avoiding starvation.

## Troubleshooting

If you encounter any issues while running the 42 Philosopher Project, consider the following troubleshooting tips:

- Ensure that you have correctly installed the required dependencies (C Compiler and POSIX Threads library) mentioned in the project requirements section.
- Double-check that your system meets the minimum system requirements for running the project.
- Verify that you are using the correct command to compile and execute the project.

---
I hope you enjoy working with the 42 Philosopher Project! If you have any questions or suggestions, please don't hesitate to contact me. Happy coding!
