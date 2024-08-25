### Table of Contents

- [Game Title, Genre and Theme](#Game Title, Genre and Theme)
- [Main Game Flow](#Main Game Flow)
- [Game Mechanics](#Game Mechanics)
- [Technical Systems](#Technical Systems)
- [Gameplay Video](#Gameplay Video)

---

## Game Title, Genre and Theme

Game Title: Scarecrow Jump

Genre: Platformer, similar to "Doodle Jump"

Theme: The game is a platformer where the player controls a scarecrow that must jump on platforms,
trying to ascend as high as possible, avoiding obstacles, and collecting various bonuses.

## Main Game Flow

1. Game Start:

The player starts from the main menu, where they can choose options like "Play or "Continue."

After selecting "Play," the player is taken to the starting level, where the scarecrow begins at the top of the screen.

2. Gameplay:

The player controls the scarecrow, which continuously jumps upward.
The player must direct the scarecrow using keyboard or touch controls to land on platforms.

Platforms are randomly generated, and the player must avoid various monsters
and collect modifiers that push the scarecrow upward.

As the scarecrow ascends, the levels become more challenging: platforms start moving,
enemies and other obstacles appear.

3. Game End Conditions:

The game ends when the scarecrow falls off the screen
or collides with an enemy.

After the game end option to restart the game apears.

4. Game Interruption:

The player can pause the game, which freezes all actions on the screen and allows them to resume the game or return to the main menu.

## Game Mechanics

Platforms

1. Static Platforms: Remain stationary and provide a stable surface for the scarecrow to jump from.

2. Moving Platforms: Move horizontally requiring precise timing and positioning to land successfully.

3. Spring Platforms: Propel the scarecrow higher with a single jump that has double the usual power.

4. One-Touch Platforms: Disappear after the scarecrow lands on them once, requiring the player to quickly jump to another platform.

5. Fake Platforms: Disappear immediately upon contact without allowing the scarecrow to jump, posing a deceptive challenge.

Monsters

1. Bees:

Description: Small, static NPCs that remain in a fixed position on the screen.
Behavior: They don't move but serve as obstacles that the scarecrow must avoid.

2. UFO:

Description: A floating NPC that moves across the screen horizontally.
Behavior: The UFO glides from one side of the screen to the other, creating a moving obstacle that the player must time their jumps to avoid.

3. Poop:

Description: A large, static NPC that occupies a significant portion of the screen.
Behavior: The poop doesn't move but acts as a major obstruction, forcing the player to find a way around it.

Modifiers

1. Tractor

Description: A powerful farming vehicle that attaches to the scarecrow upon collection.

Effects:
Upward Boost: Propels the scarecrow upward at a steady, increased speed.
Invincibility: Grants temporary immunity to all monsters and obstacles.

Duration: Lasts for a limited time before detaching, after which normal gameplay resumes.

2. Goose

Description: A swift goose that carries the scarecrow upward upon interaction.

Effects:
Rapid Ascent: Moves the scarecrow upward faster than the tractor modifier.
Invincibility: Provides temporary immunity to all threats during its effect.

Duration: Shorter lifespan compared to the tractor but covers more distance due to higher speed.

Scoring System

Points are awarded based on the height reached.

## Technical Systems


Procedurally Generated World:

 Platform Generation: Platforms are procedurally generated continuously up to a specific height, ensuring that the player always has new platforms to jump on.

 Dynamic Object Movement: When the player’s scarecrow ascends above the halfway point of the screen, all objects on the screen begin to move downward.

 Object Management: Objects that move below the screen's view are deleted to optimize performance,
 while new platforms, monsters, and modifiers are generated above the visible area to keep the gameplay fresh and challenging.

Save and Load System:

 Progress Saving: When the player exits the game, all object positions and progress are saved,
 allowing the player to continue from the previous position upon re-entering the game.

 Menu Navigation: The player can switch between the main menu and the game without losing any progress, ensuring a seamless gameplay experience.

## Gameplay Video

![Gameplay Video](https://youtu.be/W5msmxVSq0E)