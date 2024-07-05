# DSA-Project-in-Cpp
<b>ODI Record of Batsmen and International Stadiums</b>
<br>
<br>
This project is an implementation of various data structures to manage and analyze One Day International (ODI) cricket records of batsmen and distances between international stadiums.
Introduction
<br>
<br>
<b>This project includes : </b>
A dataset containing ODI cricket records of batsmen (name, matches, runs, average, fifties, centuries).
A dataset with distances between international cricket stadiums.
The C++ program provides functionalities using different data structures to manipulate and query these datasets.
<br>
<br>
<b>Functionalities : </b>
<br>
<br>
ODI Record Dataset
Get all players' data.
Get data with respect to matches played.
Get data with respect to the average of each player.
Get data with respect to runs made.
Get data of a particular player.
Add a new player to the data.
List players from lowest to highest runs made.
List players from most to least matches played.
Delete a player by name.
Calculate average runs for all players.
Sort players by average.
Search for a particular player using the average.
Find the frequency of centuries with constant time complexity.
Stadium Distances Dataset
Calculate the shortest distance from one stadium to another (connected or not).
Find the shortest connection among all stadiums.
Print the graph and results of the algorithms.
<br>
<br>
<b>Data Structures Used : </b>
<br>
<br>
Array,
Doubly Linked List,
Stack,
Queue,
Binary Search Tree (AVL Tree),
Hashing,
Graphs,
Minimum Spanning Tree
<br>
<br>
<b>Implementation Details : </b>
<br>
<br>
Linked List: Stores complete information of a single player. Data from CSV file is stored in nodes and then a linked list is created.
Stacks: Used for operations requiring Last-In-First-Out (LIFO) like sorting.
Queues: Used for operations requiring First-In-First-Out (FIFO) like intermediate storage.
BST (AVL Trees): Used for sorting data with respect to the average and reducing search time complexity to log(n).
Hashing: Used to find the frequency of a particular number of centuries with O(1) time complexity.
Graphs: Used to link data with each other. Dijkstra's Algorithm is implemented for shortest path finding.
Arrays: Used to implement graphs.
Minimum Spanning Trees: Used to create links between all nodes with the minimum distance. Prim's Algorithm is implemented.
