//Pattern matching algorithm in O(n)

void prepareLps(char *S, int lps[],int N)
{
   int i=0,j=-1;
   lps[i] = -1;
   i++;
   j++;
   while(i < N)
   {
	   if(S[i] == S[j])
		   lps[i] = lps[j];
	   else
	   {
           lps[i] = j;
           j = lps[j];
           while(j >=0 && S[i] != S[j])
           {
               j = lps[j];
           }
	   }
	   i++; j++;
   }
   for(int i=0;i<N;i++)
	   cout<<lps[i]<<" ";
   return;
}

int KMPSearch(char *A,char *B)
{
   int N = strlen(B);
   int M = strlen(A);
   int lps[strlen(B)];
   prepareLps(B,lps,N);
   int i=0,j=0;
   while(i<M)
   {
	   while(i< M and j < N)
	   {
           if(A[i] == B[j])
           {
               i++;
               j++;
        	   if(j == N)
        	   {
        		   return i-j;
        	   }
           }
           else
           {
               j = lps[j];
        	   break;
           }

	   }
	   if(j == -1)
	   {
		   j =0;
		   i++;
	   }
   }
   return 0;
}
