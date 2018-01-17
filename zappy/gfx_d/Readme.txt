********************************************************************************
                                                                                
                                                          :::      ::::::::     
     Readme.txt                                         :+:      :+:    :+:     
                                                      +:+ +:+         +:+       
     By: abanvill <abanvill@student.42.fr>          +#+  +:+       +#+          
                                                  +#+#+#+#+#+   +#+             
     Created: 2014/06/20 19:10:10 by abanvill          #+#    #+#               
     Updated: 2014/06/20 19:10:10 by abanvill         ###   ########.fr         
                                                                                
********************************************************************************

[INSTALLATION]
--------------------------------------------------------------------------------
To prepare the visual client, you need to launch [make install] to get & 
configure the SDL libraries and next you just need to [make].

[INTERFACE PROTOTYPES]
--------------------------------------------------------------------------------
################################################################################

void				charTurn(int id, int dir);

DESCRIPTION:
The actionTurn function will set the (dir) variable of the t_sprite struct 
targetted by the (id) variable.
Some defines are availables for (dir).

#| DEFINES    | Value |#
------------------------
#| DOWN_DIR   |   0   |#
#| LEFT_DIR   |   1   |#
#| RIGHT_DIR  |   2   |#
#| UP_DIR     |   3   |#

################################################################################

void				charMove(int id)

DESCRIPTION:
The actionMove function will displace the (id) sprite in the direction who has
been set in (dir) variable. That why you need to call actionTurn before.

################################################################################

void        charDisplace(int id, int dir, int caseX, int caseY);

DESCRIPTION:
The actionDisplace function allows you move an (id) sprite to a case
of the map whith the (dir) direction. 
The same defines than actionTurn function are availables for the (dir) variable.

################################################################################

void        charInvoke(int id[optionnal], int dir, int caseX, int caseY);

DESCRIPTION:
The charInvoke function will spawn an (id) new character on (caseX, caseY).
Note: For now, just 3 [id] are availables;

################################################################################

void        charRevoke(int id);

DESCRIPTION:
The charRevoke function will un-spawn an (id) existing character.

################################################################################

void        charResurrect(int id);

DESCRIPTION:
The charResurrect function will spawn an (id) revoked character with his previous 
statistics. (Case(x, y), Level...)

################################################################################

void        charDestroy(int id);

DESCRIPTION:
The charDestroy function will un-spawn an (id) character and reset all his statistics.
If the destroyed character is ressurected, it will spawn at (0, 0);

################################################################################

void        charPutGem(int id, int gem, int number);

DESCRIPTION:
The charPutGem function will remove (number) of (gem) in the (id) character
inventory and add (number) of (gem) in the current (id) character case.

################################################################################

void        charSetGem(int id, int gem, int number)

DESCRIPTION:
The charSetGem function is an absolute method that will set the (gem) (number)
of the (id) character.

################################################################################

void        charTakeGem(int id, int gem, int number);

DESCRIPTION:
The charTakeGem function will add (number) of (gem) in the (id) character
inventory and remove (number) of (gem) in the current (id) character case.

################################################################################

void        charLevel(int id, int set)

DESCRIPTION:
The charLevel function will increase or decrease the [level] variable of 
(id) character.
Some defines are availables for (set) variable.

-[set]
#| DEFINES    | Value |#
------------------------
#| LEVEL_DOWN |   0   |#
#| LEVEL_UP   |   1   |#

################################################################################

void        charSetFood(int id, int number)

The charSetFood function is an absolute method that will set the food (number)
of the (id) character.

################################################################################

void        caseSetGem(int caseX, int caseY, int gem, int set, int number);

DESCRIPTION:
The caseSetGem function authorize you to set gems in cases.
Some defines are availables for (gem) & (set).
The (number) variable determines the amount of gems that will be set.

-[set]
#| DEFINES    | Value |#
------------------------
#| REMOVE     |   0   |#
#| ADD        |   1   |#
#| SET        |   2   |#

-[gem]
#| DEFINES    | Value |#
------------------------
#| LINEMATE   |   0   |#
#| DERAUMERE  |   1   |#
#| SIBUR      |   2   |#
#| MENDIANE   |   3   |#
#| PHIRAS     |   4   |#
#| THYSTAME   |   5   |#

################################################################################

t_size      *linkWorldSize(int x, int y)

DESCRIPTION:
The linkWorldSize function allows you to set the x and y size of zappy world in
blocks unit.
Example: linkWorldSize(12, 12) for 12 x 12 blocks map.

################################################################################

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

Tasks:
	- New players Management
  - Eggs Management
  - Put / Take Actions Functions

Assets:
  - http://www.rpgmakervx.net/lofiversion/index.php/t9742.html
