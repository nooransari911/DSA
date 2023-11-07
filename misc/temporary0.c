/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*BSF and DSF on a graph represented using adjacency matrix*/


#include<stdio.h>
#define max 10

typedef struct que
{
	int rear,front;
	int data[max];
}que;

typedef struct matrix {
    int n;
    int a [max] [max];
} matrix;


que p;
struct matrix * G;
struct matrix * V;



matrix * scanm () {
    struct matrix * m0;
    int i, j;
    
    m0 = (struct matrix *) malloc (sizeof (struct matrix));
    
    m0 -> n = 4;
    
    for (i = 0; i < m0 -> n; i++) {
        for (j = 0; j < m0 -> n; j++) {
            printf ("enter <i>, <j>: ");
            scanf ("%d", &m0 -> a [i] [j]);
        }
    }
    
    return m0;
}


void printm (struct matrix * m0) {
    int i, j;
  
    
    for (i = 0; i < m0 -> n; i++) {
        for (j = 0; j < m0 -> n; j++) {
            printf ("%d\t", m0 -> a [i] [j]);
        }
        printf ("\n");
    }
}




// primitive logic begins

int empty()
{
  // returns:
  // 1 if empty,
  // 0 otherwise;
  
	if (p.front > p.rear) {
		return(1);
  }
  
	return(0);
}


int full()
{
  // returns:
  // 1 if full,
  // 0 otherwise;
  
	if(p.rear==max-1) {
		return(1);
  }
  
	return(0);
}


void init_p_vis () {
  p. front = 0;
  p. rear = -1;

  for(i=0;i<n;i++) {
	  V -> a [i] [0] = 0;
  }
}

// primitive logic ends




// insert, access logic begins here
void insert(int x)
{
  // inserts at rear
  // [lastin];
	p.rear++;
	p.data[p.rear]=x;
}


int dele()
{
  // accesses at front
  // [firstin];
  
	int x;
  
	x = p.data [p.front];
  
	if(p.rear == p.front)
	{
		p. rear = -1;
		p. front = 0;
	}
    
	else {
		p.front++;
  }
  
	return(x);
}

// insert, access logic ends here;




// BFS, DFS logic begins here

void DFS(int i)
{
	int j;
	printf("\n%d",i);
	visited[i]=1;
	for(j=0;j<n;j++)
		if(!visited[j] && G[i][j]==1)
			DFS(j);
}




void BFS (int v) {
	int i;  
	init_p_vis ();
  
	insert(v); // insert lastin
  V -> a [v] [0] = 1; // mark
	printf("\nvisited\n%d", v);
  

	while(!empty())
	{
		v = dele(); // access firstin
    
		for(i=0;i<n;i++)
			if (V -> a [v] [0] == 0 && G[v][i]!=0)
			{
				insert(i);
				visited[i]=1;
				printf("\n%d",i);
			}
	}
}




void main()
{
	int i,j,v,op,e,x;

	printf("\nEnter no of vertices : ");
	scanf("%d",&n);
	printf("\nEnter no of edges : ");
	scanf("%d",&e);
	printf("\nEnter the edges (STARTING VERTEX 0):\n ");
	for(x=0;x<e;x++)
        {
        printf("\nEnter the edge(%d): ",x+1);
        scanf("%d%d",&i,&j);
        G[i][j]=G[j][i]=1;
        }
	printf("\nThe adjecency matrix of  graph is:\n\n ");
	for(i=0;i<n;i++)
        {
        for(j=0;j<n;j++)
           printf("%d\t",G[i][j]);
        printf("\n\n");
        }
	do{
	   printf("\n\n1)DFS\n2)BFS\n3)QUIT");
	   printf("\nEnter Your choice : ");
	   scanf("%d",&op);
	   switch(op)
	    { case 1:   printf("\nEnter the starting vertex for DFS : ");
                    scanf("%d",&v);
                    for(i=0;i<n;i++)
                        visited[i]=0;
                    DFS(v);
                    break;
	      case 2:   printf("\nEnter the starting vertex for BFS : ");
                     scanf("%d",&v);
                     BFS(v);break;
	    }
	  }while(op!=3);
	  
	  
	
	
 
    void BFS(int);
    void DFS(int);
}
