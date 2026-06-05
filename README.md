# so_long
A 2D game development project from the 42 Network (1337) built using the MiniLibX graphics library. Features window management, event handling (keyboard/mouse loops), asset rendering, and a custom pathfinding parsing engine to validate map configurations (walls, collectibles, exits) safely while preventing memory leaks.

# so_long — 2D Game Development & Graphic Engine Fundamentals

A creative graphics programming project from the **1337 / 42 Network** curriculum. The core objective of this project is to develop a small, top-down 2D game using the **MiniLibX (MLX)** graphics engine. The game requires a player to collect all items on a map and escape through an exit in the fewest movements possible.

This project introduces graphical window management, real-time event-driven loop programming, sprite rendering, and strict map validation engineering.

---

## 🛠️ Key Architectural Focus Areas

* **Graphical Event Handling:** Implemented hook interfaces to handle real-time keyboard inputs, window closing flags, and window focus hooks without blocking systems.
* **Map Parsing & Validation:** Built a strict validation parser to verify layout files (`.ber`). It ensures maps are closed by walls, contain valid entities, are rectangular, and have logical completion capabilities.
* **Flood-Fill Pathfinding:** Programmed a custom **Flood-Fill algorithm** to mathematically verify that a valid path exists for the player to reach all collectibles and the exit before launching the game window.
* **Memory Optimization:** Engineered systematic cleanup routines to free all image pointers, destroy window instances, and clear heap structures upon termination, ensuring **0 memory leaks**.

---

## 🎮 Game Rules & Components

The engine reads a map configuration file containing structural characters:
* `0`: Empty space (Floor tile)
* `1`: Wall obstacle
* `C`: Collectible item
* `E`: Map Exit point
* `P`: Player starting position

### Core Mechanics:
* The player can move **Up, Down, Left, and Right** using the `W`, `A`, `S`, `D` or Arrow keys.
* The game tracks and prints the exact **current move count** directly into the shell terminal on every valid movement.
* The exit tile remains locked or inactive until the total collectible count (`C`) drops down to zero.

---

## 🚀 Compilation & Execution

The project relies on a optimized `Makefile` to compile your source files alongside the MiniLibX framework dependencies.

### Build Commands:
```bash
# Compile the game executable
make

# Remove intermediate binary object files (.o)
make clean

# Remove all object files and the final game executable
make fclean

# Perform a clean rebuild from scratch
make re
```

### Execution Example:
To run the game, pass a valid map file as an argument:
```bash
./so_long maps/level_1.ber
```

---

## ⚡ Bonus Architecture (Optional Enhancements)
The bonus framework introduces advanced real-time animation cycles and entity mechanics:
* **Enemy Patrols:** Integrated hostile map sprites (`X`) that move dynamically, triggering an instant game-over state upon collision with the player.
* **Sprite Animation Loops:** Leveraged the MLX loop hook system to continuously refresh frame vectors, giving sprites fluid movement or idle animations.
* **On-Screen Dashboard:** Extracted move telemetry out of the background terminal and rendered text metrics directly onto the graphical window space in real-time.
