# StarForge - Space Survival Shooter

## Overview
StarForge is a 2D space survival shooter built in C++ using the SFML library. Navigate a procedurally generated asteroid field, collect resources, upgrade your ship, and battle enemies in a thrilling space adventure. This project is open-source, modular, and designed for community contributions.

## Features
- **Player Movement**: Smooth keyboard-controlled ship movement (WASD keys).
- **Procedural Generation**: (Planned) Asteroid fields and enemy spawns for dynamic gameplay.
- **Upgrades**: (Planned) Collect resources to upgrade ship weapons, shields, and speed.
- **Cross-Platform**: Built with SFML for Windows, macOS, and Linux support.
- **Extensible**: Modular code structure for easy feature additions.

## Getting Started
### Prerequisites
- C++ compiler (e.g., g++ with C++11 or later)
- SFML library (version 2.5 or higher)
- CMake (optional, for build automation)

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/starforge.git
   ```
2. Install SFML:
   - On Ubuntu: `sudo apt-get install libsfml-dev`
   - On macOS: `brew install sfml`
   - On Windows: Follow [SFML setup guide](https://www.sfml-dev.org/tutorials/2.5/start-vc.php)
3. Build the project:
   ```bash
   g++ -c main.cpp -I/path/to/sfml/include
   g++ main.o -o starforge -L/path/to/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system
   ```
4. Run the game:
   ```bash
   ./starforge
   ```

## How to Play
- Use **WASD** keys to move the ship.
- Press **Escape** to exit the game.
- (Planned) Collect resources and shoot enemies with mouse clicks.

## Contributing
We welcome contributions! Please check the [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines. Ideas for new features:
- Procedural asteroid generation
- Enemy AI and spawning
- Resource collection and upgrade system
- Sound effects and music

## Sponsorship
Love StarForge? Support the project via [GitHub Sponsors](https://github.com/sponsors/yourusername) to help fund development and new features!

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.