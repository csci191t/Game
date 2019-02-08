
Hey guys I just wanted to go into more detail of the game we are making. Like I said before, I've had this idea for awhile and it is a very big idea. So I don't want to stress you guys out too much but this is what I have right now, and I am open to changes and suggestions. Ultimately, I want a game that has a simple goal, yet takes a bit of intuition and strategy to meet that goal. Even a simplified version of the game, I am about to explain, will be more than happy with.

The basic premise of this game is your average "end of the world" scenario where the player must try to prevent the doomsday by traversing the game map trying to defeat monsters, find items such as weapons and armor, and experience a random generation -yet lore and story driven- events depending on the location of the hero. Eventually the Boss will come out onto the map and the player must fight it.

The setting takes place in a fictional city, in a fictional world where the city has withstood a lot of war, cosmic and mythological terror. The boss in this game is called the World Eater and it is a cosmic entity that traverses through space and different dimensions, appearing at a planet or a world to consume and assimilate all living things and ultimately the core of the planet.

The game mechanic can be very reminiscint of classic 16-bit style strategy games like Fire Emblem or Advanced Wars where there is a player phase and then enemy phase. However since we are building the system from scratch and I want random events to occur, there will be 4 distinct phases.

1. Player phase
  -select heroes to move, attack monster, or interact with item shop or other things in map (I'll explain this more later)
  -if player chooses to attack a monster, a new scene will pop up much like how pokemon battles occur

2. Event phase
  -depending on hero's location, random events occur (I will explain this more later)
  -Only Locations can trigger events, streets (or intermediary nodes) have no events

3. Enemy phase
  -rifts in time and space open on locations along with 1 random monster
    a)if there is already a rift at the location of the new rift spawning, a monster surge occurs spawning 1 monster per every open rift
    b)the doomsday clock moves 1 extra hour closer to midnight when a monster surge occurs
  -all monsters on the map move
  -a world-wide event occurs
  -the doomsday clock moves 1 hour closer to midnight

4. Update phase
  -This is mostly invisible to the player, the game system just updates things and gets ready for Player phase
  -This phase marks the end of 1 turn, or 1 doomsday hour, however you like to explain it
  -This phase actually might not be needed, as we get closer to building the game system, will let you know.
  
How the boss comes out:
  -World Eater comes out when the doomsday clock strikes midnight
  -the player has 12 hours to prepare and defend the city
  -the boss battle is the same as monster battles except with all the heroes fighting it at once
  
So this is basically the game, it is a scenario or "mission" based game and I hope a game that has high replayability. The genre is mostly considered strategy (retro) with some RPG-like and surivival elements. The theme is mostly fantasy with a hint of horror with the setting taking place maybe post-victorian or pre WWI (introduction to simple guns and rifles), maybe some steampunk and gothic elements too.


So for the programming stuff:

Since we are making scenes at the moment in class, I'm hoping that we can make:
  -main menu
  -select heroes (for now, we will just make four heroes and add more when we get the basic game running)
  -the actual game map
  -pokemon-like, turn-based fight scene
  -item shop scene (pretty much just a backdrop of an item shop)
  
As for the back end design, I'd like to implement a couple of different systems:
  -inventory system for each hero with currency
  -weapons and armor system
  -fight system (maybe the fight scene coder can do the fight system too)
  
I think for the most part, we can achieve these systems using vectors, classes and search, so there is no need for anything fancy, not even code writing. I would suggest all of us getting familiar with using vectors, fstream, and typecasting since I think we are going to pull alot from misc files and vectors can also hold user created objects like structs and classes.

Misc:

Now here is some fun and creative stuff, I don't have too many ideas for random events, heroes, monsters and locations, so you guys can always chime in with your own so we can add these things to the game.
  -random events:
    For the most part, these events are just things that happen to the hero when they are at a specific location. If you ever have heard of a creepy or just unsettling story, from a friend or maybe personal experience or even something on the internet, try to incorporate it into an event. I can explain more on this later.
  -characters:
      It can be human, alien, lizard person, whatever, just as long as the character is well grounded and has strengths and flaws.
  -locations:
    As far as locations go, the things I have now are:
      1. Item Shop (buy weapons / armor / trinkets)
      2. Hospital (heal hero health)
      3. Psych Ward (heal hero sanity)
      4. Mansion
      5. Woods behind Mansion
      6. Research Facility
      7. Pub (buy food / rum / potions)
      Locations can be seemingly normal places but with interesting or unsettling history.
      
Music:
  I'm all ears. Someone can make it or rip it from something. Maybe have a music for the game map and something different for the fights. Maybe something epic for the boss fight. Can also be cool if we have a "select" jingle and a "cancel" jingle. Sound effects are greatly appreciated as well for the fights.
  
As always, I'm open to changes and suggestions, but I don't think this game is too difficult to implement. We should create a forum lobby so we can ask and discuss topics and questions related to this project. I can sign up for any forum based app, although I do already have Discord and the app can be easily organized for posting and discussing topics.

If you guys are wondering how or what inspired me to want to create something like this, it is mostly from a game called Arkham Horror (unrelated to Batman Arkham). Other inspirations include the SCP Foundation, r/creepypasta, Warhammer 40k, Warcraft, H.P.Lovecraft, some real life mythologies, Stephen King, the Insidious movies, and a bunch of other mystery and horror stuff.

  


