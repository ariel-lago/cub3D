<!-- *********************************************************************** -->
<!--                                                                         -->
<!--                                                      :::      ::::::::  -->
<!-- README.md                                          :+:      :+:    :+:  -->
<!--                                                  +:+ +:+         +:+    -->
<!-- By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+       -->
<!--                                              +#+#+#+#+#+   +#+          -->
<!-- Created: 2026/03/16 20:50:06 by alago-ga          #+#    #+#            -->
<!-- Updated: 2026/03/16 21:28:21 by alago-ga         ###   ########.fr      -->
<!--                                                                         -->
<!-- *********************************************************************** -->

*This project has been created as part of the 42 curriculum by rbestman, alago-ga.*

# CUB3D

## Description
This project is written in C,


## Instructions
Clone the repository, and open it on your terminal.
Since the project uses minilibX you will need to download it.
Type *make* to compile.
Now you can run the program by writing *./cub3D* followed by the path to a valid *.cub* map containing:

### (1) Path to the textures for each wall
They can be in any order, but the textures must be .xpm files and they must be formated as: 
NO ./path_to_the_north_texture.xpm
SO ./path_to_the_south_texture.xpm
WE ./path_to_the_west_texture.xpm
EA ./path_to_the_east_texture.xpm

### (2) Floor and Ceiling color (RGB)
The order here is also irrelevant, but the colors need to be in the range of 0 to 255 and must be formatted like this:
F 220,100,0
C 225,30,0

### (3) The map
The map must be written only with the characters
1: for Walls
0: for defining the area where the character can move
N, S, E or W: Only one of these characters can appear once, and it will determine where the player starts and which direction they are facing. 
Spaces are allowed as long as they are not inside the 0 area, as the map must be surrounded by walls.
Here's an example of a valid map: 

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111

### (4) Gameplay & Controls Instructions

#### Player View

The first-person perspective is achieved through a custom raycasting engine. For each vertical stripe on the screen, a ray is cast from the player's position in the direction of that stripe. The distance to the nearest wall determines how tall that wall slice should be drawn.

#### Movement System

    Press WASD keys to move in each direction, where
	
	W = forwards
	A = left
	S = backwards
	D = right
	
    in relation to the player's view direction.

#### FOV (field of view)

    The players field of view can me adjusted between

	45 degrees for narrow view and
	90 degrees for a wide view.
	
	Press 'up' arrow to narrow view, 'down' to widen. 
	
#### Minimap

    Press M to minimize/maximize a top-down minimap that shows:

	Walls (blue)
	Floor areas (pink)
	Player position (red dot)
	Player direction and FOV (green lines)
    

### Features

    Smooth movement: No grid-snapping, allowing free movement within walkable areas

    Real-time rotation: Fluid camera turning with arrow keys

    Collision detection: Prevents walking through walls while allowing movement along them

	
## Resources

### Key concepts that were essential for building the game:

    Vector mathematics - For player positioning, direction, and the camera plane

    Trigonometry - For smooth player rotation using sine and cosine

    DDA (Digital Differential Analyzer) - For efficient grid traversal when casting rays

    Raycasting - The core technique that projects 2D map data into a 3D perspective

### Tutorials & other Resources

A big help for this project has been Lode's Computer Graphics Tutorial on Raycasting: https://lodev.org/cgtutor/raycasting.html

Particularly, the idea of the DDA algorithm and the explanations on how to avoid fish eye distortion. 
Another relevant resource were youtube courses on Vectors, trigonometry, maths for game development, Raycasting and Digital Differential Analyzer. For this, channels like javidx9 or Freya Holmer were particularly useful.
Freya Holmer: https://www.youtube.com/@acegikmo
javidx9: https://www.youtube.com/watch?v=DPfxjQ6sqrc

## AI usage
Claude AI, Gemini and Deepseek were used in this project for conceptual tutoring and explanations of mathematical examples. Furthermore, it was used in debugging, giving clarification on crashes etc.
Some concrete examples of this could be:

 - Asking ai to explain the Raycasting guide in the resources in a way that was easier to understand for game dev. beginners.
- Understanding certain Valgrind errors and finding their root. 
- Ideas on different ways to treat spaces in map validation. 

All AI-generated imput was fully understood and reviewed before implementation.
