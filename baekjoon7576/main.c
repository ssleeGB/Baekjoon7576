//
//  main.c
//  baekjoon7576
//
//  Created by 이승섭 on 2018. 12. 11..
//  Copyright © 2018년 이승섭. All rights reserved.
//

#include <stdio.h>


int qu[1000][3]; //0 : visit order, 1 : y , 2 : x

int front = 0, rear = 0;
int M = 0;
int N = 0;
int Arr[1000][1000];
void push(int _order, int _y, int _x)
{
    qu[rear][0] = _order;
    qu[rear][1] = _y;
    qu[rear][2] = _x;
    rear++;
}

int pop()
{
    front++;
    return front-1;
}
void printQ(){
    for(int i=front;i<rear;i++){
        printf("order : %d y : %d x : %d\n", qu[i][0], qu[i][1], qu[i][2]);
    }
}

void printMatrix()
{
    printf("Current Matrix : \n");
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%d ", Arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main(void)
{
    
    FILE *fp = fopen("input.txt","r");
    fscanf(fp, "%d %d", &M, &N);
    
    int i, j;
    
    
    printf("%d %d \n", M, N);
    
    if(2 <= M && 2 <= N && M <=1000 && N <= 1000)
    {
        for(i = 0; i < N; i++)
        {
            for(j = 0; j < M; j++)
            {
                fscanf(fp, "%d", &Arr[i][j]);
                printf("%d ", Arr[i][j]);
                if(Arr[i][j] == 1){
                    push(1, i, j);
                }
            }
            printf("\n");
        }
    }
    fclose(fp);
    
    //printQ();
    int order, y, x;
    for(;;){
        int cur = pop();
        // check up, down, left, right, if not 0, push the tomato
        order = qu[cur][0];
        y = qu[cur][1];
        x = qu[cur][2];
        
        // check up
        if(y-1 >= 0 && Arr[y-1][x] == 0)
        {
            Arr[y-1][x] = order + 1;
            push(order+1, y-1, x);
        }
        
        // check down
        if(y+1 < N && Arr[y+1][x] == 0)
        {
            Arr[y+1][x] = order + 1;
            push(order+1, y+1, x);
        }
        
        // check left
        if(x-1 >=0 && Arr[y][x-1] == 0)
        {
            Arr[y][x-1] = order + 1;
            push(order+1, y, x-1);
        }
        
        // check right
        if(x+1 < M && Arr[y][x+1] == 0)
        {
            Arr[y][x+1] = order + 1;
            push(order+1, y, x+1);
        }
        
        
        // print current qu
        //printQ();
        printMatrix();
        
        //printf("%d", cur);
        if(front==rear) break;
    }
    
    
    // find the result
    int result = 0;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            if(Arr[i][j] > result)
            {
                result = Arr[i][j];
            }
            if(Arr[i][j] == 0)
            {
                result = -1;
                break;
            }
        }
        if(result == -1 ) break;
    }
    if(result == -1)
    {
        printf("result : %d\n", -1);
    }
    else
    {
        printf("result : %d\n", result-1);
    }
    
    // find the max order, then result is (max-1)
    // if there is 0, then result is (-1)
    
    
}



