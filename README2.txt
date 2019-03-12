
Just wanted to post a to-do list so we can start writing, posting and putting stuff together for the project checkpoint coming at the end of the month. 

Right now I'm still working on the backend structure. The goal is to be able to pull information from various objects and use them for:
1. Hero Select Scene (in progress)
2. Game Scene (in progress)
3. Battle Scene (in progress)

The structure of the openGL code is looking like we can push Scenes like we push basic data into method and memory stacks. I still need to figure out how it all works, but it seems like we are going to need a Scene Viewer Controller with an internal switch to swap between scenes. Scenes can have their current data saved so that Game Scene and Battle Scene can flow fluidly.

However, because game mechanics are fairly strict, we are going to need to start writing some more backend functions to support player controls.

Game Scene:
To make this game easier to function and code, the game map will have strict movement, meaning there are going to be fixed locations on the map and the map is NOT freeroaming. If we enable freeroaming in a grid-like map, there will have to be more UI code to write because after hero movement, there will have to be more choices to make like "end turn" or "fight monster" or "interact with location". With strict movement, all of these choice functions can be handled through backend code during Event Phase. Event Phase can do basic checks like:
  -if hero and monster in same location: invoke battle scene
  -if hero is at specific location: invoke random event (or special location like item shop)
  
More on the game scene will be added when I start getting things rolling with it.

Hero Select Scene:
Don't need the dedicated hero sprites yet, however, the scene should present a list of playable heros the user can choose from.
When a hero is selected, it should display the hero's information. Choosing a hero will be recorded somewhere visible so that the user
can see who is in the hero team. I think when it comes to a "reset team" function, creating a button for the user to click should empty
the hero team and the user can start over selecting heroes again. There should be a button to confirm the final team. Needs a check to
make sure that only 4 heroes are allowed to be selected.

Battle Scene:
This one is going to be fairly difficult because it will involve some back end sprite editing possibly. Right now the scene should grab the information from a location with a monster and a hero (the structure is a vector, so multiple monsters and heroes can be in the same
location).

Ideally, a max of four heroes and six monsters should only be allowed in one location. I'll need to provide something that checks monster count, that will be updated soon.

Within the battle scene, the backend battle controller should check the movement of every unit and the highest movement unit will go first.

At this point, I'm not entirely sure how we are going to display a hero's weapon/spell set because that involves searching the unit's inventory and then displaying them onto a HUD with clickable buttons (images of item is button). Clicking on button will invoke the attack. This is the hardest part of the Scene so far because it involves programming that needs the HUD to be updated everytime it is
the user Hero's turn. This should probably be the last thing to code before everything else since it requires the setup of the Scene anyway so we can all work on this together.

Find an appropriate damage calculator that takes in info from Hero, Item, and perform checks.

===

For everyone else, each of you volunteered to do other Scenes or backend methods, I'd like you guys to create a repository of your own within the Game project board and upload any significant updates as you go along. Please in the README, explain the methods you are using and a general idea of how everything works.

Also any questions on how the Scene should be structured or how things should look or anything general about coding, don't be afraid to ask. If you have any interesting links or articles to share, feel free as well.

Here are some links pertaining to the project we are doing.
1. http://nehe.gamedev.net/
The author goes into more detail about code that is similar to csci191 and provides lessons explaining each set of code and what it does.

2. https://wiki.unrealengine.com/HUD,_Canvas,_Code_Sample_of_800%2B_Lines,_Create_Buttons_%26_Draw_Materials
This wiki page explains on screen HUD and interractable buttons that we can probably "borrow".

3. http://www.lighthouse3d.com/tutorials/glut-tutorial/popup-menus/
I was thinking that maybe right-clicking a hero would open a dropdown menu and select a couple choices like "move" or "interract" or "end turn"

4. https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
This is the shortest path search function. We should use this to impliment highlighting of a hero's possible movement across the game map.
