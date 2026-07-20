#include <stdio.h>
#include <string.h>   
struct Team {
    char name[30];
    int played, won, lost, draw;
    int points;
};

int main() {
    int n, i;

    printf("Enter the number of teams: ");
    scanf("%d", &n);

    struct Team teams[n];

    for (i = 0; i < n; i++) {
        printf("Enter the name of team %d: ", i + 1);
        scanf("%s", teams[i].name);

        printf("Enter the number of matches played by %s: ", teams[i].name);
        scanf("%d", &teams[i].played);

        printf("Enter the number of matches won by %s: ", teams[i].name);
        scanf("%d", &teams[i].won);

        printf("Enter the number of matches lost by %s: ", teams[i].name);
        scanf("%d", &teams[i].lost);

        printf("Enter the number of matches drawn by %s: ", teams[i].name);
        scanf("%d", &teams[i].draw);

        // Calculate points
        teams[i].points = (teams[i].won * 2) + (teams[i].draw * 1);
    }

    // Sort teams based on points (descending)
    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (teams[i].points < teams[j].points) {
                struct Team temp = teams[i];
                teams[i] = teams[j];
                teams[j] = temp;
            }
        }
    }

    
    printf("\nCRICKET TOURNAMENT SCORECARD\n");
    printf("----------------------------------------------------------\n");
    printf("| %-20s %-8s %-5s %-5s %-5s %-7s|\n",
           "Team Name", "Played", "Won", "Lost", "Draw", "Points");
    printf("----------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("| %-20s %-8d %-5d %-5d %-5d %-7d|\n",
               teams[i].name,
               teams[i].played,
               teams[i].won,
               teams[i].lost,
               teams[i].draw,
               teams[i].points);
    }

    printf("----------------------------------------------------------\n");

    return 0;
}