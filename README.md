# SimpleMinesweeperGame
Experience a simplified Minesweeper game on a 5x5 grid with 5 hidden mines. Players input coordinates to explore locations. Avoid mines to win. Start from mine-free (0,0). Mines placed randomly except (0,0). Command-line interface. "X" is unexplored, "M" is mine. Aim: Reveal all except mine spots.

**Project Description: Minesweeper Game with Limited Grid**

The Minesweeper project is a simplified version of the classic game, offering both entertainment and a challenge within a constrained environment. The game operates within a 5x5 grid and contains precisely 5 hidden mines. The player's objective is to reveal all locations on the grid except for those containing mines. This implementation features two key limitations to enhance its simplicity and engagement.

In this version of the game, players are presented with two scenarios: a successful win and an unfortunate loss. A winning scenario, depicted in Case-01, showcases a user who has meticulously explored every location on the grid except for the precise positions where mines are situated. On the other hand, Case-02 represents a failed outcome, where a mine was discovered at a specific location (3,1), marked in red. The white cells signify unexplored areas.

To interact with the game, players must provide coordinates (indices) of the locations they wish to explore. Upon execution, the command-line interface (CMD) will display the grid, and users will input their desired coordinates. The program will then evaluate the chosen location. If the location is devoid of mines, a number will be displayed based on the number of mines present in its vicinity.

One constant in the game is the mine-free location (0,0), which serves as the starting point for all users. This strategic decision allows players to initiate the game without fear of an immediate loss. The randomness of mine placement, excluding the (0,0) coordinate, is achieved through file reading and writing.

Success in the game entails revealing every location on the grid, except for the predetermined 5 mine locations. If a player encounters a mine during exploration, the game ends in defeat. A player's victory is determined by their ability to uncover each cell except the ones housing mines.

The project aims to deliver an engaging and enjoyable Minesweeper experience while adhering to the constraints of the 5x5 grid and the limited number of mines. The sample run of the program is presented below, where "X" symbolizes unexplored areas and "M" denotes mine locations that have exploded.
