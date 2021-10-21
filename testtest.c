#import <stdio.h>
#import "test.h"

void global(void)
{
	int ref[100],qte[100], secu[100], nb;
          float prix[100];
          fEnregStock;
	nb=chargement(ref,qte,prix,secu,100);
	if(nb==-1 || nb==-2)
		return;
	etatStock(ref,qte,prix,secu,nb);
}    
   
int main(void)
{
    global()
    return 0;
}
