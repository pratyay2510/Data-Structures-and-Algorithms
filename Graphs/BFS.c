# include <stdio.h>
# include <stdlib.h>
# define N 40

typedef int data;

//Node for the adjacency list
struct Node{
    int d;
    struct Node *next;
};
typedef struct Node node;

//The adjacency list for each graph node
struct adjlist{
    node *head;
};
typedef struct adjlist AdjList;

//The graph
struct Graph{
    int V;                      //No of vertices
    AdjList* array;
};
typedef struct Graph graph;

int queue[N];   //The queue
int head = -1;  //The head variable
int tail = -1;  //The tail variable

//Function prototypes
node * getnode(data d);
graph *createGraph(int);
void addEdge(graph* g, int src, int dest);
void printGraph(graph* g);
int isfull();        //To check if queue is full
int isempty();        //To check if queue is empty
void enqueue(int);       //To add data to the queue
int dequeue();       //To remove data from the queue
void display();       //To display the queue
void printcolor(int visited);
int maxdist(int dist[]);
void BFS(graph *g, int start);


int main()
{
    // create the graph given in above fugure
    int V = 8;
    graph* g = createGraph(V);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 3, 4);
    addEdge(g, 3, 5);
    addEdge(g, 4, 5);
    addEdge(g, 4, 6);
    addEdge(g, 5, 6);
    addEdge(g, 5, 7);
    addEdge(g, 6, 7);

    // print the adjacency list representation of the above graph
    printGraph(g);

    printf("\nThe breadth first search of the given graph is :\n");
    BFS(g,0);
    return 0;
}

//Creating a node
node* getnode(data d){
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->d = d;
    newnode->next = NULL;
    return newnode;
}

//Creating a graph
graph *createGraph(int V)
{
    graph* g = (graph*) malloc(sizeof(graph));
    g->V = V;

    // Create an array of adjacency lists.  Size of array will be V
    g->array =(AdjList*) malloc(V * sizeof(AdjList));

    // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        g->array[i].head = NULL;

    return g;
}

//Adding the edges to the graphs
void addEdge(graph* g, int src, int dest)
{

    node* newNode = getnode(dest);                  // Add an edge from src to dest.
    newNode->next = g->array[src].head;             //The next pointer points to the existing head of the list
    g->array[src].head = newNode;                   //The new node becomes the head of the list


    newNode = getnode(src);                         // Since graph is undirected, add an edge from dest to src also
    newNode->next = g->array[dest].head;
    g->array[dest].head = newNode;
}

//To visualise the graph
void printGraph(graph* g)
{
    int v;
    for (v = 0; v < g->V; ++v)
    {
        node* crawl = g->array[v].head;                    //Goes through each and every element in each adjacency list
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (crawl)
        {
            printf("-> %d", crawl->d);
            crawl = crawl->next;
        }
        printf("\n");
    }
}

//To check if queue is full
int isfull(){
    return(tail == N-1);
}

//To check if queue is empty
int isempty(){
    return ((head>tail) || (tail==-1));
}

//To add data
void enqueue(int d){
    if(isfull())
        printf("\nOverflow!!");
    else{
            if(head == -1)
                head = 0;
            tail++;
            queue[tail] = d;
        }
}

//To remove data
int dequeue(){
    int val;
    if(isempty()){
        printf("Underflow!!");
        head = -1;
        tail = -1;
    }

    else{
        val = queue[head];
        queue[head] = NULL;
        head++;
    }
    return val;
}

//To display the queue
void display(){
    int i;
    if(isempty())
        printf("\nEmpty Queue!!");
    else{
        printf("\n\nQueue has\t");
        printf("[");
        for(i = head; i<=tail; i++){
            printf(" %d ", queue[i]);
        }
        printf("]");
    }
}

//To print the color of a node
void printcolor(int visited){
    if(visited==0)
        printf("white");
    else if(visited==1)
        printf("gray");
    else
        printf("black");
}

//To get the maximum distance in the graph from the start node
int maxdist(int dist[]){
    int i;
    int max = 0;
    for(i=0;i<N;i++){
        if(dist[i]>max)
            max = dist[i];
    }
    return max;
}


void BFS(graph *g, int start){
    int track[N];
    int k=0;
    int visited[N];
    int dist[N];
    int parent[N];
    int i;
    for(i=0;i<N;i++){
        visited[i] = 0;
        dist[i] = 0;
        parent[i] = NULL;
    }
    visited[start] = 1;                                 //Mark the starting node as gray, as it is visited
    dist[start] = 0;                                    //Mark the distance of the root node as 0
    parent[start] = NULL;                               //Mark the parent of the root node as NULL
    enqueue(start);                                     //Add the starting element to the queue to keep track

    while(!isempty()){
        display();                                      //Displays the queue

        int current = dequeue();                        //Put the current vertex as the first element in the queue
        track[k] = current;
        k +=1;
        printf("\nSearching from   : %d", current);
        printf("\nDistance of %d    : %d", current, dist[current]);
        printf("\nParent of %d      : %d", current, parent[current]);
        printf("\nColour of %d      : ",current);
        printcolor(visited[current]);
        node *t = g->array[current].head;               //A temp variable is assigned the first adjacent node of the current node

        while(t){                                       //Traversing the adjacency list of the current node
            int adjacent = t->d;
            if(visited[adjacent] == 0){                 //If we encounter a node which was previously unvisited,
                visited[adjacent] = 1;                  //we mark it as visited and put it in our queue
                dist[adjacent] = dist[current]+1;       //The distance of the adjacent nodes = 1+distance of current node from initial point
                parent[adjacent] = current;             //The parent of the nodes in the adjacency list of current node is the current node
                enqueue(adjacent);
            }
            t = t->next;
        }
        visited[current] = 2;
    }
    int j,l,number;
    int distance;
    int max = maxdist(dist);
    printf("\n\nColour of nodes after searching is complete:");
    for(l=0;l<k;l++){
        number = track[l];
        printf("\nColour of %d : ",number);
        printcolor(visited[number]);
    }
    printf("\n\n-----------------------------------------------\n");
    printf("---------------------BFS TREE------------------");
    printf("\nLevel 0 : \t%d", start);
    for(distance=1;distance<=max;distance++){
        printf("\nLevel %d:\t", distance);
        for (j=0;j<N;j++){
            if(dist[j]==distance)
                printf("%d ", j);
        }
    }
    printf("\n-----------------------------------------------\n");

}
