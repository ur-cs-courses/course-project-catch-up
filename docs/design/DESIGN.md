# Design Document

## Use Case Diagrams

To view our use case diagrams for this project, click [here](usecases/USECASES.md).

## Class Diagram

### Manager Class:
A class that represents the managers methods and objects. The manager is the user of the system or the manager of the building. The manager will be the one assignings robots to do jobs and will be able to view the status of all the robots. The manager class uses the Technician class, the Room class, and the Robot class.

### Robot Class:
A class that represents the methods related to a Robot and all its elements. The robot is responsible for cleaning the assigned rooms. A Robot is consisted of its name, size, battery level and location. We can use given functions to check the cleaning process of a room. With the functions we can move, charge, set the name, get the size and battery, check availability and failure and if a room is clean. The Robot class uses the Room class.

### Room Class:
A class that represents the members and methods of rooms.  A room has different attributes depending on how big it is, and how it should be cleaned (sweeped, mopped, or scrubbed).  The functions include us allow us to check how big the room is, as well as the ability to change how clean the room is, and a function that will randomly dirty the room.  The Room class is used by the Manager and Robot classes.

### Team Contributions: 
Jennie Campbell - We spoke about the entirty of the class diagram and the methods for each class as a group. I create the Manager class in the puml document and added all of its methods that were discussed. I also added any relationships Manager had with other classes.

Sofia Dimotsi - after going over our overall design and talking through each class during class I chose to implement the design for the Robot class. I added to the puml document the implementation of Robot class and the relationships between Robot class and the rest of the classes that we created as a team. I also exported the png file for the Class Diagram to make sure the diagrams are correctly described. 

Pierce Chancy - We talked through the entire diagram during our meetings.  I then updated our class diagram puml with the Room Class members and methods, as well as made some formatting more consistent.