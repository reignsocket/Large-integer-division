
#include <stdio.h>
#include <string.h>
#define MAX_LEN 200
char szLine1[MAX_LEN + 10];
char szLine2[MAX_LEN + 10];
int an1[MAX_LEN + 10];//Divisor, an1[0] corresponds to a single digit
int an2[MAX_LEN + 10];//Divisor, an2[0] corresponds to a single digit
int aResult[MAX_LEN + 10];//The depositor, aResult[0] corresponds to a single digit
//Substract function: The result of subtracting the large integer p1 of length nLen1 minus the large integer p2 of length nLen2 is placed in p1, and the return value represents the length of the result if it is not enough to reduce -1, just returning 0 p1[0], P2[0] is a bit
int Substract( int * p1, int * p2, int nLen1, int nLen2) {
	int i;
	if( nLen1 < nLen2 )
		return -1;
	//Let's determine if p1 is larger than p2. If not, return -1.
	bool bLarger = false;
	if( nLen1 == nLen2 ) {
		for( i = nLen1-1; i >= 0; i -- ) {
			if( p1[i] > p2[i] )
				bLarger = true;
			else if( p1[i] < p2[i] ) {
				if ( ! bLarger )
					return -1;
			}
		}
	}
	for( i = 0; i < nLen1; i ++ ) { //Subtraction
		p1[i] -= p2[i];//The parameters given when calling this function ensure that when i>=nLen2, p2[i] = 0
		if( p1[i] < 0 ) {
			p1[i]+=10;
			p1[i+1] --;
		}
	}
	for( i = nLen1 -1 ; i >= 0 ; i-- )
		if( p1[i] )
			return i + 1;
	return 0;
}
int main()
{
	int t, n;
	char szBlank[20];
	scanf("%d", &n);
	for( t = 0; t < n; t ++ ) {
		scanf("%s", szLine1);
		scanf("%s", szLine2);
		int i, j;
		int nLen1 = strlen( szLine1);
		memset( an1, 0, sizeof(an1));
		memset( an2, 0, sizeof(an2));
		memset( aResult, 0, sizeof(aResult));
		j = 0;
		for( i = nLen1 - 1;i >= 0 ; i --)
			an1[j++] = szLine1[i] - '0';
		int nLen2 = strlen(szLine2);
		j = 0;
		for( i = nLen2 - 1;i >= 0 ; i --)
			an2[j++] = szLine2[i] - '0';
		if( nLen1 < nLen2 ) {
			printf("0\n");
			continue;
		}
		nLen1 = Substract( an1, an2, nLen1, nLen2) ;
		if( nLen1 < 0 ) {
			printf("0\n");
			continue;
		}
		else if( nLen1 == 0) {
			printf("1\n");
			continue;
		}
		aResult[0] ++;
		int nTimes = nLen1 - nLen2;
		if( nTimes < 0)
			goto OutputResult;
		else if( nTimes > 0 ) {
			for( i = nLen1 -1; i >= 0; i -- ) {
				if( i >= nTimes )
					an2[i] = an2[i-nTimes];
				else
					an2[i] = 0;
			}
		}
		nLen2 = nLen1;
		for( j = 0 ; j <= nTimes; j ++ ) {
			int nTmp;
			while( (nTmp = Substract(an1, an2+j, nLen1, nLen2-j)) >= 0) {
				nLen1 = nTmp;
				aResult[nTimes-j]++;
			}
		}
		OutputResult:
		for( i = 0; i < MAX_LEN; i ++ ) {
			if( aResult[i] >= 10 ) {
				aResult[i+1] += aResult[i] / 10;
				aResult[i] %= 10;
			}
		}
		bool bStartOutput = false;
		for( i = MAX_LEN ; i >= 0; i -- )
			if( bStartOutput)
				printf("%d", aResult[i]);
			else if( aResult[i] ) {
				printf("%d", aResult[i]);
				bStartOutput = true;
			}
		if(! bStartOutput )
			printf("0\n");
		printf("\n");
	}
	 return 0;
}


