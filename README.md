# Shortest Path Finder - Campus Navigation System for BIT Mesra

## 1. INTRODUCTION

The Shortest Path Finder project provides an efficient Campus Navigation System for BIT Mesra. The project utilizes Dijkstra's Algorithm, a widely-used graph search algorithm, to efficiently compute the shortest paths between nodes representing various locations within the campus. This user-friendly application provides the shortest routes between any two locations on campus. The aim of this project is to help individuals in finding the path to their respective destinations containing the least distance, saving valuable time and effort for students and visitors who frequently need to move from one place to another within the campus.

## 2. ALGORITHM USED

1. Initialize distances of all vertices as infinite.

2. Initialize a vector to store the previous Node of each vertex. The previous Node of the ith Node is vector[i]. Initialize the previous Node of the source as -1.

3. Create an empty priority queue. Each element of the priority queue is a pair of cost (or distance) and vertex.

4. Insert the source vertex into the priority queue and make its distance as 0.

5. While the priority queue is not empty:
   - Extract the minimum distance vertex from the priority queue. Let the extracted vertex be u.
   - Loop through all adjacent vertices of u and do the following for every vertex v. If there is a shorter path to v through u, update the distance of v and insert v into the priority queue. Also, update the previous Node of v as u.
  
   If dist[v] > dist[u] + cost(u, v):
       dist[v] = dist[u] + cost(u, v)
       prevNode[v] = u
   
6. Now, with the help of the previous Node vector, print the shortest path to the destination.

## 3. FUNCTIONALITY

The project will provide the following functionalities:

1. Shortest Path Calculation: Users can input the source and destination locations, and the application will use Dijkstra's Algorithm to find the shortest path between these two locations. The resulting path will be displayed along with the distance to reach the destination. The project will save users' time and effort by providing the shortest route, helping them reach their destinations quickly.

2. Dynamic Graph: As the campus evolves and new locations are added, the system will be updated to incorporate these new nodes representing the latest locations. This ensures that the users have access to the most up-to-date navigation options.

3. User-friendly Interface: The application will have an intuitive and user-friendly interface to make it accessible to all users, including those unfamiliar with complex navigation tools.

## 4. USAGE

**Step 1: Run the program**

Run the desired program using a C++ compiler of your choice.

**Step 2: Input of the source and destination**

Input the source and destination in the form of numbers corresponding to the list shown after the execution of the program.

**Step 3: Output**

The output will be in the form of the shortest path and distance from the source to the destination.

