import networkx as nx
import matplotlib.pyplot as plt

# Create an empty graph
G = nx.Graph()

# Add vertices (nodes) to the graph
G.add_nodes_from([1, 2, 3, 4, 5])

# Add edges to the graph
G.add_edges_from([(1, 2), (2, 3), (3, 4), (4, 5), (5, 1)])

# Draw the graph
nx.draw(G, with_labels=True, node_color='lightblue', edge_color='gray')

# Show the graph
plt.show()

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.adjMatrix = [[0] * vertices for _ in range(vertices)]

    def add_edge(self, u, v):
        self.adjMatrix[u][v] = 1
        self.adjMatrix[v][u] = 1

    def is_safe(self, v, color, c):
        for i in range(self.vertices):
            if self.adjMatrix[v][i] == 1 and color[i] == c:
                return False
        return True

    def graph_coloring_util(self, m, color, v):
        if v == self.vertices:
            return True

        for c in range(1, m+1):
            if self.is_safe(v, color, c):
                color[v] = c
                if self.graph_coloring_util(m, color, v+1):
                    return True
                color[v] = 0

    def graph_coloring(self, m):
        color = [0] * self.vertices
        if not self.graph_coloring_util(m, color, 0):
            return False

        print("Graph can be colored using {} colors:".format(m))
        for i in range(self.vertices):
            print("Vertex {}: Color {}".format(i, color[i]))

        # Visualisation
        G_viz = nx.Graph()
        for i in range(self.vertices):
            for j in range(i+1, self.vertices):
                if self.adjMatrix[i][j] == 1:
                    G_viz.add_edge(i, j)
        
        color_map = ['red', 'blue', 'green', 'yellow', 'orange', 'purple', 'pink', 'brown']
        node_colors = [color_map[color[i] % len(color_map)] for i in range(self.vertices)]
        
        plt.figure(figsize=(8, 6))
        nx.draw(G_viz, with_labels=True, node_color=node_colors, node_size=800, font_size=14, font_weight='bold', edge_color='gray', width=2)
        plt.title(f"Backtracking : {m} couleurs", fontsize=14)
        plt.show()

        return True


g = Graph(5)

g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 2)
g.add_edge(1, 3)
g.add_edge(2, 3)
g.add_edge(3, 4)
g.add_edge(1, 4)

m = 4 
g.graph_coloring(m)


""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.adjMatrix = [[0] * vertices for _ in range(vertices)]

    def add_edge(self, u, v):
        self.adjMatrix[u][v] = 1
        self.adjMatrix[v][u] = 1

    def welsh_powell(self):

        degree = []
        for row in self.adjMatrix:
            degree.append(sum(row))
        
        sorted_vertices = sorted(range(self.vertices), key=lambda x: degree[x], reverse=True)

        color = [-1] * self.vertices
        current_color = 0

        # Color each vertex
        for i in range(self.vertices):
            vertex = sorted_vertices[i]
            
            # If this vertex is not yet colored
            if color[vertex] == -1:
                # Color it with current_color
                color[vertex] = current_color
                
                # Try to color all other non-adjacent vertices with the same color
                for j in range(i + 1, self.vertices):
                    v = sorted_vertices[j]
                    
                    # If v is not yet colored
                    if color[v] == -1:
                        # Check if v is not adjacent to vertex
                        if self.adjMatrix[vertex][v] == 0:
                            # Check that v is not adjacent to any vertex having current_color
                            can_color = True
                            k = 0
                            while k < self.vertices and can_color:
                                if self.adjMatrix[v][k] == 1 and color[k] == current_color:
                                    can_color = False
                                k += 1
                            
                            if can_color:
                                color[v] = current_color
                
                # Move to the next color
                current_color += 1

        num_colors = current_color

        print("Graph colored using {} colors:".format(num_colors))
        for i in range(self.vertices):
            print("Vertex {}: Color {}".format(i, color[i]))

        # Visualisation
        G_viz = nx.Graph()
        for i in range(self.vertices):
            for j in range(i+1, self.vertices):
                if self.adjMatrix[i][j] == 1:
                    G_viz.add_edge(i, j)
        
        color_map = ['red', 'blue', 'green', 'yellow', 'orange', 'purple', 'pink', 'brown']
        node_colors = []
        for i in range(self.vertices):
            node_colors.append(color_map[color[i] % len(color_map)])
        
        plt.figure(figsize=(8, 6))
        nx.draw(G_viz, with_labels=True, node_color=node_colors, node_size=800, font_size=14, font_weight='bold', edge_color='gray', width=2)
        plt.title("Welsh-Powell : {} couleurs".format(num_colors), fontsize=14)
        plt.show()

        return num_colors


g = Graph(5)

g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 2)
g.add_edge(1, 3)
g.add_edge(2, 3)
g.add_edge(3, 4)
g.add_edge(1, 4)

g.welsh_powell()
