# Linked List Snake

## Overview
Welcome to the Linked List Snake Game, a modern take on the classic snake game combined with dynamic data structures—Linked Lists. This project recreates the nostalgic Snake gameplay using C++ and linked lists for a more efficient, educational experience. Dive deep into game mechanics and learn how linked lists can manage the snake’s body growth in real-time!

## Features
- **Dynamic Snake Growth:** The snake's body grows dynamically by adding new nodes to the linked list as it consumes food.
- **Player Controls:**
  - Navigate the Snake: Use the arrow keys to control the snake's direction.
  - Grow by Eating Food: Consume food items scattered on the board to increase the snake’s length.
- **Boundary Wrapping:** The snake can pass through boundaries and reappear on the opposite side of the screen.
- **Collisions:** The game ends if the snake collides with its own body or walls.
- **Game State Management:**
  - Score Tracking: Keep track of your score based on the food consumed.
  - Lose Conditions: The game ends when the snake collides with itself or the walls. There is no win condition.

## Learning Outcomes
- **Linked Lists:** Gained hands-on experience with dynamic data structures by implementing linked lists to manage the snake's length.
- **Game Logic:** Developed an understanding of game mechanics, collision detection, and state management.
- **User Interface:** Designed an intuitive UI for displaying scores and game states.
- **Event Handling:** Created responsive controls using keyboard inputs for smooth gameplay.
- **Object-Oriented Design:** Enhanced understanding of OOP principles like encapsulation and inheritance.
- **Game Loop and State Management:** Maintained fluid transitions and consistent game states throughout the gameplay.

## Project Structure

- **GraphicService:** Manages game window and rendering operations.
- **EventService:** Handles user input and game events.
- **TimeService:** Manages game timing and countdowns.
- **SoundService:** Manages sound effects and music playback.
- **UIService:** Manages UI components.
  - **UI Controllers:** `SplashScreenUIController`, `MainMenuUIController`, `LevelSelectionUIController`, `LinkedListSelectionUIController`, `GameplayUIController`, `InstructionsScreenUIController`, `CreditsScreenUIController`
  - **UI Elements:** `UIView`, `TextView`, `ImageView`, `ButtonView`, `AnimatedImageView`, `RectangleShapeView`
  - **UI Interface:** `IUIController`
- **ElementService:** Manages interactive elements like obstacles in the game.
  - **`Obstacle`**: Represents obstacles that the snake must avoid.
  - **`ElementData`**: Manages the data related to game elements.
- **LevelService:** Manages the game levels and related logic.
  - **`LevelModel`**: Handles the data structure for levels.
  - **`LevelView`**: Responsible for rendering the level's visual components.
  - **`LevelController`**: Manages level logic, such as player interactions and level progression.
  - **`LevelData`**: Manages data related to the game elements within each level.
  - **`LevelConfig`**: Defines configurations like difficulty settings and level parameters.
- **LinkedListLib:** Manages the linked list operations for snake body management.
  - **`DoubleLinkedList`**: Handles operations for a doubly linked list that allows bidirectional traversal.
  - **`SingleLinkedList`**: Handles operations for a singly linked list, providing unidirectional traversal of the snake's body.
  - **`LinkedList`**: General linked list operations and logic, acting as a base class for specific types of linked lists.
  - **`DoubleNode`**: Defines the structure and functions of each node in a doubly linked list.
  - **`SingleNode`**: Defines the structure and functions of each node in a singly linked list.
  - **`Node`**: General node class used as the base class for both single and double nodes.
- **PlayerService:** Manages player logic and gameplay interactions.
  - **`SnakeController`**: Controls the snake's movement, collision detection, and growth.
  - **`BodyPart`**: Represents each segment of the snake's body.
  - **`Direction`**: Defines movement directions for the snake.
- **FoodService:** Manages food item generation and placement on the game board.
  - **`FoodItem`**: Represents the food (controller itself).
  - **`FoodType`**: Defines various types of food items.

### Additional Core Components:

- **Main**: Entry point of the game.
- **GameService**: Core service that initializes and manages the game.
- **ServiceLocator**: Coordinates the initialization, updating, and rendering of all services, ensuring smooth communication between components.
- **Config**: Manages global configurations like file paths for assets, textures, sounds, and fonts.

## How to Play

### Controls
- **Move:** Use the arrow keys to move the snake.

1. **Clone the repository**:
    ```bash
    git clone https://github.com/123rishiag/Linked-List-Snake.git
    ```
2. **Build the project** using your preferred C++ compiler.
   - Ensure you have SFML installed. Installation instructions are available on SFML’s [official website](https://www.sfml-dev.org/).

3. **Run the executable** to start the game.

## Video Demo
Watch the [Video Demo](https://www.loom.com/share/092116dc1aa64170a802eea3817588b1?sid=5c9e20bd-044f-44f8-8b9c-0c0ef0b24765) to understand the gameplay!