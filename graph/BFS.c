#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int src;
    int* adjList;
    int deg;
    int visited;
}graph;

int readFile(FILE*, graph**);
void printAdjList(graph*, int);
void BFS(graph*, int);
void enque(int**, int, int size);
int deque(int**, int size);
int isEmpty(int*);

int main()
{
    graph* gr;
    int size;
    FILE* fp;
    fp=fopen("graph/adjacencyMatrix.txt", "r");
    size=readFile(fp, &gr);
    fclose(fp);
    //printAdjList(gr, size);
    BFS(gr, size);
    return 0;
}

void BFS(graph* gr, int size)
{
    int i=0, j, k=0;
    int* queue=(int*)malloc(sizeof(int)*size);
    for(i=0; i<size; i++)
        queue[i]=-1;
    i=0;
    enque(&queue, gr[i].src, size);
    gr[i].visited=1;
    printf("\n\nTraversal\n");
    while(!isEmpty(queue))
    {
        int temp=deque(&queue, size);
        printf("\n%d", temp);
        for(j=0; j<gr[temp].deg; j++)
        {
            if(gr[gr[temp].adjList[j]].visited==0)
            {
                enque(&queue, gr[gr[temp].adjList[j]].src, size);
                gr[gr[temp].adjList[j]].visited=1;
            }
        }
    }
}

void enque(int** queue, int temp, int size)
{
    int rear=-1, i;
    for(i=0; (*queue)[i] > 0; ++rear, i++);
    (*queue)[++rear]=temp;
}

int deque(int** queue, int size)
{
    int i=0, temp, temp2;
    temp=(*queue)[0];
    (*queue)[0]=-9;
    for(i=0; i<size-1; i++)
    {
        if((*queue)[i] < 0 && (*queue)[i+1] >= 0)
        {
            temp2=(*queue)[i+1];
            (*queue)[i+1]=(*queue)[i];
            (*queue)[i]=temp2;
        }
        else
        {
            break;
        }
    }
    return temp;
}

int isEmpty(int* queue)
{
    if(queue[0]<0)
        return 1;
    else
        return 0;
}

int readFile(FILE* fp, graph** gr)
{
    int size, i, j;
    fscanf(fp, "%d", &size);
    (*gr)=(graph*)malloc(size*sizeof(graph));
    for(i=0; i<size; i++)
    {
        fscanf(fp, "%d%d", &(*gr)[i].src, &(*gr)[i].deg);
        (*gr)[i].adjList=(int*)malloc(sizeof(int)*(*gr)[i].deg);
        for(j=0; j<(*gr)[i].deg; j++)
        {
            fscanf(fp, "%d", &(*gr)[i].adjList[j]);
        }
        (*gr)[i].visited=0;
    }
    return size;
}

void printAdjList(graph* gr, int size)
{
    int i, j;
    printf("\tSource\t\tDegree\t\tAdjList\n\n");
    for(i=0; i<size; i++)
    {
        printf("\t%d\t\t%d\t", gr[i].src, gr[i].deg);
        for(j=0; j<gr[i].deg; j++)
        {
            printf("\t%d", gr[i].adjList[j]);
        }
        printf("\n");
    }
}