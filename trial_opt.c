/*! \mainpage Assignment 3
 *
 * \section intro_sec Introduction
 *
 *This documenation presents the code & analysis(for optimized code *trial_opt.c as well as non optimized code trial.c) for different *optimization levels.The analysis has been tabulated below.The analysis *is for a set S with numbers from 1 to 20 & k=100.

* <table border="1" style="width:100%">
* <tr>
 *   <th>Optimization level</th>
 *   <th>CPU time (in sec)</th>		
 *   <th>Memory (in Kb)</th>
 * </tr>

*<tr>
*<th>For trial.1.c</th>
*</tr>


* <tr>
 *   <th>O0(default)</th>
 *   <th></th>		
 *   <th></th>
 * </tr>

* <tr>
 *   <th>O1</th>
 *   <th></th>		
 *   <th></th>
 * </tr>


* <tr>
 *   <th>O2</th>
 *   <th></th>		
 *   <th></th>
 * </tr>


* <tr>
 *   <th>O3</th>
 *   <th></th>		
 *   <th></th>
 * </tr>

* <tr>
 *   <th>Ofast</th>
 *   <th></th>		
 *   <th></th>
 * </tr>

* <tr>
 *   <th>Os</th>
 *   <th></th>		
 *   <th></th>
 * </tr>





<tr>
<th>For trial1.1.c</th>
</tr>


* <tr>
 *   <th>O0(default)</th>
 *   <th></th>		
 *   <th></th>
 * </tr>

* <tr>
 *   <th>O1</th>
 *   <th></th>		
 *   <th></th>
 * </tr>


* <tr>
 *   <th>O2</th>
 *   <th></th>		
 *   <th></th>
 * </tr>


* <tr>
 *   <th>O3</th>
 *   <th></th>		
 *   <th></th>
 * </tr>

* <tr>
 *   <th>Ofast</th>
 *   <th></th>		
 *   <th></th>
 * </tr>

* <tr>
 *   <th>Os</th>
 *   <th></th>		
 *   <th></th>
 * </tr>




 * </table> */


/** @file trial_opt.c
 *  @brief Assignment 3.
 *
 *  This file contains the code for implementating following problem.
 *  Given a set Sand a number k find all 4 tuples a,b,c,d 
 *  such that a+b+c*d<=k.The implementation is done using a function
 *  tuple.It consist of a  2 d array aux which is
 *  used to store and print the results
 *  
 *
 *  @author Santosh Kumar Patra & Hemant Singh
 *  
 *  @bug For larger inputs the program shows segmentation fault.
 */
#include<stdio.h>
#include<string.h>


/**
 * @brief The whole program being small is being implemented as a monolithic code inside the main() function
 *
 * 
 */




int main(){


	int j,k1,l; /**variables for indexing*/
	long n_sol=0; /**no. of 4-tuples created*/


/**

@brief Reading input from input.txt & storing it to S[]

@code

*	char ch;
*	int i=0,S[10000],k,no_of_integers;
*	FILE *fp=fopen("input.txt","r");
*	while(fscanf(fp,"%d ",&S[i])!=EOF)
*	{
*       	i++;
*		fscanf(fp,"%c",&ch);
*	}
*	k1=S[i-1];
*	int N=i-1;
*


@endcode

*/


char ch;
	int i=0,S[10000],k,no_of_integers;
	FILE *fp=fopen("input.txt","r");
	while(fscanf(fp,"%d ",&S[i])!=EOF)
	{
        	i++;
		fscanf(fp,"%c",&ch);
	}
	k1=S[i-1];
	int N=i-1;








/**

@brief Counting the number of solutions,n_sol that exist so that storage for it may be created.


*@code
*
*for(i=0;i<N;i++)
*    for(j=0;j<N;j++)
*        if(j!=i)
*		for(k=0;k<N;k++)
*			if(k!=i && k!=j)
*            for(l=0;l<N;l++)
*                if(l!=i && l!=j && l!=k)
*                if(S[i]+S[j]+S[k]*S[l]<=k1) n_sol++;


*	printf("no. of solutions:%d \n",n_sol);
*
*
*
*@endcode



*/

for(i=0;i<N;i++)
    for(j=0;j<N;j++)
        if(j!=i)
		for(k=0;k<N;k++)
			if(k!=i && k!=j)
            for(l=0;l<N;l++)
                if(l!=i && l!=j && l!=k)
                if(S[i]+S[j]+S[k]*S[l]<=k1) n_sol++;


	printf("no. of solutions:%d \n",n_sol);



	char solutions[n_sol][5];
	int similarity_flag[n_sol];





int m;


	for(m=0;m<n_sol;m++){

        solutions[m][4]='\0';
        similarity_flag[m]=0;
	}

m=0; ///** resetting the value of m so that it can be reused. */



/**

@brief Finding the solutions of a+b+c*d<=k1 & storing it in a char array.It is being stored in a char array so that comparision is easy.


*@code
*
*for(i=0;i<N;i++)
*    for(j=0;j<N;j++)
*        if(j!=i)
*		for(k=0;k<N;k++)
*			if(k!=i && k!=j)
*            for(l=0;l<N;l++)
*                if(l!=i && l!=j && l!=k)
*                if(S[i]+S[j]+S[k]*S[l]<=k1){
*                    solutions[m][0]=S[i];
*                    solutions[m][1]=S[j];
*                    solutions[m][2]=S[k];
*                    solutions[m][3]=S[l];
*                    m++;
*                }
*
*
*
*@endcode

*/


	for(i=0;i<N;i++)
    for(j=0;j<N;j++)
        if(j!=i)
		for(k=0;k<N;k++)
			if(k!=i && k!=j)
            for(l=0;l<N;l++)
                if(l!=i && l!=j && l!=k)
                if(S[i]+S[j]+S[k]*S[l]<=k1){
                    solutions[m][0]=S[i];
                    solutions[m][1]=S[j];
                    solutions[m][2]=S[k];
                    solutions[m][3]=S[l];
                    m++;
                }



/**

* @brief Some solutions may be repeated.So the repetitions need to ignored.Checking for & flagging the repetitions so that they are ignored  *during printing.flag=1 imples already printed & needs to be ignored.


*@code
*for(i=0;i<n_sol;i++){
*    if(similarity_flag[i]==1)continue;  //If flag==1 then this solution has already been covered previously
 *   printf("(%d,%d,%d,%d)",solutions[i][0],solutions[i][1],solutions[i][2],solutions[i][3]);
*
 *   for(j=i+1;j<n_sol;j++)
  *      if(solutions[i]==solutions[j]) similarity_flag[j]=1;
*
*}
*@endcode


*/

for(i=0;i<n_sol;i++){
    if(similarity_flag[i]==1)continue;  //If flag==1 then this solution has already been covered previously
    printf("(%d,%d,%d,%d)",solutions[i][0],solutions[i][1],solutions[i][2],solutions[i][3]);

    for(j=i+1;j<n_sol;j++)
        if(solutions[i]==solutions[j]) similarity_flag[j]=1;

//        if(!strcmp(solutions[i],solutions[j])) similarity_flag[j]=1;

}



printf("\n\n*****done*****\n\n");


printf("\n\nNumber of solutions:%d\n\n",n_sol);

return 0;

}

