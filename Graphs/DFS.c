#include<stdio.h>
#include<stdlib.h>

#define print(a) 	printf("%d", a)
#define nline		printf("\n")
#define fl(i,a,b)	for(i=a; i<b; i++)
#define N 40
#define none 999

typedef struct listnode
{
	int data;
	struct listnode* next;
}listnode;

typedef struct list
{
	listnode *head;
}list;

typedef struct graph
{
	int vertices;
	list* array;
}graph;

int track[N];

//Function prototypes
listnode * getnode(int d);
graph* creategraph(int n);
void getvertices(graph* G);
void addEdge(graph* G, int src, int dest);
void traverse(graph* G);
int DFS_visit(graph *G, int u, int time, int visited[], int dist[], int parent[], int f[]);
void dfs(graph* G);


int main()
{
    // create the graph given in above figure
    int V = 6,i;
    graph* g = creategraph(V);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 1);
    addEdge(g, 3, 2);
    addEdge(g, 4, 3);
    addEdge(g, 4, 5);
    addEdge(g, 5, 5);

	printf("Traversing the adjacency list : ");
	nline;
	traverse(g);
	nline;

	getvertices(g);
	printf("Vertices are: \n", 0);nline;
	fl(i,0,V){
	    printf("%d ", track[i]);
	}
	nline;
	printf("\nDFS \n");
	dfs(g);
	nline;
	return 0;
}

//Creating a node
listnode* getnode(int d){
    listnode *newnode;
    newnode = (listnode*)malloc(sizeof(listnode));
    newnode->data = d;
    newnode->next = NULL;
    return newnode;
}

graph* creategraph(int n)
{
	int i;
	graph* G=(graph *)(malloc(sizeof(graph)));
	G->vertices = n;

	G->array = (list *)malloc(n * sizeof(struct list));

	fl(i,0,n)
		G->array[i].head = NULL;
	return G;
}

void getvertices(graph *G){
    int k=0;
    int i;
    fl(i,0,N){
        listnode* temp_node;
		temp_node=G->array[i].head;
		if(temp_node!=NULL){
            track[k] = i;
            k+=1;
		}
	}
	return;
}

void addEdge(graph* G, int src, int dest)
{
	listnode* newNode = getnode(dest);                  // Add an edge from src to dest.
    newNode->next = G->array[src].head;             //The next pointer points to the existing head of the list
    G->array[src].head = newNode;                   //The new node becomes the head of the list
                                                    // Since graph is directed, we dont need to add an edge from dest to src.

}

void traverse(graph* G)
{
	graph* temp=G;
	int i;
	int n = G->vertices;
	list* temp_list;
	listnode* temp_node;
	fl(i,0,n)
	{
		temp_node=temp->array[i].head;
		printf("%d", i);
		while(temp_node!=NULL)
		{
			printf("-> %d ",temp_node->data);
			temp_node=temp_node->next;
		}
		nline;
	}
	return;
}

int DFS_visit(graph *G, int u, int time, int visited[], int dist[], int parent[], int f[]){
    printf("\nVisiting ");
    print(u);

    visited[u] = 1;
    time += 1;
    dist[u] = time;

    listnode* temp_node=G->array[u].head;

    while(temp_node!=NULL)
	{
	    int adj = temp_node->data;
		if(!visited[adj])
		{
			parent[adj] = u;
			time = DFS_visit(G,adj,time,visited,dist,parent, f);
		}

		temp_node=temp_node->next;
	}
	visited[u] = 2;
	f[u]=time=time+1;
    return time;
}

void dfs(graph* G)
{
    getvertices(G);
    int n = G->vertices;
    int visited[n];
    int parent[n];
    int dist[n];
    int f[n];
	int i,time;
	fl(i,0,G->vertices){
        visited[i] = 0;
        dist[i] = 0;
        parent[i] = none;
    }
    time = 0;

    fl(i,0,G->vertices){
        if(visited[i]==0){
	    printf("Starting from : %d", i);
            time = DFS_visit(G,i,time,visited,dist,parent,f);
	}
    }
    nline;
    printf("\n\nParents :");
    for(i=0;i<G->vertices;i++)
    {
        if(parent[i] == none){
            printf("\nVertex: %d, Parent: NULL",i);
        }
        else
            printf("\nVertex: %d, Parent: %d",i,parent[i]);
    }
    printf("\n\nTime stamps :");
    for(i=0;i<G->vertices;i++)
    {
        printf("\nVertex: %d, Entry time: %d, Exit time: %d",i,dist[i],f[i]);
    }
}

