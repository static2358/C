#include <stdio.h>
#define MAX_VERTICES 100

struct Graph {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

void addEdge(struct Graph* graph, int u, int v) {
    graph->adjMatrix[u][v] = 1;
    graph->adjMatrix[v][u] = 1;
}

void welshPowell(struct Graph* graph) {
    int degree[MAX_VERTICES] = {0};
    int i, j, current_color;

    for (i = 0; i < graph->vertices; i++) {
        for (j = 0; j < graph->vertices; j++) {
            if (graph->adjMatrix[i][j] == 1)
                degree[i]++;
        }
    }

    int sorted_vertices[MAX_VERTICES];

    for (i = 0; i < graph->vertices; i++)
        sorted_vertices[i] = i;

    for (i = 0; i < graph->vertices - 1; i++) {
        for (j = 0; j < graph->vertices - i - 1; j++) {
            if (degree[sorted_vertices[j]] < degree[sorted_vertices[j + 1]]) {
                int temp = sorted_vertices[j];
                sorted_vertices[j] = sorted_vertices[j + 1];
                sorted_vertices[j + 1] = temp;
            }
        }
    }

    int color[MAX_VERTICES];
    
    for (i = 0; i < graph->vertices; i++)
        color[i] = -1;

    current_color = 0;

    for (i = 0; i < graph->vertices; i++) {
        int vertex = sorted_vertices[i];
        
        if (color[vertex] == -1) {

            color[vertex] = current_color;
            
            for (j = i + 1; j < graph->vertices; j++) {
                int v = sorted_vertices[j];
                
                if (color[v] == -1) {
                    if (graph->adjMatrix[vertex][v] == 0) {
                        int can_color = 1;
                        int k = 0;
                        while (k < graph->vertices && can_color) {
                            if (graph->adjMatrix[v][k] == 1 && color[k] == current_color) {
                                can_color = 0;
                            }
                            k++;
                        }
                        if (can_color) {
                            color[v] = current_color;
                        }
                    }
                }
            }
            current_color++;
        }
    }

    int num_colors = current_color;

    printf("Graph colored using %d colors:\n", num_colors);
    for (i = 0; i < graph->vertices; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
}

int main() {
    struct Graph graph;
    graph.vertices = 5;

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);
    addEdge(&graph, 1, 4);

    welshPowell(&graph);

    return 0;
}