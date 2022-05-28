Flappy-bird-like game in (ascii) unicode / console. Uses https://github.com/CreaJeu/textraster and curses.


Design (MVC philosophy) :

- textbird
    - allcontrollers
        - ... (keyboard inputs)
        - dependency : curses
        - "dependency" : allmodels
    - allmodels
        - ... (game data and logic, no dependency)
    - allviews
        - ... (console display)
        - dependency : textraster
        - dependency : curses
        - "dependency" : allmodels


The goal of this game is to show that low-tech is great (and shouldn't even have a specific name like "low-tech"). It runs on much much less powerful devices, really meets real real needs, and is the real real way to real real sustainable tech progress. Yes, ascii display is exaggerated, but this exaggeration is a choice to show all this :)


(ascii) unicode : the word "ascii" is here only for its intuitiveness, the game also uses unicode non-ascii characters like ░ ▒ ▓ █.


BUILD :
Only usual C here. Just compile it your favourite way, without forgetting the dependencies. Code::Blocks project included (textbird.cbp), for those who like it, providing just straightforward compilation with textraster and PDcurses.
