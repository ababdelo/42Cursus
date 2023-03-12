<br>

<h3 align="center"> 
<img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=32&pause=1000&color=2683AC&vCenter=true&width=435&lines=so_long+" alt="Typing SVG"/>
<img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=32&pause=1000&color=495455&vCenter=true&width=435&lines=And+all+thanks+for+the+fish!" alt="Typing SVG"/>
 
 <img width="50" height="50" src="https://animated-gif-creator.com/images/01/cartoon-fish-animated-gif-unique-fish-photo_78.gif"/>
 </h3>
 <br>
 <div align="center">
 <img src=https://github.com/ababdelo/42Cursus/blob/master/SO_LONG/Preview/Bonus/bonus_preview.png/>
</div>

### Table of Contents

* [Introduction](#introduction)
* [How it Works](#how-it-works)
* [Gameplay](#gameplay)
* [Installation](#installation)
* [Technical Issues](#technical-issues)
* [Features](#features)
* [Summary](#summary)

## Introduction
Through this project, you will gain valuable knowledge and experience in creating a 2D game utilizing minilibX. You will learn about the importance of textures, sprites, and tiles in game development.

### Game Rules
The game we choose must follow a set of rules. The executable ``so_long`` will receive a map as the only argument, and this map will have a ``.ber`` filetype.

The file also must follow these rules:
- Only ``P`` --> `Steve` , ``1`` --> `Wall` , ``0`` --> `Ground` , ``C`` --> `Collectible` , and ``E`` --> `Exit` will be accepted characters in our map (except if you add enemies as bonus)
- The map must be rectangular, i.e. all rows must have the same length
- There must be at least one exit, one player, and one collectible on the map
- The map must be closed, i.e. surrounded by walls

If any of these checks fail, the game must end with ``Error\n`` followed by a custom message.

The goal is for the player(s) to collect all the collectibles on the map before going to an exit in the least possible number of steps

## How it Works
For the graphics part of the project we used a library called ``minilibx``. It's fairly basic and somewhat limited, but was still fun to use in the project.


### Part 1: reading the map

In this part of the code I checked that the given map was properly opened, that it had a ``.ber`` filetype, and then continued by reading the whole file at once (lot of my peers used get_next_line because it is already exist , but i prefarred just to create a function that open and read the specified file)
Once that was done I filled a struct ``t_data`` with some basic data, like number of ` player s`, ` exits `, ` collectibles `, etc. After the reading process I created a double char pointer containing the entire map (dupplicated map), whcih was later useful when checking floodfill functionality.


### Part 2: starting the game

For this part I initialized a window with the mlx function and started drawing the static elements of the map (walls, ground and collectibles) on the window. The mlx library, as other graphic libraries, has an infinite loop where the game events happen. From here I check the state of the game to re-print certain elements of the map or to manage special events, such as when player's texture changes and when zombies move on certain pos, and when collectibles are animated.
The ``mlx`` library has hooks, which essentially link certain events on the computer (keypresses, mouse clicks, etc) with functions we implement. In my case I 'hooked' the end of the game function to pressing the ``x`` button to close the window. Also, I used a key hook to link keypresses with steve's movements.


### Part 3: game mechanics

When the ``ESC`` key is pressed, the game ends. If the arrow keys or the ``W``. ``A``, ``S``, ``D`` keys are pressed, steve changes its direction and tries to move in that direction. This way the arrow/WASD keys just change steve's direction to make him move forward/backward/to_left/to_right till he hits a wall.

Moreover, if steve reached a collectible a counter increase it's value so if steve gathered all collectibles the exit texture change confirming that he can go throught it to finish the game, then inform the player that he reached the goal of the game which is to reach the end world

Lastely, (on bonus part) if Steve moved on an enemy position the game end informing the player that steve was slain by the enemy , and that he lost.

### Part 4: animations

There some animations throughout the game (it's the other bonus part in the project), from steve's face animation (looking right and left) to collectible's animation. They are all animated in a similar way: the number of loop repetitions (frames) . Every time the specified function is called it did it's work one time at nbr of frams(as example 2500 time), and that's how i managed to create my animations. But for the enemy instead of changing his texture i change his position to make him moves a little bit.

## Gameplay

If you want to see my project preview <a href="https://youtu.be/_poahmpctSU" target="_blank" aria-label=" (opens in a new tab)" rel="noreferrer noopener ">Click Here</a> for the `Mandatory Part Preview` , or <a href="https://www.youtube.com/watch?v=nueo9ACDqNU" target="_blank" aria-label=" (opens in a new tab)" rel="noreferrer noopener ">Click Here</a> for the `Bonus Part Preview`.

## Installation

### Cloning the repositories
```shell
git clone git@github.com:ababdelo/42Cursus/.git
cd 42Cursus/SO_LONG
make
```

### Installing the MLX library

* ``Linux``

If you're not using a MacOS computer from 42, you'll need to install the libraries manually. Please refer to the [official github](https://github.com/42Paris/minilibx-linux) for more details. To install it, do the following (requires root access):

```shell
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux/
make
sudo cp mlx.h /usr/include
sudo cp libmlx.a /usr/lib
```

* ``MacOS``

To install the library, you will need to first install a package manager like homebrew (check [here](https://brew.sh/)) to then install the X11 package with ``brew install Xquartz``. After that you must extract the minilibx file called ``minilibx_opengl.tgz``. Then install it to your system with the following commands (requires sudo as well):

```shell
cd minilibx_opengl
make
sudo cp mlx.h /usr/local/include
sudo cp libmlx.a /usr/local/lib
sudo reboot
```
Note: A reboot is necessary to ensure that the ``Xquartz`` is working properly. You can test if it is by running a test example with the command ``xeyes``.

### Installing the manuals

If you want quick access to the mlx manuals, it is recommended that you copy the files from the ``man`` folder in [minilibx-linux](https://github.com/42Paris/minilibx-linux) to your system manuals:

* ``Linux``
```shell
sudo cp man/man3/* /usr/share/man/man3/
```
Note: Depending on your Linux configuration, to get the manuals working (e.g. ``man mlx``) you will need to individually gzip all the manual files you just copied, e.g. ``sudo gzip /usr/share/man/man3/mlx.3``.

* ``MacOS``
```shell
sudo cp man/man3/* /usr/X11/share/man/man3
```

### Usage

```shell
make all                        #compiles project's mandatory part
make bonus                      #compiles project's bonus part
make re                         #cleans files then re-compiles both project's parts
make clean                      #remove .o files
make fclean                     #call clean then remove all executables files
make run_mand                   #run mandatory executable file with a specific map
make run_bonus                  #run bonus executable file with a specific map
```

## Technical Issues

Throughout the project, there have been a few roadblocks that needed to be worked around, here's some of them:

- Timing: getting the timing for animations and other stuff right was quite challenging. I ended up just using the number of loop repetitions from ``mlx_loop_hook`` and fiddling with different rates, which also varied a lot between MacOS and Linux.
- Make enemy moves in the whole map, I didn't managed a way to do it. Then I ended up just moving the enemy pos in the same block
- Keycodes: yet another difference between MacOS and Linux. The keycodes (``WASD``, ``ESC``, etc) are completely different. I defined those variables straight from the makefile to correct this issue.

## Features

- Adding XP bar
- Adding to the player the possibility to kill a specific enemy
- Adding multiple types of enemies
- Adding a level heart that decrease if the player touched an enemy 

## Summary
This has been my favorite project so far, coding my own Minecraft simple clone was so much fun :)

March 8, 2023
