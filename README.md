# Cyberpet-embeded-system
A C++ state-simulation engine built within the PlatformIO ecosystem, modeling real-time metric decays and conditional logic thresholds for an embedded environment.

# Cyberpet Embedded Simulation Engine 🐾🤖

A custom firmware architecture project developed in **C++ using Visual Studio Code and the PlatformIO ecosystem**. This project serves as an advanced sandbox for implementing object-oriented programming (OOP), deterministic state-decay algorithms, memory-efficient variable management, and reactive hardware/software logic boundaries.

## ⚙️ System Mechanics & State Decays
The engine models an embedded life-cycle simulator by systematically calculating changes across core environment metrics inside a continuous loop:
* **`health` (int):** The primary survival baseline of the system.
* **`hunger` (int):** A step-incrementing decay metric representing metabolic consumption.
* **`energy` (int):** A depleting accumulator state affected by activity variables.
* **`happiness` (int):** A dynamically mapped calculation derived from vital metrics balances.

## 📂 Structural File Layout
* **`src/main.cpp`:** The core execution file managing `void setup()` initializes states and `void loop()` updates structural logic.
* **`README.md`:** System architecture, pin maps, and logic-loop lifecycle documentation.

## 🚀 Technical Features Implemented
* **Time-Based State Decay:** Implementing loop timings or hardware clock counts to degrade parameters systematically over execution periods.
* **Boundary Sanitization:** Constraining parameter metrics strictly between `0` and `100` using logical boundary structures.
* **Conditional Exception Hubs:** Triggering immediate system warnings or reactive states when any metric crosses a critical threshold value.
