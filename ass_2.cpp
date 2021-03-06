#include <stdio.h>
#include <iostream>

using namespace std;

extern int registerme ( int );
extern void startsort ( );
extern int compareballs ( int, int );
extern void verifysort ( int*);
extern void startmatch ( int );
extern int fitsin ( int i, int j );
extern void verifymatch ( int*);

void merge(int a, int e, int b, int *s){
	int c = e-a+1;
	int d = b-e;
	int k;
	int i;
	int j;
	int r[d],l[c];
	for (i = 0; i < c; i++)
        	l[i] = s[a + i];
        for (j = 0; j < d; j++){
        	r[j] = s[e + 1+ j];
	}
	i=0;
	j=0;
	k=a;
	while (i <= c && j <= d)
   	 {
        	if (compareballs(l[i], r[j]) == -1)
        	{
        	    s[k] = l[i];
        	    i++;
        	}
        	else
        	{
        	    s[k] = r[j];
        	    j++;
        	}
        	k++;
    	}
	while (i<c){
		s[k] = l[i];
		i++;
		k++;	
	}
	while (j<d){
		s[k] = r[j];
		j++;
		k++;	
	}


}

void game1(int m,int n,int *s){
	if (m<n){
		cout<<"hello";	
		int i = (m+n)/2; 
		game1(m,i,s);
		game1((i+1),n,s);
		merge(m,i,n,s);
	}

}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int binarySearch(int s[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
 
        
        if (fitsin(s[mid], x) == 0)  
            return mid;
 
        
        if (fitsin(s[mid],x) == 1) 
            return binarySearch(s, l, mid-1, x);
 
        
        return binarySearch(s, mid+1, r, x);
   }
   return -1;
}
int partition(int m[], int low, int high, int s[]){
	int pivot = m[high];
	int i;
	i = binarySearch(s,low,high,pivot);
	int k = (low-1);
	int t = high;
	for(int j=low; j=(high-low); j++){
		if(fitsin(m[j],s[i]) == -1){
			swap(&m[j],&m[k]);	
			k++;
		}
	}
	swap(&m[k+1], &m[high]);
	return (k+1);
}

void game2(int m[], int low, int high, int s[])
{
    if (low < high)
    {
        int pi = partition(m, low, high,s);
 
        game2(m, low, pi - 1,s);
        game2(m, pi + 1, high,s);
    }
}


int main(){
	int n = 10;
	int s[n],m[n];
	int i;
	registerme(n);
	
	for(i=0;i<n;i++){
		s[i] = i;
		m[i] = i;
	}
	cout<<"\n+++ Sorting the balls...\n";
	startsort();
	game1(0,(n-1),s);
	for(i=0;i<n;i++){
		cout<<s[i]; 
	}
	verifysort(s);	
	printf("\n+++ Finding the matching boxes...\n");
	startmatch(1);
	game2(m,0,(n-1),s);
	verifymatch(m);


}
