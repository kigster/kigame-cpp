# kigamé 

A set of generic C++ interfaces and classes to aid with modeling basic 2-player board games.

Initially based on the [cmake-ccspec-template](https://github.com/kigster/cmake-ccspec-template) project template and `ccspec` for automated tests.

The goal is to create a simple basic framework for quickly implementing board games in C/C++ 
either on hardware or elsewhere. Two games were used to think through the interface design:
 
  * Gomoku (Five in a Row) and it's smaller cousin — Tic Tac Toe,

  * Simon Says (as implemented on the hardware controller using Adafruit Trellis).

The design goals are simple:

  * Extract boilerplate code and assign responsibilities to the framework classes.

  * Allow for simple subclassing or composition for the actual implementation.

  * As much as possible, use header only files.

## Design

In the simplest form you can think of the design as the following:

  * The **Game** class is the controller. It provides the main flow of the program, and holds to other objects.
  * The **Player** is an abstract interface representing both AI-based and Human players. An array of two players is handed to the Game object upon start.
  * The **View** is an implementation-dependent constuct that must implement the method `render(Board board, Move move)`.
     * Note, that the only reason Move is passed to `render()` is to speed it up, so that the **View** can only draw the diff of the two states.
  * The **Board** is the model, or state of the game.  It must be created and handed to the **Game** object. The **View** will be subscribed by the game to **Board's** updates, so that it can redraw itself after each valid move.
  * The **Game** starts the game. 
  * It then asks the next player to pick their move, and sends a read-only snapshot of the **Board**.
  * The current **Player** chooses their **Move**, and returns it to the **Game**.
  * **Game** passes the move onto the Board.
  * If the **Move** is valid, the **Board** modifies itself, and notifies the **View** so that the latter can re-render.
  * The **Board** then returns one value from the enum `{ try_again, next_player, game_over }` representing the status of the move.
  * The **Game** interpretes the return and performs an appropriate action.

In this design the **Game** class likely does not need to be subclassed to implement a particular game. 

Only **Board**, **Player** and **Move** require proper game-specific implementations.


## UML

### Structure

![structure](doc/images/kigame-uml-structure.png)

### Sequence

![structure](doc/images/kigame-uml-seq.png)
