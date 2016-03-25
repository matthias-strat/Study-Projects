#include <stdio.h>

int main()
{
    int stimmenA, stimmenB, stimmenC;
    int sitze;
    int sitzeA, sitzeB, sitzeC;
    int teilerA, teilerB, teilerC;
    int qA, qB, qC;

    sitzeA = sitzeB = sitzeC = 0;
    teilerA = teilerB = teilerC = 1;

    printf("Stimmen Partei A: ");
    scanf("%d", &stimmenA);
    printf("Stimmen Partei B: ");
    scanf("%d", &stimmenB);
    printf("Stimmen Partei C: ");
    scanf("%d", &stimmenC);
    printf("Zu verteilende Sitze: ");
    scanf("%d", &sitze);
    printf("\n");

    qA = stimmenA;
    qB = stimmenB;
    qC = stimmenC;

    for (; sitze > 0; sitze--)
    {
        if (qA > qB)
        {
            if (qA > qC)
            {
                sitzeA++;
                teilerA++;
                qA = stimmenA/teilerA;
            }
            else
            {
                sitzeC++;
                teilerC++;
                qC = stimmenC/teilerC;
            }
        }
        else
        {
            if (qB > qC)
            {
                sitzeB++;
                teilerB++;
                qB = stimmenB/teilerB;
            }
            else
            {
                sitzeC++;
                teilerC++;
                qC = stimmenC/teilerC;
            }
        }
    }

    printf("Sitze:\nPartei A: %d\nPartei B: %d\nPartei C: %d\n", sitzeA, sitzeB, sitzeC);
    return 0;
}