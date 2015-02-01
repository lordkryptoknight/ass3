/*
 * trial1.c

 *
 *  Created on: 01-Feb-2015
 *      Author: kryptoknight
 */

#include<stdio.h>
#include<string.h>


int main(){


	int i,j,k,k1,l;
	int n_sol=0; //no. of solutions

	int S[]={1,1,1,1,1,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

	k1=100;

/*
	for(i=0;i<100;i++)
		for(j=0;j<100;j++){

		if(j!=i)
		for(k=0;k<100;k++){
			if(k!=i && k!=j)
				for(l=0;l<100;l++){
                    if(l!=i && l!=j && l!=k)
						if(S[i]+S[j]+S[k]*S[l]<=k1)
							n_sol++;

				}


	}


}


*/


for(i=0;i<25;i++)
    for(j=0;j<25;j++)
        if(j!=i)
		for(k=0;k<25;k++)
			if(k!=i && k!=j)
            for(l=0;l<25;l++)
                if(l!=i && l!=j && l!=k)
                if(S[i]+S[j]+S[k]*S[l]<=k1) n_sol++;


	printf("no. of solutions:%d",n_sol);



	char solutions[n_sol][5];
	int similarity_flag[n_sol];



int m;


	for(m=0;m<n_sol;m++){

        solutions[m][4]='\0';
        similarity_flag[m]=0;
	}

m=0; //resetting the value of m so that it can be reused
///*


	for(i=0;i<25;i++)
    for(j=0;j<25;j++)
        if(j!=i)
		for(k=0;k<25;k++)
			if(k!=i && k!=j)
            for(l=0;l<25;l++)
                if(l!=i && l!=j && l!=k)
                if(S[i]+S[j]+S[k]*S[l]<=k1){
                    solutions[m][0]=S[i];
                    solutions[m][1]=S[j];
                    solutions[m][2]=S[k];
                    solutions[m][3]=S[l];
                    m++;
                }


//*/

//Checking for repetitions

for(i=0;i<n_sol;i++){
    if(similarity_flag[i]==1)continue;  //If flag==1 then this solution has already been covered previously
    printf("(%d,%d,%d,%d)",solutions[i][0],solutions[i][1],solutions[i][2],solutions[i][3]);

    for(j=i+1;j<n_sol;j++)
        if(!strcmp(solutions[i],solutions[j])) similarity_flag[j]=1;

}


//printf("%s\n",solutions[0]);

//printf("\n\n%d\n\n","man"!="man");

return 0;

}

