/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*BSF and DSF on a graph represented using adjacency matrix*/


#include<stdio.h>
#include "malloc.h"
#define MAX 10

typedef struct que
{
	int rear,front;
	int data[MAX];
}que;

typedef struct matrix {
    int n;
    int a [MAX] [MAX];
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
	printf ("\n");
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
  
	if(p.rear==MAX-1) {
		return(1);
  }
  
	return(0);
}


void init_p_vis () {
    int i;
  p. front = 0;
  p. rear = -1;

  V -> n = 2;

  for(i = 0;i<MAX;i++) {
	  V -> a [0] [i] = 0;
  }
  
  for(i = 0;i < MAX; i++) {
	  V -> a [1] [i] = 0;
  }
}

// primitive logic ends




// insert, access logic begins here
void insert(int x)
{
  // inserts at rear
  // [lastin];
	p.rear++;
	p.data [p.rear] = x;
}


int dele()
{
  // accesses at front
  // [firstin];
  
	int x;
  
	x = p.data [p.front];
	V -> a [1] [x] ++;
  
	if(p.rear == p.front)
	{
		p. rear = -1;
		p. front = 0;
	}
    
	else {
		p.front++;
  	}
  
	return (x);
}

// insert, access logic ends here;




// BFS, DFS logic begins here

void DFS(int v)
{
	int i, j, k, flag0;  
	init_p_vis ();
	j = 0;
	k = 2;
	flag0 = 0;

	insert(v); // insert lastin
  	V -> a [0] [j] = v; // traversal answer
	j++;
	printf("\nvisited\n%d", v);
  

	while(empty() == 0) {
		v = dele_st(); // access firstin
    
		for(i = 0; i < MAX; i++) {
			if (V -> a [1] [i] == 0 && G [v] [i] != 0) {
				insert(i);
				V -> a [0] [j] = i;
				j++;
				printf("\n%d",i);
				flag0 = 1;
				break;
			}
		}
	}

	
	if (flag0 == 0 && k < MAX) {
		insert (V -> a [0] [j - k]);
		k++;
		flag0 = 0;
	}
}




void BFS (int v) {
	int i, j;  
	init_p_vis ();
	j = 0;

	insert(v); // insert lastin
  	V -> a [0] [j] = v; // traversal answer
	j++;
	printf("\nvisited\n%d", v);
  

	while(empty() == 0) {
		v = dele(); // access firstin
    
		for(i = 0; i < MAX; i++) {
			if (G [v] [i] != 0) {
				insert(i);
				V -> a [0] [j] = i;
				j++;
				printf("\n%d",i);
			}
		}
	}
}




void main()
{
	int i,j,v,op,e,x;
	struct matrix * matrix0;

matrix0 = scanm ():
 
    void BFS(0);
    //void DFS(0);
}
