#include <stdio.h>

int main()
{
    int liefer, vollst, bon;
    
    printf("Lieferfaehigkeit: ");
    scanf("%d", &liefer);
    printf("Angaben vollstaendig: ");
    scanf("%d", &vollst);
    printf("Bonitaet in Ordnung: ");
    scanf("%d", &bon);

    if (!liefer)
    {
        printf("nicht lieferbar\n");
    }
    else
    {
        if (bon) printf("Lieferung mit Rechnung\n");
        else printf("Lieferung als Nachname\n");

        if (!vollst) printf("Angaben vervollstaendigen\n");
    }

    return 0;
}