# OpenGL-Rabbit-Turtle

This program simulates a race between a turtle and a rabbit using OpenGL.

## Prerequisites

Make sure you have the necessary libraries installed to compile and run OpenGL programs.

For MacOS:

```bash
brew install freeglut
```

## How to Compile

```bash
g++ -o race race.cpp -framework OpenGL -framework GLUT -Wno-deprecated-declarations
```

## How to Run

```bash
./race
```

## Controls

- Press 'r' to restart the game.

## Additional Features

- The rabbit moves faster than the turtle.
- The game displays a winning message when the rabbit passes the window.

## Author

Alper Erdoğan

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
```
