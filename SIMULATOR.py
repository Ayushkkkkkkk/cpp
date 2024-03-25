import random
from collections import deque


class Node:
    def __init__(self, value):
        self.value = value


class Edge:
    def __init__(self, firstNode, secondNode):
        self.firstNode = firstNode
        self.secondNode = secondNode


class Graph:
    def __init__(self):
        self.vertices = []  # this will store all of my vertices
        self.edges = []  # this will stroe all of my edges

    def addVertices(self, value):
        vertex = Node(value)
        self.vertices.append(vertex.value)

    def addEdges(self, first_vertex, second_vertex):
        storeEdges = []
        Vertices = Edge(first_vertex, second_vertex)
        storeEdges.append(Vertices.firstNode)
        storeEdges.append(Vertices.secondNode)
        self.edges.append([Vertices.firstNode, Vertices.secondNode])
        storeEdges.clear()


world = Graph()
node1 = world.addVertices(1)
node2 = world.addVertices(2)
node3 = world.addVertices(3)
node4 = world.addVertices(4)
node5 = world.addVertices(5)
node6 = world.addVertices(6)
node7 = world.addVertices(7)

world.addEdges(1, 2)
world.addEdges(2, 3)
world.addEdges(3, 4)
world.addEdges(4, 5)
world.addEdges(5, 6)
world.addEdges(6, 7)
world.addEdges(7, 1)

VerticesArray = world.vertices
EdgesArray = world.edges
# Edges of the array
# print(EdgesArray)
# Vertices of the array
# print(VerticesArray)

VerticesCount = 7
EdgesCount = 7

ROUTES = [[] for _ in range(VerticesCount + 1)]

C = 0
for i in range(EdgesCount):
    CURR = EdgesArray[C]
    dx = CURR[0]
    dy = CURR[1]
    print(dx, dy)
    ROUTES[dx].append(dy)
    ROUTES[dy].append(dx)
    C += 1

print(ROUTES)


random_start = random.randint(1, VerticesCount)
random_end = random.randint(1, VerticesCount)


VISITED = set()  # Set to track of Visited nodes of graph


def DFS(ROUTES, source, destination, visited=None, path=None):
    if visited is None:
        visited = set()
    if path is None:
        path = []

    visited.add(source)
    path.append(source)

    if source == destination:
        return path

    for neighbor in ROUTES[source]:
        if neighbor not in visited:
            new_path = DFS(ROUTES, neighbor, destination, visited, path.copy())
            if new_path:
                return new_path

    return None


random_start = random.randint(1, VerticesCount)
random_end = random.randint(1, VerticesCount)
print(f"Random start node: {random_start}")
print(f"Random end node: {random_end}")

path = DFS(ROUTES, random_start, random_end)
if path:
    print(path)
else:
    print("path not found")


def BFS(ROUTES, source, destination):
    queue = deque([(source, [source])])
    visited = set()

    while queue:
        current, path = queue.popleft()
        visited.add(current)

        if current == destination:
            return path

        for neighbor in ROUTES[current]:
            if neighbor not in visited:
                queue.append((neighbor, path + [neighbor]))

    return None


STORE_ALL_OF_THE_PATHS = []
# 1 to 1
# 1 to 2
# 1 to 3
# 1 to 4
# 1 to 5
# 1 to 6
# 1 to 7
# 2 to 2
# 2 to 3
# 2 to 4
# 2 to 5
# 2 to 6
# 2 to 7
# 3 to 3
# 3 to 4
# 3 to 5
# 3 to 6
# 3 to 7
# 4 to 4
# 4 to 5
# 4 to 6
# 4 to 7
# 5 to 5
# 5 to 6
# 5 to 7
# 6 to 6
# 6 to 7
# 7 to 7
# THe STORE_ALL_OF_THE_PATHS will store the paths of all the possible paths if there's not a path from source to destination it will store [] empty array
for i in range(1, 8):
    for j in range(i, 8):
        path = BFS(ROUTES, i, j)
        if path:
            STORE_ALL_OF_THE_PATHS.append(path)
        else:
            STORE_ALL_OF_THE_PATHS.append([])

print(STORE_ALL_OF_THE_PATHS)


def DFS2(ROUTES, source, destination, visited=None, path=None):
    if visited is None:
        visited = set()
    if path is None:
        path = []

    visited.add(source)
    path.append(source)

    if source == destination:
        return len(path) - 1  # Subtracting 1 to exclude the starting node

    for neighbor in ROUTES[source]:
        if neighbor not in visited:
            length = DFS2(ROUTES, neighbor, destination, visited, path)
            if length is not None:
                return length

    # If destination not found from this path
    path.pop()  # Remove the current node from the path before backtracking
    return None


def BFS2(ROUTES, source, destination):
    queue = deque([[source, 0]])  # Use list instead of tuple
    visited = set()

    while queue:
        # Unpack current node and path length from the list
        current, path_length = queue.popleft()
        visited.add(current)

        if current == destination:
            return path_length

        for neighbor in ROUTES[current]:
            if neighbor not in visited:
                # Use list instead of tuple
                queue.append([neighbor, path_length + 1])

    return None


Store_Randmon_Simulation = []
Store_Shortest_pathSImulation = []

TEST_CASES_FOR_SIMULATION = []

for i in range(0, 1000):
    dx = random.randint(1, 7)
    dy = (dx % 7) + (random.randint(1, 7))
    TEST_CASES_FOR_SIMULATION.append([dx, dy])


print(TEST_CASES_FOR_SIMULATION)
# simulation for random_walk without caring about the shortest distance
for i in range(0, 1000):
    coords = TEST_CASES_FOR_SIMULATION[i]
    DX = coords[0]
    DY = coords[1]
    Visited_nodes_count = DFS2(ROUTES, DX, DY)
    if Visited_nodes_count:
        Store_Randmon_Simulation.append(Visited_nodes_count)


print(Store_Randmon_Simulation)


# Simulation for the shortest path
for i in range(0, 1000):
    coords = TEST_CASES_FOR_SIMULATION[i]
    DX = coords[0]
    DY = coords[1]
    Visited_nodes_count = BFS2(ROUTES, DX, DY)
    if Visited_nodes_count:
        Store_Shortest_pathSImulation.append(Visited_nodes_count)

print(Store_Shortest_pathSImulation)
